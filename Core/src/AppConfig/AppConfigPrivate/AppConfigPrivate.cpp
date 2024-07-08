#include "AppConfigPrivate.h"

namespace NCore
{
	CAppConfigPrivate::CAppConfigPrivate(CComponentConfig* i_pComponentConfig)
		: m_pComponentConfig(i_pComponentConfig)
	{
	}

	CAppConfigPrivate::CAppConfigPrivate(const CAppConfigPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_pComponentConfig(i_oOther.m_pComponentConfig)
	{
	}
}