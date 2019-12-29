#include "resaucer.h"

Resaucer::Resaucer() {}

void Resaucer::process() {

    for (auto& file : files) {

        auto name = file.fileName();

        auto ext = file.fileExtension();

        QHash<QString, QString> extracted;

        QString output = _template;

        for (auto& regex : extractors) {

            auto match = regex.match(name);

            if (match.hasMatch()) {

                for (auto group : regex.namedCaptureGroups()) {

                    extracted[group] = match.captured(group);

                }

            }

        }

        for (auto& group : extracted.keys()) {

            output = output.replace("{"+group+"}", extracted[group]);

        }

        for (auto& var : vars) {

            output = output.replace("{" + var.name + "}", QString::number(var.value));

            var.count++;

            if (var.count >= var.freq) {

                var.count = 0;

                var.value += var.incdec;

            }

        }

        output = output.replace("{.ext}", file.fileExtension());

        file.new_name = output;

    }

}
