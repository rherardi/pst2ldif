// XMLDirProc.hpp: interface for the CXMLDirProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLDIRPROC_HPP__68F491DE_7D9C_48F9_AD3D_6436F0EA7E7F__INCLUDED_)
#define AFX_XMLDIRPROC_HPP__68F491DE_7D9C_48F9_AD3D_6436F0EA7E7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NDIRXML_EXPORTS
#define NDIRXML_API __declspec(dllexport)
#else
#define NDIRXML_API __declspec(dllimport)
#endif

#define LDIF_PERSON_SELECTOR		_T("//ldifPersonEntry/ldifEntry")
#define LDIF_PERSON_FILTER_SELECTOR	_T("//ldifPersonEntry/ldifEntryFilter")
#define LDIF_GROUP_SELECTOR			_T("//ldifGroupEntry/ldifEntry")
#define LDIF_GROUP_FILTER_SELECTOR	_T("//ldifGroupEntry/ldifEntryFilter")
#define LDIF_PERSON_MAIN_SELECTOR	_T("//ldifPersonEntry")
#define LDIF_GROUP_MAIN_SELECTOR	_T("//ldifGroupEntry")
#define LDIF_TRANSFORMER_SELECTOR 	_T("child::*")
#define XMLATTRIBUTE_ATTRIBUTE		_T("attribute")
#define XMLATTRIBUTE_MULTIVALUE		_T("multivalue")
#define XMLATTRIBUTE_ONLYFIRSTVALUE	_T("onlyFirstValue")
#define XMLATTRIBUTE_MULTIVALUE_SEPARATOR		_T("multivalueSeparator")
#define XMLATTRIBUTE_ORG_HIERARCHY	_T("orgHierarchy")
#define XMLATTRIBUTE_EXTRACT_CN		_T("extractCN")
#define XMLATTRIBUTE_RESOLVE_DOC_FIELD	_T("resolveDocField")
#define XMLATTRIBUTE_RESOLVE_DOC_VIEW	_T("resolveDocView")
#define XMLATTRIBUTE_RESOLVE_DOC_FORM	_T("resolveDocForm")
#define XMLATTRIBUTE_RESOLVE_DOC_FORM_ALT	_T("resolveDocFormAlt")
#define XMLATTRIBUTE_RESOLVE_DOC_LOOKUP_FIELD	_T("resolveDocLookupField")
#define XMLATTRIBUTE_RESOLVE_DOC_LOOKUP_FIELD_ALT	_T("resolveDocLookupFieldAlt")
#define XMLATTRIBUTE_EXTRACTCN			_T("extractCN")

#define SMTP_ADDR_SELECTOR			_T("//smtpAddrEntry")

class CLdifEntry;
class CLdifEntryFilter;
class CLdifEntryTransformer;
class CPersonGroupEntry;

class CXMLDirProc : public CXMLProc   
{
public:
	NDIRXML_API CXMLDirProc();
	virtual ~CXMLDirProc();

	NDIRXML_API CLdifEntry* getNextLdifPersonEntry();
	NDIRXML_API CLdifEntry* getNextLdifGroupEntry();
	NDIRXML_API void getEntryFilterList(_TCHAR* selector);
	NDIRXML_API CLdifEntryFilter* getNextLdifEntryFilter(bool person = true);
	NDIRXML_API void resetEntryFilterIndex();
	NDIRXML_API void resetEntryListIndex();
	NDIRXML_API void resetTransformerListIndex();
	NDIRXML_API int getCurrentLdifEntryFilterIndex();
	NDIRXML_API void setCurrentLdifEntryFilterIndex(int index);
	NDIRXML_API CLdifEntryTransformer* getNextLdifEntryTransformer();
	NDIRXML_API CLdifEntryTransformer* getNextSMTPEntryTransformer();
	NDIRXML_API void insertLdifEntry(const _TCHAR *attribute, const _TCHAR *value);
	NDIRXML_API CSmtpAddr* getSmtpAddrInfo();
	NDIRXML_API CPersonGroupEntry* getPersonGroupEntry(bool isPerson);
};

#endif // !defined(AFX_XMLDIRPROC_HPP__68F491DE_7D9C_48F9_AD3D_6436F0EA7E7F__INCLUDED_)
