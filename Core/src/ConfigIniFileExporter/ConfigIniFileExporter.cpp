#include "ConfigIniFileExporter.h"
#include "ConfigParameter/ConfigParameter.h"
#include "ConfigIOInterface/ConfigIOInterface.h"

namespace NCore
{
	CConfigIniFileExporter::CConfigIniFileExporter(std::shared_ptr<QSettings> i_pSettings)
		: m_pPrivate(new CConfigIniFileExporterPrivate)
	{
		m_pPrivate->m_pSettings = i_pSettings;
	}

	CConfigIniFileExporter::CConfigIniFileExporter(const CConfigIniFileExporter& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{
	}

	CConfigIniFileExporter::CConfigIniFileExporter(CConfigIniFileExporterPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}

	void CConfigIniFileExporter::write(const QString& i_sGroup, std::shared_ptr<const CConfigParameter> i_pParameter)
	{
		m_pPrivate->m_pSettings->beginGroup(i_sGroup);
		m_pPrivate->m_pSettings->setValue(i_pParameter->key(), i_pParameter->value());
		m_pPrivate->m_pSettings->endGroup();
	}

	void CConfigIniFileExporter::write(const QString& i_sGroup, const QString& i_sKey, const QVariant& i_oValue)
	{
		m_pPrivate->m_pSettings->beginGroup(i_sGroup);
		m_pPrivate->m_pSettings->setValue(i_sKey, i_oValue);
		m_pPrivate->m_pSettings->endGroup();
		m_pPrivate->m_pSettings->sync();
	}
}