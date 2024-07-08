#include "HardwareFilePrivate.h"

namespace NCore
{
	CHardwareFilePrivate::CHardwareFilePrivate()
	{

	}

	CHardwareFilePrivate::CHardwareFilePrivate(const CHardwareFilePrivate& i_oOther)
		: QSharedData(i_oOther),
		m_pSettings(i_oOther.m_pSettings),
		m_sPath(i_oOther.m_sPath)
	{

	}
}