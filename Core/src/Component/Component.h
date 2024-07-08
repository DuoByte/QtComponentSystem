#pragma once

#include "ComponentPrivate/ComponentPrivate.h"
#include "ComponentInfo/ComponentInfo.h"
#include "ComponentLogic/ComponentLogic.h"

#include <qflags.h>

namespace NCore
{
	class CComponent
	{
		Q_DISABLE_COPY(CComponent);

	public:
		CComponent(const QString& i_sID, std::shared_ptr<const CComponentInfo> i_pComponentInfo);

		CComponent(CComponentPrivate* i_pPrivate);

		virtual ~CComponent() = default;

	public:
		std::shared_ptr<const CComponentInfo> info() const;

		void assignSubComponent(std::shared_ptr<const CComponent> i_pComponent);

		void assignSuperComponent(std::shared_ptr<const CComponent> i_pComponent);

		bool hasSubComponent(const QString& i_sType);

		bool hasFlag(const EComponentFlag i_eFlag) const;

		void setFlag(const EComponentFlag i_eFlag, bool i_fState);

		const QString& id() const;

	public:
		virtual std::shared_ptr<CHardwareConfig> hardwareConfig() const = 0;

		virtual std::shared_ptr<CAppConfig> appConfig() const = 0;

		virtual std::shared_ptr<CComponentLogic> logic() const = 0;

	public:


	private:
		QSharedDataPointer<CComponentPrivate> m_pPrivate;
	};
}