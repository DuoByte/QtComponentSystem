#pragma once

#include "HardwareFilePrivate/HardwareFilePrivate.h"
#include "ConfigIOInterface/ConfigIOInterface.h"

namespace NCore
{
	class CHardwareFile
	{
	public:
		struct SComponent
		{
			QString sID;
			QString sType;
		};

	public:
		CHardwareFile(const QString& i_sFile);
		
		CHardwareFile(const CHardwareFile& i_oOther);

		CHardwareFile(CHardwareFilePrivate* i_pPrivate);

		~CHardwareFile() = default;

	public:
		QVector<SComponent> components() const;

		std::shared_ptr<IConfigIO> toConfigIO() const;

	private:
		QSharedDataPointer<CHardwareFilePrivate> m_pPrivate;
	};
}