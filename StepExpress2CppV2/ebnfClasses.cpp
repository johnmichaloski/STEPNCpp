/******************************************************************************
DISCLAIMER:
This software was produced by the National Institute of Standards
and Technology (NIST), an agency of the U.S. government, and by statute is
not subject to copyright in the United States.  Recipients of this software
assume all responsibility associated with its operation, modification,
maintenance, and subsequent redistribution.

See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/

/*

This file implements the EBNF classes defined in ebnfClasses.h.

*/
#include "stdafx.h"
#include "ebnfClasses.h"
#include <stdio.h>


namespace EBNF {

	int bLex=1;
	std::set<CString> gTerminals;
	std::set<CString> gLexTokens;
	std::set<CString> gTokens;
	std::map<CString, CString> gLexExpressions;

	extern int bLex;
	prodList productions;

	//std::vector<definition *> * definition::m_pAllocs= new std::vector<definition *>;
	//std::vector<defList *> * defList::m_pAllocs= new std::vector<defList *>;
	//std::vector<expression *> * expression::m_pAllocs= new std::vector<expression *>;
	//std::vector<expList *> * expList::m_pAllocs= new std::vector<expList *>;
	//std::vector<production *> * production::m_pAllocs= new std::vector<production *>;
	//std::vector<prodList *> * prodList::m_pAllocs= new std::vector<prodList *>;

	typedef std::set<CString>::iterator TokenIterator;

	CStringVector  special(4, CString("cmd_num"), CString("event_num"), CString("tool_string"), CString("csyTransformationName"));
	char * tabs[10] = { "", "\t", "\t\t\t", "\t\t\t\t", "\t\t\t\t\t", "\t\t\t\t\t\t", "\t\t\t\t\t\t", "\t\t\t\t\t\t\t", "\t\t\t\t\t\t\t\t", "\t\t\t\t\t\t\t\t\t" };
	extern FILE * debugFile;

	//#define DEBUGMSG(X) OutputDebugString(X);
#define DEBUGMSG(X) if(debugFile!=NULL) fprintf(debugFile  , X);
	///////////////////////////////////////////////////////////
	int GetNumExp(expression * exp )
	{
		int n=1;
		if(exp->theType == NONTERMINAL)
		{
			production * p = productions.FindProduction(exp->itemName);
			if(p!=NULL)
				n=p->defs->size();
		}
		return n;
	}

	int GetNumCombinations(production * p)
	{
		int nTotal=1;
		for (int i=0; i< p->defs->size(); i++) 
		{
			defList * defs = p->defs; 
			int nDefs=0;
			for(int j=0; j< p->defs->size(); j++)
			{

				definition * d = p->defs->at(j);
				for(int k=0; k< d->expressions->size(); k++)
				{		
					expression * exp= d->expressions->at(k);
					if(exp->theType == NONTERMINAL)
					{
						production * p = productions.FindProduction(exp->itemName);
						nDefs+=GetNumCombinations( p);
					}
					else
					{
						nDefs++;
					}
				}
			}
			nTotal*=nDefs;
		}
		return nTotal;
	}

