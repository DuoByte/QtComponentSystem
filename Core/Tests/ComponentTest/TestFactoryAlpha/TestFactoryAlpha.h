#pragma once

#include "BaseFactory/BaseFactory.h"
#include "../TestComponentAlpha/TestComponentAlpha.h"

namespace NCore
{
	class CTestFactoryAlpha : public CBaseFactory
	{
	public:
		std::shared_ptr<CComponentInfo> componentInfo() const
		{
			return CTestComponentAlpha::createComponentInfo();
		}

		std::shared_ptr<CComponent> newComponent(const QString& i_sID,
			std::shared_ptr<IConfigIO> i_pHardwareConfigIO,
			std::shared_ptr<IConfigIO> i_pAppConfigIO) const
		{
			return std::make_shared<CTestComponentAlpha>(i_sID, i_pHardwareConfigIO);

		}

		std::shared_ptr<CComponent> newDummy(const QString& i_sID) const
		{
			return nullptr;
		}
	};
}