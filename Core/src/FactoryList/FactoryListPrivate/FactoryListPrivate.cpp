#include "FactoryListPrivate.h"

namespace NCore
{
	CFactoryListPrivate::CFactoryListPrivate()
	{

	}

	CFactoryListPrivate::CFactoryListPrivate(const CFactoryListPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_apFactories(i_oOther.m_apFactories)
	{

	}
}