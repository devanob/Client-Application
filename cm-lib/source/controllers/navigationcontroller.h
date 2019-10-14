#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H
#include <cm-lib_global.h>
#include <QObject>
#include "source/models/client.h"

namespace cm {
namespace controllers {

class CMLIBSHARED_EXPORT NavigationController : public QObject
{
        Q_OBJECT
    public:
        explicit NavigationController(QObject *parent = nullptr);

    signals:
         void goCreateClientView();
         void goDashboardView();
         void goEditClientView(cm::models::client* client);
         void goFindClientView();
         void goToCreateClientView();
         void goToDashboardView();
         void goToEditClientView(cm::models::client* client);
         void goToFindClientView();

    private:
         QString currentUI="none";

};
}}

#endif // NAVIGATIONCONTROLLER_H
