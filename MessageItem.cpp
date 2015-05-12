// MessageItem.cpp: implementation of the CMessageItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MessageItem.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMessageItem::CMessageItem()
{
	m_name[0] = _T('\0');
	m_value[0] = _T('\0');
	m_condition[0] = _T('\0');
	m_numeric = false;
}

CMessageItem::~CMessageItem()
{

}

// Get/Set m_name
_TCHAR const * CMessageItem::GetName()
{
	return &m_name[0];
}
void CMessageItem::SetName(const _TCHAR *name)
{
	if (name != NULL) {
		::_tcscpy(m_name, name);
	}
}

// Get/Set m_value
_TCHAR const * CMessageItem::GetValue()
{
	return &m_value[0];
}
void CMessageItem::SetValue(const _TCHAR *value)
{
	if (value != NULL) {
		::_tcscpy(m_value, value);
	}
}

// Get/Set m_valuenum
long const CMessageItem::GetValueNumeric()
{
	return m_valuenum;
}
void CMessageItem::SetValueNumeric(const long value)
{
	m_valuenum = value;
}

// Get/Set m_numeric
bool const CMessageItem::IsNumeric()
{
	return (m_numeric == true);
}
void CMessageItem::SetNumeric(const bool value)
{
	m_numeric = value;
}


// Get/Set m_condition
_TCHAR const * CMessageItem::GetCondition()
{
	return &m_condition[0];
}
void CMessageItem::SetCondition(const _TCHAR *condition)
{
	if (condition != NULL) {
		::_tcscpy(m_condition, condition);
	}
}
