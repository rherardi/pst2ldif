// PersonGroupEntry.hpp: interface for the CPersonGroupEntry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSONGROUPENTRY_HPP__ED46595D_66F1_4535_B25C_330EA3969892__INCLUDED_)
#define AFX_PERSONGROUPENTRY_HPP__ED46595D_66F1_4535_B25C_330EA3969892__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NDIRXML_EXPORTS
#define NDIRXML_API __declspec(dllexport)
#else
#define NDIRXML_API __declspec(dllimport)
#endif

class CPersonGroupEntry  
{
public:
	CPersonGroupEntry();
	virtual ~CPersonGroupEntry();

	// Get/Set m_dateFilterField
	NDIRXML_API _TCHAR const * GetDateFilterField();
	NDIRXML_API void SetDateFilterField(const _TCHAR *dateFilterField);

	// Get/Set m_dateFilterStart
	NDIRXML_API _TCHAR const * GetDateFilterStart();
	NDIRXML_API void SetDateFilterStart(const _TCHAR *dateFilterStart);

	// Get/Set m_dateMask
	NDIRXML_API _TCHAR const * GetDateMask();
	NDIRXML_API void SetDateMask(const _TCHAR *dateMask);

protected:
	_TCHAR m_dateFilterField[64];
	_TCHAR m_dateFilterStart[64];
	_TCHAR m_dateMask[64];
};

#endif // !defined(AFX_PERSONGROUPENTRY_HPP__ED46595D_66F1_4535_B25C_330EA3969892__INCLUDED_)
