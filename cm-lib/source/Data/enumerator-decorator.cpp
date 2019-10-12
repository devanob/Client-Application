#include "enumerator-decorator.h"

namespace cm  {
namespace data  {

class EnumeratorDecorator::Implemenation{
    public:
        Implemenation(EnumeratorDecorator* parent, int value, const std::map<int, QString>& mappedDescription):mappedDescription(mappedDescription), parent(parent){
            this->mappedValue =value;

        }
        QString getDescription(){
            if (mappedDescription.find(this->mappedValue) != mappedDescription.end()) {
                return mappedDescription.at(mappedValue);
            }
            else {
                return {};
            }
        }

        EnumeratorDecorator* parent = nullptr;
        int mappedValue;
        std::map<int, QString> mappedDescription;
};

EnumeratorDecorator::EnumeratorDecorator(cm::data::Entity *parentEntity, const QString &key, const QString &label, int value, const std::map<int, QString> &mappedDescription)
    :DataDecorator (parentEntity,key,label)

{
    this->implemenation.reset(new Implemenation(this,value,mappedDescription));
}

EnumeratorDecorator::~EnumeratorDecorator()
{

}

void EnumeratorDecorator::setValue(int value)
{

}

int EnumeratorDecorator::value() const
{
    return this->implemenation->mappedValue;
}

QString EnumeratorDecorator::description() const
{
    return this->implemenation->getDescription();
}

QJsonValue EnumeratorDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(this->implemenation->getDescription()));
}

void EnumeratorDecorator::update(const QJsonObject &jsonObject)
{
    if (jsonObject.contains(this->key())){
        auto description = jsonObject.value(this->key()).toString();
        this->implemenation->mappedDescription.at(this->value()) = description;
    }

}
} //end namespace
}//end name space


