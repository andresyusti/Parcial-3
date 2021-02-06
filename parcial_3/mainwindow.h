#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QMessageBox>
#include <math.h>
#include <string>
using namespace std;

#include "bala_uno.h"
#include "balas_dos.h"
#include "canon_uno.h"
#include "condiciones.h"
#include "rastro.h"
#include "circulo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public condiciones
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void actualizar();

private slots:
    void on_iniciar_clicked();

    void on_escenario_clicked();

    void on_punto_1_clicked();

    void on_punto_2_clicked();

    void on_punto_3_clicked();

    void on_punto_4_clicked();

    void on_punto_5_clicked();

    void on_manual_clicked();

    void on_encontrarvalores_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QTimer *timer;

    QList<bala_uno *> balao;
    QList<bala_uno *> balad;
    QList<bala_uno *> balaod;
    QList<canon_uno *> canones;
    QList<circulo *> circulos;
    QList<rastro *> rastros;

    float tiempo = 0;
    float limite_y = 720;
    bool escenario_creado = false, comienzo = false, opcion = false, modo_manual = false;
    int decision;

    QString val = "";
};
#endif // MAINWINDOW_H
