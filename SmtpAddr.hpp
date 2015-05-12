// SmtpAddr.hpp: interface for the CSmtpAddr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMTPADDR_HPP__DCF74D65_96F6_4D16_90E2_24AF796EA0EF__INCLUDED_)
#define AFX_SMTPADDR_HPP__DCF74D65_96F6_4D16_90E2_24AF796EA0EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NDIRXML_EXPORTS
#define NDIRXML_API __declspec(dllexport)
#else
#define NDIRXML_API __declspec(dllimport)
#endif

#define ADDRESS_CONVERSION_FF_LL	_T("FirstName, LastName")
#define ADDRESS_CONVERSION_F_LL		_T("(F)irstName, LastName")
#define ADDRESS_CONVERSION_LL_F		_T("LastName, (F)irstName")

class CSmtpAddr  
{
public:
	NDIRXML_API CSmtpAddr();
	virtual ~CSmtpAddr();

	// Get/Set m_file
	NDIRXML_API _TCHAR const * GetFile();
	NDIRXML_API void SetFile(const _TCHAR *file);

	// Get/Set m_lotusPart
	NDIRXML_API _TCHAR const * GetLotusPart();
	NDIRXML_API void SetLotusPart(const _TCHAR *lotusPart);

	// Get/Set m_emailPart
	NDIRXML_API _TCHAR const * GetEmailPart();
	NDIRXML_API void SetEmailPart(const _TCHAR *emailPart);

	// Get/Set m_emailSeparator
	NDIRXML_API _TCHAR const * GetEmailSeparator();
	NDIRXML_API void SetEmailSeparator(const _TCHAR *emailSeparator);

	// Get/Set m_emailPreference
	NDIRXML_API _TCHAR const * GetEmailPreference();
	NDIRXML_API void SetEmailPreference(const _TCHAR *emailPreference);

	// Get/Set m_partsSeparator
	NDIRXML_API _TCHAR const * GetPartsSeparator();
	NDIRXML_API void SetPartsSeparator(const _TCHAR *partsSeparator);

protected:
	_TCHAR m_file[256];
	_TCHAR m_lotusPart[256];
	_TCHAR m_emailPart[128];
	_TCHAR m_emailSeparator[32];
	_TCHAR m_emailPreference[128];
	_TCHAR m_partsSeparator[128];
};

#endif // !defined(AFX_SMTPADDR_HPP__DCF74D65_96F6_4D16_90E2_24AF796EA0EF__INCLUDED_)
