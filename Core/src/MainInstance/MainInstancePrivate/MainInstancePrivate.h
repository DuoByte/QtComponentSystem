#pragma once

#include "FactoryList/FactoryList.h"
#include "ConfigIOInterface/ConfigIOInterface.h"

#include <qshareddata.h>

namespace NCore
{
	class CMainInstancePrivate : public QSharedData
	{
	public:
		CMainInstancePrivate();

		CMainInstancePrivate(const CMainInstancePrivate& i_oOther);

		~CMainInstancePrivate() = default;

	public:
		void connectSubComponents(std::shared_ptr<CComponent> i_pComponent);

	public:
		std::shared_ptr<CFactoryList> m_pFactoryList;

		std::shared_ptr<CComponentList> m_pComponentList;

		std::shared_ptr<IConfigIO> m_pHardwareConfigIO;

		std::shared_ptr<IConfigIO> m_pAppConfigIO;

		std::shared_ptr<CHardwareFile> m_pHardwareFile;
	};
}