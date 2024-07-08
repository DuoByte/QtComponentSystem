#pragma once

#include <qshareddata.h>
#include <qsettings.h>

namespace NCore
{
	class CConfigIniFileExporterPrivate : public QSharedData
	{
	public:
		CConfigIniFileExporterPrivate();

		CConfigIniFileExporterPrivate(const CConfigIniFileExporterPrivate& i_oOther);

		~CConfigIniFileExporterPrivate() = default;

	public:
		std::shared_ptr<QSettings> m_pSettings;
	};
}