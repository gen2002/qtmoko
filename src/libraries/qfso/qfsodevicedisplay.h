/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsodevicedisplay -c QFsoDeviceDisplay specs/xml/org.freesmartphone.Device.Display.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSODEVICEDISPLAY_H
#define QFSODEVICEDISPLAY_H

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
 * Proxy class for interface org.freesmartphone.Device.Display
 */
class QFSO_EXPORT QFsoDeviceDisplay: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.Device.Display"; }

public:
    QFsoDeviceDisplay(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoDeviceDisplay();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<bool> GetBacklightPower()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetBacklightPower"), argumentList);
    }

    inline QDBusPendingReply<int> GetBrightness()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetBrightness"), argumentList);
    }

    inline QDBusPendingReply<> SetBacklightPower(bool power)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(power);
        return fsoAsyncCall(QLatin1String("SetBacklightPower"), argumentList);
    }

    inline QDBusPendingReply<> SetBrightness(int brightness)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(brightness);
        return fsoAsyncCall(QLatin1String("SetBrightness"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void BacklightPower(bool power);
};

namespace org {
  namespace freesmartphone {
    namespace Device {
      typedef ::QFsoDeviceDisplay Display;
    }
  }
}
#endif
