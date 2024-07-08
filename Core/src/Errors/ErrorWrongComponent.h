#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorWrongComponent : public CException
	{
	public:
		CErrorWrongComponent(const QString& i_sExpectedKey, const QString& i_sKeyGot, const QString& i_sLocation)
			: CException(EExceptionID::EWrongComponent, QString("Wrong component! Expected Key: %1 Got key: %2")
				.arg(i_sExpectedKey)
				.arg(i_sKeyGot), i_sLocation)
		{

		}

		~CErrorWrongComponent() override = default;

	public:
		OVERWRITE_CLONE(CErrorWrongComponent);
		OVERWRITE_RAISE();
	};
}