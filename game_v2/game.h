#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include "shoot_thread.h"
#include "enimys.h"
#include "out_thread.h"
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class game;
}
QT_END_NAMESPACE

class game : public QMainWindow
{
    Q_OBJECT

public:
    QVector <QLabel*>* enimy=new QVector<QLabel*>{};
    QVector <enimys*> thread_L;
    shoot_thread* fire=nullptr;
    int N=0;
    int E=0;
    QLabel* c;
    void keyPressEvent(QKeyEvent* event);
    void closeEvent(QCloseEvent* e);
    game(QWidget *parent = nullptr);
    ~game();

private slots:
    void on_start_clicked();

private:
    bool f_run=true;
    bool out_flag=false;
    out_thread* outer=nullptr;
    Ui::game *ui;
    bool out();
};
#endif // GAME_H
