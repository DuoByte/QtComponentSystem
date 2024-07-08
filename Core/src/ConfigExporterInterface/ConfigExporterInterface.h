#pragma once

#include <QString>
#include <qvariant.h>

namespace NCore
{
	class CConfigParameter;
	class IConfigExporter
	{
	public:
		virtual ~IConfigExporter() = default;

	public:
		virtual void write(const QString& i_sGroup, std::shared_ptr<const CConfigParameter> i_pParameter) = 0;

		virtual void write(const QString& i_sGroup, const QString& i_sKey, const QVariant& i_oValue) = 0;
	};
}