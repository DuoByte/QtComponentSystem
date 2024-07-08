#pragma once

#include "MainInstancePrivate/MainInstancePrivate.h"
#include "HardwareFile/HardwareFile.h"

namespace NCore
{
	class CMainInstance
	{
		Q_DISABLE_COPY(CMainInstance);
	public:
		CMainInstance(std::shared_ptr<CHardwareFile> i_pHardwareFile, std::shared_ptr<IConfigIO> i_pAppConfigIO);
		
		CMainInstance(CMainInstancePrivate* i_pPrivate);

		~CMainInstance() = default;

	public:
		bool load();

		void addFactory(std::shared_ptr<CBaseFactory> i_pFactory);

		std::shared_ptr<CComponentList> componentList() const;

		std::shared_ptr<CFactoryList> factoryList() const;

	private:
		QSharedDataPointer<CMainInstancePrivate> m_pPrivate;
	};
}