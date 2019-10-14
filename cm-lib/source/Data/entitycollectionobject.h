#ifndef ENTITYCOLLECTIONOBJECT_H
#define ENTITYCOLLECTIONOBJECT_H
#include "cm-lib_global.h"
#include <QObject>
/**
 * @brief The EntityCollectionObject base class
 */


namespace cm {
namespace data {
    class Entity;
    class CMLIBSHARED_EXPORT EntityCollectionObject : public QObject
    {
        Q_OBJECT
        public:
            EntityCollectionObject(QObject* parent);
            virtual ~EntityCollectionObject();
        signals:
            void collectionChanged();
    };


}
}


#endif // ENTITYCOLLECTIONOBJECT_H