	CStringVector Combine(CStringVector v1, CStringVector v2)
	{
		CStringVector v;
		if(v2.size() <1)
			return v1;
		if(v1.size() < 1)
			return v2;
		for(int i=0; i < v1.size(); i++)
		{
			for(int j=0; j< v2.size(); j++)
			{
				v.push_back(v1[i]+v2[j]);

			}
		}
		return v;
	}
	CStringVector printTestExpression( /* ARGUMENTS             */
		expression * exp,    /* expression to print   */
		prodList &prod,
		CString inPart)     /* YACC file to print in */
	{
		CStringVector strs;
		static int num=1;
		static int nevent=1;
		//DEBUGMSG(StrFormat("printTestExpression %s\n", exp->itemName));
		if(exp->theType == TERMINAL || exp->itemName=="real_val" || exp->itemName=="real_const")
		{
			if(exp->itemName=="INT_STRING")
			{
				int n =   rand()%2;
				int m = rand()% 100 ;
				strs.push_back(StrFormat("%d", m));
				/*switch(n)
				{
				case 0:
				tmp.AppendFormat("%0d", m);
				break;
				case 1:
				tmp.AppendFormat("-000");
				break;
				default:
				tmp.AppendFormat("%d", m);
				}*/
			}
			else if(exp->itemName=="DIGIT")
			{
				strs.push_back(StrFormat("%1d", rand()% 100 ));
			}
			else if(exp->itemName=="REAL_STRING" || exp->itemName=="real_val" || exp->itemName=="real_const")
			{
				CString tmp;
				int n =   rand()%9;
				float f =   -50 + rand()/(float(RAND_MAX)+1) * 100.0;
				if(n==0) tmp.AppendFormat("%8.4e", f);
				else if(n==1) tmp.AppendFormat("%8.4E", f);
				else if(n==2) tmp.AppendFormat("%12.8f", f);
				else if(n==3) tmp.AppendFormat("%8.4g", f);
				else if(n==4) tmp.AppendFormat("%8.4G", f);
				else if(n==5) tmp.AppendFormat("-000.000");
				else if(n==6) tmp.AppendFormat("-.123");
				else if(n==7) tmp.AppendFormat("-0.123");
				else if(n==8) tmp.AppendFormat("123.");
				else tmp.AppendFormat("%12.9f", f);
				strs.push_back(tmp);

			}
			else if(exp->itemName=="DBLQUOTEDSTRING")
			{
				static int dblqn=1;
				strs.push_back(StrFormat("\"Name1\"", dblqn++));
			}
			else
			{
				strs.push_back(exp->itemName);
			}
		}
		else if (exp->theType == ENDLINE)
		{
			strs.push_back(CString("\n"));
			//str+=inPart + "\n";
		}
		else if (exp->theType == ONECHAR)
		{
			strs.push_back(CString(exp->itemName[0]));
		}
		else if (exp->theType == OR)
		{
			strs.push_back(CString("OOOPS"));
		}
		else if ( exp->theType == NONTERMINAL) 
		{
			// types of NONTERMINAL  if INT_STRING print num, if cmd_num print 0001 (for now)
			if(exp->itemName=="cmd_num")
			{
				strs.push_back(StrFormat("%05d ", num++ ));

			}
			else if(exp->itemName=="event_num")
			{
				strs.push_back(StrFormat("E%04d ", nevent++ ));

			}
			else if(exp->itemName=="tool_string")
			{
				static char * tools[] = { "Probe1", "Tool1", "NoTool"};
				strs.push_back(StrFormat("\"%s\"", tools[0]));//rand() %2] );

			}
			else if(exp->itemName=="csyTransformationName")
			{
				static char * cys[] = { "Trans1", "Trans2", "Trans3"};
				strs.push_back(StrFormat("\"%s\"", cys[0]));//rand() %2] );

			}	
			else
			{
				production * p = productions.FindProduction(exp->itemName);
				if(p==NULL)
				{	
					strs.push_back(StrFormat("Production %s NOT FOUND ", exp->itemName));
					return strs;
				}
				prod.push_back(p);
				CStringVector pstrs;
				pstrs=printTestListDefinitions(p->defs, prod, inPart);
				strs=Combine(strs,pstrs);
				prod.pop_back();
#if 0
				// check for list repeating...
				if(p->visits >= p->defs->size())
				{
					p->visits=0;
					return tmp;
				}
				prod.push_back(p);
				//tmp=printTestDefinitions(p->defs, prod, inPart);
				tmp=printTestExpressions(p->defs->at(p->visits)->expressions, prod, inPart);
				if(prod[prod.size()-1]->lhs==exp->itemName)
					p->visits++;
#endif
			}
		}
		else
		{
			strs.push_back(StrFormat("unknown expression type\n")); 
		}
		return strs;
	}

	CStringVector printTestExpressions(  /* ARGUMENTS                    */
		expList * expressions, /* list of expressions to print */
		prodList &prods,
		CString inPart)       /* YACC file to print in        */
	{
		CString tmp;
		CStringVector strs;
		production * p = *prods.rbegin();
		int bInList = false;
		OutputDebugString(StrFormat("printTestExpression Production=%s Expression = %s\n", p->lhs,expressions->ToString()));

		for (int i=0; i<expressions->size(); i++) 
		{
			if(expressions->at(i)->itemName==p->lhs)
			{
				bInList =true;
				break;
			}
		}


		if(!bInList)
		{

			for (int i=0; i<expressions->size(); i++) 
			{
				CStringVector estrs;
				estrs=printTestExpression(expressions->at(i),  prods, inPart);
				strs=Combine(strs, estrs);
			}
		}
		else
		{
			//for (int i=0; i<expressions->size(); i++) 
			//{
			//	OutputDebugString(StrFormat("printTestExpression IN LIST %s\n", expressions->ToString()));
			//	CStringVector estrs;
			//	if(expressions->at(i)->itemName==p->lhs)  // multiple lists would cause problems
			//		continue;
			//	if(expressions->at(i)->theType == NONTERMINAL)
			//	{
			//		int n = GetNumExp(expressions->at(i) );
			//		//for(int i=0; i<n; i++)
			//	}
			//	else
			//	{
			//		estrs=printTestExpression(expressions->at(i),  prods, inPart);
			//		strs=Combine(strs, estrs);
			//	}

			//}
		}
		return strs;
	}

	CString printRandomTestDefinition( /* ARGUMENTS                    */
		defList * defs,       /* list of definitions to print */
		prodList &prods,	/* list of production rule names */
		CString inPart)      /* YACC file to print in        */
	{
		production * p = prods[prods.size()-1];
		CString tmp;
		CStringVector v;
		int i= rand() % defs->size(); 
		if(p->bInList)
			i = p->visits % defs->size();
		v=printTestExpressions(defs->at(i)->expressions,  prods, inPart);
		if(v.size()>0) 
			tmp = v[0];

		return tmp;
	}

