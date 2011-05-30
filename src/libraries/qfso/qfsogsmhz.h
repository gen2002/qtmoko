/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsogsmhz -c QFsoGSMHZ specs/xml/org.freesmartphone.GSM.HZ.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSOGSMHZ_H
#define QFSOGSMHZ_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <qfsodbusabstractinterface.h>

#if defined(QFSO_LIBRARY)
    #define QFSO_EXPORT Q_DECL_EXPORT
#else
    #define QFSO_EXPORT Q_DECL_IMPORT
#endif

/*
 * Proxy class for interface org.freesmartphone.GSM.HZ
 */
class QFSO_EXPORT QFsoGSMHZ: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.GSM.HZ"; }

public:
    QFsoGSMHZ(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoGSMHZ();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QString> GetHomeZoneStatus()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetHomeZoneStatus"), argumentList);
    }

    inline QDBusPendingReply<QStringList> GetKnownHomeZones()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetKnownHomeZones"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void HomeZoneStatus(const QString &name);
};

namespace org {
  namespace freesmartphone {
    namespace GSM {
      typedef ::QFsoGSMHZ HZ;
    }
  }
}
#endif
