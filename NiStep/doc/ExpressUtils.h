//
// ExpressUtils.h documentation
//

/**
\class EListT
EListT is the 1D list class for the STEP Nodes. 
It takes a template <class T> declaration argument and is assumed to be of type IStepNodePtr.
EListT itself is of type IStepNode so that it can treated like an IStepNodePtr, however, 
a reference to the EListT is passed around and not a pointer. Because of this EListT reference must
always be greater than one because they cannot be deleted since they are not allocated on the heap.
*/

/** \fn std::vector<CVarDefPtr> & template<class T> EListT< T >::GetVarDefs() 
Returns the attribute variables  for this list. The variable list contains 
a Variable definition (of type index_) for each IStepNodePtr in the actual list.
*/

/** \fn bool template<class T> EListT< T >::IsASimpleListType(CString classname=L"") 
Determines if the given list or classname parameter is a simple list type (e.g. real, integer, enumeration,
logical, boolean.)
@return true if theis list or the given classname are of a simple simple type.
@param[in] classname optional classname for testing.
*/


/** \fn void template<class T> EListT< T >::clear() 
Clears the list of Step Node pointers and corresponding attributes variables.
*/
/** \fn int template<class T> EListT< T >::size()
@return Returns the size of the list of Step Node pointers.
*/
/** \fn void template<class T> EListT< T >::Swap(int n1, int n2)
Swaps two members of the list. Both index must be valid or nothing is done. No error message.
@param[in] n1 index one into the list.
@param[in] n2 index two into the list.
*/


/** \fn HRESULT template<class T> EListT< T >::Store(int i, IStepNodePtr val)
Stores a StepNode into the list at the given index position. List size does not change.
@return Returns S_OK if store was successful.
Return E_INVALIDARG if index i is out of range.
@param[in] i index of list position in which to store item..
*/

/** \fn void template<class T> EListT< T >::push_back(T t, CString varname)
Stores a StepNode  class of derived type T at the back of the list. List size does not change.
Adds a new element to the end of the list, after its current last element. 
The content of this new element is initialized to the pointer t.

This increases the list size by one. 

@param[in] t pointer to IStepNode derived class T.
@param[in] i index of list position in which to store item.
*/

/** \fn int template<class T> EListT< T >::GetIndex(CVarDefPtr vardef)
Searches the list attribute variables for a match to the given index_ attribute variable. 
The index_ attribute variable describes the index position within the list, which can be used to look
up the corresponding StepNodePtr T.

Returns -1 if the item could not be found.

@param[in] vardef pointer to index_ attribute variable definition.
*/

/** \fn HRESULT template<class T> EListT< T >::DeleteChild(IStepNode * step)
Deletes the first instance of the StepNode in the list. 
@return Returns S_OK if delete was successful.
Return E_FAIL if step node could not be found.
@param[in] step pointer to IStepNode derived class T item to delete.
*/	 

/** \fn Iterator template<class T> EListT< T >::erase(int i)
Deletes the StepNode item at the index position in the list. 
@return Returns S_OK if delete was successful.
Return E_FAIL if step node could not be found.
@param[in] i index of list position in which to delete item..
*/	 

/** \fn CString template<class T> EListT< T >::GetVarString(CString separator=_T(""))
If the list is a list of simple types (int, real, string, booleans, logical, enumerations), 
@return returns a delimted string representation of the list.   
@param[in] separator to include between list items.
*/	 

/** \fn CString template<class T> EListT< T >::SetVarString(CString str)
If the list is a list of simple types (int, real, string, booleans, logical, enumerations), 
parses the string (optional ()) and uses commas to delimit the entries.   
@param[in] str to parse for list items.
*/

/** \fn void template<class T> EListT< T >::Init(CString classname, StepNodeType eListType )
Initializes the Step Node with list specific arguments.
parses the string (optional ()) and uses commas to delimit the entries.   
@param[in] classname string name of the list elements.
@param[in] eListType enumerated type of the list elements.
*/

/** \fn IStepNodePtr template<class T> EListT< T >::InsertItem(Iterator it)
Inserts a new Step Node item into the list of the given list element type at the given
list iterator position. Saves the list item in the variable list if not simple list item.
@return pointer to the new StepNode that was inserted into the list at list position it. Returns NULL
if the step node could not be created.
@param[in] it iterator into the list elements.
*/


/** \fn void CloneCVarDefs(CVarDefs &fromvars, CVarDefs &tovars, int bFirst=false)
\relates CVarDef
Does a deep copy of the given attribute variables list into the  tovars attribute variable list.
@param[in] fromvars  list of attribute variables from which the copy is made.
@param[in] tovars attribute variables into which the copy is made.
*/

/** \fn void CloneCVarDef(CVarDefPtr fromvardef, CVarDefPtr  tovardef)
\relates CVarDef
Does a deep copy of the the given fromvardef into the tovardef attribute variable.
@param[in] fromvardef attribute variable from which to copy all the items below it.
@param[in] tovardef attribute variable into which the copy is made.
*/ 
