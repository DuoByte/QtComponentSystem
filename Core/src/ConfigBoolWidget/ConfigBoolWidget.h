#pragma once

#include "ConfigWidget/ConfigWidget.h"

#include <qcheckbox.h>
#include <qgridlayout.h>

namespace NCore
{
	class CConfigBoolWidget : public CConfigWidget
	{
		Q_DISABLE_COPY(CConfigBoolWidget);

	public:
		CConfigBoolWidget(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent = nullptr);

		~CConfigBoolWidget() override;

	public:
		QCheckBox* checkBox() const;

	private slots:
		void onParamValueChanged();

		void onCheckBoxStateChanged(bool i_fState);

	private:
		QCheckBox* m_pCheckBox;
	};
}