#pragma once

#include "AppConfigPrivate/AppConfigPrivate.h"
#include "ComponentConfig/ComponentConfig.h"

namespace NCore
{
	class CAppConfig : public CComponentConfig
	{
		Q_DISABLE_COPY(CAppConfig);

	public:
		CAppConfig(const QString& i_sComponentID, std::shared_ptr<IConfigIO> i_pAppFileIO);

		CAppConfig(CAppConfigPrivate* i_pPrivate, CComponentConfigPrivate* i_pComponentConfig);

		virtual ~CAppConfig() = default;

	public:
		virtual QWidget* widget() const;

	private:
		QSharedDataPointer<CAppConfigPrivate> m_pPrivate;
	};
}