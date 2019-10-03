#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "source/controllers/mastercontroller.h"
#include "source/LibClasses/libcommand.h"
#include <QQmlContext>
/**
 * @brief intiateFileImport
 */
void intiateFileImport(){
qmlRegisterSingletonType( QUrl("qrc:assets/Style.qml"), "assets.Style", 1, 0, "Style" );
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<cm::controllers::MasterController>("CM", 1 , 0 , "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("CM", 1, 0,"NavigationController");
    qmlRegisterType<cm::LibClasses::LibCommand>("CM", 1, 0,"Command");
    cm::controllers::MasterController masterController;
    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:");
    intiateFileImport();
    engine.rootContext()->setContextProperty("masterController", &masterController);

    const QUrl url(QStringLiteral("qrc:views/MasterView.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
