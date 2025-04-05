/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QFrame *play_ground;
    QProgressBar *life_bar;
    QPushButton *start;

    void setupUi(QMainWindow *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName("game");
        game->resize(800, 600);
        QIcon icon;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::MediaPlaybackStop)) {
            icon = QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStop);
        } else {
            icon.addFile(QString::fromUtf8("bnb_crypto_icon_264371.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        game->setWindowIcon(icon);
        game->setStyleSheet(QString::fromUtf8(""));
        game->setIconSize(QSize(30, 30));
        centralwidget = new QWidget(game);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName("horizontalLayout");
        play_ground = new QFrame(frame_2);
        play_ground->setObjectName("play_ground");
        play_ground->setStyleSheet(QString::fromUtf8(""));
        play_ground->setFrameShape(QFrame::Shape::StyledPanel);
        play_ground->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout->addWidget(play_ground);


        verticalLayout->addWidget(frame_2);

        life_bar = new QProgressBar(centralwidget);
        life_bar->setObjectName("life_bar");
        life_bar->setValue(24);

        verticalLayout->addWidget(life_bar);

        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        start->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(start);

        game->setCentralWidget(centralwidget);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QMainWindow *game)
    {
        game->setWindowTitle(QCoreApplication::translate("game", "game", nullptr));
        start->setText(QCoreApplication::translate("game", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
