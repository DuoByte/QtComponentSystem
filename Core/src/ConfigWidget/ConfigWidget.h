#pragma once

#include <qobject.h>
#include <qwidget.h>
#include <qgridlayout.h>
#include <memory>

namespace NCore
{
	class CConfigIntWidget;
	class CConfigStringWidget;
	class CConfigDoubleWidget;
	class CConfigBoolWidget;
	class CConfigParameter;
	class CConfigWidget : public QObject
	{
		Q_DISABLE_COPY(CConfigWidget);
		Q_OBJECT
	public:
		CConfigWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent = nullptr);

		virtual ~CConfigWidget() = default;

	public:
		QWidget* widget() const;

		std::shared_ptr<CConfigParameter> parameter() const;

		CConfigIntWidget* toIntWidget();

		CConfigStringWidget* toStringWidget();

		CConfigDoubleWidget* toDoubleWidget();

		CConfigBoolWidget* toBoolWidget();

	protected:
		std::shared_ptr<CConfigParameter> m_pParameter;

		QWidget* m_pWidget;

		QHBoxLayout* m_pLayout;
	};
}