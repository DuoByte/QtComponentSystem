#include "ComponentListPrivate.h"

namespace NCore
{
	CComponentListPrivate::CComponentListPrivate()
	{
		
			
	}

	CComponentListPrivate::CComponentListPrivate(const CComponentListPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_apComponents(i_oOther.m_apComponents)
	{

	}
}