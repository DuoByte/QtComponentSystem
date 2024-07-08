#include "ConfigIniFileExporterPrivate.h"

namespace NCore
{
	CConfigIniFileExporterPrivate::CConfigIniFileExporterPrivate()
	{
	}

	CConfigIniFileExporterPrivate::CConfigIniFileExporterPrivate(const CConfigIniFileExporterPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_pSettings(i_oOther.m_pSettings)
	{
	}
}