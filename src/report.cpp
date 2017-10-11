/*
Mod Organizer shared UI functionality

Copyright (C) 2012 Sebastian Herbord. All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include "uibase/report.h"
#include "uibase/utility.h"

#include <QApplication>
#include <QMessageBox>
#include <common/sane_windows.h>

namespace MOBase {

void reportError(const QString& message) {
    // This is required because otherwise QT will crash if
    // an exception was thrown in, say, QApplication::notify/the event loop.
    // This seems to be a reliable way to determine if it is safe to display a MessageBox.
    auto title = QObject::tr("Error");
    if (QApplication::topLevelWidgets().count() != 0) {
        QMessageBox messageBox(QMessageBox::Warning, title, message, QMessageBox::Ok);
        messageBox.exec();
    } else {
        ::MessageBoxW(nullptr, message.toStdWString().c_str(), title.toStdWString().data(), MB_OK | MB_ICONERROR);
    }
}

} // namespace MOBase
