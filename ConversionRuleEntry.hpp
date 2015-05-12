// ConversionRuleEntry.hpp: interface for the CConversionRuleEntry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONVERSIONRULEENTRY_HPP__B3F6DAC4_8A9D_4BC3_8DE7_3BA1D7FFA951__INCLUDED_)
#define AFX_CONVERSIONRULEENTRY_HPP__B3F6DAC4_8A9D_4BC3_8DE7_3BA1D7FFA951__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef NDIRXML_EXPORTS
#define NDIRXML_API __declspec(dllexport)
#else
#define NDIRXML_API __declspec(dllimport)
#endif

class CConversionRuleEntry  
{
public:
	CConversionRuleEntry();
	virtual ~CConversionRuleEntry();

	// Get/Set m_input
	NDIRXML_API _TCHAR const * GetInput();
	NDIRXML_API void SetInput(const _TCHAR *input);

	// Get/Set m_output
	NDIRXML_API _TCHAR const * GetOutput();
	NDIRXML_API void SetOutput(const _TCHAR *output);

	NDIRXML_API bool IsDefault();
	NDIRXML_API void SetDefault(bool def);

protected:
	_TCHAR m_input[256];
	_TCHAR m_output[256];
	bool m_def;
};

#endif // !defined(AFX_CONVERSIONRULEENTRY_HPP__B3F6DAC4_8A9D_4BC3_8DE7_3BA1D7FFA951__INCLUDED_)
