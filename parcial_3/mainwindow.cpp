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
        balas[i]->actualizar_bala(canones.at(0)->getX(), ui->alturao->value(), tiempo, limite_y);
        if(balas[i]->collidesWithItem(canones.at(1))){
            QString val;
            val = "";
            val += "Lo mataste, perro";
            QMessageBox::about (this,"CRACK", val);
            timer->stop();
        }
        else if(balas[i]->getFisicas_bala()->getPosy() < ui->alturad->value() && balas[i]->getFisicas_bala()->getPosx() > ui->distancia->value()){
            QString val;
            val = "";
            val += "No le diste, perro";
            QMessageBox::about (this,"malo", val);
            timer->stop();
        }
    }
    tiempo += 1;
    ui->tiempo->setText(QString::number(tiempo));
}


void MainWindow::on_iniciar_clicked()
{
    balas.push_back(new bala_uno(65, 120));
    balas.back()->setPos(100, limite_y - ui->alturao->value());
    scene->addItem(balas.back());
    timer->start(1000);

}

void MainWindow::on_escenario_clicked()
{
    canones.push_back(new canon_uno(100, limite_y - ui->alturao->value(), 70, 70));
    scene->addItem(canones.back());
    canones.push_back(new canon_uno(ui->distancia->value(), limite_y - ui->alturad->value(), 70, 70));
    scene->addItem(canones.back());
}
