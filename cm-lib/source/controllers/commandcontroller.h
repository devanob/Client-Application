#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H
#include "cm-lib_global.h"
#include <QObject>

class CMLIBSHARED_EXPORT CommandController : public QObject
{
    Q_OBJECT
public:
    explicit CommandController(QObject *parent = nullptr);

signals:

public slots:
};

#endif // COMMANDCONTROLLER_H
