#pragma once

#include <qshareddata.h>
#include <qvector.h>
#include <memory>

namespace NCore
{
	class IConfigIO;
	class CConfigParameter;
	class CConfigItemPrivate : public QSharedData
	{
	public:
		CConfigItemPrivate();

		CConfigItemPrivate(const CConfigItemPrivate& i_oOther);

		~CConfigItemPrivate() = default;

	public:
		QVector<std::shared_ptr<CConfigParameter>> m_apParameter;

		std::shared_ptr<IConfigIO> m_pConfigIO;

		QString m_sName;
	};
}