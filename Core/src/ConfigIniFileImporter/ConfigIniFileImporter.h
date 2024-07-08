#pragma once

#include "ConfigImporterInterface/ConfigImporterInterface.h"
#include "ConfigIniFileImporterPrivate/ConfigIniFileImporterPrivate.h"

#include <qsettings.h>

namespace NCore
{
	class CConfigIniFileImporter : public IConfigImporter
	{
	public:
		CConfigIniFileImporter(std::shared_ptr<QSettings> i_pSettings);

		CConfigIniFileImporter(const CConfigIniFileImporter& i_oOther);

		CConfigIniFileImporter(CConfigIniFileImporterPrivate* i_pPrivate);

		~CConfigIniFileImporter() = default;

	public:
		QVariant read(const QString& i_sGroup, std::shared_ptr<const CConfigParameter> i_pParameter, const QVariant& i_oDefaultValue) override;

		QVariant read(const QString& i_sGroup, const QString& i_sKey, const QVariant& i_oDefaultValue) override;

	private:
		QSharedDataPointer<CConfigIniFileImporterPrivate> m_pPrivate;
	};
}