// dllmain.h : Declaration of module class.

class CNiStepModule : public CAtlDllModuleT< CNiStepModule >
{
public :
	DECLARE_LIBID(LIBID_NiStepLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_NISTEP, "{A89FC0C1-229B-4CAA-845F-74AA05DBE9F2}")
};

extern class CNiStepModule _AtlModule;
