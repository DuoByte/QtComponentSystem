#include "ComponentConfig.h"

namespace NCore
{
	CComponentConfig::CComponentConfig(const EComponentConfigType i_eType, std::shared_ptr<CConfigItem> i_pItem)
		: m_pPrivate(new CComponentConfigPrivate)
	{
		m_pPrivate->m_eType = i_eType;

		m_pPrivate->m_pConfigItem = i_pItem;

		
	}

	CComponentConfig::CComponentConfig(CComponentConfigPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}

	EComponentConfigType CComponentConfig::type() const
	{
		return m_pPrivate->m_eType;
	}

	std::shared_ptr<CConfigItem> CComponentConfig::configItem() const
	{
		return m_pPrivate->m_pConfigItem;
	}
}