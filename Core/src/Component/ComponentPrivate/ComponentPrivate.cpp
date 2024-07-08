#include "ComponentPrivate.h"
#include "ComponentInfo/ComponentInfo.h"

namespace NCore
{
	CComponentPrivate::CComponentPrivate()
		: m_fIsDummy(false)
	{
		
	}

	CComponentPrivate::CComponentPrivate(const CComponentPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_sID(i_oOther.m_sID),
		m_pComponentInfo(i_oOther.m_pComponentInfo),
		m_fIsDummy(i_oOther.m_fIsDummy),
		m_apSubComponents(i_oOther.m_apSubComponents),
		m_apSuperComponents(i_oOther.m_apSuperComponents)
	{
	}

	CComponentPrivate::~CComponentPrivate()
	{
	}
}