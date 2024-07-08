#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorAlreadyContains : public CException
	{
	public:
		CErrorAlreadyContains(const QString& i_sWhat, const QString& i_sLocation)
			: CException(EExceptionID::EAlreadyContains, i_sWhat, i_sLocation)
		{

		}
		~CErrorAlreadyContains() override = default;

	public:
		OVERWRITE_CLONE(CErrorAlreadyContains);
		OVERWRITE_RAISE();
	};
}