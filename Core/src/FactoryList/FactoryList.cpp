#include "FactoryList.h"
#include "Errors/ErrorNullptr.h"
#include "Errors/ErrorFactoryMissing.h"
#include "Errors/ErrorAlreadyContains.h"

#include <qdebug.h>

namespace NCore
{
	CFactoryList::CFactoryList(std::shared_ptr<IConfigIO> i_pHardwareConfigIO, std::shared_ptr<IConfigIO> i_pAppConfigIO)
		: m_pPrivate(new CFactoryListPrivate)
	{
		m_pPrivate->m_pHardwareConfigIO = i_pHardwareConfigIO;

		m_pPrivate->m_pAppConfigIO = i_pAppConfigIO;
	}
		
	CFactoryList::CFactoryList(const CFactoryList& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{

	}

	CFactoryList::CFactoryList(CFactoryListPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{

	}

	void CFactoryList::addFactory(std::shared_ptr<CBaseFactory> i_pFactory)
	{
		if (factory(i_pFactory->componentInfo()->type()))
			throw CErrorAlreadyContains("Factory already in list!", ERROR_HERE);

		m_pPrivate->m_apFactories.push_back(i_pFactory);
	}

	std::shared_ptr<CBaseFactory> CFactoryList::factory(const QString& i_sType) const
	{
		for (auto it = m_pPrivate->m_apFactories.begin(); it != m_pPrivate->m_apFactories.end(); ++it)
		{
			auto pComponentInfo = it->get()->componentInfo();
			if (!pComponentInfo)
				throw CErrorNullptr("ComponentInfo is nullptr", ERROR_HERE);

			if (pComponentInfo->type() == i_sType)
				return *it;
		}
		return nullptr;
	}

	std::shared_ptr<CComponentList> CFactoryList::constructComponents(std::shared_ptr<const CHardwareFile> i_pFile) const
	{
		auto pComponentList = std::make_shared<CComponentList>();

		auto aoHardwareComponents = i_pFile->components();
		for (const auto& oHardwareComponent : aoHardwareComponents)
		{
			if (pComponentList->component(oHardwareComponent.sID))
				throw CErrorAlreadyContains("Component ID already in list!", ERROR_HERE);

			auto pFactory = factory(oHardwareComponent.sType);
			if (!pFactory)
				throw CErrorFactoryMissing(oHardwareComponent.sType, ERROR_HERE);

			auto pComponent = pFactory->newComponent(oHardwareComponent.sID, m_pPrivate->m_pHardwareConfigIO, m_pPrivate->m_pAppConfigIO);
			if (!pComponent)
				throw CErrorNullptr("Factory return nullptr component!", ERROR_HERE);

			qDebug() << "New component constructed! Type: " << pComponent->info()->type() << " ID: " << pComponent->id();

			pComponentList->addComponent(pComponent);
		}

		return pComponentList;
	}
}