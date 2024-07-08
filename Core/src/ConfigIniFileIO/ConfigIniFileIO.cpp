#include "ConfigIniFileIO.h"
#include "ConfigIniFileExporter/ConfigIniFileExporter.h"
#include "ConfigIniFileImporter/ConfigIniFileImporter.h"

namespace NCore
{
	CConfigIniFileIO::CConfigIniFileIO(const QString& i_sFile)
		: m_pPrivate(new CConfigIniFileIOPrivate)
	{
		m_pPrivate->m_sFile = i_sFile;

		m_pPrivate->m_pSettings = std::make_shared<QSettings>(i_sFile, QSettings::Format::IniFormat);

		m_pPrivate->m_pExporter = std::make_shared<CConfigIniFileExporter>(m_pPrivate->m_pSettings);

		m_pPrivate->m_pImporter = std::make_shared<CConfigIniFileImporter>(m_pPrivate->m_pSettings);
	}

	CConfigIniFileIO::CConfigIniFileIO(const CConfigIniFileIO& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{
	}

	CConfigIniFileIO::CConfigIniFileIO(CConfigIniFileIOPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}

	std::shared_ptr<IConfigExporter> CConfigIniFileIO::exporter() const
	{
		return m_pPrivate->m_pExporter;
	}

	std::shared_ptr<IConfigImporter> CConfigIniFileIO::importer() const
	{
		return m_pPrivate->m_pImporter;
	}
}