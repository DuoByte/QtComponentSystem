#pragma once

#include "ComponentConfig/ComponentConfig.h"

#include <qshareddata.h>
#include <qmap.h>
#include <qstring.h>

namespace NCore
{
	class CComponentInfo;
	class CHardwareConfigPrivate : public QSharedData
	{
	public:
		CHardwareConfigPrivate(CComponentConfig* i_pConfig);

		CHardwareConfigPrivate(const CHardwareConfigPrivate& i_oOther);

		~CHardwareConfigPrivate() = default;

	public:
		void initializeConfigParameter();

	public:
		CComponentConfig* m_pComponentConfig;

		std::shared_ptr<const CComponentInfo> m_pComponentInfo;

		QMap<QString, std::shared_ptr<CConfigParameter>> m_aSubComponentConfigParameter;

		std::shared_ptr<CConfigParameter> m_pUseDummy;

		std::shared_ptr<CConfigParameter> m_pComponentType;
	};
}