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


#ifndef QRESAUCEFILEMODEL_H
#define QRESAUCEFILEMODEL_H

#include "resaucefileinfo.h"
#include "resaucefilter.h"

#include <QAbstractTableModel>
#include <QVariant>
#include <QVector>
#include <QFileIconProvider>

class ResauceFileModel : public QAbstractTableModel {

    Q_OBJECT

    QVector<ResauceFileInfo> files;
    QVector<ResauceFileInfo> filtered;

    QVector<ResauceFilter*>* filters;

    QFileIconProvider icon_provider;

    // Overrides

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;

    Qt::ItemFlags flags(const QModelIndex&) const override;

public:

    ResauceFileModel(QVector<ResauceFilter*>*);

    void put(ResauceFileInfo info);

//    void putFilter(ResauceFilter filter);

    ResauceFileInfo &get(int index);

    QVector<ResauceFileInfo> &names();

public slots:

    void dir_changed(const QModelIndex&, const QModelIndex&);

    void filter();

    void updateLayout();

};

#endif // QRESAUCEFILEMODEL_H
