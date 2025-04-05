#ifndef ENIMYS_H
#define ENIMYS_H
#include <QThread>
#include <QFrame>
#include <QLabel>
#include <QVector>

class enimys:public QThread
{
    Q_OBJECT
public:
     QLabel* L=nullptr;
    int H;
     int x,y=0;
    QFrame* F;
    enimys(QFrame* f,int h);
    void run();
    QLabel* get_enimy();
Q_SIGNALS:
    void label(QLabel* newLabel);
};

#endif // ENIMYS_H
