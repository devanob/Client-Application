#include "commandcontroller.h"

namespace cm {
namespace controllers  {
class CommandController::Implementation{
    public:
        Implementation(CommandController* parent_controller){
           this->parentController= parent_controller;
            connect(parentController, &CommandController::setTypeNotifier, [this](QString type){
                std::cout << type.toStdString() <<  std::endl;
                if (this->setCurrentTypeRequest(type)){

                    emit this->parentController->commandContextChanged();
                }
            });
            setCurrentTypeRequest();
        }
        bool setCurrentTypeRequest(QString type="default"){

            this->currentTypeRequest = type;
            QList<LibCommand*> contextCommands;
            for (auto & com : this->commandList){
                if(this->currentTypeRequest == com->type()){
                    contextCommands.append(com.get());
                }
            }
            this->currentCommandList = contextCommands;
            std::cout << commandList.size() << std::endl;
            return true;
        }
        ~Implementation(){

        }
        void setUp(){
            return;
        }
        void addCommands(QString type, QString description, QString iconSymbol,std::function<bool()> isActive,
                         std::function<void()> executeProcedure
                         )
        {
            auto command = std::make_shared<LibCommand>(this->parentController,type,description,iconSymbol,isActive,executeProcedure);
            commandList.append(command);
            setCurrentTypeRequest();
        }

        CommandController* parentController =nullptr;
        QList<std::shared_ptr<LibCommand>> commandList{};
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

void cm::controllers::CommandController::addCommands(QString type, QString description, QString iconSymbol,std::function<bool()> isActive,
                                                                 std::function<void()> executeProcedure
                                                ){
    this->implementation->addCommands(type,description,iconSymbol,isActive,executeProcedure);
}



