#include "resaucefilemodel.h"
#include "state.h"

#include <QDebug>
#include "fileutil.h"

void ResauceFileModel::put(ResauceFileInfo info) {
    files.append(info);
    emit layoutChanged();
}

ResauceFileInfo& ResauceFileModel::get(int index) {
    return files[index];
}

QVector<ResauceFileInfo>& ResauceFileModel::names() {
    return files;
}

// Overrides

int ResauceFileModel::columnCount(const QModelIndex&) const {

    return 3;

}

int ResauceFileModel::rowCount(const QModelIndex&) const {

    return files.size();

}

QVariant ResauceFileModel::data(const QModelIndex &index, int role) const {

    switch(role) {
        case Qt::DisplayRole: {
            auto file = files[index.row()];
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
