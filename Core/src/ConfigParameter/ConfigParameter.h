#pragma once

#include "ConfigParameterPrivate/ConfigParameterPrivate.h"
#include "ConfigIOInterface/ConfigIOInterface.h"

#include <qobject.h>

namespace NCore
{
	class CConfigParameter : public QObject
	{
		Q_OBJECT

	public:
		CConfigParameter(const QString& i_sDisplayName, const QString& i_sKey, const QVariant::Type i_eType,
			const QVariant& i_oValue, const QString& i_sGroup, std::shared_ptr<IConfigIO> i_pConfigIO);

		CConfigParameter(const CConfigParameter& i_oOther);

		CConfigParameter(CConfigParameterPrivate* i_pPrivate);

		~CConfigParameter() = default;

	public:
		const QString& displayName() const;

		const QString& key() const;

		const QVariant& value() const;

		void setValue(const QVariant& i_oValue);

		QVariant::Type type() const;

	signals:
		void onValueChanged();

	private:
		QSharedDataPointer<CConfigParameterPrivate> m_pPrivate;
	};
}