/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsodataworld -c QFsoDataWorld specs/xml/org.freesmartphone.Data.World.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSODATAWORLD_H
#define QFSODATAWORLD_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <qfsodbusabstractinterface.h>
#include "qfsoworldcountry.h"
#include "qfsoworldconnectivityaccesspoint.h"
#include "qfsostringmap.h"

#if defined(QFSO_LIBRARY)
    #define QFSO_EXPORT Q_DECL_EXPORT
#else
    #define QFSO_EXPORT Q_DECL_IMPORT
#endif

/*
 * Proxy class for interface org.freesmartphone.Data.World
 */
class QFSO_EXPORT QFsoDataWorld: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.Data.World"; }

public:
    QFsoDataWorld(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoDataWorld();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QFsoWorldCountry> GetAllCountries()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetAllCountries"), argumentList);
    }

    inline QDBusPendingReply<QFsoWorldConnectivityAccessPoint> GetApnsForMccMnc(const QString &mcc_mnc)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(mcc_mnc);
        return fsoAsyncCall(QLatin1String("GetApnsForMccMnc"), argumentList);
    }

    inline QDBusPendingReply<QString> GetCountryCodeForMccMnc(const QString &mcc_mnc)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(mcc_mnc);
        return fsoAsyncCall(QLatin1String("GetCountryCodeForMccMnc"), argumentList);
    }

    inline QDBusPendingReply<QFsoStringMap> GetTimezonesForCountryCode(const QString &country_code)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(country_code);
        return fsoAsyncCall(QLatin1String("GetTimezonesForCountryCode"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace freesmartphone {
    namespace Data {
      typedef ::QFsoDataWorld World;
    }
  }
}
#endif
