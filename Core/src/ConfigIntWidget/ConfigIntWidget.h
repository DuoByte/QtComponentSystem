#pragma once

#include "ConfigWidget/ConfigWidget.h"

#include <qspinbox.h>
#include <qlabel.h>
#include <qgridlayout.h>

namespace NCore
{
	class CConfigIntWidget : public CConfigWidget
	{
		Q_DISABLE_COPY(CConfigIntWidget);

	public:
		CConfigIntWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent = nullptr);
		
		~CConfigIntWidget() override;

	public:
		QSpinBox* spinBox() const;

		QLabel* label() const;

	private slots:
		void onParamValueChanged();

		void onSpinBoxValueChanged(int i_iValue);

	private:
		QSpinBox* m_pSpinBox;

		QLabel* m_pLabel;
	};
}