#ifndef QRESAUCEFILEMODEL_H
#define QRESAUCEFILEMODEL_H

#include <QFileSystemModel>
#include <QVariant>
#include <QHash>

class ResauceFileModel : public QFileSystemModel
{

    Q_OBJECT

    QHash<QString, QString> new_names;

    // Overrides

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public:

    ResauceFileModel();

    void put(QString& old, QString& _new);

    QString& get(QString& old);

};

#endif // QRESAUCEFILEMODEL_H
