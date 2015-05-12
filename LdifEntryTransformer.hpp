// LdifEntryTransformer.hpp: interface for the CLdifEntryTransformer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LDIFENTRYTRANSFORMER_HPP__8F29AE16_AA43_441C_ABF9_2D0AF1BA4B12__INCLUDED_)
#define AFX_LDIFENTRYTRANSFORMER_HPP__8F29AE16_AA43_441C_ABF9_2D0AF1BA4B12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NDIRXML_EXPORTS
#define NDIRXML_API __declspec(dllexport)
#else
#define NDIRXML_API __declspec(dllimport)
#endif

class CLdifEntryTransformer  
{
public:
	NDIRXML_API CLdifEntryTransformer();
	virtual ~CLdifEntryTransformer();

	// Get/Set m_name
	NDIRXML_API _TCHAR const * GetName();
	NDIRXML_API void SetName(const _TCHAR *name);

	// Get/Set m_placeholder
	NDIRXML_API _TCHAR const * GetPlaceholder();
	NDIRXML_API void SetPlaceholder(const _TCHAR *placeholder);

	// Get/Set m_resolveDocField
	NDIRXML_API _TCHAR const * GetResolveDocField();
	NDIRXML_API void SetResolveDocField(const _TCHAR *resolveDocField);

	// Get/Set m_resolveDocForm
	NDIRXML_API _TCHAR const * GetResolveDocForm();
	NDIRXML_API void SetResolveDocForm(const _TCHAR *resolveDocForm);

	// Get/Set m_resolveDocFormAlt
	NDIRXML_API _TCHAR const * GetResolveDocFormAlt();
	NDIRXML_API void SetResolveDocFormAlt(const _TCHAR *resolveDocFormAlt);

	// Get/Set m_resolveDocLookupField
	NDIRXML_API _TCHAR const * GetResolveDocLookupField();
	NDIRXML_API void SetResolveDocLookupField(const _TCHAR *resolveDocLookupField);

	// Get/Set m_resolveDocLookupFieldAlt
	NDIRXML_API _TCHAR const * GetResolveDocLookupFieldAlt();
	NDIRXML_API void SetResolveDocLookupFieldAlt(const _TCHAR *resolveDocLookupFieldAlt);

	// Get/Set m_pstItemProperty
	NDIRXML_API bool const GetPstItemProperty();
	NDIRXML_API void SetPstItemProperty(const bool m_pstItemProperty);

	// Get/Set m_multivalue
	NDIRXML_API bool const GetMultivalue();
	NDIRXML_API void SetMultivalue(const bool multivalue);

	// Get/Set m_onlyFirstValue
	NDIRXML_API bool const GetOnlyFirstValue();
	NDIRXML_API void SetOnlyFirstValue(const bool onlyFirstValue);

	// Get/Set m_multivalueSeparator
	NDIRXML_API _TCHAR const * GetMultivalueSeparator();
	NDIRXML_API void SetMultivalueSeparator(const _TCHAR *multivalueSeparator);

	// Get/Set m_orgHierarchy
	NDIRXML_API bool const GetOrgHierarchy();
	NDIRXML_API void SetOrgHierarchy(const bool orgHierarchy);

	// Get/Set m_extractCN
	NDIRXML_API bool const GetExtractCN();
	NDIRXML_API void SetExtractCN(const bool extractCN);

	// Get/Set m_dateMask
	NDIRXML_API _TCHAR const * GetDateMask();
	NDIRXML_API void SetDateMask(const _TCHAR *dateMask);

	// Get/Set m_valueModifier
	NDIRXML_API _TCHAR const * GetValueModifier();
	NDIRXML_API void SetValueModifier(const _TCHAR *valueModifier);

	// Get/Set m_blankIfAbsent
	NDIRXML_API bool IsBlankIfAbsent();
	NDIRXML_API void SetBlankIfAbsent(bool wrap);

	// Get/Set m_namedProperty
	NDIRXML_API bool IsNamedProperty();
	NDIRXML_API void SetNamedProperty(bool namedProperty);

protected:
	bool m_pstItemProperty;
	_TCHAR m_name[128];
	_TCHAR m_placeholder[256];
	_TCHAR m_resolveDocField[128];
	_TCHAR m_resolveDocForm[128];
	_TCHAR m_resolveDocFormAlt[128];
	_TCHAR m_resolveDocLookupField[128];
	_TCHAR m_resolveDocLookupFieldAlt[128];
	bool m_multivalue;
	bool m_onlyFirstValue;
	_TCHAR m_multivalueSeparator[64];
	bool m_orgHierarchy;
	bool m_extractCN;
	_TCHAR m_dateMask[64];
	_TCHAR m_valueModifier[64];
	bool m_blankIfAbsent;
	bool m_namedProperty;

};

#endif // !defined(AFX_LDIFENTRYTRANSFORMER_HPP__8F29AE16_AA43_441C_ABF9_2D0AF1BA4B12__INCLUDED_)
