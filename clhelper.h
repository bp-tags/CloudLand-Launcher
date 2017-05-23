#ifndef CLHELPER_H
#define CLHELPER_H

#include <QJsonParseError>
#include <QJsonDocument>

QJsonDocument* parse(const QString* data) {
    QJsonParseError pErr;
    QJsonDocument doc = QJsonDocument::fromJson(data->toUtf8(), &pErr);
    if(pErr.error != QJsonParseError::NoError) {
        return NULL;
    }
    return &doc;
}

#endif // CLHELPER_H
