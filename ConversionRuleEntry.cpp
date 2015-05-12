// ConversionRuleEntry.cpp: implementation of the CConversionRuleEntry class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ConversionRuleEntry.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConversionRuleEntry::CConversionRuleEntry()
{

}

CConversionRuleEntry::~CConversionRuleEntry()
{

}

// Get/Set m_input
_TCHAR const * CConversionRuleEntry::GetInput()
{
	return &m_input[0];
}
void CConversionRuleEntry::SetInput(const _TCHAR *input)
{
	_tcscpy(m_input, input);
}

// Get/Set m_output
_TCHAR const * CConversionRuleEntry::GetOutput()
{
	return &m_output[0];
}
void CConversionRuleEntry::SetOutput(const _TCHAR *output)
{
	_tcscpy(m_output, output);
}

bool CConversionRuleEntry::IsDefault()
{
	return m_def;
}
void CConversionRuleEntry::SetDefault(bool def)
{
	m_def = def;
}
