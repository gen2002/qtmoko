/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsogsmvoicemail -c QFsoGSMVoiceMail specs/xml/org.freesmartphone.GSM.VoiceMail.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSOGSMVOICEMAIL_H
#define QFSOGSMVOICEMAIL_H

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
 * Proxy class for interface org.freesmartphone.GSM.VoiceMail
 */
class QFSO_EXPORT QFsoGSMVoiceMail: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.GSM.VoiceMail"; }

public:
    QFsoGSMVoiceMail(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoGSMVoiceMail();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QStringList> GetStoredVoiceMails()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetStoredVoiceMails"), argumentList);
    }

    inline QDBusPendingReply<QString> GetVoiceMailboxNumber()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetVoiceMailboxNumber"), argumentList);
    }

    inline QDBusPendingReply<> SetVoiceMailboxNumber(const QString &number)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(number);
        return fsoAsyncCall(QLatin1String("SetVoiceMailboxNumber"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void IncomingVoiceMail(int index);
};

namespace org {
  namespace freesmartphone {
    namespace GSM {
      typedef ::QFsoGSMVoiceMail VoiceMail;
    }
  }
}
#endif
