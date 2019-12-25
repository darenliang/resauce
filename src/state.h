#ifndef STATE_H
#define STATE_H

#include <QtCore/QString>

class State {

    static QString folderName;

public:

    static const QString &getFolderName();

    static void setFolderName(const QString &fName);
};


#endif //STATE_H
