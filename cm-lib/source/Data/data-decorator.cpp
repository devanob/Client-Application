#include "data-decorator.h"

namespace cm {
namespace data {
    class DataDecorator::Implemenation{
        public:
        Implemenation(Entity* parentEntity, const QString& key, const QString& label){
            this->parentEntity = parentEntity;
            this->key = key;
            this->label = label;
        }
        public:
            QString key;
            QString label;
            Entity* parentEntity{nullptr};
    };

    DataDecorator::DataDecorator(Entity*parent, const QString &key, const QString &label) :QObject ((QObject*)parent)
    {
        this->implemenation.reset(new Implemenation(parent,key,label));
    }

    DataDecorator::~DataDecorator()
    {

    }

    QString DataDecorator::label() const
    {
        return implemenation->label;
    }

    QString DataDecorator::key() const
    {
        return implemenation->key;
    }

    Entity *DataDecorator::paarentEntity()
    {
        return this->implemenation->parentEntity;
    }



}
}

