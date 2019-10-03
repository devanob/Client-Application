#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <cm-lib_global.h>
#include "source/controllers/navigationcontroller.h"
#include <QString>
#include <memory>
namespace cm {
namespace controllers {

    class CMLIBSHARED_EXPORT MasterController : public QObject
    {
        Q_OBJECT
        //Message
        Q_PROPERTY(QString ui_welcomeMessage  READ welcomeMessage CONSTANT)
        Q_PROPERTY( cm::controllers::NavigationController*
                    ui_navigationController READ navigationController CONSTANT )

    public:
        explicit MasterController(QObject* parent = nullptr);
        const QString & welcomeMessage() const;
        NavigationController* navigationController();
        ~MasterController();
    public slots: // slots are public methods available in QML
        void doSomething(const QString &text);
    private:
        class Implementation;
        std::unique_ptr<Implementation> implementation;
    };

//

}
}


#endif // MASTERCONTROLLER_H