	CStringVector printTestListDefinitions( /* ARGUMENTS                    */
		defList * defs,       /* list of definitions to print */
		prodList &prods,	/* list of production rule names */
		CString szTerminator)      /* append print in        */
	{
		production * p = prods[prods.size()-1];
		CStringVector v1;
		for (int i=0; i< defs->size(); i++) 
		{
			CStringVector v2=printTestExpressions(defs->at(i)->expressions,  prods, _T(""));
			if(szTerminator.GetLength() > 0)
			{
				CStringVector v3;
				v3.push_back(szTerminator);
				v2=Combine(v2,v3);
			}
			v1.insert(v1.end(), v2.begin(), v2.end()) ;
			//DEBUGMSG(StrFormat("%sprintTestListDefinitions Combined Vector %s\n", tabs[prods.size()], v1.ToString("\n")));
		}
		return v1;
	}
	HRESULT AZTestFile(CString & _szPathTitle)
	{	
		FILE * testFile;
		//printTestProductions(testFile);
		CStringVector prods;
		CString szResults;
		//prods.push_back("cmd_num");
		prods.push_back("ippdme_statement");
		//prods.push_back("enum_all_prop");
		if(productions.size() > 0)
		{
			testFile = fopen(_szPathTitle , "w");
			szResults = printProductionsList(prods);
			if(testFile)
			{
				fprintf(testFile, szResults);
				fclose(testFile);
			}
			return S_OK;
		}
		return E_FAIL;
	}
	void printTestProductions( /* ARGUMENTS             */
		FILE * testFile)      /* YACC file to print in */
	{
		production * p = productions.FindProduction("input_file");
		prodList prods;
		CString str;
		CStringVector v1;
		CStringVector v2;
		srand(time(NULL));
		for(int i=0; i<100; i++)
		{
			prods.clear();
			prods.push_back(p);
			v2=printTestListDefinitions(p->defs, prods,  _T(""));
			v1=Combine(v1,v2);
			v2.clear();
			v2.push_back("\n");
			v1=Combine(v1,v2);
			str=v1.Merge();
			fprintf(testFile, str);
		}
	}

	CString printProductionsList(CStringVector szProds)
	{
		production * p = productions.FindProduction("input_file");
		prodList prods;
		CStringVector v1;
		CString szTerminator;
		srand(time(NULL));
		for(int i=0; i<1; i++)
		{
			productions.Reset();
			for(int j=0; j< szProds.size(); j++)
			{
				CStringVector v2;
				p = productions.FindProduction(szProds[j]);
				if(p==NULL)
					return StrFormat("Error production \"%s\"  not found", szProds[j]);

				prods.clear();
				prods.push_back(p);
				if(find(special.begin(), special.end(),p->lhs)!=special.end())
				{
					expression exp(NONTERMINAL, p->lhs, NULL);
					v2= printTestExpression(&exp,  prods, _T(""));
					v1=Combine(v1,v2);
				}
				else
				{
					v2=printTestListDefinitions(p->defs, prods,  szTerminator);
					v1=Combine(v1,v2);
				}
			}
			CStringVector v2;
			v2.push_back("\n");
			v1=Combine(v1,v2);
		}
		return v1.Merge();;
	}


	int findToken(const char * text)
	{
		CString sToken(text);
		TokenIterator it = gTokens.find( sToken);
		if( it== gTokens.end())
			return 0;
		return 1;

	}


	/* recordToken

	Returned Value: none

	This provides a not horribly inefficient way of recording the the
	names of all tokens so that most of the lex file for the DMIS parser
	built from a dmisebnf input file can be generated automatically. The
	tokenNames array is really 26 arrays (one for each first letter) of
	pointers to names. The token names are stored in alphabetical order.

	In the DMIS EBNF, token names are made primarily of upper case
	letters, but some include digits, underscores, or minus signs. These
	names are changed in ebnf2yacc.lex to contain only upper case
	letters. The printLex function knows to make the lex it writes look
	for the correct characters.

	*/
	void recordToken( char * tokenName)
	{
		gTokens.insert(tokenName); // [tokenName]=0;
	}

	bool recordLexToken(char * tokenName)
	{
		// compare existing availabe lex tokenizing to see if capability exists 
		gLexTokens.insert(tokenName); // [tokenName]=0;
		return 0;
	}
	bool FindLexToken(char * tokenName)
	{
		// compare existing availabe lex tokenizing to see if capability exists 
		return gLexTokens.find(tokenName)!= gLexTokens.end(); // [tokenName]=0;
	}

	CString TokensYaccString()
	{
		CString tmp;
		TokenIterator it;
		for (it = gTokens.begin(); it!= gTokens.end(); it++)
		{
			if((*it) == "AND")
				continue;
			if((*it) == "OR")
				continue;
			if((*it) == "NOT")
				continue;
			tmp.AppendFormat( "%%token %s\n", (*it));
		}
		return tmp;

	}
	void recordTerminal( const  char * terminalName)
	{
		gTerminals.insert(terminalName); 
		//gTerminals[terminalName]=0;

	}
	CString TerminalsYaccString()
	{
		CString tmp;
		TokenIterator it;
		for (it = gTerminals.begin(); it!= gTerminals.end(); it++)
		{
			tmp.AppendFormat("%%token <sval> %s\n",(*it));
		}
		return tmp;
	}

