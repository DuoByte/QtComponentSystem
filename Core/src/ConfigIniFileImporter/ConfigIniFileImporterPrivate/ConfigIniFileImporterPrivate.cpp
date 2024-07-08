#include "ConfigIniFileImporterPrivate.h"

namespace NCore
{
	CConfigIniFileImporterPrivate::CConfigIniFileImporterPrivate()
	{
	}

	CConfigIniFileImporterPrivate::CConfigIniFileImporterPrivate(const CConfigIniFileImporterPrivate& i_oOther)
		: QSharedData(i_oOther), m_pSettings(i_oOther.m_pSettings)
	{
	}
}