#include "ConfigItem.h"
#include "ConfigParameter/ConfigParameter.h"
#include "Errors/ErrorAlreadyContains.h"
#include "ConfigIOInterface/ConfigIOInterface.h"

namespace NCore
{
	CConfigItem::CConfigItem(const QString& i_sName, std::shared_ptr<IConfigIO> i_pConfigIO)
		: m_pPrivate(new CConfigItemPrivate)
	{
		m_pPrivate->m_pConfigIO = i_pConfigIO;

		m_pPrivate->m_sName = i_sName;
	}

	CConfigItem::CConfigItem(const CConfigItem& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{
	}

	CConfigItem::CConfigItem(CConfigItemPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}

	std::shared_ptr<CConfigParameter> CConfigItem::addParameter(const QString& i_sDisplayName, const QString& i_sKey, const QVariant& i_oDefaultValue)
	{
		for (std::shared_ptr<const CConfigParameter> pParameter : m_pPrivate->m_apParameter)
		{
			if (i_sKey == pParameter->key())
			{
				throw CErrorAlreadyContains(QString("Key already in list: %1").arg(i_sKey), ERROR_HERE);
			}
		}
		QVariant oValue;
		if (m_pPrivate->m_pConfigIO)
		{
			oValue = m_pPrivate->m_pConfigIO->importer()->read(m_pPrivate->m_sName, i_sKey, i_oDefaultValue);
			m_pPrivate->m_pConfigIO->exporter()->write(m_pPrivate->m_sName, i_sKey, oValue);
		}
		else
		{
			oValue = i_oDefaultValue;
		}

		std::shared_ptr<CConfigParameter> pParameter = std::make_shared<CConfigParameter>(i_sDisplayName, i_sKey, i_oDefaultValue.type(), oValue, m_pPrivate->m_sName, m_pPrivate->m_pConfigIO);
		m_pPrivate->m_apParameter.push_back(pParameter);
		return pParameter;
	}

	bool CConfigItem::hasParameter(const QString& i_sKey) const
	{
		for (std::shared_ptr<const CConfigParameter> pParameter : m_pPrivate->m_apParameter)
			if (pParameter->key() == i_sKey)
				return true;

		return false;
	}

	void CConfigItem::removeParameter(const QString& i_sKey)
	{
		for (int i = 0; i < m_pPrivate->m_apParameter.size(); i++)
		{
			if (m_pPrivate->m_apParameter.at(i)->key() == i_sKey)
			{
				m_pPrivate->m_apParameter.removeAt(i);
				break;
			}
		}
	}

	std::shared_ptr<CConfigParameter> NCore::CConfigItem::parameter(const QString& i_sKey) const
	{
		for (std::shared_ptr<CConfigParameter> pParameter : m_pPrivate->m_apParameter)
			if (pParameter->key() == i_sKey)
				return pParameter;
		return nullptr;
	}

	const QVector<std::shared_ptr<CConfigParameter>>& CConfigItem::parameters() const
	{
		return m_pPrivate->m_apParameter;
	}

	const QString& CConfigItem::name() const
	{
		return m_pPrivate->m_sName;
	}
}