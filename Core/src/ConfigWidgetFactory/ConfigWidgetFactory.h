#pragma once

#include "ConfigIntWidget/ConfigIntWidget.h"
#include "ConfigStringWidget/ConfigStringWidget.h"
#include "ConfigBoolWidget/ConfigBoolWidget.h"
#include "ConfigDoubleWidget/ConfigDoubleWidget.h"

namespace NCore
{
	class CConfigWidgetFactory
	{
	public:
		static std::shared_ptr<CConfigWidget> widgetFromParameter(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent = nullptr);
	};
}