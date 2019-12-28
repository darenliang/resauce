#ifndef QRESAUCEFILEMODEL_H
#define QRESAUCEFILEMODEL_H

#include "resaucefileinfo.h"

#include <QAbstractTableModel>
#include <QVariant>
#include <QVector>
#include <QFileIconProvider>

class ResauceFileModel : public QAbstractTableModel {

    Q_OBJECT

    QVector<ResauceFileInfo> files;

    QFileIconProvider icon_provider;

    // Overrides

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

public:

    void put(ResauceFileInfo info);

    ResauceFileInfo& get(int index);

    QVector<ResauceFileInfo>& names();

};

#endif // QRESAUCEFILEMODEL_H
