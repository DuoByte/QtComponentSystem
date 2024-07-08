#pragma once

#include "ComponentLoaderPrivate/ComponentLoaderPrivate.h"
#include "Component/Component.h"

#include <qvector.h>

namespace NCore
{
	class CComponentLoader
	{
		Q_DISABLE_COPY(CComponentLoader);
	public:
		CComponentLoader(std::shared_ptr<CComponentList> i_pComponentList);

		CComponentLoader(CComponentLoaderPrivate* i_pPrivate);

		~CComponentLoader() = default;

	public:


	private:
		QSharedDataPointer<CComponentLoaderPrivate> m_pPrivate;
	};
}