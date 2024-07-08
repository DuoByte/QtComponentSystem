#include "Component.h"

#include <qdebug.h>

namespace NCore
{
	CComponent::CComponent(const QString& i_sID,
		std::shared_ptr<const CComponentInfo> i_pComponentInfo)
		: m_pPrivate(new CComponentPrivate)
	{
		m_pPrivate->m_sID = i_sID;

		m_pPrivate->m_pComponentInfo = i_pComponentInfo;

		setFlag(EComponentFlag::SConstructed, true);
	}

	CComponent::CComponent(CComponentPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}

	std::shared_ptr<const CComponentInfo> CComponent::info() const
	{
		return m_pPrivate->m_pComponentInfo;
	}

	void CComponent::assignSubComponent(std::shared_ptr<const CComponent> i_pComponent)
	{
		qInfo() << "New SubComponent assigned! Component: (" << this->info()->type() << ", " << this->id() <<
			") SubComponent: (" << i_pComponent->info()->type() << ", " << i_pComponent->id() << ")";
		m_pPrivate->m_apSubComponents.push_back(i_pComponent);
	}

	void CComponent::assignSuperComponent(std::shared_ptr<const CComponent> i_pComponent)
	{
		qInfo() << "New SuperComponent assigned! Component: (" << this->info()->type() << ", " << this->id() <<
			") SuperComponent: (" << i_pComponent->info()->type() << ", " << i_pComponent->id() << ")";
		m_pPrivate->m_apSuperComponents.push_back(i_pComponent);
	}

	bool CComponent::hasSubComponent(const QString& i_sType)
	{
		for (auto pComponent : m_pPrivate->m_apSubComponents)
			if (pComponent->info()->type() == i_sType)
				return true;
		return false;
	}

	bool CComponent::hasFlag(const EComponentFlag i_eFlag) const
	{
		return m_pPrivate->m_eFlag.testFlag(i_eFlag);
	}

	void CComponent::setFlag(const EComponentFlag i_eFlag, bool i_fState)
	{
		m_pPrivate->m_eFlag.setFlag(i_eFlag, i_fState);
	}

	const QString& CComponent::id() const
	{
		return m_pPrivate->m_sID;
	}
}