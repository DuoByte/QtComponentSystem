#pragma once

#include <qstring.h>
#include <qsharedpointer.h>

namespace NCore
{
	class CVersionPrivate : public QSharedData
	{
	public:
		CVersionPrivate();

		CVersionPrivate(const CVersionPrivate& i_oOther);

		~CVersionPrivate() = default;

	public:
		bool validVersionString(const QString& i_sVersion) const;

		bool fromString(const QString& i_sVersion);

	public:
		uint m_iMajor;

		uint m_iMinor;

		uint m_iMiner;

		bool m_fIsValid;
	};
}