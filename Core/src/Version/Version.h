#pragma once

#include "VersionPrivate/VersionPrivate.h"

#include <qstring.h>
#include <memory>

namespace NCore
{
	class CVersion
	{
	public:
		CVersion();

		CVersion(const QString& i_sVersion);

		CVersion(const uint i_iMajor, const uint i_iMinor, const uint i_iMiner);

		CVersion(const CVersion& i_oOther);

		CVersion(CVersionPrivate* i_pPrivate);

	public:
		QString asString() const;

		bool isValid() const;

		uint major() const;

		uint minor() const;

		uint miner() const;

		bool isSame(const CVersion& i_oVersion) const;

		bool isSame(const QString& i_sVersion) const;

		bool isHigherThan(const CVersion& i_oVersion) const;

		bool isLowerThan(const CVersion& i_oVersion) const;

		void increaseMajor(const int i_iAmount = 1);

		void increaseMinor(const int i_iAmount = 1);

		void increaseMiner(const int i_iAmount = 1);

		void decreaseMajor(const int i_iAmount = 1);

		void decreaseMinor(const int i_iAmount = 1);

		void decreaseMiner(const int i_iAmount = 1);

		void setMajor(const int i_iMajor);

		void setMinor(const int i_iMinor);

		void setMiner(const int i_iMiner);

	public:
		bool operator==(const CVersion& i_oVersion) const;

		bool operator>(const CVersion& i_oVersion) const;

		bool operator<(const CVersion& i_oVersion) const;

	private:
		QSharedDataPointer<CVersionPrivate> m_pPrivate;
	};
}