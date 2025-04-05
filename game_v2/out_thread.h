#ifndef OUT_THREAD_H
#define OUT_THREAD_H

#include <QThread>
#include <QMetaObject>
#include <QLabel>
#include <QVector>
#include <QFrame>

class out_thread: public QThread
{
    Q_OBJECT
public:
    QVector <QLabel*>* enmy_list;
    QLabel* c;
    QFrame* F;
    out_thread(QVector<QLabel*>* list,QLabel* c,QFrame* F);
    void run();
    void out();
    void stop();
Q_SIGNALS:
    void out_signal_1(bool x);
};

#endif // OUT_THREAD_H
