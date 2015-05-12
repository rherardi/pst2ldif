// PersonGroupEntry.cpp: implementation of the CPersonGroupEntry class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PersonGroupEntry.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPersonGroupEntry::CPersonGroupEntry()
{

}

CPersonGroupEntry::~CPersonGroupEntry()
{

}

// Get/Set m_dateFilterField
_TCHAR const * CPersonGroupEntry::GetDateFilterField()
{
	return &m_dateFilterField[0];
}

void CPersonGroupEntry::SetDateFilterField(const _TCHAR *dateFilterField)
{
	if (dateFilterField != NULL) {
		::_tcscpy(m_dateFilterField, dateFilterField);
	}
}

// Get/Set m_dateFilterStart
_TCHAR const * CPersonGroupEntry::GetDateFilterStart()
{
	return &m_dateFilterStart[0];
}

void CPersonGroupEntry::SetDateFilterStart(const _TCHAR *dateFilterStart)
{
	if (dateFilterStart != NULL) {
		::_tcscpy(m_dateFilterStart, dateFilterStart);
	}
}

// Get/Set m_dateMask
_TCHAR const * CPersonGroupEntry::GetDateMask()
{
	return &m_dateMask[0];
}

void CPersonGroupEntry::SetDateMask(const _TCHAR *dateMask)
{
	if (dateMask != NULL) {
		::_tcscpy(m_dateMask, dateMask);
	}
}