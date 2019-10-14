#include "entity-collection-base.h"
namespace cm {
namespace data {
    EntityCollectionBase::EntityCollectionBase(QObject* parent , const QString& key)
        :EntityCollectionObject (parent), key(key)
    {

    }

    EntityCollectionBase::~EntityCollectionBase()
    {

    }
}
}
