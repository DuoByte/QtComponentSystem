#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorNotImplemented : public CException
	{
	public:
		CErrorNotImplemented(const QString& i_sWhat, const QString& i_sLocation)
			: CException(EExceptionID::ENotImplemented, QString("Not implemented: %1").arg(i_sWhat), i_sLocation)
		{

		}
		~CErrorNotImplemented() override = default;

	public:
		OVERWRITE_CLONE(CErrorNotImplemented);
		OVERWRITE_RAISE();
	};
}