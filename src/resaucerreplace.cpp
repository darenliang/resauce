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


#include "resaucerreplace.h"

#include <utility>

ResaucerReplace::ResaucerReplace(QString start, QString end, bool caseBool) {
    startString = std::move(start);
    endString = std::move(end);
    caseInsensitive = caseBool;
}

void ResaucerReplace::compile() {
    QString tempCompile = templateRegex.replace("{{replaceString}}", startString);
    if (caseInsensitive) {
        tempCompile = templateRegex.replace("{{caseDisable}}", "(?i)")
                .replace("{{caseEnable}}", "(?-i)");
    } else {
        tempCompile = templateRegex.replace("{{caseDisable}}", "")
                .replace("{{caseEnable}}", "");
    }
    replaceRegex = QRegExp(tempCompile);
}

QString ResaucerReplace::execute(QString name) {
    compile();
    return name.replace(replaceRegex, endString);
}