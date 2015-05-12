// XMLDirProc.cpp: implementation of the CXMLDirProc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include <xercesc/util/XercesDefs.hpp>

#include <xalanc/Include/PlatformDefinitions.hpp>

#include <xercesc/util/PlatformUtils.hpp>
//#include <xercesc/framework/LocalFileInputSource.hpp>
//#include <xercesc/framework/MemBufInputSource.hpp>

#include <xalanc/DOMSupport/XalanDocumentPrefixResolver.hpp>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/sax/SAXParseException.hpp>

#include <xalanc/XalanDOM/XalanDocument.hpp>
#include <xalanc/XalanDOM/XalanElement.hpp>
#include <xalanc/XalanDOM/XalanNode.hpp>
#include <xalanc/XalanDOM/XalanNamedNodeMap.hpp>
#include <xalanc/XalanDOM/XalanNodeList.hpp>
#include <xalanc/XalanDOM/XalanDOMException.hpp>
#include <xalanc/XPath/XPathEvaluator.hpp>

#include <xalanc/XercesParserLiaison/XercesDOMSupport.hpp>
#include <xalanc/XercesParserLiaison/XercesParserLiaison.hpp>
#include <xalanc/XercesParserLiaison/XercesDocumentWrapper.hpp>
#include <xalanc/XercesParserLiaison/XercesDOMException.hpp>

//#include <xalanc/XalanSourceTree/XalanSourceTreeDOMSupport.hpp>
//#include <xalanc/XalanSourceTree/XalanSourceTreeInit.hpp>
//#include <xalanc/XalanSourceTree/XalanSourceTreeParserLiaison.hpp>
#include <xalanc/XPath/NodeRefList.hpp>
#include <xalanc/XPath/MutableNodeRefList.hpp>

#include <xalanc/XercesParserLiaison/XercesDocumentWrapper.hpp>

#include "LdifEntry.hpp"
#include "LdifEntryFilter.hpp"
#include "LdifEntryTransformer.hpp"
#include "SmtpAddr.hpp"
#include "PersonGroupEntry.hpp"
#include "SAXErrorHandler.hpp"
#include "XMLProc.hpp"

#include "XMLDirProc.hpp"

#include "resource.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXMLDirProc::CXMLDirProc()
{
}

CXMLDirProc::~CXMLDirProc()
{

}

