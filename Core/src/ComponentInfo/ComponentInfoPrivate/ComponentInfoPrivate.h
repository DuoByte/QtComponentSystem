#pragma once

#include "Version/Version.h"

#include <qsharedpointer.h>
#include <qstringlist.h>

namespace NCore
{
	class CComponentInfo;
	class CComponentInfoPrivate : public QSharedData
	{
	public:
		CComponentInfoPrivate();

		CComponentInfoPrivate(const CComponentInfoPrivate& i_oOther);

		~CComponentInfoPrivate() = default;

	public:
		CVersion m_oVersion;

		CVersion m_oQtVersion;

		QString m_sQtCompiler;

		QString m_sModule;

		QString m_sKey;

		QStringList m_asRequiredSubComponents;

		QString m_sInterface;

		QString m_sDescription;

		unsigned int m_iMaxParents;
	};
}