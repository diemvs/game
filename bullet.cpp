#include "bullet.h"
#include "enemy.h"

#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    //qDebug()<< "Shot!";
}

void Bullet::move()
{
    //Проверяет попадание в врага
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //Движение выстрела
    setPos(x(), y()-10);
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;

    }
}
