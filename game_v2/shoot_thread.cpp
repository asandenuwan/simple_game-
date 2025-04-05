#include "shoot_thread.h"
#include <QDebug>
#include <QMetaObject>

shoot_thread::shoot_thread(QFrame* F,int x, int y,QVector<QLabel*>* l):F(F),x(x),y(y),L(l){qDebug()<<"fire";}

void shoot_thread::run(){
    qDebug()<<"run 1";
    QLabel* l=nullptr;
    int x1=x+12;
    QMetaObject::invokeMethod(F,[&](){
        l=new QLabel(F);
        l->setGeometry(x1,y,1,10);
        l->setStyleSheet("background-color:yellow;");
        l->show();
    },Qt::BlockingQueuedConnection);

    qDebug()<<"run 2";

    bool a=true;
    while (y>0 && a ) {
        y-=10;
        QMetaObject::invokeMethod(F,[&](){
            l->setGeometry(x1,y,1,10);
        },Qt::BlockingQueuedConnection);
        int i=0;
        for(QLabel* label:*(this->L)){
            i++;
            if(label!=nullptr){
                QMetaObject::invokeMethod(label,[&](){
                    int Lx=label->geometry().x();
                    int Ly=label->geometry().y();
                    int Lv=label->geometry().width();
                    int Lh=label->geometry().height();
                    if(((Lx+Lv)>=x) && (x>=Lx-10)){
                        if(((Ly+Lh)>=y) && (y>=Ly)){
                                l->hide();
                                label->hide();
                                l->setGeometry(0,0,0,0);
                                label->setGeometry(0,0,0,0);
                                a=false;
                        }
                    }
                },Qt::BlockingQueuedConnection);
                if(!a){break;}
            }
            else{qDebug()<<"------error-----";}
        }
        msleep(1);
    }

    QMetaObject::invokeMethod(F,[&](){
        l->hide();
        l->deleteLater();
    },Qt::BlockingQueuedConnection);

}

