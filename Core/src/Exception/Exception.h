#pragma once

#include <qexception.h>
#include <qstring.h>

#define OVERWRITE_RAISE() virtual void raise() const override { throw *this; }

#define OVERWRITE_CLONE(c) virtual c* clone() const override { return new c(*this); }

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define ERROR_HERE QString(__FILE__  " Line: " TOSTRING(__LINE__) " Function: " __FUNCTION__)

namespace NCore
{
	enum EExceptionID
	{
		EUnknown = 0,
		ENotImplemented = 1,
		EInvalidConfigValueType = 2,
		EAlreadyContains = 3,
		EFileNotExists = 4,
		ENullptr = 5,
		EFactoryMissing = 6,
		ESubComponentMissing = 7,
		EWrongComponent = 8,
		ECompareFailed = 9,
		ESubComponentLinkingFailed = 10,
	};

	class CException : public QException
	{
	public:
		CException();

		CException(const EExceptionID i_eID, const QString& i_sWhat, const QString& i_sLocation);

		CException(const EExceptionID i_eID, const QString& i_sWhat, const QString& i_sFix, const QString& i_sLocation);

		virtual ~CException() = default;

	public:
		const QString& msg() const;

		const QString& location() const;

		const QString& fix() const;

		EExceptionID expectionID() const;

	public:
		OVERWRITE_RAISE();

		OVERWRITE_CLONE(CException);

	private:
		const QString m_sWhat;

		const QString m_sLocation;

		const QString m_sFix;

		const EExceptionID m_eID;
	};
}