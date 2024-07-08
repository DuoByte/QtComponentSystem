#include "HardwareConfig.h"
#include "ComponentInfo/ComponentInfo.h"
#include "ConfigParameter/ConfigParameter.h"

namespace NCore
{
	CHardwareConfig::CHardwareConfig(const QString& i_sComponentID, std::shared_ptr<const CComponentInfo> i_pComponentInfo,
		std::shared_ptr<IConfigIO> i_pHardwareFileIO)
		: CComponentConfig(EComponentConfigType::CTHardwareConfig, std::make_shared<CConfigItem>(i_sComponentID, i_pHardwareFileIO)),
		m_pPrivate(new CHardwareConfigPrivate(this))
	{
		m_pPrivate->m_pComponentInfo = i_pComponentInfo;

		m_pPrivate->initializeConfigParameter();
	}

	CHardwareConfig::CHardwareConfig(CHardwareConfigPrivate* i_pPrivate, CComponentConfigPrivate* i_pComponentPrivate)
		: m_pPrivate(i_pPrivate), CComponentConfig(i_pComponentPrivate)
	{
	}

	const QMap<QString, std::shared_ptr<CConfigParameter>>& CHardwareConfig::subConfigParameterMap() const
	{
		return m_pPrivate->m_aSubComponentConfigParameter;
	}

	bool CHardwareConfig::useDummy() const
	{
		return m_pPrivate->m_pUseDummy->value().toBool();
	}

	QString CHardwareConfig::componentType() const
	{
		return m_pPrivate->m_pComponentType->value().toString();
	}

	QWidget* CHardwareConfig::widget() const
	{
		return nullptr;
	}
}