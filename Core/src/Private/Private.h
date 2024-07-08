#pragma once

#include <qshareddata.h>

namespace NCore
{
	class CPrivate : public QSharedData
	{
	public:
		CPrivate();

		CPrivate(const CPrivate& i_oOther);

		~CPrivate() = default;

	public:

	}
}