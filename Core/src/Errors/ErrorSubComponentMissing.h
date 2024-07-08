#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorSubComponentMissing : public CException
	{
	public:
		CErrorSubComponentMissing(const QString& i_sKey, const QString& i_sID, const QString& i_sLocation)
			: CException(EExceptionID::ESubComponentMissing, 
				QString("Subcomponent missing, type: %1 id: %2").arg(i_sKey).arg(i_sID), i_sLocation)
		{

		}

		~CErrorSubComponentMissing() override = default;

	public:
		OVERWRITE_CLONE(CErrorSubComponentMissing);
		OVERWRITE_RAISE();
	};
}