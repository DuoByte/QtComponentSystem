#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorCompareFailed : public CException
	{
	public:
		CErrorCompareFailed(const QString& i_s1, const QString& i_s2, const QString& i_sLocation)
			: CException(EExceptionID::ECompareFailed, QString("Compare failed! Compared %1 with %2").arg(i_s1).arg(i_s2), i_sLocation)
		{

		}

		~CErrorCompareFailed() override = default;

	public:
		OVERWRITE_CLONE(CErrorCompareFailed);
		OVERWRITE_RAISE();
	}; 
}