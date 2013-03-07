/***************************************************************************
* Copyright (c) 2013 Abdurrahman AVCI <abdurrahmanavci@gmail.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
***************************************************************************/

#ifndef SDE_DISPLAYSERVER_H
#define SDE_DISPLAYSERVER_H

#include <QObject>

class QProcess;

namespace SDE {

    class DisplayServer : public QObject {
        Q_OBJECT
        Q_DISABLE_COPY(DisplayServer)
    public:
        explicit DisplayServer(QObject *parent = 0);
        ~DisplayServer();

        void setDisplay(const QString &display);
        void setAuthPath(const QString &authPath);

    public slots:
        bool start();
        void stop();
        void finished();

    private:
        bool waitForStarted(int msecs = 10000);

        bool m_started { false };

        QString m_display { "" };
        QString m_authPath { "" };

        QProcess *process { nullptr };
    };
}

#endif // SDE_DISPLAYSERVER_H