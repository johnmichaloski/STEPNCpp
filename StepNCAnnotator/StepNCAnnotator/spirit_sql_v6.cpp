

//
//  A simple "toy SQL" parser for Spirit.
//  Requires -  Spirit version 1.6.0 or later
//
//  Written by:  Andy Elvey
//  
//  This parser parses a very small subset of SQL : 
//  the "select" clause only.
//  
//  NOT YET SUPPORTED - 
//  a) Left joins. 
//  b) The "case when" statement 
//      ( e.g. case when myvar <= 5 then 'foo' 
//                  when myvar  = 6 then 'bar'  
//                  else 'baz' 
//             end 
//                  as var1  )  
//  
//  NOTE - If you use a text variable in your query (e.g. 
//   select * from mystuff where var1 = 'abc' ;  ) make sure that 
//  the variable is in **single** quotes, as shown above. 
//
//  Examples of queries that will work - 
//    select * from table1, table2 where table1.foo = table2.bar ;  
//    select var1, var2, var3 from moredata, mystuff, yourdata ; 
//    select test as var1, foo as var2 from mystuff 
//          where a < 45 and b in (1, 2, 3) or c <= 78 ;  
//
//  ========================================================================= 
//    Permission to copy, use, modify, sell and distribute this software is
//    granted provided this copyright notice appears in all copies. This
//    software is provided "as is" without express or implied warranty, and
//    with no claim as to its suitability for any purpose.
//  =========================================================================  


//#define BOOST_SPIRIT_DEBUG  ///$$$ DEFINE THIS WHEN DEBUGGING $$$///

#include "stdafx.h"

#include <boost/spirit/core.hpp>
#include <boost/spirit/symbols/symbols.hpp>
#include <boost/spirit/utility/lists.hpp>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

///////////////////////////////////////////////////////////////////////////////
using namespace boost::spirit;
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------
//  Start grammar definition
//----------------------------------------------------------------------------

