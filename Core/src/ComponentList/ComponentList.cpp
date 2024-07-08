#include "ComponentList.h"

namespace NCore
{
	CComponentList::CComponentList()
		: m_pPrivate(new CComponentListPrivate)
	{

	}
		
	CComponentList::CComponentList(const CComponentList& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{

	}

	CComponentList::CComponentList(CComponentListPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{

	}

	void CComponentList::addComponent(std::shared_ptr<CComponent> i_pComponent)
	{
		m_pPrivate->m_apComponents.push_back(i_pComponent);
	}

	std::shared_ptr<CComponent> CComponentList::component(const QString& i_sID) const
	{
		for (auto p : m_pPrivate->m_apComponents)
		{
			if (p->id() == i_sID)
				return p;
		}
		// Throw exception?
		return nullptr;
	}
	std::shared_ptr<CComponent>* CComponentList::begin()
	{
		return m_pPrivate->m_apComponents.begin();
	}
	std::shared_ptr<CComponent>* CComponentList::end()
	{
		return m_pPrivate->m_apComponents.end();
	}
}