#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score=0;
    setPlainText(QString("Ilość zestrzelonych czołgów: ")+QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    score++;
    setPlainText(QString("Ilość zestrzelonych czołgów: ")+QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}

