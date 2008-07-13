/*
FatRat download manager
http://fatrat.dolezel.info

Copyright (C) 2006-2008 Lubos Dolezel <lubos a dolezel.info>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
version 2 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.
*/

#ifndef _FATRAT_H
#define _FATRAT_H

#include <QString>
#include <QThread>
#include <QUuid>
#include <QList>
#include <QVariant>
#include <QFile>
#include <QNetworkProxy>

#define VERSION "1.0"

QString formatSize(qulonglong size, bool persec = false);
QString formatTime(qulonglong secs);
QVariant getSettingsDefault(QString id);
QVariant getSettingsValue(QString id);
QWidget* getMainWindow();
void recursiveRemove(QString what);
bool openDataFile(QFile* file, QString filePath);

class Sleeper : public QThread
{
public:
	static void sleep(unsigned long secs) {QThread::sleep(secs);}
	static void msleep(unsigned long msecs) {QThread::msleep(msecs);}
	static void usleep(unsigned long usecs) {QThread::usleep(usecs);}
};

struct Proxy
{
	Proxy() : nType(ProxyNone) {}
	
	QString strName, strIP, strUser, strPassword;
	quint16 nPort;
	enum ProxyType { ProxyNone=-1, ProxyHttp, ProxySocks5 } nType;
	QUuid uuid;
	
	QString toString() const
	{
		return QString("%1 (%2)").arg(strName).arg( (nType==0) ? "HTTP" : "SOCKS 5");
	}
	operator QNetworkProxy() const;
	
	static QList<Proxy> loadProxys();
	static Proxy getProxy(QUuid uuid);
};

struct Auth
{
	QString strRegExp, strUser, strPassword;
	static QList<Auth> loadAuths();
};

enum FtpMode { FtpActive = 0, FtpPassive };

#endif
