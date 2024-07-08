#pragma once

#include "Component/Component.h"

namespace NCore
{
	class CTestComponentAlpha : public CComponent
	{
	public:
		CTestComponentAlpha(const QString& i_sID, std::shared_ptr<IConfigIO> i_pHardwareConfig)
			: CComponent(i_sID, createComponentInfo())
		{
			m_pHardwareConfig = std::make_shared<CHardwareConfig>(this->id(), this->info(), i_pHardwareConfig);
		}

	public:
		static std::shared_ptr<CComponentInfo> createComponentInfo()
		{
			return std::make_shared<CComponentInfo>("Test", "Alpha", CVersion("1.0.0"), QStringList() << "Test.Beta");
		}

	public:
		std::shared_ptr<CHardwareConfig> hardwareConfig() const override
		{
			return m_pHardwareConfig;
		}

		std::shared_ptr<CAppConfig> appConfig() const override
		{
			return nullptr;
		}

		std::shared_ptr<CComponentLogic> logic() const override
		{
			return nullptr;
		}

	private:
		std::shared_ptr<CHardwareConfig> m_pHardwareConfig;
	};
}