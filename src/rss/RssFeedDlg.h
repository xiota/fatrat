/*
FatRat download manager
http://fatrat.dolezel.info

Copyright (C) 2006-2008 Lubos Dolezel <lubos a dolezel.info>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
version 3 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.

In addition, as a special exemption, Luboš Doležel gives permission
to link the code of FatRat with the OpenSSL project's
"OpenSSL" library (or with modified versions of it that use the; same
license as the "OpenSSL" library), and distribute the linked
executables. You must obey the GNU General Public License in all
respects for all of the code used other than "OpenSSL".
*/

#ifndef RSSFEEDDLG_H
#define RSSFEEDDLG_H
#include <QDialog>
#include "ui_RssFeedDlg.h"

class RssFeedDlg : public QDialog, Ui_RssFeedDlg
{
Q_OBJECT
public:
	RssFeedDlg(QWidget* parent)
	: QDialog(parent)
	{
		setupUi(this);
	}

	int exec()
	{
		int r;

		lineName->setText(m_strName);
		lineURL->setText(m_strURL);

		if((r = QDialog::exec()) == QDialog::Accepted)
		{
			m_strName = lineName->text();
			m_strURL = lineURL->text();
		}
		return r;
	}

	void accept()
	{
		if(!lineName->text().isEmpty() && !lineURL->text().isEmpty())
			QDialog::accept();
	}

	QString m_strName, m_strURL;
};

#endif
