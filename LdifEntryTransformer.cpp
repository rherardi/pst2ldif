// LdifEntryTransformer.cpp: implementation of the CLdifEntryTransformer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LdifEntryTransformer.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLdifEntryTransformer::CLdifEntryTransformer()
{
	m_valueModifier[0] = _T('\0');
}

CLdifEntryTransformer::~CLdifEntryTransformer()
{

}

// Get/Set m_name
_TCHAR const * CLdifEntryTransformer::GetName()
{
	return &m_name[0];
}
void CLdifEntryTransformer::SetName(const _TCHAR *name)
{
	::_tcscpy(m_name, name);
}

// Get/Set m_placeholder
_TCHAR const * CLdifEntryTransformer::GetPlaceholder()
{
	return &m_placeholder[0];
}
void CLdifEntryTransformer::SetPlaceholder(const _TCHAR *placeholder)
{
	::_tcscpy(m_placeholder, placeholder);
}

// Get/Set m_resolveDocField
_TCHAR const * CLdifEntryTransformer::GetResolveDocField()
{
	return &m_resolveDocField[0];
}
void CLdifEntryTransformer::SetResolveDocField(const _TCHAR *resolveDocField)
{
	::_tcscpy(m_resolveDocField, resolveDocField);
}

// Get/Set m_resolveDocForm
_TCHAR const * CLdifEntryTransformer::GetResolveDocForm()
{
	return &m_resolveDocForm[0];
}
void CLdifEntryTransformer::SetResolveDocForm(const _TCHAR *resolveDocForm)
{
	::_tcscpy(m_resolveDocForm, resolveDocForm);
}

// Get/Set m_resolveDocFormAlt
_TCHAR const * CLdifEntryTransformer::GetResolveDocFormAlt()
{
	return &m_resolveDocFormAlt[0];
}
void CLdifEntryTransformer::SetResolveDocFormAlt(const _TCHAR *resolveDocFormAlt)
{
	::_tcscpy(m_resolveDocFormAlt, resolveDocFormAlt);
}

// Get/Set m_resolveDocLookupField
_TCHAR const * CLdifEntryTransformer::GetResolveDocLookupField()
{
	return &m_resolveDocLookupField[0];
}
void CLdifEntryTransformer::SetResolveDocLookupField(const _TCHAR *resolveDocLookupField)
{
	::_tcscpy(m_resolveDocLookupField, resolveDocLookupField);
}

// Get/Set m_resolveDocLookupFieldAlt
_TCHAR const * CLdifEntryTransformer::GetResolveDocLookupFieldAlt()
{
	return &m_resolveDocLookupFieldAlt[0];
}
void CLdifEntryTransformer::SetResolveDocLookupFieldAlt(const _TCHAR *resolveDocLookupFieldAlt)
{
	::_tcscpy(m_resolveDocLookupFieldAlt, resolveDocLookupFieldAlt);
}

// Get/Set m_pstItemProperty
bool const CLdifEntryTransformer::GetPstItemProperty()
{
	return m_pstItemProperty;
}
void CLdifEntryTransformer::SetPstItemProperty(const bool pstItemProperty)
{
	m_pstItemProperty = pstItemProperty;
}

// Get/Set m_multivalue
bool const CLdifEntryTransformer::GetMultivalue()
{
	return m_multivalue;
}
void CLdifEntryTransformer::SetMultivalue(const bool multivalue)
{
	m_multivalue = multivalue;
}

// Get/Set m_onlyFirstValue
bool const CLdifEntryTransformer::GetOnlyFirstValue()
{
	return m_onlyFirstValue;
}

void CLdifEntryTransformer::SetOnlyFirstValue(const bool onlyFirstValue)
{
	m_onlyFirstValue = onlyFirstValue;
}

// Get/Set m_multivalueSeparator
_TCHAR const * CLdifEntryTransformer::GetMultivalueSeparator()
{
	return &m_multivalueSeparator[0];
}

void CLdifEntryTransformer::SetMultivalueSeparator(const _TCHAR *multivalueSeparator)
{
	::_tcscpy(m_multivalueSeparator, multivalueSeparator);
}

// Get/Set m_orgHierarchy
bool const CLdifEntryTransformer::GetOrgHierarchy()
{
	return m_orgHierarchy;
}

void CLdifEntryTransformer::SetOrgHierarchy(const bool orgHierarchy)
{
	m_orgHierarchy = orgHierarchy;
}

// Get/Set m_extractCN
bool const CLdifEntryTransformer::GetExtractCN()
{
	return m_extractCN;
}

void CLdifEntryTransformer::SetExtractCN(const bool extractCN)
{
	m_extractCN = extractCN;
}

// Get/Set m_dateMask
_TCHAR const * CLdifEntryTransformer::GetDateMask()
{
	return &m_dateMask[0];
}

void CLdifEntryTransformer::SetDateMask(const _TCHAR *dateMask)
{
	::_tcscpy(m_dateMask, dateMask);
}

// Get/Set m_valueModifier
_TCHAR const * CLdifEntryTransformer::GetValueModifier()
{
	return &m_valueModifier[0];
}

void CLdifEntryTransformer::SetValueModifier(const _TCHAR *valueModifier)
{
	_tcscpy(m_valueModifier, valueModifier);
}

// Get/Set m_blankIfAbsent
bool CLdifEntryTransformer::IsBlankIfAbsent()
{
	return m_blankIfAbsent;
}
void CLdifEntryTransformer::SetBlankIfAbsent(bool blankIfAbsent)
{
	m_blankIfAbsent = blankIfAbsent;
}

// Get/Set m_namedProperty
bool CLdifEntryTransformer::IsNamedProperty()
{
	return m_namedProperty;
}
void CLdifEntryTransformer::SetNamedProperty(bool namedProperty)
{
	m_namedProperty = namedProperty;
}

