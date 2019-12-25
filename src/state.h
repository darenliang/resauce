#ifndef STATE_H
#define STATE_H
#include <QtCore/QString>

class State {

    static QString folderName;

public:

    State(State const &) = delete;

    void operator=(State const &) = delete;

    static void setFolderName(QString &fName);

    static const QString getFolderName();

private:
    State() {}
};


#endif //STATE_H
