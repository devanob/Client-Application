#ifndef ENTITYCOLLECTIONBASE_H
#define ENTITYCOLLECTIONBASE_H
#include "entitycollectionobject.h"
#include <QJsonArray>
#include<QJsonObject>
namespace cm {
namespace data {
    class CMLIBSHARED_EXPORT EntityCollectionBase : public EntityCollectionObject
    {
    public:
        EntityCollectionBase(QObject* parent = nullptr, const QString& key = "default-key");
        QString getKey() const
        {
            return  this->key;
        }
        virtual ~EntityCollectionBase();
        virtual bool clear() = 0;
        virtual void update(const QJsonArray& json) = 0;
        virtual std::vector<Entity*> baseEntities() = 0;

        template <class T>
        QList<T*>& derivedEntities();

        template <class T>
        T* addEntity(T* entity);
    private:
        QString key;
    };

    //
    template <typename T>
    class EntityCollection : public EntityCollectionBase
    {
        public:
        EntityCollection(QObject* parent = nullptr, const QString& key ="SomeCollectionKey") :EntityCollectionBase(parent, key){

        }
        ~EntityCollection(){

        }
        bool clear() override{
            for(auto entity : collection) {
                entity->deleteLater();
            }
            collection.clear();
        }
        void update(const QJsonArray& jsonArray) override{
            clear();
            for(const QJsonValue& jsonValue : jsonArray) {
                addEntity(new T(this, jsonValue.toObject()));
            }
        }

        std::vector<Entity*> baseEntities() override{
            std::vector<Entity*> returnValue;
            for(T* entity : collection) {
                returnValue.push_back(entity);
            }
            return returnValue;
         }

        QList<T*>& derivedEntities(){
            return collection;
        }

        T* addEntity(T* entity){
            if(!collection.contains(entity)) {
                collection.append(entity);
                emit this->collectionChanged();
            }
            return entity;
        }

        private:
            QList<T*> collection;
        };
    //Defered Implementation

    template <class T>
    QList<T*>& EntityCollectionBase::derivedEntities()
    {
        return dynamic_cast<const EntityCollection<T>&>(*this).derivedEntities();
    }

    template <class T>
    T* EntityCollectionBase::addEntity(T* entity)
    {
        return dynamic_cast<const EntityCollection<T>&>(*this).addEntity(entity);
    }
}
}





#endif // ENTITYCOLLECTIONBASE_H
