// LdifEntryFilter.hpp: interface for the CLdifEntryFilter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LDIFENTRYFILTER_HPP__E41A7515_18ED_46D1_B8CE_CEAE242DF35E__INCLUDED_)
#define AFX_LDIFENTRYFILTER_HPP__E41A7515_18ED_46D1_B8CE_CEAE242DF35E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NDIRXML_EXPORTS
#define NDIRXML_API __declspec(dllexport)
#else
#define NDIRXML_API __declspec(dllimport)
#endif

#define XMLATTRIBUTE_FILTER_FIELD		_T("lotusDocField")
#define XMLATTRIBUTE_FILTER_CONDITION	_T("condition")
#define XMLATTRIBUTE_FILTER_COMBINE		_T("combine")
#define XMLATTRIBUTE_FILTER_BRACKET		_T("bracket")

#define XMLFILTER_CONDITION_EQUAL		_T("EQUAL")
#define XMLFILTER_CONDITION_NOT_EQUAL	_T("NOT EQUAL")
#define XMLFILTER_CONDITION_ONLY_USERS	_T("ONLY USERS")
#define XMLFILTER_CONDITION_SKIP		_T("SKIP")

#define XMLFILTER_COMBINE_OR			_T("OR")
#define XMLFILTER_COMBINE_AND			_T("AND")

#define XMLFILTER_BRACKET_OPEN			_T("(")
#define XMLFILTER_BRACKET_CLOSE			_T(")")

class CLdifEntryFilter  
{
public:
	CLdifEntryFilter();
	virtual ~CLdifEntryFilter();

	// Get/Set m_pstItemProperty
	NDIRXML_API _TCHAR const * GetPstItemProperty();
	NDIRXML_API void SetPstItemProperty(const _TCHAR *pstItemProperty);

	// Get/Set m_value
	NDIRXML_API _TCHAR const * GetValue();
	NDIRXML_API void SetValue(const _TCHAR *value);

	// Get/Set m_condition
	NDIRXML_API _TCHAR const * GetCondition();
	NDIRXML_API void SetCondition(const _TCHAR *condition);

	// Get/Set m_combine
	NDIRXML_API _TCHAR const * GetCombine();
	NDIRXML_API void SetCombine(const _TCHAR *combine);

	// Get/Set m_bracket
	NDIRXML_API _TCHAR const * GetBracket();
	NDIRXML_API void SetBracket(const _TCHAR *bracket);

protected:
	_TCHAR m_pstItemProperty[128];
	_TCHAR m_value[1024];
	_TCHAR m_condition[32];
	_TCHAR m_combine[16];
	_TCHAR m_bracket[16];

};

#endif // !defined(AFX_LDIFENTRYFILTER_HPP__E41A7515_18ED_46D1_B8CE_CEAE242DF35E__INCLUDED_)
