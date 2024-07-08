#include "ConfigIniFileIOPrivate.h"

#include "ConfigIniFileExporter/ConfigIniFileExporter.h"
#include "ConfigIniFileImporter/ConfigIniFileImporter.h"

namespace NCore
{
	CConfigIniFileIOPrivate::CConfigIniFileIOPrivate()
	{
		
	}

	CConfigIniFileIOPrivate::CConfigIniFileIOPrivate(const CConfigIniFileIOPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_pSettings(i_oOther.m_pSettings),
		m_pExporter(i_oOther.m_pExporter),
		m_pImporter(i_oOther.m_pImporter)
	{
		
	}

	CConfigIniFileIOPrivate::~CConfigIniFileIOPrivate()
	{
	}
}