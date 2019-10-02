#include "mastercontroller.h"



namespace cm {
namespace controllers {

class MasterController::Implementation{
    public:
        Implementation(MasterController* _masterController) : masterController(_masterController){
            navigationController = new NavigationController(masterController);

        }
        MasterController* masterController{nullptr};
        NavigationController* navigationController{nullptr};
        QString welcomeMessage = "This is MasterController to Major Tom";
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
 return implementation->navigationController;
}

void cm::controllers::MasterController::doSomething(const QString &text){

}
