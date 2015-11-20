#include "tank.h"

Tank::Tank(QString playerName)
    :name(playerName)
{
    czolg = new TankModel;
    czolg->setFocus();
}
