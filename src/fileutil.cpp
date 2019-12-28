/*
 * Copyright (C) 2019 Daren Liang, George Lewis
 *
 * This file is part of Resauce.
 *
 * Resauce is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Resauce is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Resauce.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "fileutil.h"

#include <QDebug>

// Instantiate
QFileSystemModel FileUtil::model;

const QString FileUtil::sizes[] = {"B", "KB", "MB", "GB", "TB"};

QIcon FileUtil::getIcon(QString file) {

    auto dex = model.index(file);

    return model.fileIcon(dex);

}

QIcon FileUtil::getIcon(QFileInfo &file) { return getIcon(file.filePath()); }

qint64 FileUtil::getDirSize(QFileInfo &file) {

    qint64 total = 0;

    if (file.isDir()) {

        QDirIterator iter{file.absoluteFilePath(), QDir::NoDotAndDotDot | QDir::AllEntries};

        while (iter.hasNext()) {

            QFileInfo info{iter.next()};

            qDebug() << "Cur: " << file.absoluteFilePath() << " Scan: " << iter.next();

            total = total + getDirSize(info);

        }

    } else {
        total = file.size();
    }

    return total;

}

QPair<double, qint8> FileUtil::size(double s, qint8 index) {

    if (s >= 1000) {
        return size(s / 1000, index + 1);
    } else {
        return QPair<double, qint8>(s, index);
    }

}

QString FileUtil::sizeStr(QFileInfo &info) {

    auto p = size(info.size(), 0);

    return QString::number(p.first, 'f', 2) + " " + sizes[p.second];

}
