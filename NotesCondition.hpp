// NotesCondition.hpp: interface for the CNotesCondition class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOTESCONDITION_HPP__79ADC945_2F9D_48D8_A931_DD242A441425__INCLUDED_)
#define AFX_NOTESCONDITION_HPP__79ADC945_2F9D_48D8_A931_DD242A441425__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NDIRXML_EXPORTS
#define NDIRXML_API __declspec(dllexport)
#else
#define NDIRXML_API __declspec(dllimport)
#endif

#define CONDITION_NOATTACHMENTS			_T("NoAttachments")
#define CONDITION_ATTACHMENTEXISTS		_T("AttachmentExists")
#define CONDITION_TEXTPART				_T("TextPart")
#define CONDITION_ATTACHMENTPART		_T("AttachmentPart")
#define CONDITION_ENDOFPARTS			_T("EndOfParts")
#define CONDITION_SENDER				_T("Sender")
#define CONDITION_RECIPIENTTO			_T("RecipientTo")
#define CONDITION_RECIPIENTCC			_T("RecipientCc")
#define CONDITION_RECIPIENTBCC			_T("RecipientBcc")

class CNotesCondition  
{
public:
	CNotesCondition();
	virtual ~CNotesCondition();

	NDIRXML_API static bool IsNotesCondition(LPMESSAGE pmsg, const _TCHAR *condition, HRESULT *error);
	NDIRXML_API static bool CheckAttachmentExists(LPMESSAGE pmsg, HRESULT *error);

};

#endif // !defined(AFX_NOTESCONDITION_HPP__79ADC945_2F9D_48D8_A931_DD242A441425__INCLUDED_)
