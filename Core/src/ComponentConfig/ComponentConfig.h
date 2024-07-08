#pragma once

#include "ComponentConfigPrivate/ComponentConfigPrivate.h"
#include "ComponentConfigType/ComponentConfigType.h"

namespace NCore
{
	class CComponentConfig
	{
		Q_DISABLE_COPY(CComponentConfig);

	public:
		CComponentConfig(const EComponentConfigType i_eType, std::shared_ptr<CConfigItem> i_pItem);

		CComponentConfig(CComponentConfigPrivate* i_pPrivate);

		virtual ~CComponentConfig() = default;

	public:
		EComponentConfigType type() const;

		std::shared_ptr<CConfigItem> configItem() const;

	private:
		CComponentConfigPrivate* m_pPrivate;
	};
}