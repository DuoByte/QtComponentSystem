#include "ComponentLoader.h"

namespace NCore
{
	CComponentLoader::CComponentLoader(std::shared_ptr<CComponentList> i_pComponentList)
		: m_pPrivate(new CComponentLoaderPrivate)
	{
		m_pPrivate->m_pComponentList = i_pComponentList;
	}

	CComponentLoader::CComponentLoader(CComponentLoaderPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}
}