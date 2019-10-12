#ifndef ENTITY_H
#define ENTITY_H
#include "Data/data-decorator.h"
#include <QObject>
#include <map>
#include "cm-lib_global.h"
namespace cm {
namespace data {
    class  CMLIBSHARED_EXPORT  Entity : public QObject
    {
        Q_OBJECT
        public:
            Entity(QObject *parent = nullptr, const QString& key = "defaultKey");
            Entity(QObject* parent, const QString& key,const QJsonObject& jsonObject);
            //class methods
            const QString& key() const;
            Entity *update(const QJsonObject& jsonObject);
            QJsonObject toJson() const;
            virtual ~Entity();
        protected:
            Entity* addChild(Entity* entity, const QString& key);
            DataDecorator* addDataItem(DataDecorator* data);
            class Implemenation;
            std::unique_ptr<Implemenation> implemetation;
        signals:
            void childEntitiesChanged();
            void dataDecoratorChanged();

        public slots:
    };

}
}


#endif // ENTITY_H
