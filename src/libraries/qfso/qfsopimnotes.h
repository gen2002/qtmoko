/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsopimnotes -c QFsoPIMNotes specs/xml/org.freesmartphone.PIM.Notes.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSOPIMNOTES_H
#define QFSOPIMNOTES_H

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
 * Proxy class for interface org.freesmartphone.PIM.Notes
 */
class QFSO_EXPORT QFsoPIMNotes: public QFsoDbusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.PIM.Notes"; }

public:
    QFsoPIMNotes(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoPIMNotes();

public Q_SLOTS: // METHODS
    inline QFsoDBusPendingReply<QString> Add(const QVariantMap &note_data)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(note_data);
        return fsoAsyncCall(QLatin1String("Add"), argumentList);
    }

    inline QFsoDBusPendingReply<QString> GetSingleEntrySingleField(const QVariantMap &query, const QString &field)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(query) << qVariantFromValue(field);
        return fsoAsyncCall(QLatin1String("GetSingleEntrySingleField"), argumentList);
    }

    inline QFsoDBusPendingReply<QStringList> GetUsedTags()
    {
        QList<QVariant> argumentList;
        return fsoAsyncCall(QLatin1String("GetUsedTags"), argumentList);
    }

    inline QFsoDBusPendingReply<QString> Query(const QVariantMap &query)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(query);
        return fsoAsyncCall(QLatin1String("Query"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void NewNote(const QString &note_path);
    void NewTag(const QString &tag);
    void TagRemoved(const QString &tag);
};

namespace org {
  namespace freesmartphone {
    namespace PIM {
      typedef ::QFsoPIMNotes Notes;
    }
  }
}
#endif
