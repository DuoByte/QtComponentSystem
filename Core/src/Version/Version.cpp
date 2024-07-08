#include "Version.h"
#include "VersionPrivate/VersionPrivate.h"

#include <qdebug.h>

namespace NCore
{
	CVersion::CVersion()
		: m_pPrivate(new CVersionPrivate)
	{
		m_pPrivate->m_fIsValid = false;
	}

	CVersion::CVersion(const QString& i_sVersion)
		: m_pPrivate(new CVersionPrivate)
	{
		if (m_pPrivate->fromString(i_sVersion))
			m_pPrivate->m_fIsValid = true;
	}

	CVersion::CVersion(const uint i_iMajor, const uint i_iMinor, const uint i_iMiner)
		: m_pPrivate(new CVersionPrivate)
	{
		m_pPrivate->m_iMajor = i_iMajor;

		m_pPrivate->m_iMinor = i_iMinor;

		m_pPrivate->m_iMiner = i_iMiner;

		m_pPrivate->m_fIsValid = true;
	}

	CVersion::CVersion(const CVersion& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{
	}

	CVersion::CVersion(CVersionPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}

	QString CVersion::asString() const
	{
		return QString("%1.%2.%3")
			.arg(m_pPrivate->m_iMajor)
			.arg(m_pPrivate->m_iMinor)
			.arg(m_pPrivate->m_iMiner);
	}

	bool CVersion::isValid() const
	{
		return m_pPrivate->m_fIsValid;
	}

	uint CVersion::major() const
	{
		return m_pPrivate->m_iMajor;
	}

	uint CVersion::minor() const
	{
		return m_pPrivate->m_iMinor;
	}

	uint CVersion::miner() const
	{
		return m_pPrivate->m_iMiner;
	}

	bool CVersion::isSame(const CVersion& i_oVersion) const
	{
		return major() == i_oVersion.major() 
			&& minor() == i_oVersion.minor() 
			&& miner() == i_oVersion.miner();
	}

	bool CVersion::isSame(const QString& i_sVersion) const
	{
		const CVersion oVersion(i_sVersion);
		if (oVersion.isValid())
			if (oVersion.isSame(*this))
				return true;
		return false;
	}

	bool CVersion::isHigherThan(const CVersion& i_oVersion) const
	{
		if (isSame(i_oVersion))
			return false;

		if (major() > i_oVersion.major())
			return true;

		if (major() == i_oVersion.major())
		{
			if (minor() > i_oVersion.minor())
				return true;

			if (minor() == i_oVersion.minor())
				if (miner() > i_oVersion.miner())
					return true;
		}

		return false;
	}

	bool CVersion::isLowerThan(const CVersion& i_oVersion) const
	{
		if (isSame(i_oVersion))
			return false;

		return !isHigherThan(i_oVersion);
	}

	void CVersion::increaseMajor(const int i_iAmount)
	{
		m_pPrivate->m_iMajor += i_iAmount;
	}

	void CVersion::increaseMinor(const int i_iAmount)
	{
		m_pPrivate->m_iMinor += i_iAmount;
	}

	void CVersion::increaseMiner(const int i_iAmount)
	{
		m_pPrivate->m_iMiner += i_iAmount;
	}

	void CVersion::decreaseMajor(const int i_iAmount)
	{
		m_pPrivate->m_iMajor -= i_iAmount;
	}

	void CVersion::decreaseMinor(const int i_iAmount)
	{
		m_pPrivate->m_iMinor -= i_iAmount;
	}

	void CVersion::decreaseMiner(const int i_iAmount)
	{
		m_pPrivate->m_iMiner -= i_iAmount;
	}

	void CVersion::setMajor(const int i_iMajor)
	{
		m_pPrivate->m_iMajor = i_iMajor;
	}

	void CVersion::setMinor(const int i_iMinor)
	{
		m_pPrivate->m_iMinor = i_iMinor;
	}

	void CVersion::setMiner(const int i_iMiner)
	{
		m_pPrivate->m_iMiner = i_iMiner;
	}

	bool CVersion::operator==(const CVersion& i_oVersion) const
	{
		return this->isSame(i_oVersion);
	}

	bool CVersion::operator>(const CVersion& i_oVersion) const
	{
		return this->isHigherThan(i_oVersion);
	}

	bool CVersion::operator<(const CVersion& i_oVersion) const
	{
		return this->isLowerThan(i_oVersion);
	}
}

