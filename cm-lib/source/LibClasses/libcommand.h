#ifndef LIBCOMMAND_H
#define LIBCOMMAND_H
#include <QObject>
#include <cm-lib_global.h>
#include <QString>
#include <memory>
#include <functional>
#include <iostream>
namespace cm {
namespace LibClasses {

    class CMLIBSHARED_EXPORT LibCommand : public QObject
    {
        Q_OBJECT
        Q_PROPERTY( QString ui_command_name READ iconSymbol CONSTANT )
        Q_PROPERTY( QString ui_description READ description CONSTANT )
        //Notifies The Ui if the isActice has chnaged
        Q_PROPERTY( bool ui_isActive READ isActive NOTIFY isActiveChanged)
        public:
            explicit LibCommand(QObject* parent = nullptr, QString name="None",
                                QString description="None",
                                QString iconSymbol="None",
                                std::function<bool()> isActive =[](){ return true;},
                                std::function<void()> executeProcedure =[](){
                                std::cout << "executed" << std::endl;
                                return;
                                    }
                                );
            ~LibCommand();

         private:
            class Implementation;
            std::unique_ptr<Implementation> implementation;
            const QString name();
            const QString& iconSymbol() const;
            const QString& description() const;
            bool isActive() const;
        signals:
            void isActiveChanged();
            void executed();


    };



}
}


#endif // LIBCOMMAND_H
