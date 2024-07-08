#include "gtest/gtest.h"

#include "../src/Version/Version.h"

using namespace NCore;

TEST(Version, validVersionString) 
{
	CVersionPrivate* pPrivate = new CVersionPrivate();
	
	EXPECT_TRUE(pPrivate->validVersionString("1.0.0"));
	EXPECT_TRUE(pPrivate->validVersionString("1.2.3"));
	EXPECT_TRUE(pPrivate->validVersionString("1.0"));
	EXPECT_TRUE(pPrivate->validVersionString("1"));

	EXPECT_FALSE(pPrivate->validVersionString("1.0.0.0"));
	EXPECT_FALSE(pPrivate->validVersionString("1.0.0d"));
	EXPECT_FALSE(pPrivate->validVersionString(""));
}

TEST(Version, fromString)
{
	const QString sVersion = "11.22.33";
	const CVersion oVersion(sVersion);
	EXPECT_EQ(oVersion.major(), 11);
	EXPECT_EQ(oVersion.minor(), 22);
	EXPECT_EQ(oVersion.miner(), 33);
	EXPECT_EQ(oVersion.asString(), sVersion);
}

TEST(Version, isSame)
{
	{
		const QString sVersion = "1.2.3";
		const CVersion oVersion(sVersion);
		const CVersion oVersion2(sVersion);
		EXPECT_TRUE(oVersion.isSame(oVersion2));
	}
	{
		const CVersion oVersion("1.2.3");
		const CVersion oVersion2("1.0.0");
		EXPECT_FALSE(oVersion.isSame(oVersion2));
	}
}

TEST(Version, isSameString)
{
	const QString sVersion = "1.2.3";
	const CVersion oVersion(sVersion);
	EXPECT_TRUE(oVersion.isSame(sVersion));
}

TEST(Version, isHigherThan)
{
	{
		const CVersion oVersion("10.1.3");
		const CVersion oVersion2("10.1.2");
		EXPECT_TRUE(oVersion.isHigherThan(oVersion2));
	}
	{
		const CVersion oVersion("11.1.3");
		const CVersion oVersion2("10.1.2");
		EXPECT_TRUE(oVersion.isHigherThan(oVersion2));
	}
	{
		const CVersion oVersion("10.1.1");
		const CVersion oVersion2("10.1.2");
		EXPECT_FALSE(oVersion.isHigherThan(oVersion2));
	}
	{
		const CVersion oVersion("10.1.1");
		const CVersion oVersion2("10.1.1");
		EXPECT_FALSE(oVersion.isHigherThan(oVersion2));
	}
}

TEST(Version, isLowerThan)
{
	{
		const CVersion oVersion("10.1.3");
		const CVersion oVersion2("10.1.2");
		EXPECT_FALSE(oVersion.isLowerThan(oVersion2));
	}
	{
		const CVersion oVersion("10.1.1");
		const CVersion oVersion2("10.1.2");
		EXPECT_TRUE(oVersion.isLowerThan(oVersion2));
	}
	{
		const CVersion oVersion("10.1.1");
		const CVersion oVersion2("10.1.1");
		EXPECT_FALSE(oVersion.isLowerThan(oVersion2));
	}
}

TEST(Version, operators)
{
	const CVersion oVersion1("1.0.0");
	const CVersion oVersion2("1.0.1");
	const CVersion oVersion3("0.9.9");

	EXPECT_TRUE(oVersion1 == oVersion1);
	EXPECT_TRUE(oVersion2 > oVersion1);
	EXPECT_TRUE(oVersion3 < oVersion2);
}