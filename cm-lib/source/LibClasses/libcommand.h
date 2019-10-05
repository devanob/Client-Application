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
        Q_PROPERTY( QString ui_command_icon READ iconSymbol CONSTANT )
        Q_PROPERTY( QString ui_description READ description CONSTANT )
        //Notifies The Ui if the isActice has chnaged
        Q_PROPERTY( bool ui_isActive READ isActive NOTIFY isActiveChanged)
        //signal connection

        public:
            explicit LibCommand(QObject* parent = nullptr, QString type="default",
                                QString description="Default",
                                QString iconSymbol="Default",
                                std::function<bool()> isActive =[](){ return true;},
                                std::function<void()> executeProcedure =[](){
                                std::cout << "executed" << std::endl;
                                return;
                                    }
                                );
            ~LibCommand();
        const QString& type() const;
        const QString& iconSymbol() const;
        const QString& description() const;

        bool isActive() const;
       public slots:
           void executeProcedureHandlier();

         private:
            class Implementation;
            std::unique_ptr<Implementation> implementation;
        signals:
            void isActiveChanged();
            void executed();




    };



}
}


#endif // LIBCOMMAND_H
