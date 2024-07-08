#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorFileNotExists : public CException
	{
	public:
		CErrorFileNotExists(const QString& i_sFile, const QString& i_sLocation)
			: CException(EExceptionID::EFileNotExists, QString("File not exists: %1").arg(i_sFile), i_sLocation)
		{

		}

		~CErrorFileNotExists() override = default;

	public:
		OVERWRITE_CLONE(CErrorFileNotExists);
		OVERWRITE_RAISE();
	};
}