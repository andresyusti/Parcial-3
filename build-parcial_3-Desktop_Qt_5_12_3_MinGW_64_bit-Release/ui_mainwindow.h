/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *tiempo;
    QLabel *label_2;
    QDoubleSpinBox *distancia;
    QDoubleSpinBox *alturao;
    QDoubleSpinBox *alturad;
    QGraphicsView *graphicsView;
    QPushButton *iniciar;
    QPushButton *escenario;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *punto_1;
    QPushButton *punto_2;
    QPushButton *punto_3;
    QPushButton *punto_4;
    QPushButton *punto_5;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *velocidad_i_m;
    QDoubleSpinBox *angulo_m;
    QPushButton *manual;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 730);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tiempo = new QLabel(centralwidget);
        tiempo->setObjectName(QString::fromUtf8("tiempo"));
        tiempo->setGeometry(QRect(1375, 20, 100, 30));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1310, 20, 60, 30));
        distancia = new QDoubleSpinBox(centralwidget);
        distancia->setObjectName(QString::fromUtf8("distancia"));
        distancia->setGeometry(QRect(1375, 50, 125, 20));
        distancia->setMaximum(100000000000000003889357755108838843130737249295202013334302382007691294289384896763079965607877701387326460311941213291353170611409437561654018367221268940354434586262616943544566455807655946219322240663552.000000000000000);
        alturao = new QDoubleSpinBox(centralwidget);
        alturao->setObjectName(QString::fromUtf8("alturao"));
        alturao->setGeometry(QRect(1375, 80, 125, 20));
        alturao->setMaximum(100000000000000003889357755108838843130737249295202013334302382007691294289384896763079965607877701387326460311941213291353170611409437561654018367221268940354434586262616943544566455807655946219322240663552.000000000000000);
        alturad = new QDoubleSpinBox(centralwidget);
        alturad->setObjectName(QString::fromUtf8("alturad"));
        alturad->setGeometry(QRect(1375, 110, 125, 20));
        alturad->setMaximum(100000000000000003889357755108838843130737249295202013334302382007691294289384896763079965607877701387326460311941213291353170611409437561654018367221268940354434586262616943544566455807655946219322240663552.000000000000000);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1282, 722));
        iniciar = new QPushButton(centralwidget);
        iniciar->setObjectName(QString::fromUtf8("iniciar"));
        iniciar->setGeometry(QRect(1410, 140, 90, 30));
        iniciar->setCursor(QCursor(Qt::ArrowCursor));
        iniciar->setAutoRepeatDelay(300);
        escenario = new QPushButton(centralwidget);
        escenario->setObjectName(QString::fromUtf8("escenario"));
        escenario->setGeometry(QRect(1310, 140, 90, 30));
        escenario->setCursor(QCursor(Qt::ArrowCursor));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1310, 50, 60, 30));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1310, 80, 60, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1310, 110, 60, 25));
        punto_1 = new QPushButton(centralwidget);
        punto_1->setObjectName(QString::fromUtf8("punto_1"));
        punto_1->setGeometry(QRect(1310, 180, 190, 30));
        punto_2 = new QPushButton(centralwidget);
        punto_2->setObjectName(QString::fromUtf8("punto_2"));
        punto_2->setGeometry(QRect(1310, 220, 190, 30));
        punto_3 = new QPushButton(centralwidget);
        punto_3->setObjectName(QString::fromUtf8("punto_3"));
        punto_3->setGeometry(QRect(1310, 260, 190, 30));
        punto_4 = new QPushButton(centralwidget);
        punto_4->setObjectName(QString::fromUtf8("punto_4"));
        punto_4->setGeometry(QRect(1310, 300, 190, 30));
        punto_5 = new QPushButton(centralwidget);
        punto_5->setObjectName(QString::fromUtf8("punto_5"));
        punto_5->setGeometry(QRect(1310, 340, 190, 30));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1310, 370, 190, 80));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1310, 460, 60, 30));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1310, 490, 60, 30));
        velocidad_i_m = new QDoubleSpinBox(centralwidget);
        velocidad_i_m->setObjectName(QString::fromUtf8("velocidad_i_m"));
        velocidad_i_m->setGeometry(QRect(1375, 460, 125, 20));
        velocidad_i_m->setMaximum(100000000000000003889357755108838843130737249295202013334302382007691294289384896763079965607877701387326460311941213291353170611409437561654018367221268940354434586262616943544566455807655946219322240663552.000000000000000);
        angulo_m = new QDoubleSpinBox(centralwidget);
        angulo_m->setObjectName(QString::fromUtf8("angulo_m"));
        angulo_m->setGeometry(QRect(1375, 490, 125, 20));
        angulo_m->setMaximum(100000000000000003889357755108838843130737249295202013334302382007691294289384896763079965607877701387326460311941213291353170611409437561654018367221268940354434586262616943544566455807655946219322240663552.000000000000000);
        manual = new QPushButton(centralwidget);
        manual->setObjectName(QString::fromUtf8("manual"));
        manual->setGeometry(QRect(1310, 530, 190, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        tiempo->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Tiempo:</span></p></body></html>", nullptr));
        iniciar->setText(QApplication::translate("MainWindow", "Inicio", nullptr));
        escenario->setText(QApplication::translate("MainWindow", "Escenario", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">distancia:</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Alturo O:</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Altura D:</span></p></body></html>", nullptr));
        punto_1->setText(QApplication::translate("MainWindow", "Punto 1.", nullptr));
        punto_2->setText(QApplication::translate("MainWindow", "Punto 2.", nullptr));
        punto_3->setText(QApplication::translate("MainWindow", "Punto 3.", nullptr));
        punto_4->setText(QApplication::translate("MainWindow", "Punto 4.", nullptr));
        punto_5->setText(QApplication::translate("MainWindow", "Punto 5.", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Si quieres usar el modo manual, llena</span></p><p><span style=\" font-weight:600;\">los siguientes recuadros con lo que te</span></p><p><span style=\" font-weight:600;\">te pide y darle en el boton manual</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:7pt; font-weight:600;\">Velocidad I:</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Angulo:</span></p></body></html>", nullptr));
        manual->setText(QApplication::translate("MainWindow", "Modo manual.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