	/********************************************************************/

	/* printDefinition

	Returned Value: none

	Called By: printDefinitions

	This prints into the YACC file one definition of a production.

	It is OK if the expressions list in the definition is NULL.

	*/

	void printDefinition( /* ARGUMENTS                                        */
		definition * def,    /* definition to print                              */
		bool orBar,          /* whether to print an OR bar before the definition */
		FILE * yaccFile)     /* YACC file to print in                            */
	{
		fprintf(yaccFile, "\t%s", ((orBar == true) ? "|" : " "));
		printExpressions(def->expressions, yaccFile);
		fprintf(yaccFile, "\n");
	}

	/********************************************************************/

	/* printDefinitions

	Returned Value: none

	Called By: printProduction

	This prints into the YACC file all the definitions of a production.

	*/

	void printDefinitions( /* ARGUMENTS                    */
		defList * defs,       /* list of definitions to print */
		FILE * yaccFile)      /* YACC file to print in        */
	{
		for (DefinitionListIterator it = defs->begin(); it != defs->end(); it++) 
		{
			printDefinition((*it), it != defs->begin(), yaccFile);
		}
	}


	/********************************************************************/
	/* printExpression

	Returned Value: none

	Called By: printExpressions

	This prints into the YACC file one expression.

	When printExpression is called, no optionals should remain.

	Although the EBNF uses ^ to represent the operation of raising
	a number to a power, the POWER token is recognized in lex as ** .
	The ^ symbol could be replaced in the EBNF by the terminal
	"power", but it is nice to have all the arithmetic operators
	represented by single characters.
	*/
	void printExpression( /* ARGUMENTS             */
		expression * exp,    /* expression to print   */
		FILE * yaccFile)     /* YACC file to print in */
	{
		if ((exp->theType == DMISTOKEN)   ||
			(exp->theType == NONTERMINAL) ||
			(exp->theType == TERMINAL))
			fprintf(yaccFile, "%s", exp->itemName);
		else if (exp->theType == ENDLINE)
			fprintf(yaccFile, "ENDLINE");
		else if (exp->theType == ONECHAR)
		{
			switch (exp->itemName[0])
			{
			case '+':
				fprintf(yaccFile, "PLUS");
				break;
			case '-':
				fprintf(yaccFile, "MINUS");
				break;
			case '*':
				fprintf(yaccFile, "TIMES");
				break;
			case '^':
				fprintf(yaccFile, "POWER");
				break;
			case '/':
				fprintf(yaccFile, "SLASH");
				break;
			case '@':
				fprintf(yaccFile, "AT");
				break;

			case ',':
				if(bLex)
					fprintf(yaccFile, "COMMA");
				else 
					fprintf(yaccFile, "','");
				break;
			case '=':
				if(bLex)
					fprintf(yaccFile, "EQUALS");
				else 
					fprintf(yaccFile, "'='");
				break;
			case ':':
				if(bLex)
					fprintf(yaccFile, "COLON");
				else 
					fprintf(yaccFile, "':'");
				break;
			case '[':
				if(bLex)
					fprintf(yaccFile, "LBOX");
				else 
					fprintf(yaccFile, "'['");
				break;
			case ']':
				if(bLex)
					fprintf(yaccFile, "RBOX");
				else 
					fprintf(yaccFile, "']'");
				break;
			case '(':
				if(bLex)
					fprintf(yaccFile, "LPAREN");
				else 
					fprintf(yaccFile, "'('");
				break;
			case ')':
				if(bLex)
					fprintf(yaccFile, "RPAREN");
				else 
					fprintf(yaccFile, "')'");
				break;
			default:
				fprintf(yaccFile, "'%c'", exp->itemName[0]);

			} 
		}
		else if (exp->theType == OR)
		{
			fprintf(yaccFile, "OOOPS");
		}
		else
		{
			StdErrMsg("unknown expression type\n"); 
		}
	}


	/********************************************************************/

	/* printExpressions

	Returned Value: none

	Called By: printDefinition

	This prints into the YACC file the expressions of a definition.

	It is OK if expressions is NULL. In that case, this
	prints " empty " with comment marks around it.

	*/


	void printExpressions(  /* ARGUMENTS                    */
		expList * expressions, /* list of expressions to print */
		FILE * yaccFile)       /* YACC file to print in        */
	{
		if (expressions->size()==0)
			fprintf(yaccFile, " /* empty */");
		else
		{
			for (ExpressListIterator it = expressions->begin(); it!=expressions->end(); it++)
			{
				fprintf(yaccFile, " ");
				printExpression((*it), yaccFile);
			}
		}
	}


