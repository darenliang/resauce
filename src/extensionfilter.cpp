#include "extensionfilter.h"

ExtensionFilter::ExtensionFilter(QVector<QString>& extensions): extensions(extensions) {}

ExtensionFilter::ExtensionFilter(QString extension) {
    extensions.append(extension);
}

bool ExtensionFilter::predicate(ResauceFileInfo info) {

    for (auto ext : extensions) {

        if (info.fileExtension() == ext) {

            return true; // The extension matches one of the accepted ones

        }

    }

    return false;

}
