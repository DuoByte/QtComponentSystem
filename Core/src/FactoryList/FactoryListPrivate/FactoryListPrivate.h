#pragma once

#include "BaseFactory/BaseFactory.h"

#include <qvector.h>
#include <qshareddata.h>

namespace NCore
{
	class CFactoryListPrivate : public QSharedData
	{
	public:
		CFactoryListPrivate();

		CFactoryListPrivate(const CFactoryListPrivate& i_oOther);

		~CFactoryListPrivate() = default;

	public:
		QVector<std::shared_ptr<CBaseFactory>> m_apFactories;

		std::shared_ptr<IConfigIO> m_pHardwareConfigIO;

		std::shared_ptr<IConfigIO> m_pAppConfigIO;
	};
}