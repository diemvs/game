#include "game.h"
#include "myrect.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene();

    MyRect *rectItem = new MyRect();
    rectItem->setRect(0,0,100,100);

    scene->addItem(rectItem);

    rectItem->setFlag(QGraphicsItem::ItemIsFocusable);
    rectItem->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    view->show();
    view->setFixedSize(800, 600);
    scene->setSceneRect(0,0,800,600);
    rectItem->setPos(view->width()/2, view->height() - rectItem->rect().height());

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), rectItem, SLOT(spawn()));


    timer->start(2000);

    return a.exec();
}
