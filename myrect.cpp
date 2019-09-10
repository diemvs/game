#include "myrect.h"
#include "bullet.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "U pressed a key!";
    if (event->key() == Qt::Key_A){
        if (pos().x() > 0)
        setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x() + 100 < 800)
        setPos(x()+10, y());
    }

    else if (event->key() == Qt::Key_W){
        if (pos().y() > 200)
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_S){
        if (pos().y() < 500)
        setPos(x(), y()+10);
    }
    //выстрел
    else if (event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        //qDebug() << "Bullet created!";
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }

}
