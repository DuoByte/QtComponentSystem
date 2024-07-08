#include "ComponentInfoPrivate.h"
#include "../ComponentInfo.h"

namespace NCore
{
	CComponentInfoPrivate::CComponentInfoPrivate()
		: m_iMaxParents(std::numeric_limits<unsigned int>::max())
	{
	}

	CComponentInfoPrivate::CComponentInfoPrivate(const CComponentInfoPrivate& i_oOther)
		: QSharedData(i_oOther),
		m_oVersion(i_oOther.m_oVersion),
		m_sModule(i_oOther.m_sModule),
		m_sKey(i_oOther.m_sKey),
		m_asRequiredSubComponents(i_oOther.m_asRequiredSubComponents),
		m_sInterface(i_oOther.m_sInterface),
		m_sDescription(i_oOther.m_sDescription),
		m_iMaxParents(i_oOther.m_iMaxParents),
		m_oQtVersion(i_oOther.m_oQtVersion),
		m_sQtCompiler(i_oOther.m_sQtCompiler)
	{
	}
}