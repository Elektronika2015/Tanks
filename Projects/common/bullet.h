#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "common_lib.h"
class COMMON_LIBSHARED_EXPORT bullet : public QObject
{
    Q_OBJECT
public:
    explicit bullet(QObject *parent = 0);

signals:

public slots:
};

#endif // BULLET_H
