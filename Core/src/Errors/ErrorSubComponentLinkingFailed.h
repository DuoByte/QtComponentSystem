#pragma once

#include "Exception/Exception.h"

namespace NCore
{
	class CErrorSubComponentLinkingFailed : public CException
	{
	public:
		CErrorSubComponentLinkingFailed(const QString& i_sParentComponentType, const QString& i_sParentComponentID, const QString& i_sLocation)
			: CException(EExceptionID::ESubComponentLinkingFailed, 
				QString("SubComponent linking failed for: (%1, %2)").arg(i_sParentComponentType, i_sParentComponentID), i_sLocation)
		{

		}

		~CErrorSubComponentLinkingFailed() override = default;
	public:
		OVERWRITE_CLONE(CErrorSubComponentLinkingFailed);
		OVERWRITE_RAISE();
	};
}