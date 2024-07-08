#pragma once

#include "FactoryListPrivate/FactoryListPrivate.h"
#include "ComponentList/ComponentList.h"
#include "HardwareFile/HardwareFile.h"

namespace NCore
{
	class CFactoryList
	{
	public:
		CFactoryList(std::shared_ptr<IConfigIO> i_pHardwareConfigIO, std::shared_ptr<IConfigIO> i_pAppConfigIO);
		
		CFactoryList(const CFactoryList& i_oOther);

		CFactoryList(CFactoryListPrivate* i_pPrivate);

		~CFactoryList() = default;

	public:
		void addFactory(std::shared_ptr<CBaseFactory> i_pFactory);

		std::shared_ptr<CBaseFactory> factory(const QString& i_sType) const;

		std::shared_ptr<CComponentList> constructComponents(std::shared_ptr<const CHardwareFile> i_pFile) const;

	private:
		QSharedDataPointer<CFactoryListPrivate> m_pPrivate;
	};
}