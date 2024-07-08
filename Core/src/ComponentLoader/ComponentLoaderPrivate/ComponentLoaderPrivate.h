#pragma once

#include "ComponentList/ComponentList.h"

#include <qshareddata.h>

namespace NCore
{
	class CComponentLoaderPrivate : public QSharedData
	{
	public:
		CComponentLoaderPrivate();

		CComponentLoaderPrivate(const CComponentLoaderPrivate& i_oOther);

		~CComponentLoaderPrivate() = default;

	public:


	public:
		std::shared_ptr<CComponentList> m_pComponentList;
	};
}