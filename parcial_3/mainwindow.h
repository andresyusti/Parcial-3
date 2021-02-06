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

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QTimer *timer;

    QList<bala_uno *> balao;
    QList<bala_uno *> balad;
    QList<bala_uno *> balaod;
    QList<canon_uno *> canones;
    QList<rastro *> rastros;

    float tiempo = 0;
    float limite_y = 720;
    bool escenario_creado = false, comienzo = false;
};
#endif // MAINWINDOW_H
