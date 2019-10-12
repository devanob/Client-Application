#include "entity.h"

namespace cm {
namespace data {
    //Implemenation
    class Entity::Implemenation {
    public:
        Implemenation(Entity* parent, const QString& key) : entityParent(parent), key(key){

        }
        //End
        Entity* entityParent = {nullptr};
        QString key;
        std::map<QString, Entity*> childEntities;
        std::map<QString, DataDecorator*> childDataDecorators;

        Entity* addChild(Entity *entity, const QString &key){
            if(childEntities.find(key) == std::end(childEntities)) {
                childEntities[key] = entity;
                if (entityParent != nullptr){
                    emit entityParent->childEntitiesChanged();
                }
            }
            return entity;
        }
        //End
        DataDecorator* addDataItem(DataDecorator* dataDecorator){
            if(childDataDecorators.find(dataDecorator->key()) == std::end(childDataDecorators)) {
                childDataDecorators[dataDecorator->key()] = dataDecorator;
                if(entityParent != nullptr)
                    emit entityParent->dataDecoratorChanged();
            }
            return dataDecorator;
        }//En
        Entity* update(const QJsonObject &jsonObject){
            //update children decorators
            for (auto& pair : this->childDataDecorators){
                pair.second->update(jsonObject);
            }
            //update entites children
            for (auto& pair: this->childEntities){
                pair.second->update(jsonObject.value(pair.first).toObject());
            }
            return this->entityParent;

        }
        QJsonObject toJson(){
            auto jsonObject = QJsonObject(); //make an empty json object
            for (auto& pair : this->childDataDecorators){
                jsonObject.insert(pair.first, pair.second->jsonValue());
            }
            for (auto& pair: this->childEntities){
                jsonObject.insert(pair.first, pair.second->toJson());
            }
            return jsonObject;
        }


    };

    //Non-implemenation
    Entity::Entity(QObject *parent, const QString &key) : QObject (parent)
    {
        this->implemetation.reset(new Implemenation(this,key));
    }

    Entity::Entity(QObject *parent, const QString &key, const QJsonObject &jsonObject) : Entity(parent, key)
    {
        this->update(jsonObject);
    }

    const QString &Entity::key() const
    {
        return  this->implemetation->key;
    }

    Entity* Entity::update(const QJsonObject &jsonObject)
    {
        return this->implemetation->update(jsonObject);
    }

    QJsonObject Entity::toJson() const
    {
       return this->implemetation->toJson();
    }

    Entity::~Entity()
    {

    }

    Entity* Entity::addChild(Entity *entity, const QString &key)
    {
        return  this->implemetation->addChild(entity,key);
    }

    DataDecorator* Entity::addDataItem(DataDecorator *data)
    {
        return this->implemetation->addDataItem(data);
    }


}}
