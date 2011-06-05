/****************************************************************************
**
** This file is part of the Qt Extended Opensource Package.
**
** Copyright (C) 2011 Radek Polak.
**
** Contact: Qt Extended Information (info@qtextended.org)
**
** This file may be used under the terms of the GNU General Public License
** version 2.0 as published by the Free Software Foundation and appearing
** in the file LICENSE.GPL included in the packaging of this file.
**
** Please review the following information to ensure GNU General Public
** Licensing requirements will be met:
**     http://www.fsf.org/licensing/licenses/info/GPLv2.html.
**
**
****************************************************************************/
#include "fsomodemservice.h"
#include "fsoservicechecker.h"
#include "fsophonerffunctionality.h"
#include "fsonetworkregistration.h"
#include "fsocallprovider.h"
#include "fsophonecall.h"

FsoModemService::FsoModemService
        ( const QString& service, QSerialIODeviceMultiplexer *mux,
          QObject *parent )
    : QModemService( service, mux, parent )
    , gsmNet("org.freesmartphone.ogsmd", "/org/freesmartphone/GSM/Device", QDBusConnection::systemBus(), this)
    , gsmCall("org.freesmartphone.ogsmd", "/org/freesmartphone/GSM/Device", QDBusConnection::systemBus(), this)
    , call_provider(this)
{
    connect(&gsmCall,
            SIGNAL(CallStatus(int, const QString &, const QVariantMap &)),
            this,
            SLOT(callStatusChange(int, const QString &, const QVariantMap &)));    
}

FsoModemService::~FsoModemService()
{
}

void FsoModemService::initialize()
{
    // Create our Fso-specific overrides for the service interfaces
 
     // If the modem does not exist, then tell clients via QServiceChecker.
    if ( !supports<QServiceChecker>() )
        addInterface( new FsoServiceChecker( service(), this ) );
 
    if ( !supports<QPhoneRfFunctionality>() )
        addInterface( new FsoRfFunctionality( service(), this ) );
 
    if ( !supports<QNetworkRegistration>() )
        addInterface( new FsoNetworkRegistration( this ) );

/*    if ( !supports<QSimInfo>() )
        addInterface( new FsoSimInfo( this ) );

    if ( !supports<QSimToolkit>() )
        addInterface( new FsoSimToolkit( this ) );

    if ( !supports<QPhoneBook>() )
        addInterface( new FsoPhoneBook( this ) );

    if ( !supports<QTelephonyConfiguration>() )
        addInterface( new FsoConfiguration( this ) );
	*/

    if ( !callProvider() )
        setCallProvider( &call_provider );

    // Call QModemService to create other interfaces that we didn't override.
    //QModemService::initialize();
}

void FsoModemService::callStatusChange(int id, const QString &status, const QVariantMap &properties)
{
    QString str = QString("id=%1, status=%2").arg(id).arg(status);
    for(int i = 0; i < properties.count(); i++)
    {
        QString key = properties.keys().at(i);
        str += ", " + key + "=" + properties.value(key).toString();
    }
    qDebug() << "CallStatusChange" << str;

    if(status == "INCOMING")
    {
        // Incoming calls have to be created here
        FsoPhoneCall *call = new FsoPhoneCall( this, NULL, "Voice", id );
        call->setNumber(properties.value("peer").toString());
        call->setFsoStatus(status);
        return;
    }
    
    // Check if it is an existing call
    QList<QPhoneCallImpl *> list = call_provider.calls();
    for(int i = 0; i < list.count(); i++)
    {
        FsoPhoneCall *call = static_cast<FsoPhoneCall*>(list.at(i));
        qDebug() << "call identifier=" << call->identifier() << ", call id=" << call->id;
        if(call->id == id)
        {
            call->setFsoStatus(status);
            return;
        }
    }

    if(status == "RELEASE")
    {
        return;     // Released call can have id -1, it was not found in the loop but that's ok
    }

    qWarning() << "callStatusChange: unhandled status for new call" << status;
}