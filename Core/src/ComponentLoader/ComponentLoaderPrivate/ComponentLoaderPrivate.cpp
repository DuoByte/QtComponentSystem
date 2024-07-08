#include "ComponentLoaderPrivate.h"

namespace NCore
{
	CComponentLoaderPrivate::CComponentLoaderPrivate()
	{
	}

	CComponentLoaderPrivate::CComponentLoaderPrivate(const CComponentLoaderPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_pComponentList(i_oOther.m_pComponentList)
	{
	}
}