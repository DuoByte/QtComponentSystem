#pragma once

#include "ConfigIOInterface/ConfigIOInterface.h"

#include <qshareddata.h>
#include <qvariant.h>
#include <qstring.h>

namespace NCore
{
	class CConfigParameterPrivate : public QSharedData
	{
	public:
		CConfigParameterPrivate();

		CConfigParameterPrivate(const CConfigParameterPrivate& i_oOther);

		~CConfigParameterPrivate() = default;

	public:
		QString m_sDisplayName;

		QString m_sKey;

		QString m_sGroup;

		QVariant m_oValue;

		QVariant::Type m_eType;

		std::shared_ptr<IConfigIO> m_pConfigIO;
	};
}