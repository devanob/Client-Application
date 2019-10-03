#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H
#include "cm-lib_global.h"
#include "source/LibClasses/libcommand.h"
#include <QObject>
#include <memory>
#include <QVector>

//using namepsace
using namespace cm::LibClasses;
namespace cm  {
namespace controllers {
    class CMLIBSHARED_EXPORT CommandController : public QObject
    {
        Q_OBJECT
    public:
        explicit CommandController(QObject *parent = nullptr);
        ~CommandController();
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
