// LdifEntry.hpp: interface for the CLdifEntry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LDIFENTRY_HPP__41376355_4939_4C5A_B1E9_8B91C7484DCE__INCLUDED_)
#define AFX_LDIFENTRY_HPP__41376355_4939_4C5A_B1E9_8B91C7484DCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NDIRXML_EXPORTS
#define NDIRXML_API __declspec(dllexport)
#else
#define NDIRXML_API __declspec(dllimport)
#endif

class CLdifEntry  
{
public:
	NDIRXML_API CLdifEntry();
	virtual ~CLdifEntry();

	// Get/Set m_attribute
	NDIRXML_API _TCHAR const * GetAttribute();
	NDIRXML_API void SetAttribute(const _TCHAR *attribute);

	// Get/Set m_value
	NDIRXML_API _TCHAR const * GetValue();
	NDIRXML_API void SetValue(const _TCHAR *value);

protected:
	_TCHAR m_attribute[128];
	_TCHAR m_value[512];
};

#endif // !defined(AFX_LDIFENTRY_HPP__41376355_4939_4C5A_B1E9_8B91C7484DCE__INCLUDED_)
