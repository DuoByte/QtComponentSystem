#include "gtest/gtest.h"

#include "ComponentTest/TestFactoryAlpha/TestFactoryAlpha.h"
#include "ComponentTest/TestFactoryBeta/TestFactoryBeta.h"
#include "Errors/ErrorFactoryMissing.h"
#include "MainInstance/MainInstance.h"

#include <qdir.h>

using namespace NCore;

#define TEST_FILE QDir::currentPath() + "/TestHardwareConfig.ini"

TEST(MainInstance, SubComponentLinking)
{
	// Build Hardware File:
	QFile oFile(TEST_FILE);
	oFile.open(QFile::WriteOnly);
	QByteArray abFile;
	abFile.append("[1]\n");
	abFile.append(QString("ComponentType=%1\n").arg(CTestFactoryAlpha().componentInfo()->type()));
	abFile.append(QString("SubComponent/%1=2\n").arg(CTestFactoryBeta().componentInfo()->type()));
	abFile.append("\n");
	abFile.append("[2]\n");
	abFile.append(QString("ComponentType=%1\n").arg(CTestFactoryBeta().componentInfo()->type()));
	oFile.write(abFile);
	oFile.close();

	std::shared_ptr<CHardwareFile> pHardwareFile = std::make_shared<CHardwareFile>(TEST_FILE);
	std::shared_ptr<CMainInstance> pInstance = std::make_shared<CMainInstance>(pHardwareFile, nullptr);

	pInstance->addFactory(std::make_shared<CTestFactoryAlpha>());
	pInstance->addFactory(std::make_shared<CTestFactoryBeta>());

	EXPECT_TRUE(pInstance->load());

	auto apComponentList = pInstance->componentList();
	for (auto it = apComponentList->begin(); it != apComponentList->end(); ++it)
	{
		EXPECT_TRUE((*it)->hasFlag(EComponentFlag::SConstructed));
		EXPECT_TRUE((*it)->hasFlag(EComponentFlag::SAllSubComponentsLoaded));
	}



	oFile.remove();
}