	/********************************************************************/

	/* expList::spliceInAfterCurrent

	This:
	1. copies the contents of the "from" list into the "this" list
	immediately after this->current.
	2. possibly resets the "first" and "last" of "this".

	Example: Suppose the "this" list is (A,B,C,D), the "from" list is
	(X,Y,Z), this->current is B, and (x,y,z) is a copy of (X,Y,Z), then
	the following two diagrams show the before and after situations.

	current
	|
	v
	A <-> B <-> C <-> D                        X <-> Y <-> Z


	current
	|
	v
	A <-> B <-> x <-> y <-> z <-> C <-> D      X <-> Y <-> Z


	Appropriate checks for resetting first and last are made.

	The from list should not be empty. The this list may be empty.

	This allows one to splice in at the beginning or end of a list.

	*/


	/* listIsOpt

	Returned Value: int
	If the list characterized by optExps is optional in defExps, this
	returns 1. Otherwise, it returns 0.

	Called By: replaceOptList

	See documentation of replaceOptList.

	A list is not optional if the contents of optExps immediately precedes
	the optional in defExps. For example, if defExps is A B C [B C ...] D,
	then optExps is "B C". Since "B C" immediately precedes [B C ...], at
	least one "B C" is required, so the list is not optional.

	If the list is not optional, this function will change defExps 
	by removing the copy of optExps that immediately precedes the optional.
	For example, A B C [B C ...] D will be changed to A <list of B C> D. The
	meaning of the definition will be preserved, since both before and after
	processing, at least one "B C" will be required.

	The check is made by going backwards along optExps and seeing if the
	preceding entries in defExps match. Matching is done by value.  That
	is, we cannot expect two data pointers to point to the same
	expression, but they might point to different expressions that have
	the same contents. If optExps contains an optional, which never
	happens in the DMIS ebnf, this prints an error message and exits.

	Unless there is a bug, optExp and defExp will never be NULL, so
	that is not being tested.

	defExps->current is expected to be pointing at the optional
	when this starts.

	This could free some storage it is not bothering to free.

	*/

	int listIsOpt(      /* ARGUMENTS                                            */
		expList * defExps, /* list of expressions in which an optional list occurs */
		expList * optExps) /* list of expressions inside the optional list         */
	{
		//expListCell * optCell;
		//expListCell * defCell;
		expression * optExp;
		expression * defExp;
		ExpressListReverseIterator  optCell=optExps->rbegin();
		ExpressListReverseIterator  defCell=(ExpressListReverseIterator)defExps->Current();
		defCell--;

		for (;
			optCell!=optExps->rend (); 
			optCell++, defCell++)
		{
			if (defCell==optExps->rend())
				return 1;
			optExp = (*optCell);
			defExp = (*defCell);
			if (optExp->theType == OR)
			{
				StdErrMsg("Cannot handle optional inside list\n");
				exit(1);
			}
			if ((optExp->theType != defExp->theType) ||
				(strcmp(optExp->itemName, defExp->itemName)))
				return 1;
		}

		defCell = (ExpressListReverseIterator) defExps->Current();  // may not work if end() != 
		for (optCell = optExps->rbegin(); optCell!=optExps->rend(); optCell++)
		{ 
			// remove the copy of optExps from defExps
			//defCell->back = defCell->back->back;
			//if (defCell->back)
			// defCell->back->next = defCell;
			//else
			// defExps->first = defCell;
		}
		return 0;
	}


	/* expListsSame

	Returned Value: int
	If the exps1 and exps2 are identical lists of expressions that contain
	no optionals, this returns 1. If either list contains an optional
	(which should never happen and means there is a bug), this exits.
	Otherwise, it returns 0.

	Called By: unduplicateDefinitions

	*/

	int expListsSame( /* ARGUMENTS                         */
		expList * exps1, /* first expression list to compare  */
		expList * exps2) /* second expression list to compare */
	{
		expression * exp1;
		expression * exp2;
		ExpressListIterator it1, it2;

		for(it1=exps1->begin(), it2=exps2->begin(); it1!=exps1->end() &&  it2!=exps2->end() ; it1++, it2++)
		{
			exp1 = (*it1);
			exp2 = (*it2);
			if ((exp1->theType == OR) || (exp2->theType == OR))
			{
				StdErrMsg( "BUG in expListsSame\n");
				exit(1);
			}
			else if (exp1->theType != exp2->theType)
				return 0;
			else if (exp1->theType == ENDLINE);
			else if (strcmp(exp1->itemName, exp2->itemName))
				return 0;
		}
		return (((it1==exps1->end()) && (it2==exps2->end())) ? 1 : 0);
	}
	/* replaceOptDefinitions

	Returned Value: none

	Called By: replaceOptProductions

	The prodName (production name) and numExtras (number of additional
	productions required) are used to construct unique names for the extra
	productions, all of which (if there are any) are lists. prodName and
	numExtras are passed down the function call chain.

	The name of a list used in the production has the form
	"[prodName][numExtras]List".

	The name of the set of items in each list has the form
	"[prodName][numExtras]ListItems". It would be nicer to use the
	name of the thing listed, but there may be more than one instance
	of the same type of list, and the names of the instances must be
	distinct.

	The numExtras is incremented each time it is used to form a name.

	*/

