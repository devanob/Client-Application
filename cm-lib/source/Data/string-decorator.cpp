#include "string-decorator.h"

namespace cm {
namespace data {

class StringDecorator::Implementation{
    public:
    Implementation(StringDecorator& stringDecorator, const QString& value){
        this->stringDecorator = &stringDecorator;
        this->value = value;

    }
    StringDecorator* stringDecorator{nullptr};
     QString value;


};

StringDecorator::StringDecorator(Entity *parentEntity, const QString &key, const QString &label, const QString &value):DataDecorator (parentEntity,key,label)
{
    this->implementation.reset(new Implementation(*this,value));
}

StringDecorator &StringDecorator::setValue(const QString &value)
{
    if (value != this->implementation->value){
        //validation here
        this->implementation->value = value;
        emit this->valueChanged();

        return *this;
    }
}

const QString &StringDecorator::value() const
{
    return this->implementation->value;
}

QJsonValue StringDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(this->implementation->value));
}

void StringDecorator::update(const QJsonObject &jsonObject)
{
    if (jsonObject.contains(this->key())){
        setValue(jsonObject.value(this->key()).toString());

    }
    else{
        setValue("");
    }
}

StringDecorator::~StringDecorator()
{

}

}

}
