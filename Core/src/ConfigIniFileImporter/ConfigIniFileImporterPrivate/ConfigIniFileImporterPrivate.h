#pragma once

#include <qshareddata.h>
#include <qsettings.h>

namespace NCore
{
	class CConfigIniFileImporterPrivate : public QSharedData
	{
	public:
		CConfigIniFileImporterPrivate();

		CConfigIniFileImporterPrivate(const CConfigIniFileImporterPrivate& i_oOther);

		~CConfigIniFileImporterPrivate() = default;

	public:
		std::shared_ptr<QSettings> m_pSettings;
	};
}