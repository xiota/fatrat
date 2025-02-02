/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -p NotificationsProxy -a NotificationsAdaptor org.freedesktop.Notifications.xml
 *
 * qdbusxml2cpp is Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef NOTIFICATIONSPROXY_H_1306780651
#define NOTIFICATIONSPROXY_H_1306780651

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.Notifications
 */
class OrgFreedesktopNotificationsInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.Notifications"; }

public:
    OrgFreedesktopNotificationsInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopNotificationsInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> CloseNotification(uint id)
    {
        QList<QVariant> argumentList;
		argumentList << QVariant::fromValue(id);
        return asyncCallWithArgumentList(QLatin1String("CloseNotification"), argumentList);
    }

    inline QDBusPendingReply<QStringList> GetCapabilities()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetCapabilities"), argumentList);
    }

    inline QDBusPendingReply<QString, QString, QString, QString> GetServerInformation()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetServerInformation"), argumentList);
    }
    inline QDBusReply<QString> GetServerInformation(QString &return_vendor, QString &return_version, QString &return_spec_version)
    {
        QList<QVariant> argumentList;
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QLatin1String("GetServerInformation"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 4) {
            return_vendor = qdbus_cast<QString>(reply.arguments().at(1));
            return_version = qdbus_cast<QString>(reply.arguments().at(2));
            return_spec_version = qdbus_cast<QString>(reply.arguments().at(3));
        }
        return reply;
    }

    inline QDBusPendingReply<uint> Notify(const QString &app_name, uint id, const QString &icon, const QString &summary, const QString &body, const QStringList &actions, const QVariantMap &hints, int timeout)
    {
        QList<QVariant> argumentList;
		argumentList << QVariant::fromValue(app_name) << QVariant::fromValue(id) << QVariant::fromValue(icon) << QVariant::fromValue(summary) << QVariant::fromValue(body) << QVariant::fromValue(actions) << QVariant::fromValue(hints) << QVariant::fromValue(timeout);
        return asyncCallWithArgumentList(QLatin1String("Notify"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace freedesktop {
    typedef ::OrgFreedesktopNotificationsInterface Notifications;
  }
}
#endif
