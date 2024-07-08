#include "ConfigIntWidget.h"

#include "ConfigParameter/ConfigParameter.h"

namespace NCore
{
	CConfigIntWidget::CConfigIntWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent)
		: CConfigWidget(i_pParameter, i_pParent)
	{
		m_pSpinBox = new QSpinBox(m_pWidget);
		m_pLabel = new QLabel(m_pWidget);

		m_pLayout->addWidget(m_pLabel);
		m_pLayout->addWidget(m_pSpinBox);

		m_pSpinBox->setMaximum(std::numeric_limits<int>::max());
		m_pSpinBox->setMinimum(std::numeric_limits<int>::min());

		m_pSpinBox->setValue(m_pParameter->value().toInt());
		m_pLabel->setText(QString("%1:").arg(m_pParameter->displayName()));

		m_pSpinBox->show();
		m_pLabel->show();

		connect(m_pParameter.get(), &CConfigParameter::onValueChanged, this, &CConfigIntWidget::onParamValueChanged);
		connect(m_pSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &CConfigIntWidget::onSpinBoxValueChanged);
	}

	CConfigIntWidget::~CConfigIntWidget()
	{
	}

	QSpinBox* CConfigIntWidget::spinBox() const
	{
		return m_pSpinBox;
	}

	QLabel* CConfigIntWidget::label() const
	{
		return m_pLabel;
	}

	void CConfigIntWidget::onParamValueChanged()
	{
		m_pSpinBox->setValue(m_pParameter->value().toInt());
	}

	void CConfigIntWidget::onSpinBoxValueChanged(int i_iValue)
	{
		m_pParameter->setValue(i_iValue);
	}
}