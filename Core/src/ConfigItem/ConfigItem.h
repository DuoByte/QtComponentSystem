#pragma once

#include "ConfigItemPrivate/ConfigItemPrivate.h"

#include <qvariant.h>

namespace NCore
{
	class IConfigIO;
	class CConfigItem 
	{
	public:
		CConfigItem(const QString& i_sName, std::shared_ptr<IConfigIO> i_pConfigIO);

		CConfigItem(const CConfigItem& i_oOther);

		CConfigItem(CConfigItemPrivate* i_pPrivate);

		~CConfigItem() = default;

	public:
		std::shared_ptr<CConfigParameter> addParameter(const QString& i_sDisplayName, const QString& i_sKey, const QVariant& i_oDefaultValue);

		bool hasParameter(const QString& i_sKey) const;

		void removeParameter(const QString& i_sKey);

		std::shared_ptr<CConfigParameter> parameter(const QString& i_sKey) const;

		const QVector<std::shared_ptr<CConfigParameter>>& parameters() const;

		const QString& name() const;

	private:
		QSharedDataPointer<CConfigItemPrivate> m_pPrivate;
	};
}