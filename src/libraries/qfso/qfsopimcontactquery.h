/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsopimcontactquery -c QFsoPIMContactQuery specs/xml/org.freesmartphone.PIM.ContactQuery.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSOPIMCONTACTQUERY_H
#define QFSOPIMCONTACTQUERY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <qfsodbusabstractinterface.h>
#include "qfsovariantmaplist.h"

#if defined(QFSO_LIBRARY)
    #define QFSO_EXPORT Q_DECL_EXPORT
#else
    #define QFSO_EXPORT Q_DECL_IMPORT
#endif

/*
 * Proxy class for interface org.freesmartphone.PIM.ContactQuery
 */
class QFSO_EXPORT QFsoPIMContactQuery: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.PIM.ContactQuery"; }

public:
    QFsoPIMContactQuery(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoPIMContactQuery();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Dispose()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("Dispose"), argumentList);
    }

    inline QDBusPendingReply<QString> GetContactPath()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetContactPath"), argumentList);
    }

    inline QDBusPendingReply<QFsoVariantMapList> GetMultipleResults(int count)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(count);
        return fsoAsyncCall(QLatin1String("GetMultipleResults"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> GetResult()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetResult"), argumentList);
    }

    inline QDBusPendingReply<int> GetResultCount()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetResultCount"), argumentList);
    }

    inline QDBusPendingReply<> Rewind()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("Rewind"), argumentList);
    }

    inline QDBusPendingReply<> Skip(int count)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(count);
        return fsoAsyncCall(QLatin1String("Skip"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void ContactAdded(const QString &contact_path);
};

namespace org {
  namespace freesmartphone {
    namespace PIM {
      typedef ::QFsoPIMContactQuery ContactQuery;
    }
  }
}
#endif
