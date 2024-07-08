#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorFactoryMissing : public CException
	{
	public:
		CErrorFactoryMissing(const QString &i_sType, const QString & i_sLocation)
			: CException(EExceptionID::EFactoryMissing, QString("Factory missing for component type: %1").arg(i_sType), i_sLocation)
		{

		}

		~CErrorFactoryMissing() override = default;

	public:
		OVERWRITE_CLONE(CErrorFactoryMissing);
		OVERWRITE_RAISE();
	};
}