struct toysql_grammar :
    public grammar<toysql_grammar>
{
    template <typename ScannerT>
    struct definition
    {
        definition(toysql_grammar const& self)
        {
        
            //-----------------------------------------------------------------
            // KEYWORDS
            //-----------------------------------------------------------------
            keywords =
                "select", "distinct", "from" , "where" , "in" , 
                "and" , "or" , "as" , "left" , "join" , "on" ,
                "is" , "not" , "null" ;             
        
            //-----------------------------------------------------------------
            // OPERATORS
            //-----------------------------------------------------------------

            chlit<>     STAR('*');
            chlit<>     COMMA(',');
            chlit<>     LPAREN('(');
            chlit<>     RPAREN(')'); 
            chlit<>     SEMI(';');
            chlit<>     LT('<');
            chlit<>     GT('>');
            strlit<>    LE("<=");
            strlit<>    GE(">=");
            chlit<>     EQUAL('=');
            strlit<>    NE("!=");    
            chlit<>     DOT('.');        

            //---------------------------------------
            // TOKENS
            //---------------------------------------
            typedef inhibit_case<strlit<> > token_t;

            token_t SELECT      = as_lower_d["select"];
            token_t DISTINCT    = as_lower_d["distinct"];
            token_t FROM        = as_lower_d["from"];
            token_t LEFT        = as_lower_d["left"];
            token_t JOIN        = as_lower_d["join"];
            token_t ON          = as_lower_d["on"];
            token_t WHERE       = as_lower_d["where"];
            token_t IN_         = as_lower_d["in"];
            token_t AND         = as_lower_d["and"];
            token_t OR          = as_lower_d["or"];
            token_t AS          = as_lower_d["as"];
            token_t IS          = as_lower_d["is"];
            token_t NOT         = as_lower_d["not"]; 
            token_t NULL_       = as_lower_d["null"];  
                  

          //-----------------------------------------
          //	Start grammar definition
          //-----------------------------------------

            identifier =
                nocase_d
                [
                    lexeme_d
                    [
                        (alpha_p >> *(alnum_p | '_'))
                    ]
                ]
            ;

            string_literal =
        lexeme_d
            [
              ch_p('\'') >>  +( anychar_p - ch_p('\'') )
              >> ch_p('\'')
            ]
            ;


 //-----------------------------------------------------------------
 // RULES
 //-----------------------------------------------------------------

 //  Now - the actual BNF grammar for the parser

    program =  +(query) ; 
                     
    query
    = longest_d[ select_from_clause
    | select_from_where_clause ] >> SEMI;
            
    select_from_clause
    =  select_clause >> from_clause ; 
            
    select_from_where_clause 
    =  select_from_clause >> where_clause ; 
                                    
    select_clause 
    = SELECT >> !(DISTINCT) >> ( STAR | var_list_clause ) ;
            
    var_list_clause
    = list_p( varname >> !alias_clause, COMMA ) ;   
            
    from_clause 
    =  FROM >> list_p( table_name >> !alias_clause, COMMA ) ; 
            
    alias_clause 
    = AS >> alias ; 
    
//  Yes, I could have done something like name = identifier (so 
//  saving a couple of lines), but using separate names like varname,
//  table_name, alias hopefully makes things clearer.  ;-)     
    varname = identifier ;
            
    alias = identifier ; 
            
    table_name =  identifier ; 
        
//  Where clause 
   where_clause
  =  WHERE 
  >> list_p( join_clause | compare_clause, AND | OR ) ; 

//  Join clause. OP is an operator (  >, <, = and so on ). 
//  A join clause is like the following - 
//  table1.foo = table2.bar 
//  foo.city = bar.city 
//  foo.var1 > bar.var1
   join_clause 
   =  list_p( table_name >> DOT >> varname , op ); 

//  compare clause. 
//  Examples of compare clauses - 
//  city = 'Sydney' and var1 = 25 ; 
//  name = 'Fred' and dept not in ('Finance' , 'Sales' ) ; 
    compare_clause
  = longest_d[ var_op_clause | var_in_clause | var_null_clause ]; 

//  Examples of var_op_clause - 
//  myvar > 23 ,  city = 'Vancouver' 
    var_op_clause 
  =  varname >> op >> (varname | value) ; 

//  Examples of var_in_clause - 
//  name not in ('Fred' , 'Andy' )
//  dept in ('Sales' , 'Finance' ) 
    var_in_clause 
  = varname >> !(NOT) >> IN_ >> value_list ; 
  
//  Example of var_null_clause - 
//  name is not null   
    var_null_clause
  = varname >> IS >> !(NOT) >> NULL_ ; 
  
    value_list            
  = string_list | number_list ; 
  
    string_list
  = LPAREN >> list_p( string_literal, COMMA ) >> RPAREN ; 
            
    number_list 
  = LPAREN >> list_p( number, COMMA ) >> RPAREN ; 
  
    value 
  = string_literal | number ;    
                                                                                                                                                                                               
    number = uint_p ;  
                    
//  We allow operators to be either the symbol or the letter 
//  (e.g. > or gt ,  <= or le , and so on ).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    op = +( LT | LE | EQUAL | GE | GT | NE 
        | "lt" | "le" | "eq" | "ge" | "gt" | "ne" ) ;      
                                                                                                                                                                                                                                                                              
   }

      rule<ScannerT> const&
        start() const { return program; }
                  
//  Declare the keywords here         
        symbols<> keywords;
        
        rule<ScannerT> 
        program, query, select_from_clause, 
        select_from_where_clause, select_clause, 
        table_name, from_clause, var_list_clause, 
        alias_clause, table_alias, alias, 
        where_clause, join_clause, varname, compare_clause, 
        var_op_clause, var_in_clause, 
        var_null_clause, value, 
        value_list, string_list, number_list,
        number, op, identifier, string_literal ;   
                  
    };
};


int
main(int /*argc*/, char* /*argv[]*/)
{
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "\t\t A toy SQL parser...\n\n";
    cout << "/////////////////////////////////////////////////////////\n\n";
    cout << "Type a SQL expression \n" ; 
    cout << " (e.g.  select * from mytable where city = \'Sydney\' ; ) \n" ;
    cout << " Type [q or Q] to quit\n\n" ;

    toysql_grammar g;

    string str;
    while (getline(cin, str))
    {
        if (str[0] == 'q' || str[0] == 'Q')
            break;

        if (parse(str.c_str(), g, space_p).full)
        {
            cout << "parsing succeeded\n";
        }
        else
        {
            cout << "parsing failed\n";
        }
    }

    cout << "Bye... :-) \n\n";
    return 0;
}



