#pragma once

#include "ComponentConfig/ComponentConfig.h"
#include "HardwareConfig/HardwareConfig.h"
#include "AppConfig/AppConfig.h"

#include <qsharedpointer.h>
#include <memory>
#include <qvector.h>
#include <qflags.h>

namespace NCore
{
	enum EComponentFlag
	{
		SConstructed = 1 << 0,
		SAllSubComponentsLoaded = 1 << 1,
		SLoaded = 1 << 2,
		SFailed = 1 << 3,
	};

	class CComponent;
	class CComponentInfo;
	class CComponentPrivate : public QSharedData
	{
	public:
		CComponentPrivate();

		CComponentPrivate(const CComponentPrivate& i_oOther);

		~CComponentPrivate();

	public:

	public:
		QString m_sID;
		
		std::shared_ptr<const CComponentInfo> m_pComponentInfo;

		bool m_fIsDummy;

		QVector<std::shared_ptr<const CComponent>> m_apSubComponents;

		QVector<std::shared_ptr<const CComponent>> m_apSuperComponents;

		QFlags<EComponentFlag> m_eFlag;
	};
}