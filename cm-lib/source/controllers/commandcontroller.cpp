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
            setCurrentTypeRequest();
        }
        bool setCurrentTypeRequest(QString type="default"){
            this->currentTypeRequest = type;
            QList<LibCommand*> contextCommands;
            for (LibCommand* com : this->commandList){
                if (com->type() == this->currentTypeRequest){
                    contextCommands.append(com);
                }
            }
            this->currentCommandList = contextCommands;
            return true;
        }
        ~Implementation(){


        }
        void setUp(){

        }
        void addCommands(){

        }
        CommandController* parentController =nullptr;
        QList<LibCommand*> commandList{};
        //generate from commandlist depends on currentRequestType
        QList<LibCommand*> currentCommandList{};
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

QQmlListProperty<LibCommand> cm::controllers::CommandController::ui_commands()
{
    return QQmlListProperty<LibCommand>(this,this->implementation->currentCommandList);
}




