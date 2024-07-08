#pragma once

#include "ComponentInfoPrivate/ComponentInfoPrivate.h"

namespace NCore
{
	class CComponentInfo
	{
	public:
		CComponentInfo(const QString& i_sModule, const QString& i_sKey, 
			const CVersion& i_oVersion, const QStringList& i_asRequiredSubComponents);

		CComponentInfo(const QString& i_sModule, const QString& i_sKey,
			const CVersion& i_oVersion, const QStringList& i_asRequiredSubComponents, const QString& i_sInterface);

		CComponentInfo(const CComponentInfo& i_oOther);

		CComponentInfo(CComponentInfoPrivate* i_pPrivate);

		virtual ~CComponentInfo() = default;

	public:
		const QString& module() const;

		const QString& key() const;

		QString type() const;

		const QString& interface() const;

		const QStringList& requiredSubComponents() const;

		const CVersion& version() const;

		bool subComponentRequired(const QString& i_sName) const;

		void setDescription(const QString& i_sDescription);

		void setMaxParents(const unsigned int i_iCount);

		const CVersion& qtVersion() const;

	protected:
		QSharedDataPointer<CComponentInfoPrivate> m_pPrivate;
	};
}