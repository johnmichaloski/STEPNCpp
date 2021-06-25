/**
\class  CExpQueryParser
SPath is the StepPath language that provides the ability to navigate around a Step Instance tree, selecting step nodes by a variety of criteria.
SPath approximates a small subset of XPath, the XML Expression Path language. 
In SPath Step Nodes are the equivalent to Express Schema class instances. Each Step Node can have several variables or attributes.
Each attribute is described by the IAttribute interface and implemented by CVarDef.  

SPath consists of  a location path that can be refined by a set of filters. SPath only supports a small set of filters at this time.
A location path selects a set of Step Nodes relative to the context node. As an example 
/feature_placement/location/coordinates
traverses the tree from the current Step node down the attribute/node first feature_placement, then location and finally
coordinates.

The result of evaluating an expression that is a location path is the node-set containing the nodes selected by the location path.
There are two kinds of location path: relative location paths and absolute location paths.
Some difference between SPath and XPath, include the need for SPath to be able to create node elements based on an inheritance hierarchy 


The SPATH grammar uses  Basic EBNF notation. Non-terminals:
\code
SPath					::=	PathExpr

INDEX					::=  -2 | -1 | [0..9]+
EXPRESSVAR				::=  (a-zA-z)(a-zA-z0-9_)*
ClassSeq				::= "{" EXPRESSCLASS  "}"
IndexSeq				::= "[" INDEX  "]"
RelativePathExpr		::= "/" EXPRESSVAR [IndexSeq] [ClassSeq]
							|  "//" RelativePathExpr [IndexSeq] [ClassSeq]
PathExpr				::= [ RelativePathExpr ]+ 

\ebndcode
*/

/** 
\fn CExpQueryParser::CExpQueryParser(CString attrname=L"")
@param[in] attrname
*/

/** 
\fn int CExpQueryParser::size() { return _attrs.size(); }
*/

/** 
\fn static void CExpQueryParser::Prune(CString & attr)
@param[in] attr
*/

/** 
\fn static void ParentChild(CString attrname, CString &parent, CString &child)
Splits a spath into a parent/child pair. The parent is equivalent to a root in a file path,
all the elements leading up to the filename. The child is equivalent to the filename. 
@par Example
\code
attrname = its_bounding_geometry/_Eblock/position/ref_direction/direction_ratios
parent   = its_bounding_geometry/_Eblock/position/ref_direction
child = direction_ratios
\endcode
For cases where there is no root path, the parent is returned as an empty string.

attrname = direction_ratios
parent   = ""
child = direction_ratios
@param[in] attrname - spath describing an attribute
@param[out] parent
@param[out] child
*/

/** 
\fn static void CExpQueryParser::Parse(CString & attr)
Parses an spath into its constituent components:
_qualifiers, and _attrs. 

First the parse strips the attr into its constittuent _attrs, that is,
items between each slash, i.e., "/.../". Then each attribute is parsed 
for potential attribute qualifiers: classnames and index.

_qualifiers contain an index  into a list(if any)
as well as a definining classname, enclosed by {}, if any.
@param[in] attr spath describing a step branch.
*/
/** 
\fn static int &  CExpQueryParser::Index(int i)
Return index for the ith attribute. -2 if none.
-1 means add index. >=0 is list index.
Note i must exist, or std::exception thrown.
@param[in] i index into attribute list.
*/
/** 
\fn static CString &  CExpQueryParser::Classname(int i)
Return classname for the ith attribute. Empty string if none.
Note i must exist, or std::exception thrown.
@param[in] i index into attribute list.
*/


/**
\class CExpQueryAttributes
SPath qualifies for each 
*/
/** \var int CExpQueryAttributes::index
Potential list index for the ith attribute. Values:
-2 if none,
-1 means add index, and  >=0 is list index.
*/

/**
\class CExpQueryAttributes
SPath qualifies for each 
*/

/** \var CString CExpQueryAttributes::indexqualifier
TBD.
*/

/** \var CString CExpQueryAttributes::classname
Classname for ith attribute. Empty if none. 
*/
