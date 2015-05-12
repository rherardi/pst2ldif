// LdifEntryFilter.cpp: implementation of the CLdifEntryFilter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LdifEntryFilter.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLdifEntryFilter::CLdifEntryFilter()
{

}

CLdifEntryFilter::~CLdifEntryFilter()
{

}

// Get/Set m_pstItemProperty
_TCHAR const * CLdifEntryFilter::GetPstItemProperty()
{
	return &m_pstItemProperty[0];
}
void CLdifEntryFilter::SetPstItemProperty(const _TCHAR *pstItemProperty)
{
	if (pstItemProperty != NULL) {
		::_tcscpy(m_pstItemProperty, pstItemProperty);
	}
}

// Get/Set m_value
_TCHAR const * CLdifEntryFilter::GetValue()
{
	return &m_value[0];
}
void CLdifEntryFilter::SetValue(const _TCHAR *value)
{
	if (value != NULL) {
		::_tcscpy(m_value, value);
	}
}

// Get/Set m_condition
_TCHAR const * CLdifEntryFilter::GetCondition()
{
	return &m_condition[0];
}
void CLdifEntryFilter::SetCondition(const _TCHAR *condition)
{
	if (condition != NULL) {
		::_tcscpy(m_condition, condition);
	}
}

// Get/Set m_combine
_TCHAR const * CLdifEntryFilter::GetCombine()
{
	return &m_combine[0];
}
void CLdifEntryFilter::SetCombine(const _TCHAR *combine)
{
	if (combine != NULL) {
		::_tcscpy(m_combine, combine);
	}
}

// Get/Set m_bracket
_TCHAR const * CLdifEntryFilter::GetBracket()
{
	return &m_bracket[0];
}
void CLdifEntryFilter::SetBracket(const _TCHAR *bracket)
{
	if (bracket != NULL) {
		::_tcscpy(m_bracket, bracket);
	}
}


