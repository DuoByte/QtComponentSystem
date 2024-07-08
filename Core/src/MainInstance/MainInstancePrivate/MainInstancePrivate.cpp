#include "MainInstancePrivate.h"
#include "Errors/ErrorNullptr.h"
#include "ConfigParameter/ConfigParameter.h"
#include "Errors/ErrorSubComponentMissing.h"
#include "Errors/ErrorWrongComponent.h"
#include "Errors/ErrorCompareFailed.h"

#include <qdebug.h>

namespace NCore
{
	CMainInstancePrivate::CMainInstancePrivate()
	{

	}

	CMainInstancePrivate::CMainInstancePrivate(const CMainInstancePrivate& i_oOther)
		: QSharedData(i_oOther),
		m_pFactoryList(i_oOther.m_pFactoryList),
		m_pComponentList(i_oOther.m_pComponentList),
		m_pHardwareConfigIO(i_oOther.m_pHardwareConfigIO),
		m_pAppConfigIO(i_oOther.m_pAppConfigIO),
		m_pHardwareFile(i_oOther.m_pHardwareFile)
	{

	}

	void CMainInstancePrivate::connectSubComponents(std::shared_ptr<CComponent> i_pComponent)
	{
		if (!m_pComponentList)
			throw CErrorNullptr("ComponentList is nullptr!", ERROR_HERE);

		auto asRequierdSubComponents = i_pComponent->info()->requiredSubComponents();

		for (const auto& sType : asRequierdSubComponents)
		{
			QString sComponentID = i_pComponent->hardwareConfig()->subConfigParameterMap()[sType]->value().toString();
			auto pSubComponent = m_pComponentList->component(sComponentID);
			if (!pSubComponent)
				throw CErrorSubComponentMissing(sType, sComponentID, ERROR_HERE);

			if (QString("%1.%2").arg(pSubComponent->info()->module()).arg(pSubComponent->info()->interface()) == sType ||
				pSubComponent->info()->type() == sType)
			{
				qInfo() << QString("Sign Subcomponent (%1, %2) to Component (%3, %4)")
					.arg(sType)
					.arg(sComponentID)
					.arg(i_pComponent->info()->key())
					.arg(i_pComponent->id());

				if (!pSubComponent->info()->qtVersion().isSame(i_pComponent->info()->qtVersion()))
				{
					throw CErrorCompareFailed(pSubComponent->info()->qtVersion().asString(),
						i_pComponent->info()->qtVersion().asString(), ERROR_HERE);
				}

				i_pComponent->assignSubComponent(pSubComponent);
				pSubComponent->assignSuperComponent(i_pComponent);
			}
			else
			{
				throw CErrorWrongComponent(sType, pSubComponent->info()->key(), ERROR_HERE);
			}
		}

		i_pComponent->setFlag(EComponentFlag::SAllSubComponentsLoaded, true);
	}
}