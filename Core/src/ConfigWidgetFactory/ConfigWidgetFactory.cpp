#include "ConfigWidgetFactory.h"

#include "ConfigParameter/ConfigParameter.h"
#include "Errors/ErrorNotImplemented.h"

namespace NCore
{
	std::shared_ptr<CConfigWidget> CConfigWidgetFactory::widgetFromParameter(std::shared_ptr<CConfigParameter> i_pParameter, QWidget* i_pParent)
	{
		switch (i_pParameter->type())
		{
		case QVariant::Type::Int:
			return std::make_shared<CConfigIntWidget>(i_pParameter, i_pParent);
			break;
		case QVariant::Type::Double:
			return std::make_shared<CConfigDoubleWidget>(i_pParameter, i_pParent);
			break;
		case QVariant::Type::String:
			return std::make_shared<CConfigStringWidget>(i_pParameter, i_pParent);
			break;
		case QVariant::Type::Bool:
			return std::make_shared<CConfigBoolWidget>(i_pParameter, i_pParent);
			break;
		default:
			throw CErrorNotImplemented(QString("Config widget type: %1").arg(i_pParameter->type()), ERROR_HERE);
			break;
		}

		return nullptr;
	}
}