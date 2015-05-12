// NotesProc.h: interface for the CPSTProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSTPROC_H__8CD32256_505C_4973_9A04_DBC9BF1C4FA2__INCLUDED_)
#define AFX_PSTPROC_H__8CD32256_505C_4973_9A04_DBC9BF1C4FA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define DATEMASK_DWK_ALL			_T("DWK, DD MMM YYYY HH:MI:SS TZHH")
#define DATEMASK_DWK2				_T("DWK MMM DD HH:MI:SS YYYY")
#define DATEMASK_YYYYMMDDHHMI		_T("YYYYMMDDHHMI")
#define DATEMASK_YYYYMMDDHHMISS		_T("YYYYMMDDHHMISS")
#define DATEMASK_YYYYMMDDTHHMISSZ	_T("YYYYMMDDTHHMISSZ")

#define MODIFIER_UID				_T("uid")
#define MODIFIER_SMTPLOOKUP			_T("smtpLookup")

#define PSTMASK _T("*.pst")
#define PST_DEFAULT_SUFFIX _T(".pst")
#define LDIF_DEFAULT_SUFFIX _T(".ldif")

#define BUFFER_SIZE 8192
#define ENTRY_LEN 256

DEFINE_OLEGUID(PSETID_Address, MAKELONG(0x2000+(0x04),0x0006),0,0);

#define PidLidDistributionListOneOffMembers			0x8054
#define PidLidDistributionListMembers				0x8055

typedef struct {
	ULONG pID;
	ULONG pType;
	LPGUID pGuid;
	_TCHAR *pName;
} NamedProperty;

class CPST2LDIFApp;
class CObjectArray;
class CMessageItem;
class CList;

class CPSTProc  
{
public:
	CPSTProc();
	virtual ~CPSTProc();

	int Start(_TCHAR* exec, CPST2LDIFApp *theApp);
	int PerformMigration(char *dbFullPath);
	int PerformMigrationLocal(_TCHAR *inputDir);
	int PerformOneMailboxMigration(LPMAPISESSION pses, LPMDB pmdb, const _TCHAR *pstFile, const _TCHAR *outputdir, 
		UINT *totalFiles = NULL, UINT *totalFilesError = NULL);
	HRESULT ProcessOneFolder(LPMDB pmdb, 
		LPMAPIFOLDER pf, _TCHAR *output_dir, _TCHAR *icsFile,
		UINT *totalFolderMsgs, UINT *totalFolderMsgsDone, 
		UINT *totalFolderMsgsSkipped, UINT *totalFolderMsgsError);
	HRESULT ProcessOneContactDoc(LPMESSAGE lpMsg, FILE *f);
	HRESULT ApplyTransformers(LPMESSAGE lpMsg,  const _TCHAR *name, 
		const _TCHAR *value, FILE *outputFile);

	void parseSMTPFile(const _TCHAR *smtpAddrFile, const _TCHAR *smtpPartsSep);
	void DoSmtpLookup(_TCHAR *field_text, WORD *field_len);


protected:
	bool m_verbose;
	_TCHAR m_language[3];
	_TCHAR m_server[256];
	_TCHAR m_basedn[512];
	_TCHAR m_filter[256];
	_TCHAR m_container[512];
	_TCHAR m_groupcontainer[512];
	_TCHAR m_pstfilePassword[128];
	_TCHAR m_inputdir[512];
	_TCHAR m_logFile[512];
	unsigned int m_logSizeWrap;
	_TCHAR m_outputdir[512];
	_TCHAR m_onlyPSTFile[512];
	_TCHAR m_smtpAddrFile[256];
	_TCHAR m_smtpPartsSep[32];
	bool m_appendLogFile;

	CPST2LDIFApp *theParentApp;

	CList *listSuppl;
	CList *smtpAdr;

public:
	// Get/Set m_language
	_TCHAR const * GetLanguage();
	void SetLanguage(const _TCHAR *language);

	// Get/Set m_server
	_TCHAR const * GetServer();
	void SetServer(const _TCHAR *server);

	// Get/Set m_filter
	_TCHAR const * GetFilter();
	void SetFilter(const _TCHAR *filter);

	// Get/Set m_container
	_TCHAR const * GetContainer();
	void SetContainer(const _TCHAR *container);

	// Get/Set m_groupcontainer
	_TCHAR const * GetGroupContainer();
	void SetGroupContainer(const _TCHAR *groupcontainer);

	// Get/Set m_idfilePassword
	_TCHAR const * GetPSTFilePassword();
	void SetPSTFilePassword(const _TCHAR *idFilePassword);

	// Get/Set m_inputdir
	_TCHAR const * GetInputDir();
	void SetInputDir(const _TCHAR *inputDir);

	// Get/Set m_logFile
	_TCHAR const * GetLogFile();
	void SetLogFile(const _TCHAR *logFile);

	// Get/Set m_logSizeWrap
	unsigned int GetLogSizeWrap();
	void SetLogSizeWrap(unsigned int logSizeWrap);

	// Get/Set m_outputdir
	_TCHAR const * GetOutputDir();
	void SetOutputDir(const _TCHAR *outputDir);

	// Get/Set m_onlyNSFFile
	_TCHAR const * GetOnlyPSTFile();
	void SetOnlyPSTFile(const _TCHAR *onlyNSFFile);

	// Get/Set m_smtpAddrFile
	_TCHAR const * GetSmtpAddrFile();
	void SetSmtpAddrFile(const _TCHAR *smtpAddrFile);

	// Get/Set m_smtpPartsSep
	_TCHAR const * GetSmtpPartsSep();
	void SetSmtpPartsSep(const _TCHAR *smtpPartsSep);

	// Get/Set m_verbose
	bool const GetVerbose();
	void SetVerbose(const bool verbose);

	// Get/Set m_appendLogFile
	bool const GetAppendLogFile();
	void SetAppendLogFile(const bool appendLogFile);

	int CreateOutlookFile(_TCHAR *targetdir, const _TCHAR *name, int how, bool splitName = TRUE, _TCHAR *nsfFile = NULL);

private:
	void GetPSTMask(_TCHAR *pstmask);
	ULONG GetXMLPropTagValue(const _TCHAR *propTag);
	bool IsIgnoredFolder(_TCHAR *ignoredFolders, _TCHAR *folderName);
	bool IsIgnoredMessageForm(_TCHAR *messageForms, char *messageFormCh);
//	STATUS RetrieveFirstLastDomainFromSent(HANDLE hMessageFile, _TCHAR *firstLast);
	void SetRecipient(CMessageItem *item, LPMESSAGE lpMessage, char *field_text, char *email, LPSPropValue pMessagePropValues, UINT *c);
	int GetNamedPropertyIdx(ULONG namedProperty);

};

#endif // !defined(AFX_PSTPROC_H__8CD32256_505C_4973_9A04_DBC9BF1C4FA2__INCLUDED_)
