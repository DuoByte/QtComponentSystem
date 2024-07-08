#pragma once

#include "Component/Component.h"
#include "ComponentInfo/ComponentInfo.h"

namespace NCore
{
	class CBaseFactory
	{
	public:
		CBaseFactory() = default;

		virtual ~CBaseFactory() = default;

	public:
		virtual std::shared_ptr<CComponentInfo> componentInfo() const = 0;

		virtual std::shared_ptr<CComponent> newComponent(const QString& i_sID, 
			std::shared_ptr<IConfigIO> i_pHardwareConfigIO, 
			std::shared_ptr<IConfigIO> i_pAppConfigIO) const = 0;

		virtual std::shared_ptr<CComponent> newDummy(const QString& i_sID) const = 0;
	};
}