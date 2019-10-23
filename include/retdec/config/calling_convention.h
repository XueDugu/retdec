/**
 * @file include/retdec/config/calling_convention.h
 * @brief Decompilation configuration manipulation: calling convention.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#ifndef RETDEC_CONFIG_CALLING_CONVENTION_H
#define RETDEC_CONFIG_CALLING_CONVENTION_H

#include <string>

#include "retdec/config/base.h"

namespace retdec {
namespace config {

/**
 * Represents functions' calling conventions.
 * It supports the same calling convention types as IDA Pro.
 * Convenient query methods are provided to get and set all conventions.
 */
class CallingConvention
{
	public:
		CallingConvention();

		/// @name Calling convention named constructors.
		/// @{
		static CallingConvention initVoidarg();
		static CallingConvention initCdecl();
		static CallingConvention initEllipsis();
		static CallingConvention initStdcall();
		static CallingConvention initPascal();
		static CallingConvention initFastcall();
		static CallingConvention initThiscall();
		static CallingConvention initManual();
		static CallingConvention initSpoiled();
		static CallingConvention initSpecialE();
		static CallingConvention initSpecialP();
		static CallingConvention initSpecial();
		/// @}

		/// @name Calling convention query methods.
		/// @{
		bool isUnknown() const;
		bool isKnown() const;
		bool isVoidarg() const;
		bool isCdecl() const;
		bool isEllipsis() const;
		bool isStdcall() const;
		bool isPascal() const;
		bool isFastcall() const;
		bool isThiscall() const;
		bool isManual() const;
		bool isSpoiled() const;
		bool isSpecialE() const;
		bool isSpecialP() const;
		bool isSpecial() const;
		/// @}

		/// @name Calling convention set methods.
		/// @{
		void setIsUnknown();
		void setIsVoidarg();
		void setIsCdecl();
		void setIsEllipsis();
		void setIsStdcall();
		void setIsPascal();
		void setIsFastcall();
		void setIsThiscall();
		void setIsManual();
		void setIsSpoiled();
		void setIsSpecialE();
		void setIsSpecialP();
		void setIsSpecial();
		/// @}

		bool operator<(const CallingConvention& cc) const;
		friend std::ostream& operator<< (std::ostream &out, const CallingConvention& cc);

		Json::Value getJsonValue() const;
		void readJsonValue(const Json::Value& val);

	public:
		enum class eCallingConvention
		{
			CC_UNKNOWN = 0,
			CC_VOIDARG,
			CC_CDECL,
			CC_ELLIPSIS,
			CC_STDCALL,
			CC_PASCAL,
			CC_FASTCALL,
			CC_THISCALL,
			CC_MANUAL,
			CC_SPOILED,
			CC_SPECIALE,
			CC_SPECIALP,
			CC_SPECIAL,
			CC_WATCOM,
			CC_X64,
			CC_ARM,
			CC_ARM64,
			CC_MIPS,
			CC_MIPS64,
			CC_POWERPC,
			CC_POWERPC64,
			CC_PIC32,
			CC_ENDING,
		};

		eCallingConvention getID() const;

		friend std::ostream& operator<< (std::ostream &out, const eCallingConvention& cc);
		CallingConvention& operator=(const eCallingConvention& cc);

	private:
		CallingConvention(eCallingConvention cc);

	private:
		eCallingConvention _callingConvention = eCallingConvention::CC_UNKNOWN;
};

typedef CallingConvention::eCallingConvention CallingConventionID;

} // namespace config
} // namespace retdec

#endif
