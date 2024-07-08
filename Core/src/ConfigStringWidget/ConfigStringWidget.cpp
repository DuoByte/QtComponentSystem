#include "ConfigStringWidget.h"

#include "ConfigParameter/ConfigParameter.h"

namespace NCore
{
	CConfigStringWidget::CConfigStringWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent)
		: CConfigWidget(i_pParameter, i_pParent)
	{
		m_pLineEdit = new QLineEdit(m_pWidget);
		m_pLabel = new QLabel(m_pWidget);

		m_pLayout->addWidget(m_pLabel);
		m_pLayout->addWidget(m_pLineEdit);

		m_pLineEdit->setText(m_pParameter->value().toString());
		m_pLabel->setText(QString("%1:").arg(m_pParameter->displayName()));
		
		m_pLineEdit->show();
		m_pLabel->show();

		connect(m_pParameter.get(), &CConfigParameter::onValueChanged, this, &CConfigStringWidget::onParamValueChanged);
		connect(m_pLineEdit, &QLineEdit::textChanged, this, &CConfigStringWidget::onLineEditStringChanged);
	}

	CConfigStringWidget::~CConfigStringWidget()
	{
	}

	QLabel* CConfigStringWidget::label() const
	{
		return m_pLabel;
	}

	QLineEdit* CConfigStringWidget::lineEdit() const
	{
		return m_pLineEdit;
	}

	void CConfigStringWidget::onParamValueChanged()
	{
		m_pLineEdit->setText(m_pParameter->value().toString());
	}

	void CConfigStringWidget::onLineEditStringChanged(const QString& i_sValue)
	{
		m_pParameter->setValue(i_sValue);
	}
}