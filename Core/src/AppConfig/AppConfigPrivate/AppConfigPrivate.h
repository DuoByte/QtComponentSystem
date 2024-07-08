#pragma once

#include "ComponentConfig/ComponentConfig.h"

#include <qshareddata.h>

namespace NCore
{
	class CAppConfigPrivate : public QSharedData
	{
	public:
		CAppConfigPrivate(CComponentConfig* i_pComponentConfig);

		CAppConfigPrivate(const CAppConfigPrivate& i_oOther);

		~CAppConfigPrivate() = default;

	private:
		CComponentConfig* m_pComponentConfig;
	};
}