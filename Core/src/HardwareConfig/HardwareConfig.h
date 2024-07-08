#pragma once

#include "ComponentConfig/ComponentConfig.h"
#include "HardwareConfigPrivate/HardwareConfigPrivate.h"

namespace NCore
{
	class CComponentInfo;
	class CHardwareConfig : public CComponentConfig
	{
	public:
		Q_DISABLE_COPY(CHardwareConfig);

	public:
		CHardwareConfig(const QString& i_sComponentID, std::shared_ptr<const CComponentInfo> i_pComponentInfo,
			std::shared_ptr<IConfigIO> i_pHardwareFileIO);

		CHardwareConfig(CHardwareConfigPrivate* i_pPrivate, CComponentConfigPrivate* i_pComponentPrivate);

	public:
		bool validate() const;

		const QMap<QString, std::shared_ptr<CConfigParameter>>& subConfigParameterMap() const;

		bool useDummy() const;

		QString componentType() const;

		virtual QWidget* widget() const;

	private:
		QSharedDataPointer<CHardwareConfigPrivate> m_pPrivate;
	};
}