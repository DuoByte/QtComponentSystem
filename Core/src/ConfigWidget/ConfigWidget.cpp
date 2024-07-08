#include "ConfigWidget.h"

#include "ConfigParameter/ConfigParameter.h"

#include "ConfigIntWidget/ConfigIntWidget.h"
#include "ConfigStringWidget/ConfigStringWidget.h"
#include "ConfigBoolWidget/ConfigBoolWidget.h"
#include "ConfigDoubleWidget/ConfigDoubleWidget.h"

namespace NCore
{
	CConfigWidget::CConfigWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent)
		: m_pParameter(i_pParameter)
	{
		m_pWidget = new QWidget(i_pParent);
		m_pLayout = new QHBoxLayout(m_pWidget);
		m_pWidget->setLayout(m_pLayout);

		m_pWidget->show();
	}

	QWidget* CConfigWidget::widget() const
	{
		return m_pWidget;
	}

	std::shared_ptr<CConfigParameter> CConfigWidget::parameter() const
	{
		return m_pParameter;
	}

	CConfigIntWidget* CConfigWidget::toIntWidget()
	{
		if (m_pParameter->type() != QVariant::Type::Int)
			return nullptr;
		return static_cast<CConfigIntWidget*>(this);
	}

	CConfigStringWidget* CConfigWidget::toStringWidget()
	{
		if (m_pParameter->type() != QVariant::Type::String)
			return nullptr;
		return static_cast<CConfigStringWidget*>(this);
	}

	CConfigDoubleWidget* CConfigWidget::toDoubleWidget()
	{
		if (m_pParameter->type() != QVariant::Type::Double)
			return nullptr;
		return static_cast<CConfigDoubleWidget*>(this);
	}

	CConfigBoolWidget* CConfigWidget::toBoolWidget()
	{
		if (m_pParameter->type() != QVariant::Type::Bool)
			return nullptr;
		return static_cast<CConfigBoolWidget*>(this);
	}
}