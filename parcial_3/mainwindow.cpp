#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1250,limite_y);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/pictures/tree-247122.jpg"));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar(){
    for (int i = 0; i < balas.size(); i++){
        balas[i]->actualizar_bala(0, ui->alturao->value(), tiempo, limite_y);
    }
    tiempo += 0.06;
}


void MainWindow::on_iniciar_clicked()
{
    balas.push_back(new bala_uno(45, 150));
    balas.back()->setPos(0, limite_y - ui->alturao->value());
    scene->addItem(balas.back());
    timer->start(60);

}

void MainWindow::on_escenario_clicked()
{
    canones.push_back(new canon_uno(0, limite_y - ui->alturao->value(), 70, 70));
    canones.back()->setPos(100, limite_y - ui->alturao->value());
    scene->addItem(canones.back());
    canones.push_back(new canon_uno(ui->distancia->value(), limite_y - ui->alturad->value(), 70, 70));
    canones.back()->setPos(ui->distancia->value(), limite_y - ui->alturad->value());
    scene->addItem(canones.back());
}
