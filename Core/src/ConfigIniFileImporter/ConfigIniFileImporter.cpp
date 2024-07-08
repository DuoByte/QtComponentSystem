#include "ConfigIniFileImporter.h"
#include "ConfigParameter/ConfigParameter.h"
#include "ConfigIOInterface/ConfigIOInterface.h"

namespace NCore
{
	CConfigIniFileImporter::CConfigIniFileImporter(std::shared_ptr<QSettings> i_pSettings)
		: m_pPrivate(new CConfigIniFileImporterPrivate)
	{
		m_pPrivate->m_pSettings = i_pSettings;
	}

	CConfigIniFileImporter::CConfigIniFileImporter(const CConfigIniFileImporter& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{
	}

	CConfigIniFileImporter::CConfigIniFileImporter(CConfigIniFileImporterPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}
	QVariant CConfigIniFileImporter::read(const QString& i_sGroup, std::shared_ptr<const CConfigParameter> i_pParameter, const QVariant& i_oDefaultValue)
	{
		m_pPrivate->m_pSettings->beginGroup(i_sGroup);
		QVariant oValue = m_pPrivate->m_pSettings->value(i_pParameter->key(), i_oDefaultValue);
		m_pPrivate->m_pSettings->endGroup();
		return oValue;
	}

	QVariant CConfigIniFileImporter::read(const QString& i_sGroup, const QString& i_sKey, const QVariant& i_oDefaultValue)
	{
		m_pPrivate->m_pSettings->beginGroup(i_sGroup);
		QVariant oValue = m_pPrivate->m_pSettings->value(i_sKey, i_oDefaultValue);
		m_pPrivate->m_pSettings->endGroup();
		return oValue;
	}
}