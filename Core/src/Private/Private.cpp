#include "CPrivate.h"

namespace NCore
{
	CPrivate::CPrivate()
	{

	}

	CPrivate::CPrivate(const CPrivate& i_oOther)
		: QSharedData(i_oOther)
	{

	}
}