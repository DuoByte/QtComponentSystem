#include "ComponentConfigPrivate.h"

namespace NCore
{
	CComponentConfigPrivate::CComponentConfigPrivate()
	{
	}

	CComponentConfigPrivate::CComponentConfigPrivate(const CComponentConfigPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_pConfigItem(i_oOther.m_pConfigItem),
		m_eType(i_oOther.m_eType)
	{
	}
}