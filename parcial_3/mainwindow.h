#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QMessageBox>

#include "bala_uno.h"
#include "canon_uno.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
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

    QList<bala_uno *> balas;
    QList<canon_uno *> canones;

    float tiempo;
    float limite_y = 700;
};
#endif // MAINWINDOW_H
