#include "source/LibClasses/libcommand.h"


namespace cm  {
namespace LibClasses  {
        class LibCommand::Implementation{
            public:
                Implementation(QString name, QString description, QString iconSymbol,
                std::function<bool()> isActive, std::function<void()> executeProcedure){
                    this->type= name;
                    this->description = description;
                    this->iconSymbol = iconSymbol;
                    this->isActive = isActive;
                    this->executeProcedure = executeProcedure;



                }
             QString type;
             QString iconSymbol;
             QString description;
             std::function<bool()> isActive;
             std::function<void()> executeProcedure;
        };
    }
}


cm::LibClasses::LibCommand::LibCommand(QObject* parent, QString type, QString description, QString iconSymbol,
                                       std::function<bool()> isActive,
                                       std::function<void()> executeProcedure
                                        ) :  QObject(parent){
    this->implementation.reset(new Implementation(type,description, iconSymbol, isActive, executeProcedure));
    connect(this,&LibCommand::executed, this, &LibCommand::executeProcedureHandlier);
}

cm::LibClasses::LibCommand::~LibCommand(){
    disconnect(this,&LibCommand::executed, this, &LibCommand::executeProcedureHandlier);
}

void cm::LibClasses::LibCommand::executeProcedureHandlier()
{
    this->implementation->executeProcedure();
}

const QString &cm::LibClasses::LibCommand::type() const
{
    return this->implementation->type;
}

const QString &cm::LibClasses::LibCommand::iconSymbol() const
{
    return this->implementation->iconSymbol;
}

const QString &cm::LibClasses::LibCommand::description() const
{
    return this->implementation->description;
}

bool cm::LibClasses::LibCommand::isActive() const
{
    return this->implementation->isActive();
}
