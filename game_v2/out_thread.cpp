#include "out_thread.h"
out_thread::out_thread(QVector<QLabel*>* list,QLabel* c,QFrame* F):enmy_list(list),c(c),F(F) {}

void out_thread::out(){
    QMetaObject::invokeMethod(F,[&]{
       F->setStyleSheet("background-color:red;");
    },Qt::BlockingQueuedConnection);
    emit this->out_signal_1(true);
}

void out_thread::run(){
    while (1) {
        qDebug()<<"run 1";
        for(QLabel* l:*(this->enmy_list)){
            int x1,x2,y1,y2,cx1,cx2,cy1,cy2=0;
            qDebug()<<"run 2";
            QMetaObject::invokeMethod(l,[&]{
                x1=l->geometry().x();
                x2=l->geometry().x()+l->geometry().width();
                y1=l->geometry().y();
                y2=l->geometry().y()+l->geometry().height();

                cx1=this->c->geometry().x();
                cx2=this->c->geometry().x()+this->c->geometry().width();
                cy1=this->c->geometry().y();
                cy2=this->c->geometry().y()+this->c->geometry().height();
            },Qt::BlockingQueuedConnection);

            if(cx1>=x1 && cx1<=x2){
                if(cy1>=y1&&cy1<=y2){
                    this->out();
                }
            }

            if(cx2>=x1 && cx2<=x2){
                if(cy1>=y1&&cy1<=y2){
                    this->out();
                }
            }

            if(cy2>=y1 && cy2<=y2){
                if(cx1>=x1 && cx1<=x2){
                    this->out();
                }
            }

            if(cy2>=y1 && cy2<=y2){
                if(cx2>=x1 && cx2<=x2){
                    this->out();
                }
            }
        }
    }
}


void out_thread::stop(){
    this->setTerminationEnabled(true);
}
