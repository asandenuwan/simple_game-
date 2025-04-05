#include "game.h"
#include "ui_gui.h"
#include <QDebug>
#include <QThread>

game::game(QWidget *parent): QMainWindow(parent), ui(new Ui::game){

    ui->setupUi(this);
    c=new QLabel(this->ui->play_ground);
    c->setText("");
    this->resize(900,700);
    ui->life_bar->setValue(100);
    ui->life_bar->setTextVisible(1);
    ui->life_bar->setStyleSheet("QProgressBar {"
                                "   border: 2px solid grey;"
                                "   border-radius: 5px;"
                                "   text-align: center;"
                                "   background-color: red;"
                                "   color:white;"
                                "}"
                                "QProgressBar::chunk {"
                                "   background-color: green;"
                                "   width: 10px;"
                                "}");

    outer=new out_thread((this->enimy),c,this->ui->play_ground);
    outer->start();
    connect(outer,&out_thread::out_signal_1,this,[&](bool x){
        this->out_flag=x;
        qDebug()<<"out flag= "<<x;
    });
}

void game::keyPressEvent(QKeyEvent* event){
    qDebug()<<"event: "<<event->key();

    if(!out_flag){
        if(event->key()==83){//down
            N+=10;
            if(N>this->ui->play_ground->height()-25){
                N=this->ui->play_ground->height()-25;
            }
            this->c->setGeometry(E,N,30,30);
        }
        else if(event->key()==87){//up
            N-=10;
            if(N<10){
                N=10;
            }
            this->c->setGeometry(E,N,30,30);
        }
        else if(event->key()==68){//--> way
            E+=10;
            if(E>this->ui->play_ground->width()-25){
                E=this->ui->play_ground->width()-25;
            }
            this->c->setGeometry(E,N,30,30);
        }
        else if(event->key()==65){ //<-- way
            E-=10;
            if(E<5){
                E=5;
            }
            this->c->setGeometry(E,N,30,30);
        }

        else if(event->key()==16777220){//shoot
            if(ui->life_bar->value()>0){
                int x1=(ui->life_bar->value())-1;
                ui->life_bar->setValue(x1);
                qDebug()<<"size of vector in game: "<<this->enimy->size();
                shoot_thread* fire=new shoot_thread(ui->play_ground,c->geometry().x(),c->geometry().y(),this->enimy);
                fire->start();
            }
        }
    }



    else if(event->key()==49){
        this->c->setStyleSheet("background-color:red;");
    }
    else if(event->key()==50){
        this->c->setStyleSheet("background-color:green;");
    }
    else if(event->key()==51){
        this->c->setStyleSheet("background-color:blue;");
    }
    else if(event->key()==52){
        this->c->setStyleSheet("background-color:yellow;");
    }
    else if(event->key()==53){
        this->c->setStyleSheet("background-color:black;");
    }
    else if(event->key()==54){
        this->c->setStyleSheet("background-color:white;");
    }
    else if(event->key()==82){//reload gun
       int x=ui->life_bar->value()+1;
        ui->life_bar->setValue(x);
    }

}

void game::closeEvent(QCloseEvent *e){
    qDebug()<<"----------------------------------close event";
    this->outer->stop();
    this->outer->deleteLater();
    for(enimys*i:this->thread_L){
        i->deleteLater();
    }
    qDebug()<<"stop-------------";
    delete ui;
    e->accept();
    exit(0);
}

void game::on_start_clicked()
{
    ui->play_ground->setStyleSheet("");
    if(f_run){
        this->E = E + ui->play_ground->geometry().width()/2.0f;
        this->N = N+ui->play_ground->geometry().height()-30;
    }
    f_run=false;
    this->out_flag=false;
    c->setGeometry(E,N,30,30);
    c->setStyleSheet("background-color:blue;");
    c->show();

    enimys* e1=new enimys(ui->play_ground,ui->play_ground->height());
    e1->start();
    this->thread_L.push_back(e1);

    connect(e1,&enimys::label, this, [&](QLabel* lbl) {
        this->enimy->push_back(lbl);
    });
}

game::~game(){
    this->outer->stop();
    this->outer->deleteLater();
    for(enimys*i:this->thread_L){
        i->deleteLater();
    }
    qDebug()<<"stop-------------";
    delete ui;
}
