#include "ConfigDoubleWidget.h"

#include "ConfigParameter/ConfigParameter.h"

namespace NCore
{
	CConfigDoubleWidget::CConfigDoubleWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent)
		: CConfigWidget(i_pParameter, i_pParent)
	{
		m_pDoubleSpinBox = new QDoubleSpinBox(m_pWidget);
		m_pLabel = new QLabel(m_pWidget);

		m_pLayout->addWidget(m_pLabel);
		m_pLayout->addWidget(m_pDoubleSpinBox);

		m_pDoubleSpinBox->setMaximum(std::numeric_limits<double>::max());
		m_pDoubleSpinBox->setMinimum(std::numeric_limits<double>::min());

		m_pDoubleSpinBox->setValue(m_pParameter->value().toDouble());
		m_pLabel->setText(QString("%1:").arg(m_pParameter->displayName()));

		m_pDoubleSpinBox->show();
		m_pLabel->show();

		connect(m_pParameter.get(), &CConfigParameter::onValueChanged, this, &CConfigDoubleWidget::onParamValueChanged);
		connect(m_pDoubleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &CConfigDoubleWidget::onSpinBoxValueChanged);
	}

	CConfigDoubleWidget::~CConfigDoubleWidget()
	{
	}

	QDoubleSpinBox* CConfigDoubleWidget::doubleSpinBox() const
	{
		return m_pDoubleSpinBox;
	}

	QLabel* CConfigDoubleWidget::label() const
	{
		return m_pLabel;
	}

	void CConfigDoubleWidget::onParamValueChanged()
	{
		m_pDoubleSpinBox->setValue(m_pParameter->value().toDouble());
	}

	void CConfigDoubleWidget::onSpinBoxValueChanged(double i_dValue)
	{
		m_pParameter->setValue(i_dValue);
	}
}