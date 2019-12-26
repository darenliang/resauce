#include "resaucefilemodel.h"
#include "state.h"

ResauceFileModel::ResauceFileModel() {

    this->setFilter(QDir::Files | QDir::NoDotAndDotDot);

}

int ResauceFileModel::columnCount(const QModelIndex &parent) const {

    return QFileSystemModel::columnCount(parent) + 1;

}

QVariant ResauceFileModel::headerData(int section, Qt::Orientation orientation, int role) const {

    if (section == 1) {
        return "New Name";
    } else {
        return QFileSystemModel::headerData(section, orientation, role);
    }

}

QVariant ResauceFileModel::data(const QModelIndex &index, int role) const {

    if (!index.isValid() || index.model() != this)
            return QVariant();

    if (index.column() == 1) {

        switch (role) {

            case Qt::DisplayRole: return new_names[this->fileInfo(index).fileName()];

            default: return QFileSystemModel::data(index, role);

        }

    } else {
        return QFileSystemModel::data(index, role);
    }

}
