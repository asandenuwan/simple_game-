#ifndef SHOOT_THREAD_H
#define SHOOT_THREAD_H

#include <QThread>
#include <QFrame>
#include <QLabel>
#include <QVector>


class shoot_thread:public QThread
{
public:
    QFrame* F;
    int y,x;
    QVector<QLabel*>* L;
    shoot_thread(QFrame* F,int x,int y,QVector<QLabel*>* l);
    void run();
};

#endif // SHOOT_THREAD_H
