#pragma once

#include "BaseFactory/BaseFactory.h"
#include "../TestComponentBeta/TestComponentBeta.h"

namespace NCore
{
	class CTestFactoryBeta : public CBaseFactory
	{
	public:
		std::shared_ptr<CComponentInfo> componentInfo() const
		{
			return CTestComponentBeta::createComponentInfo();
		}

		std::shared_ptr<CComponent> newComponent(const QString& i_sID,
			std::shared_ptr<IConfigIO> i_pHardwareConfigIO,
			std::shared_ptr<IConfigIO> i_pAppConfigIO) const
		{
			return std::make_shared<CTestComponentBeta>(i_sID, i_pHardwareConfigIO);
		}

		std::shared_ptr<CComponent> newDummy(const QString& i_sID) const
		{
			return nullptr;
		}
	};
}