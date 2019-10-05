#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H
#include "cm-lib_global.h"
#include "source/LibClasses/libcommand.h"
#include <QObject>
#include <memory>
#include <QVector>
#include <QList>
#include <QtQml/QQmlListProperty>
#include <iostream>
//using namepsace
using namespace cm::LibClasses;
namespace cm  {
namespace controllers {
    class CMLIBSHARED_EXPORT CommandController : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QQmlListProperty<cm::LibClasses::LibCommand>
         ui_commands READ
         ui_commands NOTIFY commandContextChanged)
    public:
        explicit CommandController(QObject *parent = nullptr);
        ~CommandController();
        QQmlListProperty<LibCommand> ui_commands();
        void addCommands(QString type, QString description, QString iconSymbol,std::function<bool()> isActive,
                         std::function<void()> executeProcedure
                         );

    private:
        class Implementation;
        //internel implemenation of this controller
        std::unique_ptr<Implementation> implementation;



    signals:
        void setTypeNotifier(QString type);
        void commandContextChanged();

    public slots:


};
}
}


#endif // COMMANDCONTROLLER_H
