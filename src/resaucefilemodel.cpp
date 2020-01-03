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


#include "resaucefilemodel.h"
#include "state.h"
#include "fileutil.h"
#include "resaucer.h"

#include <QDebug>
#include <algorithm>

#include "extensionfilter.h"

ResauceFileModel::ResauceFileModel(QVector<ResauceFilter*>* filters): QAbstractTableModel(), filters{filters} {}

void ResauceFileModel::put(ResauceFileInfo info) {
    files.append(info);
}

//void /*ResauceFileModel::putFilter(ResauceFilter filter) {
//    filters.append(filter);
//}*/

void ResauceFileModel::updateLayout() {
    emit layoutChanged();
}

ResauceFileInfo& ResauceFileModel::get(int index) {
    return files[index];
}

QVector<ResauceFileInfo>& ResauceFileModel::names() {
    return files;
}

// Slots

void ResauceFileModel::dir_changed(const QModelIndex& current, const QModelIndex&) {

    auto file = State::getDirectoryModel().fileInfo(current);

    qDebug() << file.absoluteFilePath();

    this->names().clear();

    Resaucer r;

    ResauceVariable x;

    x.name = "x";
    x.value = 1;
    x.incdec = 1;

    ResauceVariable s;

    s.name = "s";
    s.value = 1;
    s.incdec = 1;
    s.freq = 10;

    r.vars.append(x);
    r.vars.append(s);

    r._template = "Season {s} Episode {x}{.ext}";

    QDirIterator iter{file.absoluteFilePath(),
                      QDir::NoDotAndDotDot | QDir::Files}; // Create a dir iterator for the selected folder

    while (iter.hasNext()) {
        this->names().append(ResauceFileInfo(iter.next()));
    }

    this->filter();

    emit layoutChanged();

    // This will return later

//    while (iter.hasNext()) {
//        auto x = ResauceFileInfo(iter.next()); // Create file info
//        r.files.append(x);
//    }

//    r.process();

//    for (auto rfi : r.files) {
//        fileList.put(rfi);
//    }

//    fileList.updateLayout();

}

void ResauceFileModel::filter() {

    filtered.clear();

    if (filters->empty()) {
        for (auto f : files) {
            filtered.append(f);
        }
        return;
    }

    for (auto f : this->files) {

        for (auto predicate : *filters) {

            if (predicate->predicate(f)) {

                filtered.append(f);

                goto nextfile;

            }

        }

        nextfile:;

    }

}

// Overrides

int ResauceFileModel::columnCount(const QModelIndex&) const {

    return 3;

}

int ResauceFileModel::rowCount(const QModelIndex&) const {

    return filtered.size();

}

QVariant ResauceFileModel::data(const QModelIndex &index, int role) const {

    switch(role) {
        case Qt::DisplayRole: {
            auto file = filtered[index.row()];
            switch(index.column()) { // Get data by column and row
                case 0: return file.fileName();
                case 1: return file.new_name;
                case 2: return FileUtil::sizeStr(file);
                default: return QVariant();
            }
        }
        case Qt::DecorationRole: { // We need to decorate the index
            if (index.column() == 0) { // If "Name" index
                return icon_provider.icon(files[index.row()]); // Put an icon in there
            } else {
                return QVariant(); // Return no decoration
            }
        }
        default: return QVariant(); // Unhandled role
    }

}

QVariant ResauceFileModel::headerData(int section, Qt::Orientation, int role) const {

    if (role != Qt::DisplayRole) { // We only handle display role right now
        return QVariant();
    }

    switch (section) { // Custom model headers
        case 0: return "Name";
        case 1: return "New Name";
        case 2: return "Size";
        default: return QVariant();
    }

}

void ResauceFileModel::sort(int column, Qt::SortOrder order) {

    std::sort(filtered.begin(), filtered.end(), [&](ResauceFileInfo a, ResauceFileInfo b){

        if (column == 0 || column == 1) {
            auto ax = (column == 0) ? a.fileName() : a.new_name;
            auto bx = (column == 0) ? b.fileName() : b.new_name;
            if (order == Qt::AscendingOrder) {
                return QString::compare(ax, bx) <= 0;
            } else {
                return QString::compare(ax, bx) > 0;
            }
        }

        if (column == 2) {
            if (order == Qt::AscendingOrder) {
                return a.size() > b.size();
            } else {
                return a.size() <= b.size();
            }
        }

    });

    emit layoutChanged();

}
