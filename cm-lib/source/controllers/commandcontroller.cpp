#include "commandcontroller.h"

namespace cm {
namespace controllers  {
class CommandController::Implementation{
    public:
        Implementation(CommandController* parent_controller){
           this->parentController= parentController;
            connect(parentController, &CommandController::setTypeNotifier, [this](QString type){
                if (this->setCurrentTypeRequest(type)){
                    emit this->parentController->commandContextChanged();
                }
            });
        }
        bool setCurrentTypeRequest(QString type="default"){
            this->currentTypeRequest = type;
            return true;
        }
        ~Implementation(){


        }
    private:
        CommandController* parentController =nullptr;
        QVector<LibCommand*> commandList;
        //generate from commandlist depends on currentRequestType
        QVector<LibCommand*> currentCommandList;
        //
        QString currentTypeRequest="default";



};
}
}


cm::controllers::CommandController::CommandController(QObject *parent) : QObject(parent)
{
    this->implementation.reset(new Implementation(this));
}

cm::controllers::CommandController::~CommandController()
{

}




