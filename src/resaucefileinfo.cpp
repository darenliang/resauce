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


#include "resaucefileinfo.h"

ResauceFileInfo::ResauceFileInfo(const QString &file, const QString new_name) : QFileInfo(file) {

    this->new_name = new_name;

}

ResauceFileInfo::ResauceFileInfo() : QFileInfo() {}

QString ResauceFileInfo::fileNameWithoutExtension() {

    return fileName().left(fileName().lastIndexOf("."));

}

QString ResauceFileInfo::fileExtension() {

    if (!fileName().contains('.')) {
        return "";
    }

    return fileName().right(fileName().length() - fileName().lastIndexOf("."));

}
