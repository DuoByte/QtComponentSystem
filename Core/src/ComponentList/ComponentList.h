#pragma once

#include "ComponentListPrivate/ComponentListPrivate.h"

namespace NCore
{
	class CComponentList
	{
	public:
		CComponentList();
		
		CComponentList(const CComponentList& i_oOther);

		CComponentList(CComponentListPrivate* i_pPrivate);

		~CComponentList() = default;

	public:
		void addComponent(std::shared_ptr<CComponent> i_pComponent);

		std::shared_ptr<CComponent> component(const QString& i_sID) const;

		std::shared_ptr<CComponent>* begin();

		std::shared_ptr<CComponent>* end();

	private:
		QSharedDataPointer<CComponentListPrivate> m_pPrivate;
	};
}