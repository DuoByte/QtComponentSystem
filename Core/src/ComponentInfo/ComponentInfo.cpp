#include "ComponentInfo.h"

namespace NCore
{
	CComponentInfo::CComponentInfo(const QString& i_sModule, const QString& i_sKey,
		const CVersion& i_oVersion, const QStringList& i_asRequiredSubComponents)
		: m_pPrivate(new CComponentInfoPrivate)
	{
		m_pPrivate->m_sModule = i_sModule;

		m_pPrivate->m_sKey = i_sKey;

		m_pPrivate->m_oVersion = i_oVersion;

		m_pPrivate->m_asRequiredSubComponents = i_asRequiredSubComponents;

		m_pPrivate->m_oQtVersion = CVersion(QT_VERSION_MAJOR, QT_VERSION_MINOR, QT_VERSION_PATCH);
	}

	CComponentInfo::CComponentInfo(const QString& i_sModule, const QString& i_sKey, const CVersion& i_oVersion, 
		const QStringList& i_asRequiredSubComponents, const QString& i_sInterface)
	{
		m_pPrivate->m_sModule = i_sModule;

		m_pPrivate->m_sKey = i_sKey;

		m_pPrivate->m_oVersion = i_oVersion;

		m_pPrivate->m_asRequiredSubComponents = i_asRequiredSubComponents;

		m_pPrivate->m_sInterface = i_sInterface;
	}

	CComponentInfo::CComponentInfo(const CComponentInfo& i_oOther)
		: m_pPrivate(i_oOther.m_pPrivate)
	{
	}

	CComponentInfo::CComponentInfo(CComponentInfoPrivate* i_pPrivate)
		: m_pPrivate(i_pPrivate)
	{
	}

	const QString& CComponentInfo::module() const
	{
		return m_pPrivate->m_sModule;
	}

	const QString& CComponentInfo::key() const
	{
		return m_pPrivate->m_sKey;
	}

	QString CComponentInfo::type() const
	{
		return QString("%1.%2").arg(m_pPrivate->m_sModule).arg(m_pPrivate->m_sKey);
	}

	const QString& CComponentInfo::interface() const
	{
		return m_pPrivate->m_sInterface;
	}

	const QStringList& CComponentInfo::requiredSubComponents() const
	{
		return m_pPrivate->m_asRequiredSubComponents;
	}

	const CVersion& CComponentInfo::version() const
	{
		return m_pPrivate->m_oVersion;
	}

	bool CComponentInfo::subComponentRequired(const QString& i_sName) const
	{
		return m_pPrivate->m_asRequiredSubComponents.contains(i_sName);
	}

	void CComponentInfo::setDescription(const QString& i_sDescription)
	{
		m_pPrivate->m_sDescription = i_sDescription;
	}

	void CComponentInfo::setMaxParents(const unsigned int i_iCount)
	{
		m_pPrivate->m_iMaxParents = i_iCount;
	}

	const CVersion& CComponentInfo::qtVersion() const
	{
		return m_pPrivate->m_oQtVersion;
	}
}