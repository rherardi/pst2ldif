// SmtpAddr.cpp: implementation of the CSmtpAddr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SmtpAddr.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSmtpAddr::CSmtpAddr()
{
	m_file[0] = _T('\0');
	m_lotusPart[0] = _T('\0');
	m_emailPart[0] = _T('\0');
	m_emailSeparator[0] = _T('\0');
	m_emailPreference[0] = _T('\0');
	m_partsSeparator[0] = _T('\0');
}

CSmtpAddr::~CSmtpAddr()
{

}

// Get/Set m_file
_TCHAR const * CSmtpAddr::GetFile()
{
	return &m_file[0];
}
void CSmtpAddr::SetFile(const _TCHAR *file)
{
	if (file != NULL) {
		::_tcscpy(m_file, file);
	}
}

// Get/Set m_lotusPart
_TCHAR const * CSmtpAddr::GetLotusPart()
{
	return &m_lotusPart[0];
}
void CSmtpAddr::SetLotusPart(const _TCHAR *lotusPart)
{
	if (lotusPart != NULL) {
		::_tcscpy(m_lotusPart, lotusPart);
	}
}

// Get/Set m_emailPart
_TCHAR const * CSmtpAddr::GetEmailPart()
{
	return &m_emailPart[0];
}
void CSmtpAddr::SetEmailPart(const _TCHAR *emailPart)
{
	if (emailPart != NULL) {
		::_tcscpy(m_emailPart, emailPart);
	}
}

// Get/Set m_emailSeparator
_TCHAR const * CSmtpAddr::GetEmailSeparator()
{
	return &m_emailSeparator[0];
}
void CSmtpAddr::SetEmailSeparator(const _TCHAR *emailSeparator)
{
	if (emailSeparator != NULL) {
		::_tcscpy(m_emailSeparator, emailSeparator);
	}
}

// Get/Set m_emailPreference
_TCHAR const * CSmtpAddr::GetEmailPreference()
{
	return &m_emailPreference[0];
}
void CSmtpAddr::SetEmailPreference(const _TCHAR *emailPreference)
{
	if (emailPreference != NULL) {
		::_tcscpy(m_emailPreference, emailPreference);
	}
}

// Get/Set m_partsSeparator
_TCHAR const * CSmtpAddr::GetPartsSeparator()
{
	return &m_partsSeparator[0];
}
void CSmtpAddr::SetPartsSeparator(const _TCHAR *partsSeparator)
{
	if (partsSeparator != NULL) {
		::_tcscpy(m_partsSeparator, partsSeparator);
	}
}