CLdifEntry* CXMLDirProc::getNextLdifPersonEntry()
{
	_TCHAR usage[256];
	HINSTANCE hInst = ::GetModuleHandle(NULL);
	_TCHAR current_method[] = _TEXT("CXMLDirProc::getNextLdifPersonEntry");
	if (m_verbose){
		::LoadString(hInst, IDS_ENTER_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	CLdifEntry *entry = NULL;
	if (!m_entryListInitialized) {
		getEntryList(LDIF_PERSON_SELECTOR);
		m_entryListInitialized = true;
	}
	if (m_currentEntryIndex < m_entryList->getLength()) {
		entry = new CLdifEntry();
		const XalanNode* const	theNode = m_entryList->item(m_currentEntryIndex);
		const XalanNamedNodeMap* attrs = theNode->getAttributes();
		XalanNode* attrNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_ATTRIBUTE));
		XalanNode* valueNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_VALUE));
		entry->SetAttribute(attrNode->getNodeValue().c_str());
		entry->SetValue(valueNode->getNodeValue().c_str());

		m_currentEntryIndex++;
	}
	else {
		m_currentEntryIndex = 0;
		m_entryListInitialized=false;
		entry = NULL;
	}

	if (m_verbose){
		::LoadString(hInst, IDS_EXIT_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	return entry;
}

CLdifEntry* CXMLDirProc::getNextLdifGroupEntry()
{
	_TCHAR usage[256];
	HINSTANCE hInst = ::GetModuleHandle(NULL);
	_TCHAR current_method[] = _TEXT("CXMLDirProc::getNextLdifGroupEntry");
	if (m_verbose){
		::LoadString(hInst, IDS_ENTER_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	CLdifEntry *entry;
	if (!m_entryFilterListInitialized) {
		getEntryList(LDIF_GROUP_SELECTOR);
		m_entryFilterListInitialized = true;
	}
	if (m_currentEntryIndex < m_entryList->getLength()) {
		entry = new CLdifEntry();
		const XalanNode* const	theNode = m_entryList->item(m_currentEntryIndex);
		const XalanNamedNodeMap* attrs = theNode->getAttributes();
		XalanNode* attrNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_ATTRIBUTE));
		XalanNode* valueNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_VALUE));
		entry->SetAttribute(attrNode->getNodeValue().c_str());
		entry->SetValue(valueNode->getNodeValue().c_str());

		m_currentEntryIndex++;
	}
	else {
		m_currentEntryIndex = 0;
		m_entryListInitialized=false;
		entry = NULL;
	}

	if (m_verbose){
		::LoadString(hInst, IDS_EXIT_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	return entry;
}

void CXMLDirProc::getEntryFilterList(_TCHAR* selector)
{
	_TCHAR usage[256];
	HINSTANCE hInst = ::GetModuleHandle(NULL);
	_TCHAR current_method[] = _TEXT("CXMLProc::getEntryFilterList");
	if (m_verbose){
		::LoadString(hInst, IDS_ENTER_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	XPathEvaluator	*theEvaluator = new XPathEvaluator();
	NodeRefList	theResult;
	theEvaluator->selectNodeList(
							theResult,
							*theDOMSupport,
							theDocument,
							XalanDOMString(selector).c_str(),
							*thePrefixResolver);
	m_entryFilterList = new MutableNodeRefList(theResult, theResult.getMemoryManager());
	theEvaluator->~XPathEvaluator();
	if (m_verbose){
		::LoadString(hInst, IDS_EXIT_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
}

CLdifEntryFilter* CXMLDirProc::getNextLdifEntryFilter(bool person)
{
	_TCHAR usage[256];
	HINSTANCE hInst = ::GetModuleHandle(NULL);
	_TCHAR current_method[] = _TEXT("CXMLDirProc::getNextLdifEntryFilter");
	if (m_verbose){
		::LoadString(hInst, IDS_ENTER_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	CLdifEntryFilter *entry;
	if (!m_entryFilterListInitialized) {
		if (person)
			getEntryFilterList(LDIF_PERSON_FILTER_SELECTOR);
		else
			getEntryFilterList(LDIF_GROUP_FILTER_SELECTOR);
		m_entryFilterListInitialized = true;
	}
	if (m_currentEntryFilterIndex < m_entryFilterList->getLength()) {
		entry = new CLdifEntryFilter();
		const XalanNode* const	theNode = m_entryFilterList->item(m_currentEntryFilterIndex);
		const XalanNamedNodeMap* attrs = theNode->getAttributes();
		XalanNode* fieldNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_FILTER_FIELD));
		XalanNode* valueNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_VALUE));
		XalanNode* conditionNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_FILTER_CONDITION));
		XalanNode* combineNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_FILTER_COMBINE));
		XalanNode* bracketNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_FILTER_BRACKET));
		entry->SetPstItemProperty(fieldNode->getNodeValue().c_str());
		entry->SetValue(valueNode->getNodeValue().c_str());
		entry->SetCondition(conditionNode->getNodeValue().c_str());

		if (combineNode != NULL) {
			entry->SetCombine(combineNode->getNodeValue().c_str());
		}
		if (bracketNode != NULL) {
			entry->SetCombine(bracketNode->getNodeValue().c_str());
		}

		m_currentEntryFilterIndex++;
	}
	else {
		m_currentEntryFilterIndex = 0;
		m_entryFilterListInitialized=false;
		entry = NULL;
	}

	if (m_verbose){
		::LoadString(hInst, IDS_EXIT_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	return entry;
}

int CXMLDirProc::getCurrentLdifEntryFilterIndex()
{
	return m_currentEntryFilterIndex;
}
void CXMLDirProc::setCurrentLdifEntryFilterIndex(int index)
{
	m_currentEntryFilterIndex = index;
	m_entryFilterListInitialized = true;
}

void CXMLDirProc::resetEntryFilterIndex()
{
	m_currentEntryFilterIndex = 0;
	m_entryFilterListInitialized = false;
	if (m_entryFilterList != NULL) {
		delete(m_entryFilterList);
		m_entryFilterList = NULL;
	}
}

void CXMLDirProc::resetEntryListIndex()
{
	m_currentEntryIndex = 0;
	m_entryListInitialized = false;
	if (m_entryList != NULL) {
		delete(m_entryList);
		m_entryList = NULL;
	}
}

void CXMLDirProc::resetTransformerListIndex()
{
	m_currentTransformerIndex = 0;
	m_transformerListInitialized = false;
	if (m_transformerList != NULL) {
		delete(m_transformerList);
		m_transformerList = NULL;
	}
}

CLdifEntryTransformer* CXMLDirProc::getNextLdifEntryTransformer()
{
	_TCHAR usage[256];
	HINSTANCE hInst = ::GetModuleHandle(NULL);
	_TCHAR current_method[] = _TEXT("CXMLDirProc::getNextLdifEntryTransformer");
	if (m_verbose){
		::LoadString(hInst, IDS_ENTER_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}

	CLdifEntryTransformer *transformer;
	if (!m_transformerListInitialized) {
		XalanNode* theNode = m_entryList->item(m_currentEntryIndex-1);
		XPathEvaluator	*theEvaluator = new XPathEvaluator();
		NodeRefList	theResult;
		theEvaluator->selectNodeList(
								theResult,
								*theDOMSupport,
								theNode,
								XalanDOMString(LDIF_TRANSFORMER_SELECTOR).c_str(),
								*thePrefixResolver);
		m_transformerList = new MutableNodeRefList(theResult, theResult.getMemoryManager());
		theEvaluator->~XPathEvaluator();
		m_transformerListInitialized = true;
	}
	if (m_currentTransformerIndex < m_transformerList->getLength()) {
		transformer = new CLdifEntryTransformer();
		const XalanNode* const	theTransformerNode = m_transformerList->item(m_currentTransformerIndex);
		const XalanNamedNodeMap* attrs = theTransformerNode->getAttributes();
		XalanNode* nameNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_NAME));
		XalanNode* placeholderNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_PLACEHOLDER));
		XalanNode* multivalueNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_MULTIVALUE));
		XalanNode* onlyFirstValueNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_ONLYFIRSTVALUE));
		XalanNode* multivalueSeparatorNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_MULTIVALUE_SEPARATOR));
		XalanNode* orgHierarchyNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_ORG_HIERARCHY));
		XalanNode* resolveDocFieldNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_RESOLVE_DOC_FIELD));
		XalanNode* resolveDocFormNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_RESOLVE_DOC_FORM));
		XalanNode* resolveDocFormAltNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_RESOLVE_DOC_FORM_ALT));
		XalanNode* resolveDocLookupFieldNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_RESOLVE_DOC_LOOKUP_FIELD));
		XalanNode* resolveDocLookupFieldAltNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_RESOLVE_DOC_LOOKUP_FIELD_ALT));
		XalanNode* extractCN = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_EXTRACTCN));
		
		XalanNode* namedPropertyValue = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_NAMED_PROPERTY));

		transformer->SetName(nameNode->getNodeValue().c_str());
		transformer->SetPlaceholder(placeholderNode->getNodeValue().c_str());
		if (multivalueNode == NULL) {
			transformer->SetMultivalue(false);
		}
		else {
			transformer->SetMultivalue(_tcscmp(multivalueNode->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}
		if (onlyFirstValueNode == NULL) {
			transformer->SetOnlyFirstValue(true);
		}
		else {
			transformer->SetOnlyFirstValue(_tcscmp(onlyFirstValueNode->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}
		if (multivalueSeparatorNode == NULL) {
			transformer->SetMultivalueSeparator(_T(";"));
		}
		else {
			transformer->SetMultivalueSeparator(multivalueSeparatorNode->getNodeValue().c_str());
		}
		if (orgHierarchyNode == NULL) {
			transformer->SetOrgHierarchy(false);
		}
		else {
			transformer->SetOrgHierarchy(_tcscmp(orgHierarchyNode->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}
		if (resolveDocFieldNode != NULL) {
//			_tprintf(_T("resolveDocFieldNode: %s\n"), resolveDocFieldNode->getNodeValue().c_str());
			transformer->SetResolveDocField(resolveDocFieldNode->getNodeValue().c_str());
		}
		if (resolveDocFormNode != NULL) {
//			_tprintf(_T("resolveDocFormNode: %s\n"), resolveDocFormNode->getNodeValue().c_str());
			transformer->SetResolveDocForm(resolveDocFormNode->getNodeValue().c_str());
		}
		if (resolveDocFormAltNode != NULL) {
//			_tprintf(_T("resolveDocFormNode: %s\n"), resolveDocFormNode->getNodeValue().c_str());
			transformer->SetResolveDocFormAlt(resolveDocFormAltNode->getNodeValue().c_str());
		}
		if (resolveDocLookupFieldNode != NULL) {
//			_tprintf(_T("resolveDocLookupFieldNode: %s\n"), resolveDocLookupFieldNode->getNodeValue().c_str());
			transformer->SetResolveDocLookupField(resolveDocLookupFieldNode->getNodeValue().c_str());
		}
		if (resolveDocLookupFieldAltNode != NULL) {
//			_tprintf(_T("resolveDocLookupFieldNode: %s\n"), resolveDocLookupFieldNode->getNodeValue().c_str());
			transformer->SetResolveDocLookupFieldAlt(resolveDocLookupFieldAltNode->getNodeValue().c_str());
		}

		if (_tcscmp(theTransformerNode->getNodeName().c_str(), XMLELEMENT_PSTITEMPROPERTY) == 0) {
			transformer->SetPstItemProperty(true);
		}
		else {
			transformer->SetPstItemProperty(false);
		}
		if (extractCN == NULL) {
			transformer->SetExtractCN(false);
		}
		else {
			transformer->SetExtractCN(_tcscmp(extractCN->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}
		if (namedPropertyValue == NULL) {
			transformer->SetNamedProperty(false);
		}
		else {
			transformer->SetNamedProperty(_tcscmp(namedPropertyValue->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}

		m_currentTransformerIndex++;
	}
	else {
		m_currentTransformerIndex = 0;
		m_transformerListInitialized = false;
		transformer = NULL;
	}

	if (m_verbose){
		::LoadString(hInst, IDS_EXIT_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	return transformer;
}

CLdifEntryTransformer* CXMLDirProc::getNextSMTPEntryTransformer()
{
	_TCHAR usage[256];
	HINSTANCE hInst = ::GetModuleHandle(NULL);
	_TCHAR current_method[] = _TEXT("CXMLDirProc::getNextSMTPEntryTransformer");
	if (m_verbose){
		::LoadString(hInst, IDS_ENTER_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}

	CLdifEntryTransformer *transformer;
	if (!m_transformerListInitialized) {
		XPathEvaluator	*theEvaluator = new XPathEvaluator();

		XalanNode* theNode = theEvaluator->selectSingleNode(
							*theDOMSupport,
							theDocument,
							XalanDOMString(SMTP_ADDR_SELECTOR).c_str(),
							*thePrefixResolver);

		NodeRefList	theResult;
		theEvaluator->selectNodeList(
								theResult,
								*theDOMSupport,
								theNode,
								XalanDOMString(LDIF_TRANSFORMER_SELECTOR).c_str(),
								*thePrefixResolver);
		m_transformerList = new MutableNodeRefList(theResult, theResult.getMemoryManager());
		theEvaluator->~XPathEvaluator();
		m_transformerListInitialized = true;
	}
	if (m_currentTransformerIndex < m_transformerList->getLength()) {
		transformer = new CLdifEntryTransformer();
		const XalanNode* const	theTransformerNode = m_transformerList->item(m_currentTransformerIndex);
		const XalanNamedNodeMap* attrs = theTransformerNode->getAttributes();
		XalanNode* nameNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_NAME));
		XalanNode* placeholderNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_PLACEHOLDER));
		XalanNode* multivalueNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_MULTIVALUE));
		XalanNode* onlyFirstValueNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_ONLYFIRSTVALUE));
		XalanNode* multivalueSeparatorNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_MULTIVALUE_SEPARATOR));
		XalanNode* orgHierarchyNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_ORG_HIERARCHY));
		XalanNode* resolveDocFieldNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_RESOLVE_DOC_FIELD));
		XalanNode* resolveDocFormNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_RESOLVE_DOC_FORM));
		XalanNode* resolveDocLookupFieldNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_RESOLVE_DOC_LOOKUP_FIELD));
		XalanNode* extractCN = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_EXTRACTCN));
		
		transformer->SetName(nameNode->getNodeValue().c_str());
		transformer->SetPlaceholder(placeholderNode->getNodeValue().c_str());
		if (multivalueNode == NULL) {
			transformer->SetMultivalue(false);
		}
		else {
			transformer->SetMultivalue(_tcscmp(multivalueNode->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}
		if (onlyFirstValueNode == NULL) {
			transformer->SetOnlyFirstValue(true);
		}
		else {
			transformer->SetOnlyFirstValue(_tcscmp(onlyFirstValueNode->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}
		if (multivalueSeparatorNode == NULL) {
			transformer->SetMultivalueSeparator(_T(";"));
		}
		else {
			transformer->SetMultivalueSeparator(multivalueSeparatorNode->getNodeValue().c_str());
		}
		if (orgHierarchyNode == NULL) {
			transformer->SetOrgHierarchy(false);
		}
		else {
			transformer->SetOrgHierarchy(_tcscmp(orgHierarchyNode->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}
		if (resolveDocFieldNode != NULL) {
//			_tprintf(_T("resolveDocFieldNode: %s\n"), resolveDocFieldNode->getNodeValue().c_str());
			transformer->SetResolveDocField(resolveDocFieldNode->getNodeValue().c_str());
		}
		if (resolveDocFormNode != NULL) {
//			_tprintf(_T("resolveDocFormNode: %s\n"), resolveDocFormNode->getNodeValue().c_str());
			transformer->SetResolveDocForm(resolveDocFormNode->getNodeValue().c_str());
		}
		if (resolveDocLookupFieldNode != NULL) {
//			_tprintf(_T("resolveDocLookupFieldNode: %s\n"), resolveDocLookupFieldNode->getNodeValue().c_str());
			transformer->SetResolveDocLookupField(resolveDocLookupFieldNode->getNodeValue().c_str());
		}

		if (_tcscmp(theTransformerNode->getNodeName().c_str(), XMLELEMENT_PSTITEMPROPERTY) == 0) {
			transformer->SetPstItemProperty(true);
		}
		else {
			transformer->SetPstItemProperty(false);
		}
		if (extractCN == NULL) {
			transformer->SetExtractCN(false);
		}
		else {
			transformer->SetExtractCN(_tcscmp(extractCN->getNodeValue().c_str(), _T("true")) == 0 ? true : false);
		}

		m_currentTransformerIndex++;
	}
	else {
		m_currentTransformerIndex = 0;
		m_transformerListInitialized = false;
		transformer = NULL;
	}

	if (m_verbose){
		::LoadString(hInst, IDS_EXIT_METHOD, usage, 256);
		::_tprintf(_TEXT("%s %s\n"), usage, current_method);
	}
	return transformer;
}

void CXMLDirProc::insertLdifEntry(const _TCHAR *attribute, const _TCHAR *value)
{
	try
	{

	const XalanNode* const	theCurrentEntryNode = m_entryList->item(m_currentEntryIndex-1);
	const XalanNamedNodeMap* attrs = theCurrentEntryNode->getAttributes();
	XalanNode* valueNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_VALUE));
	assert(theDocument != 0);
	DOMElement *theNewNode= theXercesDocument->createElement(theCurrentEntryNode->getNodeName().c_str());

	int i = 0;
	int j = 0;
	for (i=0; i<attrs->getLength(); i++) {
		theNewNode->setAttribute(attrs->item(i)->getNodeName().c_str(), attrs->item(i)->getNodeValue().c_str());
	}

	const DOMNamedNodeMap* newAttrs = theNewNode->getAttributes();
	DOMNode* valueNodeDOM = newAttrs->getNamedItem(XMLATTRIBUTE_VALUE);
	valueNodeDOM->setNodeValue(value);

	const XalanNodeList *childNodes = theCurrentEntryNode->getChildNodes();
	for (j=0; j < childNodes->getLength(); j++) {
		if (childNodes->item(j)->getNodeType() != XalanElement::ELEMENT_NODE) {
			continue;
		}
//		_tprintf(_T("ax201 %s %d\n"), childNodes->item(j)->getNodeName().c_str(), childNodes->item(j)->getNodeType());
		DOMElement *theNewChildNode = theXercesDocument->createElement(childNodes->item(j)->getNodeName().c_str());
		attrs = childNodes->item(j)->getAttributes();
		for (i=0; i<attrs->getLength(); i++) {
			theNewChildNode->setAttribute(attrs->item(i)->getNodeName().c_str(), attrs->item(i)->getNodeValue().c_str());
		}
		theNewNode->appendChild(theNewChildNode);
	}

	theXercesDocument->getDocumentElement()->appendChild(theNewNode);

	XercesParserLiaison *theLiaison2 = new XercesParserLiaison(*theDOMSupport);
	XalanDocument* theXDoc = theLiaison2->createDocument(theXercesDocument);

	XPathEvaluator	*theEvaluator = new XPathEvaluator();
	NodeRefList	theResult;
	theEvaluator->selectNodeList(
							theResult,
							*theDOMSupport,
							theXDoc,
							XalanDOMString(_T("//ldifEntry")).c_str(),
							*thePrefixResolver);
	MutableNodeRefList* testList = new MutableNodeRefList(theResult, theResult.getMemoryManager());
	if (testList->getLength() > 0) {
		m_entryList->addNode(testList->item(testList->getLength()-1));
	}
	theEvaluator->~XPathEvaluator();
	}
	catch (const XMLException& e)
	{
		_tprintf(_T("XMLException: %s\n"), e.getMessage());
	}
	catch (const DOMException& e)
	{
		_tprintf(_T("DOMException: %s\n"), e.getMessage());
	}
}

CSmtpAddr* CXMLDirProc::getSmtpAddrInfo()
{
	_TCHAR selector[256];
	CSmtpAddr* info = NULL;
	_tcscpy(selector, SMTP_ADDR_SELECTOR);

	XPathEvaluator	*theEvaluator = new XPathEvaluator();

	XalanNode* const	theSmtpAddrNode =
							theEvaluator->selectSingleNode(
							*theDOMSupport,
							theDocument,
							XalanDOMString(selector).c_str(),
							*thePrefixResolver);

	if (theSmtpAddrNode != NULL)
	{
		const XalanNamedNodeMap* attrs = theSmtpAddrNode->getAttributes();
		XalanNode* fileNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_FILE));
		XalanNode* lotusPartNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_SMTP_LOTUSPART));
		XalanNode* emailPartNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_SMTP_EMAILPART));
		XalanNode* emailSeparatorNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_SMTP_EMAILSEP));
		XalanNode* emailPreferenceNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_SMTP_EMAILPREF));
		XalanNode* partsSeparatorNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_SMTP_PARTSSEP));
		info = new CSmtpAddr();
		info->SetFile(fileNode->getNodeValue().c_str());
		info->SetLotusPart(lotusPartNode->getNodeValue().c_str());
		info->SetEmailPart(emailPartNode->getNodeValue().c_str());
		info->SetEmailSeparator(emailSeparatorNode->getNodeValue().c_str());
		if (emailPreferenceNode != NULL)
			info->SetEmailPreference(emailPreferenceNode->getNodeValue().c_str());
		info->SetPartsSeparator(partsSeparatorNode->getNodeValue().c_str());
	}

	theEvaluator->~XPathEvaluator();
	return info;
}

