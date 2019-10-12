#ifndef ENUMERATORDECORATOR_H
#define ENUMERATORDECORATOR_H
#include <QJsonValue>
#include <QJsonObject>
#include <QObject>
#include <QVariant>
#include <memory>
#include <cm-lib_global.h>
#include <Data/data-decorator.h>
#include <cm-lib_global.h>
namespace cm {
namespace data {
    class  CMLIBSHARED_EXPORT EnumeratorDecorator : public DataDecorator
    {
        Q_OBJECT
        Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
        Q_PROPERTY(QString ui_valueDescription READ value NOTIFY valueChanged)
    public:
        EnumeratorDecorator(Entity* parentEntity = nullptr, const QString& key="DefaultKey",const QString& label ="", int value = 0,
                                const std::map<int,QString> & mappedDescription = std::map<int, QString>()
                            );

        ~EnumeratorDecorator() override;
        void setValue(int value);
        int value() const;
        QString description() const;
        QJsonValue jsonValue() const override;
        void update(const QJsonObject& jsonObject) override;
    signals:
        void valueChanged();
    private:
        class Implemenation;
        std::unique_ptr<Implemenation> implemenation;


    };

}}


#endif // ENUMERATORDECORATOR_H
