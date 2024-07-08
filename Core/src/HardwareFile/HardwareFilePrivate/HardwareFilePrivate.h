#pragma once

#include <qshareddata.h>
#include <qsettings.h>

namespace NCore
{
	class CHardwareFilePrivate : public QSharedData
	{
	public:
		CHardwareFilePrivate();

		CHardwareFilePrivate(const CHardwareFilePrivate& i_oOther);

		~CHardwareFilePrivate() = default;

	public:
		std::shared_ptr<QSettings> m_pSettings;

		QString m_sPath;
	};
}