CPersonGroupEntry* CXMLDirProc::getPersonGroupEntry(bool isPerson)
{
	_TCHAR selector[256];
	CPersonGroupEntry* info = new CPersonGroupEntry();

	XPathEvaluator	*theEvaluator = new XPathEvaluator();

	if (isPerson)
		_tcscpy(selector, LDIF_PERSON_MAIN_SELECTOR);
	else
		_tcscpy(selector, LDIF_GROUP_MAIN_SELECTOR);
	XalanNode* const	theNode =
							theEvaluator->selectSingleNode(
							*theDOMSupport,
							theDocument,
							XalanDOMString(selector).c_str(),
							*thePrefixResolver);

	const XalanNamedNodeMap* attrs = theNode->getAttributes();
	XalanNode* dateFilterFieldNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_DATEFILTERFIELD));
	XalanNode* dateFilterStartNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_DATEFILTERSTART));
	XalanNode* dateMaskNode = attrs->getNamedItem(XalanDOMString(XMLATTRIBUTE_DATEMASK));
	if (dateFilterFieldNode != NULL && 
		dateFilterStartNode != NULL && 
		dateMaskNode != NULL) {
		info->SetDateFilterField(dateFilterFieldNode->getNodeValue().c_str());
		info->SetDateFilterStart(dateFilterStartNode->getNodeValue().c_str());
		info->SetDateMask(dateMaskNode->getNodeValue().c_str());
	}

	theEvaluator->~XPathEvaluator();
	return info;
}

