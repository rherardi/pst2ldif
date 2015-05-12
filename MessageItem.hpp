// MessageItem.hpp: interface for the CMessageItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MESSAGEITEM_HPP__EC66FE86_817C_4257_84C8_5D4905E2CCBE__INCLUDED_)
#define AFX_MESSAGEITEM_HPP__EC66FE86_817C_4257_84C8_5D4905E2CCBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NMAILXML_EXPORTS
#define NMAILXML_API __declspec(dllexport)
#else
#define NMAILXML_API __declspec(dllimport)
#endif

class CMessageItem  
{
public:
	CMessageItem();
	virtual ~CMessageItem();

	// Get/Set m_attribute
	NMAILXML_API _TCHAR const * GetName();
	NMAILXML_API void SetName(const _TCHAR *name);

	// Get/Set m_value
	NMAILXML_API _TCHAR const * GetValue();
	NMAILXML_API void SetValue(const _TCHAR *value);

	// Get/Set m_value
	NMAILXML_API long const GetValueNumeric();
	NMAILXML_API void SetValueNumeric(const long value);

	// Get/Set m_numeric
	NMAILXML_API bool const IsNumeric();
	NMAILXML_API void SetNumeric(const bool value);

	// Get/Set m_condition
	NMAILXML_API _TCHAR const * GetCondition();
	NMAILXML_API void SetCondition(const _TCHAR *value);

protected:
	_TCHAR m_name[128];
	_TCHAR m_value[512];
	long m_valuenum;
	bool m_numeric;
	_TCHAR m_condition[128];

};

#endif // !defined(AFX_MESSAGEITEM_HPP__EC66FE86_817C_4257_84C8_5D4905E2CCBE__INCLUDED_)
