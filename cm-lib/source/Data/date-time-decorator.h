#ifndef DATETIMEDECORATOR_H
#define DATETIMEDECORATOR_H

#include "source/Data/data-decorator.h"
#include <cm-lib_global.h>
#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <memory>
#include <QString>
#include <QVariant>
#include <QDateTime>
namespace cm {
    namespace data {
    class CMLIBSHARED_EXPORT  DateTimeDecorator : public DataDecorator
    {
        Q_OBJECT
        Q_PROPERTY( QString ui_iso8601String READ toIso8601String NOTIFY
        valueChanged )
        Q_PROPERTY( QString ui_prettyDateString READ toPrettyDateString NOTIFY
        valueChanged )
        Q_PROPERTY( QString ui_prettyTimeString READ toPrettyTimeString NOTIFY
        valueChanged )
        Q_PROPERTY( QString ui_prettyString READ toPrettyString NOTIFY valueChanged
        )

    public:
        //get datetime String Values
        QString toIso8601String() const;
        QString toPrettyString() const;
        QString toPrettyDateString() const;
        QString toPrettyTimeString() const;
        //end

        DateTimeDecorator(Entity* parentEntity, const QString& key, const QString& label, const QDateTime& value);
        DateTimeDecorator& setValue(const QDateTime& value);
//        const QDateTime& value() const;
        QJsonValue jsonValue() const override;
        void update(const QJsonObject& jsonObject) override;
        ~DateTimeDecorator() override;

    signals:
        void valueChanged();
    private:
        class Implementation;
        std::unique_ptr<Implementation> implementation;
    };

    }




}



#endif // DATETIMEDECORATOR_H
