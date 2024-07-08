#include "VersionPrivate.h"

#include <qregularexpression.h>

namespace NCore
{
	CVersionPrivate::CVersionPrivate()
		: m_iMajor(0),
		m_iMinor(0),
		m_iMiner(0),
		m_fIsValid(false)
	{
	}

	CVersionPrivate::CVersionPrivate(const CVersionPrivate& i_oOther)
		: QSharedData(i_oOther), 
		m_iMajor(i_oOther.m_iMajor),
		m_iMinor(i_oOther.m_iMinor),
		m_iMiner(i_oOther.m_iMiner),
		m_fIsValid(i_oOther.m_fIsValid)
	{
	}

	bool CVersionPrivate::validVersionString(const QString& i_sVersion) const
	{
		const QRegularExpression oRegEx(R"(^(\*|(\d+(\.(\d+(\.(\d+|\*))?|\*))?))$)");
		const QRegularExpressionMatch oMatch = oRegEx.match(i_sVersion);
		return oMatch.hasMatch();
	}

	bool CVersionPrivate::fromString(const QString& i_sVersion)
	{
		if (!validVersionString(i_sVersion))
			return false;

		const QRegularExpression oRegEx(
			"^(?<major>[0-9]+)\\.(?<minor>[0-9]+)\\.(?<miner>[0-9]+)$");
		const QRegularExpressionMatch oMatch = oRegEx.match(i_sVersion);

		if (!oMatch.hasMatch())
			return false;

		const QString sMajor = oMatch.captured("major");
		const QString sMinor = oMatch.captured("minor");
		const QString sMiner = oMatch.captured("miner");

 		if (sMajor.isEmpty() || sMinor.isEmpty() || sMiner.isEmpty())
			return false;

		bool fMajor = false;
		uint iMajor = sMajor.toInt(&fMajor);

		bool fMinor = false;
		uint iMinor = sMinor.toInt(&fMinor);

		bool fMiner = false;
		uint iMiner = sMiner.toInt(&fMiner);

		if (!fMajor || !fMinor || !fMiner)
			return false;

		m_iMajor = iMajor;
		m_iMinor = iMinor;
		m_iMiner = iMiner;

		return true;
	}
}