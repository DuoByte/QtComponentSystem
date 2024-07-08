#pragma once

#include <qvariant.h>
#include <memory>

namespace NCore
{
	class CConfigParameter;
	class IConfigImporter
	{
	public:
		virtual ~IConfigImporter() = default;

	public:
		virtual QVariant read(const QString& i_sGroup, std::shared_ptr<const CConfigParameter> i_pParameter, const QVariant& i_oDefaultValue) = 0;

		virtual QVariant read(const QString& i_sGroup, const QString& i_sKey, const QVariant& i_oDefaultValue) = 0;
	};
}