#include "Exception.h"

namespace NCore
{
	CException::CException()
		: m_eID(EExceptionID::EUnknown)
	{
	}

	CException::CException(const EExceptionID i_eID, const QString& i_sWhat, const QString& i_sLocation)
		: m_sWhat(i_sWhat), m_sLocation(i_sLocation), m_eID(i_eID)
	{
	}

	CException::CException(const EExceptionID i_eID, const QString& i_sWhat, const QString& i_sFix, const QString& i_sLocation)
		: m_sWhat(i_sWhat), m_sFix(i_sFix), m_sLocation(i_sLocation), m_eID(i_eID)
	{
	}

	const QString& CException::msg() const
	{
		return m_sWhat;
	}

	const QString& CException::location() const
	{
		return m_sLocation;
	}

	const QString& CException::fix() const
	{
		return m_sFix;
	}

	EExceptionID CException::expectionID() const
	{
		return m_eID;
	}
}