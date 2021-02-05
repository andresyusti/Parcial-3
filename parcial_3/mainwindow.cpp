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
    for (int i = 0; i < balao.size(); i++){
        balao[i]->actualizar_bala(canones.at(0)->getX(), ui->alturao->value(), limite_y);
        balao[i]->setTiempo(balao[i]->getTiempo()+0.1);
        if(balad.size() > 0){
            balad[i]->actualizar_bala(canones.at(1)->getX(), ui->alturad->value(), limite_y);
            balad[i]->setTiempo(balad[i]->getTiempo()+0.1);
        }
        if(sqrt(pow((canones[1]->getX() - balao[i]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balao[i]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value()){
            QString val;
            val = "";
            val = "El disparo ofensivo fue efectivo.";
            QMessageBox::about (this,"CRACK", val);
            timer->stop();
        }
        else if(balao[i]->getFisicas_bala()->getPosy() < ui->alturad->value() && balao[i]->getFisicas_bala()->getPosx() > ui->distancia->value()){
            QString val;
            val = "";
            val = "sasdasd";
            QMessageBox::about (this,"er", val);
            timer->stop();
        }
    }

    //Buscar velocidad inicial y angulo para saber donde lanzar la bala.
    if (balao[0]->getTiempo() >= 2 && balao[0]->getTiempo() <= 2.05){
        defensivo_defiende_ofensivo(canones[0]->getX(), ui->alturao->value(), canones[1]->getX(), ui->alturad->value(),balao[0]->getVelocidad_inicial(),balao[0]->getAngulo());
        balad.push_back(new bala_uno((270 - getAngulo()), getVelocidad_inicial(), (0.025 * ui->distancia->value())));
        balad.back()->setPos(ui->distancia->value(), limite_y - ui->alturad->value());
        scene->addItem(balad.back());
    }




    if(balad.size() > 0){
        if(sqrt(pow((balad.back()->getFisicas_bala()->getPosx() - balao.back()->getFisicas_bala()->getPosx()), 2)+pow((balad.back()->getFisicas_bala()->getPosy() - balao.back()->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value()){
            QString val;
            val = "";
            val = "La defensa fue un exito";
            QMessageBox::about (this,"er", val);
            timer->stop();
        }
    }

}


void MainWindow::on_iniciar_clicked()
{
    if (escenario_creado){
        ofensivo_golpe_defensivo(0, ui->alturao->value(), ui->distancia->value(), ui->alturad->value());
        balao.push_back(new bala_uno(getAngulo(), getVelocidad_inicial(), (0.05 * ui->distancia->value())));
        balao.back()->setPos(0, limite_y - ui->alturao->value());
        scene->addItem(balao.back());

        timer->start(100);
    }

}

void MainWindow::on_escenario_clicked()
{
    escenario_creado = true;
    timer->stop();
    for(int i = 0; i < canones.size(); i++){
        scene->removeItem(canones.at(i));
    }
    canones.clear();
    for (int i = 0; i < balao.size(); i++){
        scene->removeItem(balao.at(i));
    }
    balao.clear();
    for (int i = 0; i < balad.size(); i++){
        scene->removeItem(balad.at(i));
    }
    balad.clear();
    tiempo = 0;
    canones.push_back(new canon_uno(0, limite_y - ui->alturao->value(), 70, 70));
    scene->addItem(canones.back());
    canones.push_back(new canon_uno(ui->distancia->value(), limite_y - ui->alturad->value(), 70, 70));
    scene->addItem(canones.back());
}
