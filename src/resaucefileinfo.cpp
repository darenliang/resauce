#include "resaucefileinfo.h"

ResauceFileInfo::ResauceFileInfo(const QString& file, const QString new_name): QFileInfo(file) {

    this->new_name = new_name;

}
