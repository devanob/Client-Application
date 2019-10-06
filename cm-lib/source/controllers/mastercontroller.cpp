#include "source/controllers/mastercontroller.h"



namespace cm {
namespace controllers {

class MasterController::Implementation{
    public:
        Implementation(MasterController* _masterController) : masterController(_masterController){
            this->navigationController.reset(new NavigationController(masterController));
            this->commanndController.reset(new CommandController(masterController));
            this->commanndController->addCommands("create-client","Save","\uf0c7",[](){
                return true;}
           ,[](){
                std::cout << "save stuff " << std::endl;
            });
            this->commanndController->addCommands("dashboard","opendash","\uf210",[](){
                return true;}
           ,[](){
                std::cout << "dashboard stuff" << std::endl;
            });
            this->commanndController->addCommands("dashboard","closedash","\uf042",[](){
                return true;}
           ,[](){
                std::cout << "dashboard stuff" << std::endl;
            });


        }
        MasterController* masterController{nullptr};
        std::unique_ptr<NavigationController> navigationController{nullptr};
        std::unique_ptr<CommandController> commanndController{nullptr};
        QString welcomeMessage = "Welcome to The Cleint Application";
        };

}}

cm::controllers::MasterController::MasterController(QObject* parent) : QObject (parent)
{
    implementation.reset(new Implementation(this));
}

const QString& cm::controllers::MasterController::welcomeMessage() const{
    return this->implementation->welcomeMessage;
}

cm::controllers::MasterController::~MasterController(){

}

cm::controllers::NavigationController* cm::controllers::MasterController::navigationController()
{
 return implementation->navigationController.get();
}

cm::controllers::CommandController* cm::controllers::MasterController::commandController(){
    return implementation->commanndController.get();
}


