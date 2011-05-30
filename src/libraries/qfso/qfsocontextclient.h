/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsocontextclient -c QFsoContextClient specs/xml/org.freesmartphone.Context.Client.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSOCONTEXTCLIENT_H
#define QFSOCONTEXTCLIENT_H

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
 * Proxy class for interface org.freesmartphone.Context.Client
 */
class QFSO_EXPORT QFsoContextClient: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.Context.Client"; }

public:
    QFsoContextClient(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoContextClient();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> LocationUpdate(const QVariantMap &from, const QVariantMap &to)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(from) << qVariantFromValue(to);
        return fsoAsyncCall(QLatin1String("LocationUpdate"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace freesmartphone {
    namespace Context {
      typedef ::QFsoContextClient Client;
    }
  }
}
#endif
