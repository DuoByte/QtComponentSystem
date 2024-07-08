#pragma once

#include "ConfigIOInterface/ConfigIOInterface.h"

#include <qshareddata.h>
#include <qsettings.h>

namespace NCore
{
	class CConfigIniFileImporter;
	class CConfigIniFileExporter;
	class CConfigIniFileIOPrivate : public QSharedData
	{
	public:
		CConfigIniFileIOPrivate();

		CConfigIniFileIOPrivate(const CConfigIniFileIOPrivate& i_oOther);

		~CConfigIniFileIOPrivate();

	public:
		QString m_sFile;

		std::shared_ptr<QSettings> m_pSettings;

		std::shared_ptr<CConfigIniFileExporter> m_pExporter;

		std::shared_ptr< CConfigIniFileImporter> m_pImporter;
	};
}