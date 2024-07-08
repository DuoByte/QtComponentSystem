#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorNullptr : public CException
	{
	public:
		CErrorNullptr(const QString& i_sMessage, const QString& i_sLocation)
			: CException(EExceptionID::ENullptr, i_sMessage, i_sLocation)
		{

		}

		~CErrorNullptr() override = default;

	public:
		OVERWRITE_CLONE(CErrorNullptr);
		OVERWRITE_RAISE();
	};
}