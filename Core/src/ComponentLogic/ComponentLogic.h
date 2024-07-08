#pragma once

#include <qstring.h>
#include <memory>

namespace NCore
{
	class CComponentLogic
	{
		Q_DISABLE_COPY(CComponentLogic);

	public:
		CComponentLogic(void* i_pLogic);

		virtual ~CComponentLogic() = default;

	public:
		template<typename T>
		std::shared_ptr<T> interface()
		{
			return *reinterpret_cast<std::shared_ptr<T>*>(m_pLogic);
		}

	private:
		void* m_pLogic;
	};
}