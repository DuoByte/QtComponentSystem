#pragma once

#include "ConfigIniFileIOPrivate/ConfigIniFileIOPrivate.h"
#include "ConfigIOInterface/ConfigIOInterface.h"

#include <qstring.h>

namespace NCore
{
	class CConfigIniFileIO : public IConfigIO
	{
	public:
		CConfigIniFileIO(const QString& i_sFile);

		CConfigIniFileIO(const CConfigIniFileIO& i_oOther);

		CConfigIniFileIO(CConfigIniFileIOPrivate* i_pPrivate);

		~CConfigIniFileIO() = default;

	public:
		std::shared_ptr<IConfigExporter> exporter() const override;

		std::shared_ptr<IConfigImporter> importer() const override;

	private:
		QSharedDataPointer<CConfigIniFileIOPrivate> m_pPrivate;
	};
}