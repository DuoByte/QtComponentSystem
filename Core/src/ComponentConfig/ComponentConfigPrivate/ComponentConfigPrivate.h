#pragma once

#include "ConfigItem/ConfigItem.h"
#include "ComponentConfigType/ComponentConfigType.h"

#include <qsharedpointer.h>
#include <qvariant.h>
#include <qmap.h>
#include <qvector.h>

namespace NCore
{
	class CComponentConfigPrivate : public QSharedData
	{
	public:
		CComponentConfigPrivate();

		CComponentConfigPrivate(const CComponentConfigPrivate& i_oOther);

		~CComponentConfigPrivate() = default;

	public:
		std::shared_ptr<CConfigItem> m_pConfigItem;

		EComponentConfigType m_eType;
	};
}