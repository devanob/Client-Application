#ifndef DATADECORATOR_H
#define DATADECORATOR_H
#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <memory>
#include <cm-lib_global.h>
#include <QString>


namespace cm {
namespace data {

    class Entity; //forware delcaration
    class CMLIBSHARED_EXPORT  DataDecorator  : public QObject
    {
        Q_OBJECT
        Q_PROPERTY( QString ui_label READ label CONSTANT )
    public:
        explicit DataDecorator (Entity* parent, const QString& key="Default Key", const QString& label="Default Label");
        virtual ~DataDecorator ();
        QString label() const;
        QString key() const;
        Entity* paarentEntity();
        virtual QJsonValue jsonValue() const = 0;
        virtual void update(const QJsonObject& jsonObject) = 0;



    signals:

    public slots:

    private:
        class Implemenation;
        std::unique_ptr<Implemenation> implemenation;

    };
}}

#endif // ENTITY_H
