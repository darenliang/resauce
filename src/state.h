#ifndef STATE_H
#define STATE_H
#include <QtCore/QString>

class State {

    QString folderName;

public:
    static State &getInstance() {
        static State instance;
        return instance;
    }

    State(State const &) = delete;

    void operator=(State const &) = delete;

    void setFolderName(QString &fName);

    QString getFolderName();

private:
    State() {}
};


#endif //STATE_H
