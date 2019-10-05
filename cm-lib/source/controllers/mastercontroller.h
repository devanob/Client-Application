#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H
#include <memory>
#include <QObject>
#include <cm-lib_global.h>
#include "source/controllers/navigationcontroller.h"
#include "source/controllers/commandcontroller.h"
#include <QString>


namespace cm {
namespace controllers {

    class CMLIBSHARED_EXPORT MasterController : public QObject
    {
        Q_OBJECT
        //Message
        Q_PROPERTY(QString ui_welcomeMessage  READ welcomeMessage CONSTANT)
        Q_PROPERTY( cm::controllers::NavigationController*
                    ui_navigationController READ navigationController CONSTANT )
        Q_PROPERTY( cm::controllers::CommandController*
                    ui_commandController READ  commandController CONSTANT )

    public:
        explicit MasterController(QObject* parent = nullptr);
        const QString & welcomeMessage() const;
        NavigationController* navigationController();
        CommandController * commandController();
        ~MasterController();
    public slots: // slots are public methods available in QML
    private:
        class Implementation;
        std::unique_ptr<Implementation> implementation;
    };

//

}
}


#endif // MASTERCONTROLLER_H
