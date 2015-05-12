// Notes2PSTApp.hpp: interface for the CPST2LDIFApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PST2LDIFAPP_HPP__DF6D88D6_63BA_4734_8960_CA9DC7327262__INCLUDED_)
#define AFX_PST2LDIFAPP_HPP__DF6D88D6_63BA_4734_8960_CA9DC7327262__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPSTProc;
class CXMLDirProc;
class CLdifEntry;
class CLdifEntryFilter;
class CLdifEntryTransformer;
class CSmtpAddr;
class CPersonGroupEntry;

#define DEFAULT_CONFIG_FILE	_T("pst2ldif.xml")
#define DEFAULT_SCHEMA_FILE	_T("pst2ldif.xsd")

#define DEFAULT_SCHEMA_PREFIX		_T("http://www.gssnet.com/pst2ldif")
#define DEFAULT_PST_EXT _T(".pst")

class CPST2LDIFApp  
{
public:
	CPST2LDIFApp();
	virtual ~CPST2LDIFApp();

	void ShowUsage();
	_TCHAR *PrefixWithCurDir(_TCHAR *fileName, _TCHAR *fileNameFull);
	int ProcessCommandLine(int argc, _TCHAR *argv[]);
	int StartMigration(_TCHAR* exec);

	CLdifEntry* getNextLdifPersonEntry();
	CLdifEntry* getNextLdifGroupEntry();
	CLdifEntryFilter* getNextLdifEntryFilter(bool person);
	int getCurrentLdifEntryFilterIndex();
	void setCurrentLdifEntryFilterIndex(int index);
	void resetEntryFilterIndex();
	void resetEntryListIndex();
	void resetTransformerListIndex();
	CLdifEntryTransformer* getNextLdifEntryTransformer();
	CLdifEntryTransformer* getNextSMTPEntryTransformer();
	const _TCHAR* getConfigSettingValue(const _TCHAR* settingName);
	void insertLdifEntry(const _TCHAR *attribute, const _TCHAR *value);
	CSmtpAddr* getSmtpAddrInfo();
	bool matchesRegExp(char *regExpPattern, char* matchString);
	CPersonGroupEntry *getPersonGroupEntry(bool isPerson);

protected:
	CPSTProc *m_pstProc;
	CXMLDirProc *m_xmlProc;
	bool m_verbose;
	bool m_printFormsOnly;

public:

	int IsVerbose() {
		return m_verbose == true;
	}

private:
	int ExtractSchemaFile(_TCHAR* tempDir);
};

#endif // !defined(AFX_PST2LDIFAPP_HPP__DF6D88D6_63BA_4734_8960_CA9DC7327262__INCLUDED_)
