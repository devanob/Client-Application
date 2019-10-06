#ifndef STRINGDECORATOR_H
#define STRINGDECORATOR_H
#include "source/Data/data-decorator.h"
#include <cm-lib_global.h>
#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <memory>
#include <QString>
#include <QVariant>

namespace cm {
    namespace data {
    class CMLIBSHARED_EXPORT  StringDecorator : public DataDecorator
    {
        Q_OBJECT
        Q_PROPERTY(QString ui_value READ value WRITE setValue NOTIFY valueChanged )

    public:
        StringDecorator(Entity* parentEntity, const QString& key, const QString& label, const QString& value);
        StringDecorator& setValue(const QString& value);
        const QString& value() const;
        QJsonValue jsonValue() const override;
        void update(const QJsonObject& jsonObject) override;
        ~StringDecorator() override;
    signals:
        void valueChanged();
    private:
        class Implementation;
        std::unique_ptr<Implementation> implementation;
    };

    }




}

#endif // STRINGDECORATOR_H

