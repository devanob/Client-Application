#include "source/Data/int-decorator.h"

namespace cm {
namespace data {
class IntDecorator::Implementation{
    public:
    Implementation(IntDecorator& stringDecorator, const int& value){
        this->stringDecorator = &stringDecorator;
        this->value = value;

    }
    IntDecorator* stringDecorator{nullptr};
    int value;


};

IntDecorator::IntDecorator(Entity *parentEntity, const QString &key, const QString &label, const int &value):DataDecorator (parentEntity,key,label)
{
    this->implementation.reset(new Implementation(*this,value));
}

IntDecorator& IntDecorator::setValue(const int &value)
{
    if (value != this->implementation->value){
        //validation here
        this->implementation->value = value;
        emit this->valueChanged();

        return *this;
    }
    else{
        return *this;
    }
}

const int& IntDecorator::value() const
{
    return this->implementation->value;
}

QJsonValue IntDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(this->implementation->value));
}

void IntDecorator::update(const QJsonObject &jsonObject)
{
    if (jsonObject.contains(this->key())){
        setValue(jsonObject.value(this->key()).toInt());

    }
    else{
        setValue(0);
    }
}

IntDecorator::~IntDecorator()
{

}
}
}
