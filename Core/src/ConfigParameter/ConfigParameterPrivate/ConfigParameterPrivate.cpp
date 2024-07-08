#include "ConfigParameterPrivate.h"

namespace NCore
{
	CConfigParameterPrivate::CConfigParameterPrivate()
	{
	}

	CConfigParameterPrivate::CConfigParameterPrivate(const CConfigParameterPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_sDisplayName(i_oOther.m_sDisplayName),
		m_sKey(i_oOther.m_sKey),
		m_oValue(i_oOther.m_oValue),
		m_eType(i_oOther.m_eType),
		m_pConfigIO(i_oOther.m_pConfigIO)
	{
	}
}