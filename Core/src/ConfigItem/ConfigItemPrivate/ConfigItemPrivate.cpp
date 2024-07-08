#include "ConfigItemPrivate.h"
#include "ConfigParameter/ConfigParameter.h"

#include "ConfigIOInterface/ConfigIOInterface.h"

namespace NCore
{
	CConfigItemPrivate::CConfigItemPrivate()
	{
	}

	CConfigItemPrivate::CConfigItemPrivate(const CConfigItemPrivate& i_oOther)
		: QSharedData(i_oOther), 
		m_apParameter(i_oOther.m_apParameter),
		m_pConfigIO(i_oOther.m_pConfigIO),
		m_sName(i_oOther.m_sName)
	{
	}
}