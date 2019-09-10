#include "enemy.h"

#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy()
{
    //Задаем рандомную позицию
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setRect(0, 0, 50, 50);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    //qDebug()<< "Shot!";
}

void Enemy::move()
{
    setPos(x(), y()+5);
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;

    }
}