	void replaceOptDefinitions( /* ARGUMENTS                                 */
		const char * prodName,           /* name of production, used for making names */
		defList * defs)            /* definitions in which replace optionals    */
	{
		int numExtras;

		numExtras = 0;
		for (int i=0; i< defs->size();i++)
		{
			defs->current = defs->at(i);
			while (replaceOptExpression(defs, prodName, &numExtras));
		}
		unduplicateDefinitions(defs);
	}

	/********************************************************************/

	/* replaceOptExpression

	Returned Value: int
	If an optional item is found, this returns 1. Otherwise, it returns 0.

	Called By: replaceOptDefinitions

	This looks at each expression in the list, stopping as soon as it
	finds an optional item. It converts the optional to a non-optional by
	calling the appropriate converter.

	The digit in a multiplicity must be at least 2 (digit 1 is pointless,
	since that is a simple optional).

	*/

	int replaceOptExpression( /* ARGUMENTS                                  */
		defList * defs,          /* list of definitions to examine             */
		const char * prodName,         /* base name to use for making names          */
		int * numExtras)         /* number to use for names, may change here   */
	{
		expList * exps;   // expression list from which to remove opts
		optional * opt;   // optional to replace
		int digit;        // digit indicating type of optional

		exps = defs->current->expressions;
		int i;
		for(i =0; i< exps->size(); i++) // it = exps->begin(); it != exps->end(); it++)
		{
			exps->current=exps->at(i); // (*it);

			if (exps->current->theType != OR) // not an optional
				continue;
			opt = exps->current->optValue;
			if (!opt)
			{
				OutputDebugString( "BUG1 in replaceOptExpression\n");
				exit(1);
			}
			digit = opt->digit;
			if (digit < -1)
			{
				OutputDebugString( "BUG2 in replaceOptExpression\n");
				exit(1);
			}
			else if (digit == -1) // simple optional
			{ // exps->current is now set to the optional to remove
				replaceOptMulti(exps, 1);
				break;
			}
			else if (digit == 0) // list
			{ // exps->current is now set to the optional to remove
				replaceOptList(exps, prodName, numExtras);
				break;
			}
			else if (digit == 1)
			{
				OutputDebugString( "Multiplicity of size 1 not allowed.\n");
				exit(1);
			}
			else // found multiplicity of size at least 2
			{ // exps->current is now set to the optional to remove
				replaceOptMulti(exps, digit);
				break;
			}
		}
		return (i != exps->size() ? 1 : 0);
	}

	/********************************************************************/

	/* replaceOptList

	Returned Value: none

	Called By: replaceOptExpression

	Almost all the lists in the EBNF for DMIS that used the ellipsis (...)
	notation in the printed version of DMIS 05.0 have been replaced by
	notation that does not use ellipsis notation, so this function does
	not currently have much work to do.

	The optional (Opt) has "digit" set to 0 (meaning Opt is a list):

	A. A production P is built defined by the items in Opt and inserted
	after the current production.
	B. A production is built defined as a list of P's and inserted
	after the current production.
	C1. If Opt is actually required (which is determined by seeing if the
	items in Opt are the same as the items immediately preceding Opt),
	Opt and the immediately preceding items are deleted from the
	ExpressionList and replaced by a new expression of type
	NONTERMINAL whose name is the name used in B.

	Example C1: The DMIS EBNF had
	<tol_usetol> ::=  USETOL ',' <any_val> [',' <any_val> ...]

	When the right side is read in, a list of expressions is built with
	the following types:
	DMISTOKEN ONECHAR NONTERMINAL OPTIONAL
	and the list of expressions in the OPTIONAL has the types:
	ONECHAR NONTERMINAL
	Since the ONECHAR NONTERMINAL in the OPTIONAL matches the same two
	items immediately preceding the OPTIONAL, it is recognized that
	the list is actually required, and the following are printed out

	tol_usetol :
	USETOL tol_usetol2List
	;

	tol_usetol2List :
	tol_usetol1ListItems
	| tol_usetol2List tol_usetol1ListItems
	;

	tol_usetol1ListItems :
	C any_val
	;

	C2. If Opt is not actually required, the same steps A and B are taken,
	but the definition being modified is changed by replacing the
	optional items with the new list and keeping it optional. The
	optional will be removed by subsequent processing.

	Example C1: Suppose the DMIS EBNF were the following,
	<tol_usetol> ::=  USETOL [',' <any_val> ...]

	Then the second and third items above would be the same, but the first
	item would be:

	tol_usetol :
	USETOL [tol_usetol2List]
	;

	The listIsOpt function will change exps if the list is not optional
	by removing the copy of the expressions in the optional that immediately
	precedes the optional. For example, A B C [B C ...] D will be changed
	to A <list of B C> D. This preserves the meaning of the definition, since
	both before and after processing, at least one "B C" will be required.

	*/

