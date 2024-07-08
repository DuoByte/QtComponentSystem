#include <qcoreapplication.h>
#include <qapplication.h>
#include <thread>
#include <qmainwindow.h>

#include "Version/Version.h"
#include "gtest/gtest.h"

#include <qdebug.h>

#include "Component/Component.h"

#include "ConfigItem/ConfigItem.h"
#include "ConfigParameter/ConfigParameter.h"
#include "ConfigIniFileIO/ConfigIniFileIO.h"

#include "ConfigIntWidget/ConfigIntWidget.h"
#include "ConfigStringWidget/ConfigStringWidget.h"
#include "ConfigDoubleWidget/ConfigDoubleWidget.h"
#include "ConfigBoolWidget/ConfigBoolWidget.h"
#include "ConfigWidgetFactory/ConfigWidgetFactory.h"

#include "HardwareFile/HardwareFile.h"
#include "FactoryList/FactoryList.h"

int applicationMain(int argc, char** argv);

GTEST_API_ int main(int argc, char** argv)
{
	using namespace NCore;

	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	
	if (RUN_ALL_TESTS() != 0)
		return 0;

	QCoreApplication *pApplication = new QCoreApplication(argc, argv);

	//std::thread(&applicationMain, argc, argv).detach();
	pApplication->exit();
	delete pApplication;

	return applicationMain(argc, argv);
}


int applicationMain(int argc, char** argv)
{
	using namespace NCore;

	QApplication oApp(argc, argv);
	

	return oApp.exec();
}