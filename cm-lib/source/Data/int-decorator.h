#ifndef INTDECORATOR_H
#define INTDECORATOR_H
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
    class CMLIBSHARED_EXPORT  IntDecorator : public DataDecorator
    {
        Q_OBJECT
        Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged )

    public:
        IntDecorator(Entity* parentEntity, const QString& key, const QString& label, const int& value);
        IntDecorator& setValue(const int& value);
        const int& value() const;
        QJsonValue jsonValue() const override;
        void update(const QJsonObject& jsonObject) override;
        ~IntDecorator() override;
    signals:
        void valueChanged();
    private:
        class Implementation;
        std::unique_ptr<Implementation> implementation;
    };

}
}



#endif // INTDECORATOR_H
