#pragma once

#include "ConfigWidget/ConfigWidget.h"

#include <qspinbox.h>
#include <qlabel.h>
#include <qgridlayout.h>

namespace NCore
{
	class CConfigDoubleWidget : public CConfigWidget
	{
		Q_DISABLE_COPY(CConfigDoubleWidget);

	public:
		CConfigDoubleWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent = nullptr);

		~CConfigDoubleWidget() override;

	public:
		QDoubleSpinBox* doubleSpinBox() const;

		QLabel* label() const;

	private slots:
		void onParamValueChanged();

		void onSpinBoxValueChanged(double i_dValue);

	private:
		QDoubleSpinBox* m_pDoubleSpinBox;

		QLabel* m_pLabel;
	};
}