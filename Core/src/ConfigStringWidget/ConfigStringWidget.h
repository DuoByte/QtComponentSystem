#pragma once

#include "ConfigWidget/ConfigWidget.h"

#include <qlabel.h>
#include <qgridlayout.h>
#include <qlineedit.h>

namespace NCore
{
	class CConfigStringWidget : public CConfigWidget
	{
		Q_DISABLE_COPY(CConfigStringWidget);

	public:
		CConfigStringWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent = nullptr);

		~CConfigStringWidget() override;

	public:
		QLabel* label() const;

		QLineEdit* lineEdit() const;

	private slots:
		void onParamValueChanged();

		void onLineEditStringChanged(const QString& i_sValue);

	private:
		QLineEdit* m_pLineEdit;

		QLabel* m_pLabel;
	};
}