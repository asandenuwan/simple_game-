#include "enimys.h"

enimys::enimys(QFrame* f,int h):F(f),H(h) {}

void enimys::run(){
    y=0;
    srand(time(0));
    x=rand()%(H-20)+10;
    QMetaObject::invokeMethod(F,[&](){
        this->L=new QLabel(F);
        this->L->setGeometry(x,y,30,30);
        L->setStyleSheet("background-color:red;");
        L->show();
    },Qt::BlockingQueuedConnection);

    emit this->label(L);

    if(this->L!=nullptr){
        qDebug()<<"L is not null";
    }

    bool a=true;
    while (a) {

        y=0;
        x=rand()%(H-20)+10;
        while (y<H) {

            y++;

            QMetaObject::invokeMethod(F,[&](){
                if(L->isHidden()){
                    qDebug()<<"hidden";
                    a=false;
                }
                L->setGeometry(x,y,30,30);
            },Qt::BlockingQueuedConnection);
            if(a==false){break;}


            msleep(5);
        }
    }
}

QLabel* enimys::get_enimy(){
    if(this->L==nullptr){qDebug()<<"--label is null";}
    return this->L;
}
