#include "AppConfig.h"

namespace NCore
{
	CAppConfig::CAppConfig(const QString& i_sComponentID, std::shared_ptr<IConfigIO> i_pAppFileIO)
		: CComponentConfig(EComponentConfigType::CTAppConfig, std::make_shared<CConfigItem>(i_sComponentID, i_pAppFileIO)),
			m_pPrivate(new CAppConfigPrivate(this))
	{
	}

	CAppConfig::CAppConfig(CAppConfigPrivate* i_pPrivate, CComponentConfigPrivate* i_pComponentConfig)
		: m_pPrivate(i_pPrivate), CComponentConfig(i_pComponentConfig)
	{
	}

	QWidget* CAppConfig::widget() const
	{
		return nullptr;
	}
}