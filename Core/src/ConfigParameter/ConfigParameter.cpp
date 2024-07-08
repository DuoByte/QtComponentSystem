#include "ConfigParameter.h"
#include "Exception/Exception.h"
#include "Errors/ErrorInvalidConfigValueType.h"

#include <qmetaobject.h>

namespace NCore
{
	CConfigParameter::CConfigParameter(const QString& i_sDisplayName, const QString& i_sKey, const QVariant::Type i_eType,
		const QVariant& i_oValue, const QString& i_sGroup, std::shared_ptr<IConfigIO> i_pConfigIO)
		: m_pPrivate(new CConfigParameterPrivate)
	{
		m_pPrivate->m_sDisplayName = i_sDisplayName;

		m_pPrivate->m_sKey = i_sKey;

		m_pPrivate->m_oValue = i_oValue;

		m_pPrivate->m_sGroup = i_sGroup;

		m_pPrivate->m_eType = i_eType;

		m_pPrivate->m_pConfigIO = i_pConfigIO;
	}

	CConfigParameter::CConfigParameter(const CConfigParameter& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{
	}

	CConfigParameter::CConfigParameter(CConfigParameterPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}

	const QString& CConfigParameter::displayName() const
	{
		return m_pPrivate->m_sDisplayName;
	}

	const QString& CConfigParameter::key() const
	{
		return m_pPrivate->m_sKey;
	}

	const QVariant& CConfigParameter::value() const
	{
		return m_pPrivate->m_oValue;
	}

	void CConfigParameter::setValue(const QVariant& i_oValue)
	{
		auto eGot = i_oValue.type();

		if (i_oValue.type() != m_pPrivate->m_eType)
		{
			throw CErrorInvalidConfigValueType(m_pPrivate->m_eType, i_oValue.type(), ERROR_HERE);
		}

		if (m_pPrivate->m_pConfigIO)
			m_pPrivate->m_pConfigIO->exporter()->write(m_pPrivate->m_sGroup, m_pPrivate->m_sKey, i_oValue);

		m_pPrivate->m_oValue = i_oValue;

		emit onValueChanged();
	}

	QVariant::Type CConfigParameter::type() const
	{
		return m_pPrivate->m_eType;
	}
}