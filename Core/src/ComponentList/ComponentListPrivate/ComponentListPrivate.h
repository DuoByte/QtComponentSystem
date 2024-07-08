#pragma once

#include "Component/Component.h"

#include <qshareddata.h>
#include <qvector.h>

namespace NCore
{
	class CComponentListPrivate : public QSharedData
	{
	public:
		CComponentListPrivate();

		CComponentListPrivate(const CComponentListPrivate& i_oOther);

		~CComponentListPrivate() = default;

	public:
		QVector<std::shared_ptr<CComponent>> m_apComponents;
	};
}