	void replaceOptList( /* ARGUMENTS                                       */
		expList * exps,     /* expression list from which to remove lists      */
		const  char * prodName,    /* base name to use for making names               */
		int * numExtras)    /* number to use for making names, may change here */
	{
		char buffer[256];
		optional * opt;      // the option in the list to convert
		expression * newExp;
		expList * newExpList;
		char * itemsName;
		char * listName;
		production * newProd;
		definition * newDef;
		defList * newDefs;

		opt = exps->current->optValue;

		sprintf(buffer, "%s%dListItems", prodName, ++(*numExtras));
		itemsName = strdup(buffer);
		sprintf(buffer, "%s%dList", prodName, ++(*numExtras));
		listName = strdup(buffer);

		newExp = expression::NewExpression(NONTERMINAL, itemsName, NULL);
		newExpList = expList::NewExpList(newExp);
		newDef = definition::NewDefinition(newExpList);
		newDefs = defList::NewDefList(newDef);
		newExp = expression::NewExpression(NONTERMINAL, listName, NULL);
		newExpList = expList::NewExpList(newExp);
		newExp = expression::NewExpression(NONTERMINAL, itemsName, NULL);
		newExpList->pushBack(newExp);
		newDef = definition::NewDefinition(newExpList);
		newDefs->pushBack(newDef);
		newProd = production::NewProduction(listName, newDefs);
		productions.insertAfterCurrent(newProd);

		newDef = definition::NewDefinition(opt->expressions);
		newDefs = defList::NewDefList(newDef);
		newProd = production::NewProduction(itemsName, newDefs);
		productions.insertAfterCurrent(newProd);

		newExp = expression::NewExpression(NONTERMINAL, listName, NULL);
		if (listIsOpt(exps, opt->expressions))
		{ // if optional, replace expressions and change digit in opt
			newExpList = expList::NewExpList(newExp);
			opt->digit = -1;
			opt->expressions = newExpList;
		}
		else
		{ // if not optional, replace optional with list
			exps->current = newExp;
		}
	}


	void replaceOptMulti( /* ARGUMENTS                                     */
		expList * exps,      /* list of expressions in which to replace multi */
		int digit)           /* maximum number of copies                      */
	{
		definition * def;
		defList * defs;
		expList * spliceEm;
		expList * newExps;
		int n;

		if (exps->current == NULL)
		{
			StdErrMsg("BUG exps->current is NULL in replaceOptMulti\n");
			exit(1);
		}
		else if (exps->current == NULL)
		{
			StdErrMsg( "BUG exps->current->data is NULL in replaceOptMulti\n");
			exit(1);
		}

		ExpressListIterator it ;
		spliceEm = exps->current->optValue->expressions;
		it=exps->remove(exps->current);
#if 0
		if (exps->current->next) // wire next to back
			exps->current->next->back = exps->current->back;
		else // or reset last if there is no next
			exps->last = exps->current->back;
		if (exps->current->back) // wire back to next
			exps->current->back->next = exps->current->next;
		else // or reset first if there is no back
			exps->first = exps->current->next;
#endif
		if(it!=exps->end())
			exps->current =  (*it) ; //  exps->current->back; // back up to insert, may be NULL
		else 
			exps->current =  NULL;

		newExps = expList::NewExpList();
		newExps->copyFrom(exps);

		defs = productions.current->defs;
		def = defs->current;
		def->expressions = newExps; // replace original exps with copy without opt
		for (n = 0; n < digit; n++)
		{
			exps->spliceInAfterCurrent(spliceEm); // modifies exps
			newExps = expList::NewExpList();
			newExps->copyFrom(exps);
			def = definition::NewDefinition(newExps);
			defs->insertAfterCurrent(def);
		}
		if (exps->current == NULL)
			exps->current = exps->front(); // will now be NULL only if exps is empty
	}


	void replaceOptProductions() /* NO ARGUMENTS */
	{
		ProdListIterator  aCell;

		for (aCell = productions.begin(); aCell != productions.end(); aCell++)
		{
			productions.current= (*aCell);
			replaceOptDefinitions((*aCell)->lhs, (*aCell)->defs);
		}
	}

	/********************************************************************/

	/* unduplicateDefinitions

	Returned Value: none

	Called By: replaceOptDefinitions

	This goes through a list of definitions, and for each definition def1,
	compares all the definitions in the list after def1 with def1. If any
	definition def2 after def1 is a duplicate of def1, def2 is removed
	from the list.

	There are expected to be no optionals in any definition. If there
	are, expListsSame exits.

	This could free up some memory it is not bothering to free.

	*/

