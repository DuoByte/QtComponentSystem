#pragma once

#include "Exception/Exception.h"

#include <qvariant.h>

namespace NCore
{
	class CErrorInvalidConfigValueType : public CException
	{
	public:
		CErrorInvalidConfigValueType(QVariant::Type i_eExpected, QVariant::Type i_eGot, const QString& i_sLocation)
			: CException(EExceptionID::EInvalidConfigValueType, 
				QString("Invalid config value type: Expected Type: %1 Type got: %2")
				.arg(i_eExpected)
				.arg(i_eGot), 
				i_sLocation)
		{

		}
		~CErrorInvalidConfigValueType() override = default;

	public:
		OVERWRITE_CLONE(CErrorInvalidConfigValueType);
		OVERWRITE_RAISE();
	};
}