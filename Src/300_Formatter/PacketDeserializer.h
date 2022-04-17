#pragma once

#include <string>
#include <vector>

#include "Interface.h"
#include "Pair.h"
#include "FmtTypes.h"
#include "IChannel.h"
#include "HelperFunc.h"

namespace fmt_internal
{
	class CPacketDeserializer : public core::IFormatterT
	{
	private:
		bool			m_bValidity		;
		bool			m_bReserved[7]	;

	public:
						CPacketDeserializer(core::IChannel& channel);
						~CPacketDeserializer(void);

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