	void unduplicateDefinitions( /* ARGUMENTS                  */
		defList * defs)             /* definitions to unduplicate */
	{
		DefinitionListIterator defCell1;
		DefinitionListIterator defCell2;

		for (defCell1 = defs->begin(); defCell1!= defs->end(); defCell1++)
		{
			defCell2 = defCell1;
			for (defCell2++; defCell2!= defs->end(); defCell2++)
			{
				if (expListsSame((*defCell1)->expressions, (*defCell2)->expressions))
				{
					defs->erase(defCell2);;
				}
			}
		}
	}





	CStringVector prodList::CompletenessCheck()
	{
		CStringVector errs;
		for(int i=0; i<size(); i++) 
		{
			production * p = at(i);
			defList * defs = p->defs; 
			for(int j=0; j< p->defs->size(); j++)
			{
				definition * d = p->defs->at(j);
				for(int k=0; k< d->expressions->size(); k++)
				{
					expression * exp= d->expressions->at(k);
					if(exp->theType == NONTERMINAL)
					{
						production * p = productions.FindProduction(exp->itemName);
						if(p==NULL)
						{
							errs.push_back(StrFormat("Production %s used but not defined\n", exp->itemName));
						}
					}		
				}
			}
		}
		return errs;
	}


	bool recordLexExpression(char * szToken, char * szExpression)
	{
		gTerminals.insert(szToken); 
		gLexExpressions[szToken] = szExpression;
		return true;
	}


	void StdErrMsg(char * format, ...)
	{

		va_list ap;
		va_start(ap, format);

		int n= strlen(format) + 1028;
		char * s=new char[n];	

		if(s==NULL)
		{
			return ;   // this is a serious problem
		}

		// Kind of a bogus way to insure that we don't
		// exceed the limit of our buffer
		while(_vsnprintf(s, n-1, format, ap)<0){
			if(s!=NULL) delete [] s;
			n=n+1028;
			s = new char[n]; 
		}

		va_end(ap);
		OutputDebugString(s);
		delete [] s;	

	}

	
void printProduction( /* ARGUMENTS             */
 production * prod,   /* production to print   */
 FILE * yaccFile)     /* YACC file to print in */
{
  char c; // space or | to start definition
  fprintf(yaccFile, "%s :\n", prod->lhs);
  if (strcmp(prod->lhs, "decl_stm") == 0)
    {
      fprintf(yaccFile, "\t  DECL {varLoc = IN_DECL;} SLASH decl_minor ENDLINE"
	      " {varLoc = IN_OPEN;}\n");
    }
  else if (strcmp(prod->lhs, "macro_stm") == 0)
    {
      fprintf(yaccFile, 
"\t  m_label_const EQUALS MACRO macro_action ENDLINE {varLoc = IN_OPEN;}\n"
"\t| m_label_const EQUALS MACRO macro_action SLASH\n"
"\t  macro_par_list ENDLINE {varLoc = IN_OPEN;}\n\t;\n\n"
"macro_action : /* empty */ {varLoc = IN_MACRO;}\n");
    }
  else if (strcmp(prod->lhs, "decl_type") == 0)
    {
      c = ' ';
      if (findToken("BOOL"))
	{
	  fprintf(yaccFile, "\t%c BOOL { varType = BOOL_VARNAME; }\n", c);
	  c = '|';
	}
      if (findToken("INTGR"))
	{
	  fprintf(yaccFile, "\t%c INTGR { varType = INT_VARNAME; }\n", c);
	  c = '|';
	}
      if (findToken("LONG"))
	{
	  fprintf(yaccFile, "\t%c LONG { varType = REAL_VARNAME; }\n", c);
	  c = '|';
	}
      if (findToken("REAL"))
	{
	  fprintf(yaccFile, "\t%c REAL { varType = REAL_VARNAME; }\n", c);
	  c = '|';
	}
      if (findToken("DOUBLE"))
	{
	  fprintf(yaccFile, "\t%c DOUBLE { varType = REAL_VARNAME; }\n", c);
	  c = '|';
	}
      if (findToken("CHAR"))
	{
	  fprintf(yaccFile, 
		  "\t%c CHAR C int_val { varType = STRING_VARNAME; }\n", c);
	  c = '|';
	}
      if (findToken("VECTOR"))
	{
	  fprintf(yaccFile, "\t%c VECTOR { varType = VECTOR_VARNAME; }\n", c);
	  c = '|';
	}
    }
  else
    {
      printDefinitions(prod->defs, yaccFile);
    }
  if ((strcmp(prod->lhs, "dmis_statement") == 0) ||
      (strcmp(prod->lhs, "dmis_first_statement") == 0) ||
      (strcmp(prod->lhs, "endfil_stm") == 0))
    fprintf(yaccFile, "\t| error ENDLINE {numErrors++; yyerrok;}\n");
  fprintf(yaccFile, "\t;\n\n");
}

/********************************************************************/

/* printProductions

Returned Value: none

Called By: printYacc

This prints all the productions.

*/
void printProductions(FILE * yaccFile)      /* YACC file to print in */
{
  ProdListIterator  aCell;

  for (aCell = productions.begin(); aCell != productions.end(); aCell++)
    {
      printProduction((*aCell), yaccFile);
    }
}

};