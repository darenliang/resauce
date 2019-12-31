#include "extensionfilter.h"

ExtensionFilter::ExtensionFilter(QVector<QString>& extensions): extensions(extensions) {}

ExtensionFilter::ExtensionFilter(QString& extension) {
    extensions.append(extension);
}

QString ExtensionFilter::ext(QString &name) {

    return name.right( name.length() - name.lastIndexOf('.') );

}

bool ExtensionFilter::predicate(QString &name) {

    for (auto ext : extensions) {

        if (ExtensionFilter::ext(name) == ext) {

            return true; // The extension matches one of the accepted ones

        }

    }

    return false;

}
