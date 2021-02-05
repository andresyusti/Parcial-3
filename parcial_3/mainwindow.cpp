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

    //Muestra el tiempo transcurrido
    tiempo += 0.1;
    ui->tiempo->setText(QString::number(tiempo));

    //Actualiza las posiciones de las balas y revisa sus coliciones
    for (int i = 0; i < balas.size(); i++){
        balas[i]->actualizar_bala(canones.at(0)->getX(), ui->alturao->value(), limite_y);
        balas[i]->setTiempo(balas[i]->getTiempo()+0.1);
        if(sqrt(pow((canones[1]->getX() - balas[i]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balas[i]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value()){
            QString val;
            val = "";
            val = "El disparo ofensivo fue efectivo.";
            QMessageBox::about (this,"CRACK", val);
            timer->stop();
        }
        else if(balas[i]->getFisicas_bala()->getPosy() < ui->alturad->value() && balas[i]->getFisicas_bala()->getPosx() > ui->distancia->value()){
            QString val;
            val = "";
            val = "sasdasd";
            QMessageBox::about (this,"er", val);
            timer->stop();
        }
    }

    //Buscar velocidad inicial y angulo para saber donde lanzar la bala
}


void MainWindow::on_iniciar_clicked()
{
    if (escenario_creado){
        ofensivo_golpe_defensivo(0, ui->alturao->value(), ui->distancia->value(), ui->alturad->value());
        balas.push_back(new bala_uno(getAngulo(), getVelocidad_inicial(), (0.05 * ui->distancia->value())));
        balas.back()->setPos(0, limite_y - ui->alturao->value());
        scene->addItem(balas.back());
        timer->start(100);
    }

}

void MainWindow::on_escenario_clicked()
{
    escenario_creado = true;
    for(int i = 0; i < canones.size(); i++){
        scene->removeItem(canones.at(i));
    }
    canones.clear();
    for (int i = 0; i < balas.size(); i++){
        scene->removeItem(balas.at(i));
    }
    balas.clear();
    tiempo = 0;
    canones.push_back(new canon_uno(0, limite_y - ui->alturao->value(), 70, 70));
    scene->addItem(canones.back());
    canones.push_back(new canon_uno(ui->distancia->value(), limite_y - ui->alturad->value(), 70, 70));
    scene->addItem(canones.back());
}
