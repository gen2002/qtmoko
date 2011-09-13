/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsopimmessagequery -c QFsoPIMMessageQuery specs/xml/org.freesmartphone.PIM.MessageQuery.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSOPIMMESSAGEQUERY_H
#define QFSOPIMMESSAGEQUERY_H

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
 * Proxy class for interface org.freesmartphone.PIM.MessageQuery
 */
class QFSO_EXPORT QFsoPIMMessageQuery: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.PIM.MessageQuery"; }

public:
    QFsoPIMMessageQuery(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoPIMMessageQuery();

public Q_SLOTS: // METHODS
    inline QFsoDBusPendingReply<> Dispose()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("Dispose"), argumentList);
    }

    inline QFsoDBusPendingReply<QString> GetMessagePath()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetMessagePath"), argumentList);
    }

    inline QFsoDBusPendingReply<QFsoVariantMapList> GetMultipleResults(int count)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(count);
        return fsoAsyncCall(QLatin1String("GetMultipleResults"), argumentList);
    }

    inline QFsoDBusPendingReply<QVariantMap> GetResult()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetResult"), argumentList);
    }

    inline QFsoDBusPendingReply<int> GetResultCount()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetResultCount"), argumentList);
    }

    inline QFsoDBusPendingReply<> Rewind()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("Rewind"), argumentList);
    }

    inline QFsoDBusPendingReply<> Skip(int count)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(count);
        return fsoAsyncCall(QLatin1String("Skip"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void MessageAdded(const QString &message_path);
};

namespace org {
  namespace freesmartphone {
    namespace PIM {
      typedef ::QFsoPIMMessageQuery MessageQuery;
    }
  }
}
#endif
