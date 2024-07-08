#include "MainInstance.h"

#include "Errors/ErrorSubComponentLinkingFailed.h"

#include <qdebug.h>

namespace NCore
{
	CMainInstance::CMainInstance(std::shared_ptr<CHardwareFile> i_pHardwareFile, std::shared_ptr<IConfigIO> i_pAppConfigIO)
		: m_pPrivate(new CMainInstancePrivate)
	{
		m_pPrivate->m_pHardwareFile = i_pHardwareFile;

		m_pPrivate->m_pHardwareConfigIO = i_pHardwareFile->toConfigIO();

		m_pPrivate->m_pAppConfigIO = i_pAppConfigIO;

		m_pPrivate->m_pFactoryList = std::make_shared<CFactoryList>(m_pPrivate->m_pHardwareConfigIO, i_pAppConfigIO);
	}
		
	CMainInstance::CMainInstance(CMainInstancePrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{

	}

	bool CMainInstance::load()
	{
		qInfo() << "Try to load MainInstance..";

		// Construct all components
		qInfo() << "Construct components!";
		m_pPrivate->m_pComponentList = m_pPrivate->m_pFactoryList->constructComponents(m_pPrivate->m_pHardwareFile);

		// Connect subcomponents
		qInfo() << "Try to connect components!";
		for (auto it = m_pPrivate->m_pComponentList->begin(); 
			it != m_pPrivate->m_pComponentList->end(); ++it)
		{
			m_pPrivate->connectSubComponents(*it);

			// Sub components check
			auto asRequiredSubComponents = (*it)->info()->requiredSubComponents();
			for (const auto& s : asRequiredSubComponents)
			{
				if (!(*it)->hasSubComponent(s))
					throw CErrorSubComponentLinkingFailed((*it)->info()->type(), (*it)->id(), ERROR_HERE);
			}
		}
		qInfo() << "Connect components successfully!";

		qInfo() << "Loading MainInstance successfully finished!";

		return true;
	}

	void CMainInstance::addFactory(std::shared_ptr<CBaseFactory> i_pFactory)
	{
		if (i_pFactory)
			m_pPrivate->m_pFactoryList->addFactory(i_pFactory);
	}

	std::shared_ptr<CComponentList> CMainInstance::componentList() const
	{
		return m_pPrivate->m_pComponentList;
	}

	std::shared_ptr<CFactoryList> CMainInstance::factoryList() const
	{
		return m_pPrivate->m_pFactoryList;
	}
}