#include "gtest/gtest.h"

#include "ConfigIniFileIO/ConfigIniFileIO.h"
#include "ConfigIniFileImporter/ConfigIniFileImporter.h"
#include "ConfigItem/ConfigItem.h"
#include "ConfigParameter/ConfigParameter.h"
#include "Exception/Exception.h"
#include "ConfigWidgetFactory/ConfigWidgetFactory.h"

#include <qfile.h>
#include <qdir.h>
#include <qapplication.h>

using namespace NCore;

TEST(ConfigIO, ConfigIniFileExporter)
{
	QString sFile = QDir::currentPath() + "/testFile.ini";
	if (QFile(sFile).exists())
		QFile::remove(sFile);

	QString sGroup = "TestGroup";
	QString sKey = "GoogleTest";
	QVariant oValue = 1337;

	auto pFileIO = std::make_shared<CConfigIniFileIO>(sFile);
	pFileIO->exporter()->write(sGroup, sKey, oValue);

	EXPECT_TRUE(QFile(sFile).exists());

	QSettings oSettings(sFile, QSettings::Format::IniFormat);
	oSettings.beginGroup(sGroup);
	EXPECT_EQ(oSettings.value(sKey), oValue);
}

TEST(ConfigIO, ConfigIniFileImporter)
{
	QString sFile = QDir::currentPath() + "/testFile.ini";
	if (QFile(sFile).exists())
		QFile::remove(sFile);


	QString sGroup = "TestGroup";
	QString sKey = "GoogleTest";
	QVariant oValue = 1337;

	QSettings oSettings(sFile, QSettings::Format::IniFormat);
	oSettings.beginGroup(sGroup);
	oSettings.setValue(sKey, oValue);
	oSettings.endGroup();
	oSettings.sync();

	auto pFileIO = std::make_shared<CConfigIniFileIO>(sFile);
	auto oResVal = pFileIO->importer()->read(sGroup, sKey, 0);
	EXPECT_EQ(oResVal, oValue);
}

TEST(Config, ConfigItem)
{
	QString sFile = QDir::currentPath() + "/testFile.ini";
	auto pFileIO = std::make_shared<CConfigIniFileIO>(sFile);

	auto pConfigItem = std::make_shared<CConfigItem>("TestItem", pFileIO);
	EXPECT_EQ(pConfigItem->name(), "TestItem");

	pConfigItem->addParameter("Test", "Test", 0);
	EXPECT_TRUE(pConfigItem->hasParameter("Test"));
	EXPECT_FALSE(pConfigItem->hasParameter("dsfsd"));

	EXPECT_TRUE((pConfigItem->parameter("Test") != nullptr));
	EXPECT_TRUE(pConfigItem->parameters().size() == 1);
	pConfigItem->removeParameter("Test");
	EXPECT_TRUE(pConfigItem->parameters().size() == 0);
}

TEST(Config, ConfigParameter)
{
	auto pItem = std::make_shared<CConfigItem>("TestItem", nullptr);

	auto pParam = pItem->addParameter("Display", "Key", int(1337));
	EXPECT_EQ(pParam->displayName(), "Display");
	EXPECT_EQ(pParam->key(), "Key");
	EXPECT_EQ(pParam->value(), 1337);

	EXPECT_THROW(pParam->setValue("13dsf"), CException);
	pParam->setValue(1500);
	EXPECT_EQ(pParam->value(), 1500);
	EXPECT_EQ(pParam->type(), QVariant::Type::Int);
}
