#include "ConfigBoolWidget.h"

#include "ConfigParameter/ConfigParameter.h"

namespace NCore
{
	CConfigBoolWidget::CConfigBoolWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent)
		: CConfigWidget(i_pParameter, i_pParent)
	{
		m_pCheckBox = new QCheckBox(m_pWidget);

		m_pLayout->addWidget(m_pCheckBox);

		m_pCheckBox->setChecked(m_pParameter->value().toBool());
		m_pCheckBox->setText(QString("%1").arg(m_pParameter->displayName()));

		m_pCheckBox->show();

		connect(m_pParameter.get(), &CConfigParameter::onValueChanged, this, &CConfigBoolWidget::onParamValueChanged);
		connect(m_pCheckBox, &QCheckBox::stateChanged, this, &CConfigBoolWidget::onCheckBoxStateChanged);
	}

	CConfigBoolWidget::~CConfigBoolWidget()
	{
	}

	QCheckBox* CConfigBoolWidget::checkBox() const
	{
		return m_pCheckBox;
	}

	void CConfigBoolWidget::onParamValueChanged()
	{
		m_pCheckBox->setChecked(m_pParameter->value().toBool());
	}

	void CConfigBoolWidget::onCheckBoxStateChanged(bool i_fState)
	{
		m_pParameter->setValue(i_fState);
	}
}