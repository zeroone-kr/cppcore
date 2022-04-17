#pragma once

#include <string>
#include <vector>

#include "Interface.h"
#include "Pair.h"
#include "FmtTypes.h"
#include "IChannel.h"

namespace fmt_internal
{
	class CXMLSerializer_V2 : public core::IFormatterT
	{
		E_BOM_TYPE		m_nBOM;
		std::stack<std::tstring> m_stkElement;
		std::stack<sGroupingData> m_stkGroupingData;

		std::tstring	m_strRootTag;
		std::tstring	m_strRootAttr;

	public:
		CXMLSerializer_V2(core::IChannel& channel, E_BOM_TYPE nBOM, std::tstring strRoot, std::map<std::tstring, std::tstring>* pRootAttr);
		~CXMLSerializer_V2(void);

		bool			CheckValidity(std::tstring* pStrErrMsg)	{	return true;	}

	private:
		size_t			BeginDictionaryGrouping(std::tstring& strKey, const size_t tSize, bool bAllowMultiKey);
		void			EndDictionaryGrouping();

		size_t			BeginArrayGrouping(std::tstring& strKey, const size_t tSize);
		void			EndArrayGrouping();

		void			BeginObjectGrouping(std::tstring& strKey);
		void			EndObjectGrouping();

		void			BeginRootGrouping();
		void			EndRootGrouping();

		core::IFormatterT& Sync(std::tstring& strKey, std::tstring* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, std::ntstring* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, bool* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, char* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, short* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, int32_t* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, int64_t* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, BYTE* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, WORD* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, DWORD* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, QWORD* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, float* pValue);
		core::IFormatterT& Sync(std::tstring& strKey, double* pValue);
	};
}

