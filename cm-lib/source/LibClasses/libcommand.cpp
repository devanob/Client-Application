#include "source/LibClasses/libcommand.h"


namespace cm  {
namespace LibClasses  {
        class LibCommand::Implementation{
            public:
                Implementation(QString name, QString description, QString iconSymbol,
                std::function<bool()> isActive, std::function<void()> executeProcedure){
                    this->name= name;
                    this->description = description;
                    this->iconSymbol = iconSymbol;
                    this->isActive = isActive;
                    this->executeProcedure = executeProcedure;



                }
             QString name;
             QString iconSymbol;
             QString description;
             std::function<bool()> isActive;
             std::function<void()> executeProcedure;
        };
    }
}


cm::LibClasses::LibCommand::LibCommand(QObject* parent, QString name, QString description, QString iconSymbol,
                                       std::function<bool()> isActive,
                                       std::function<void()> executeProcedure
                                        ) :  QObject(parent){
    this->implementation.reset(new Implementation(name,description, iconSymbol, isActive, executeProcedure));
}

cm::LibClasses::LibCommand::~LibCommand(){

}

const QString cm::LibClasses::LibCommand::name()
{
    return this->implementation->name;
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
