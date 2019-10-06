#include "source/Data/date-time-decorator.h"

namespace cm {
namespace data {

class DateTimeDecorator::Implementation{
    public:
    Implementation(DateTimeDecorator& stringDecorator, const QDateTime& value){
        this->stringDecorator = &stringDecorator;
        this->value = value;

    }
    //ToISOString
    QString toIso8601String() const
    {
         if (value.isNull()) {
            return "";
         }
         else {
            return value.toString(Qt::ISODate);
         }
    }
    //toPretty
    QString toPrettyString() const
    {
         if (value.isNull()) {
            return "Not set";
         }
         else {
            return value.toString( "ddd d MMM yyyy @ HH:mm:ss");
         }
    }
    //toPretty Date
    QString toPrettyDateString() const
    {
         if (value.isNull()) {
            return "Not set";
         }
         else {
            return value.toString( "d MMM yyyy" );
         }
    }
    //toPrettyTimeString
    QString toPrettyTimeString() const
    {
         if (value.isNull()) {
            return "Not set";
         }
         else {
            return value.toString( "hh:mm ap" );
         }
    }
    DateTimeDecorator* stringDecorator{nullptr};
    QDateTime value;


};

QString DateTimeDecorator::toIso8601String() const
{
    return this->implementation->toIso8601String();
}


QString DateTimeDecorator::toPrettyString() const
{
    return this->implementation->toPrettyString();
}

QString DateTimeDecorator::toPrettyDateString() const
{
    return this->implementation->toPrettyDateString();
}

QString DateTimeDecorator::toPrettyTimeString() const
{
    return this->implementation->toPrettyTimeString();
}

DateTimeDecorator::DateTimeDecorator(Entity *parentEntity, const QString &key, const QString &label, const QDateTime &value):DataDecorator (parentEntity,key,label)
{
    this->implementation.reset(new Implementation(*this,value));
}

DateTimeDecorator &DateTimeDecorator::setValue(const QDateTime &value)
{
    if (value != this->implementation->value){
        //validation here
        this->implementation->value = value;
        emit this->valueChanged();

        return *this;
    }
    else {
        return *this;
    }
}



QJsonValue DateTimeDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(this->implementation->value));
}

void DateTimeDecorator::update(const QJsonObject &jsonObject)
{
    if (jsonObject.contains(this->key())){
        QDateTime dateTime = QDateTime::fromString(jsonObject.value(this->key()).toString());
        setValue(dateTime);

    }
    else{
        setValue(QDateTime());
    }
}

DateTimeDecorator::~DateTimeDecorator()
{

}

}

}
