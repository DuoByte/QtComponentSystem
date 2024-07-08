#include "HardwareFile.h"
#include "Errors/ErrorFileNotExists.h"
#include "ConfigIniFileIO/ConfigIniFileIO.h"

#include <qfile.h>
#include <qdebug.h>

namespace NCore
{
	CHardwareFile::CHardwareFile(const QString& i_sFile)
		: m_pPrivate(new CHardwareFilePrivate)
	{
		m_pPrivate->m_sPath = i_sFile;

		QFile oFile(i_sFile);
		if (!oFile.exists())
			throw CErrorFileNotExists(i_sFile, ERROR_HERE);

		m_pPrivate->m_pSettings = std::make_shared<QSettings>(i_sFile, QSettings::Format::IniFormat);
	}
		
	CHardwareFile::CHardwareFile(const CHardwareFile& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{

	}

	CHardwareFile::CHardwareFile(CHardwareFilePrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{

	}

	QVector<CHardwareFile::SComponent> CHardwareFile::components() const
	{
		QVector<SComponent> aoRet;

		QStringList asComponents = m_pPrivate->m_pSettings->childGroups();
		for (const QString& sName : asComponents)
		{
			m_pPrivate->m_pSettings->beginGroup(sName);

			QString sType = m_pPrivate->m_pSettings->value("ComponentType", "").toString();
			if (sType.size() == 0)
			{
				qWarning() << "ComponentType is empty, invalid component!";
				continue;
			}

			aoRet.push_back(SComponent{ sName, sType });
			m_pPrivate->m_pSettings->endGroup();
		}

		return aoRet;
	}

	std::shared_ptr<IConfigIO> CHardwareFile::toConfigIO() const
	{
		return std::make_shared<CConfigIniFileIO>(m_pPrivate->m_sPath);
	}
}