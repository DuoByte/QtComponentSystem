#pragma once

#include "ConfigExporterInterface/ConfigExporterInterface.h"
#include "ConfigImporterInterface/ConfigImporterInterface.h"

#include <memory>

namespace NCore
{
	class IConfigIO
	{
	public:
		virtual ~IConfigIO() = default;
		
	public:
		virtual std::shared_ptr<IConfigExporter> exporter() const = 0;

		virtual std::shared_ptr<IConfigImporter> importer() const = 0;
	};
}