#pragma once

#include "ConfigIniFileExporterPrivate/ConfigIniFileExporterPrivate.h"
#include "ConfigExporterInterface/ConfigExporterInterface.h"

#include <qsettings.h>

namespace NCore
{
	class CConfigParameter;
	class CConfigIniFileExporter : public IConfigExporter
	{
	public:
		CConfigIniFileExporter(std::shared_ptr<QSettings> i_pSettings);

		CConfigIniFileExporter(const CConfigIniFileExporter& i_oOther);

		CConfigIniFileExporter(CConfigIniFileExporterPrivate* i_pPrivate);

		~CConfigIniFileExporter() override = default;

	public:
		void write(const QString& i_sGroup, std::shared_ptr<const CConfigParameter> i_pParameter) override;

		void write(const QString& i_sGroup, const QString& i_sKey, const QVariant& i_oValue) override;

	private:
		QSharedDataPointer<CConfigIniFileExporterPrivate> m_pPrivate;
	};
}