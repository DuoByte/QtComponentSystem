#include "HardwareConfigPrivate.h"
#include "ComponentInfo/ComponentInfo.h"

namespace NCore
{
	CHardwareConfigPrivate::CHardwareConfigPrivate(CComponentConfig* i_pConfig)
		: m_pComponentConfig(i_pConfig)
	{
	}

	CHardwareConfigPrivate::CHardwareConfigPrivate(const CHardwareConfigPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_pComponentConfig(i_oOther.m_pComponentConfig),
		m_pComponentInfo(i_oOther.m_pComponentInfo),
		m_aSubComponentConfigParameter(i_oOther.m_aSubComponentConfigParameter),
		m_pUseDummy(i_oOther.m_pUseDummy),
		m_pComponentType(i_oOther.m_pComponentType)
	{
	}

	void CHardwareConfigPrivate::initializeConfigParameter()
	{
		m_pComponentType = m_pComponentConfig->configItem()->addParameter("Component Type", "ComponentType", m_pComponentInfo->type());

		for (const auto& sSubComponent : m_pComponentInfo->requiredSubComponents())
		{
			auto pParamter = m_pComponentConfig->configItem()->addParameter(sSubComponent, "SubComponent/" + sSubComponent, "");
			m_aSubComponentConfigParameter[sSubComponent] = pParamter;
		}

		m_pUseDummy = m_pComponentConfig->configItem()->addParameter("Use Dummy", "UseDummy", false);
	}
}