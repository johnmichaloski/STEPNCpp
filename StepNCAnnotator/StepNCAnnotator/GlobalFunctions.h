//
// GlobalFunctions.h: Schnittstelle für die Klasse CGlobalFunctions.
//


#pragma once
class CGlobalFunctions 
{
public:
	CGlobalFunctions(){}
	virtual ~CGlobalFunctions(){}

public:
	 CString GetFileVersionX();
	 CString GetProductVersionX();
	 CString GetVersionInfo(HMODULE hLib, CString csEntry);
	 CString FormatVersion(CString cs);

private:
	 CString m_csFileVersion;
	 CString m_csProductVersion;

};


inline  CString CGlobalFunctions::GetVersionInfo(HMODULE hLib, CString csEntry)
{
  CString csRet;
  
  HRSRC hVersion = FindResource( hLib, MAKEINTRESOURCE(VS_VERSION_INFO), RT_VERSION );
  if (hVersion != NULL)
  {
    HGLOBAL hGlobal = LoadResource( hLib, hVersion ); 
    if ( hGlobal != NULL)  
    {  
  
      LPVOID versionInfo  = LockResource(hGlobal);  
      if (versionInfo != NULL)
      {
        DWORD vLen,langD;
        BOOL retVal;    
    
        LPVOID retbuf=NULL;
    
        static char fileEntry[256];

        sprintf(fileEntry,"\\VarFileInfo\\Translation");
        retVal = VerQueryValue(versionInfo,fileEntry,&retbuf,(UINT *)&vLen);
        if (retVal && vLen==4) 
        {
          memcpy(&langD,retbuf,4);            
          sprintf(fileEntry, "\\StringFileInfo\\%02X%02X%02X%02X\\%s",
                  (langD & 0xff00)>>8,langD & 0xff,(langD & 0xff000000)>>24, 
                  (langD & 0xff0000)>>16, csEntry);            
        }
        else 
          sprintf(fileEntry, "\\StringFileInfo\\%04X04B0\\%s",  GetUserDefaultLangID(), csEntry);

        if (VerQueryValue(versionInfo,fileEntry,&retbuf,(UINT *)&vLen)) 
          csRet = (char*)retbuf;
      }
    }

    UnlockResource( hGlobal );  
    FreeResource( hGlobal );  
  }

  return csRet;
}

/***********************************************************************************/
/*                                                                                 */
/* Class:   CGlobalFunctions                                                       */
/* Method:  FormatVersion                                                          */
/*                                                                                 */
/* Parameters:                                                                     */
/* -----------                                                                     */
/*   CString cs                                                                    */
/*                Specifies a version number such as "FileVersion" or              */
/*                "ProductVersion" in the format "m, n, o, p"                      */
/*                (e.g. "1, 2, 3, a")                                              */
/*                                                                                 */
/* Return Values:                                                                  */
/* --------------                                                                  */
/* If the function succeeds, the return value is a string containing the version   */
/* in the format "m.nop" (e.g. "1.23a")                                            */ 
/*                                                                                 */
/* If the function fails, the returned string is empty.                            */
/*                                                                                 */
/***********************************************************************************/
inline CString CGlobalFunctions::FormatVersion(CString cs)
{
  CString csRet;
  if (!cs.IsEmpty())
  {
    cs.TrimRight();
    int iPos = cs.Find(',');
    if (iPos == -1)
      return "";
    cs.TrimLeft();
    cs.TrimRight();
    csRet.Format("%s.", cs.Left(iPos));

    while (1)
    {
      cs = cs.Mid(iPos + 1);
      cs.TrimLeft();
      iPos = cs.Find(',');
      if (iPos == -1)
      {
        csRet +=cs;
        break;
      }
      csRet += cs.Left(iPos);
    }
  }

  return csRet;
}

/***********************************************************************************/
/*                                                                                 */
/* Class:   CGlobalFunctions                                                       */
/* Method:  GetFileVersionX                                                        */
/*                                                                                 */
/* Parameters:                                                                     */
/* -----------                                                                     */
/*                                                                                 */
/* Return Values:                                                                  */
/* --------------                                                                  */
/* If the function succeeds, the return value is a string containing the           */
/* "FileVersion" in the format "m.nop" (e.g. "1.23a")                              */ 
/*                                                                                 */
/* If the function fails, the returned string is empty.                            */
/*                                                                                 */
/***********************************************************************************/
inline  CString CGlobalFunctions::GetFileVersionX()
{
  if (m_csFileVersion.IsEmpty())
  {
    CString csVersion = FormatVersion(GetVersionInfo(NULL, "FileVersion"));
    m_csFileVersion.Format("Version %s (Build %s)", csVersion, GetVersionInfo(NULL, "SpecialBuild"));
  }

  return m_csFileVersion;
}

/***********************************************************************************/
/*                                                                                 */
/* Class:   CGlobalFunctions                                                       */
/* Method:  GetFileVersionX                                                        */
/*                                                                                 */
/* Parameters:                                                                     */
/* -----------                                                                     */
/*                                                                                 */
/* Return Values:                                                                  */
/* --------------                                                                  */
/* If the function succeeds, the return value is a string containing the           */
/* "ProductVersion" in the format "m.nop" (e.g. "1.23a")                           */ 
/*                                                                                 */
/* If the function fails, the returned string is empty.                            */
/*                                                                                 */
/***********************************************************************************/
inline CString CGlobalFunctions::GetProductVersionX()
{
  if (m_csProductVersion.IsEmpty())
    m_csProductVersion = FormatVersion(GetVersionInfo(NULL, "ProductVersion"));

  return m_csProductVersion;
}