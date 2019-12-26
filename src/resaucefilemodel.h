#ifndef QRESAUCEFILEMODEL_H
#define QRESAUCEFILEMODEL_H

#include <QFileSystemModel>
#include <QVariant>

class ResauceFileModel : public QFileSystemModel
{

    Q_OBJECT

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};

#endif // QRESAUCEFILEMODEL_H
