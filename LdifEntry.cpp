// LdifEntry.cpp: implementation of the CLdifEntry class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LdifEntry.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLdifEntry::CLdifEntry()
{

}

CLdifEntry::~CLdifEntry()
{

}

// Get/Set m_attribute
_TCHAR const * CLdifEntry::GetAttribute()
{
	return &m_attribute[0];
}
void CLdifEntry::SetAttribute(const _TCHAR *attribute)
{
	if (attribute != NULL) {
		::_tcscpy(m_attribute, attribute);
	}
}

// Get/Set m_attribute
_TCHAR const * CLdifEntry::GetValue()
{
	return &m_value[0];
}
void CLdifEntry::SetValue(const _TCHAR *value)
{
	if (value != NULL) {
		::_tcscpy(m_value, value);
	}
}

