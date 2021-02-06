#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(-35,0,1280,limite_y);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/imagenes/fondo 2.jpg"));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar(){

    //Actualiza las posiciones de las balas y revisa sus coliciones
    for (int i = 0; i < balao.size(); i++){
        balao[i]->actualizar_bala(canones.at(0)->getX(), ui->alturao->value(), limite_y);
        balao[i]->setTiempo(balao[i]->getTiempo()+0.1);
        if(balao[i]->getRastro()%10 == 0){
            rastros.push_back(new rastro(1));
            rastros.back()->setPos(balao[i]->getFisicas_bala()->getPosx(), limite_y - balao[i]->getFisicas_bala()->getPosy());
            scene->addItem(rastros.back());
        }
        if(balad.size() > 0){
            balad[i]->actualizar_bala(canones.at(1)->getX(), ui->alturad->value(), limite_y);
            balad[i]->setTiempo(balad[i]->getTiempo()+0.1);
            if(balad[i]->getRastro()%10 == 0){
                rastros.push_back(new rastro(2));
                rastros.back()->setPos(balad[i]->getFisicas_bala()->getPosx(), limite_y - balad[i]->getFisicas_bala()->getPosy());
                scene->addItem(rastros.back());
            }
        }
        if(balaod.size() > 0){
            balaod[i]->actualizar_bala(canones.at(0)->getX(), ui->alturao->value(), limite_y);
            balaod[i]->setTiempo(balaod[i]->getTiempo()+0.1);
            if(balaod[i]->getRastro()%10 == 0){
                rastros.push_back(new rastro(3));
                rastros.back()->setPos(balaod[i]->getFisicas_bala()->getPosx(), limite_y - balaod[i]->getFisicas_bala()->getPosy());
                scene->addItem(rastros.back());
            }
        }
    }

    //Buscar velocidad inicial y angulo para saber donde lanzar la bala.

    if (balao[0]->getTiempo() >= 2 && balao[0]->getTiempo() <= 2.05){
        defensivo_defiende_ofensivo(canones[0]->getX(), ui->alturao->value(), canones[1]->getX(), ui->alturad->value(),balao[0]->getVelocidad_inicial(),balao[0]->getFisicas_bala()->getVelx(), balao[0]->getFisicas_bala()->getVely(), balao.back()->getTiempo());
        balad.push_back(new bala_uno((270 - getAngulo()), getVelocidad_inicial(), (0.025 * ui->distancia->value())));
        balad.back()->setPos(ui->distancia->value(), limite_y - ui->alturad->value());
        scene->addItem(balad.back());
        comienzo = true;
    }

    if (balad.size() > 0){
        if (balad[0]->getTiempo() >= 1 && balad[0]->getTiempo() <= 1.05){
            ofensivo_defiende_defensivo(balao[0]->getFisicas_bala()->getVelx(), balao[0]->getFisicas_bala()->getVely(), balad[0]->getFisicas_bala()->getVelx(), balad[0]->getFisicas_bala()->getVely(), canones[0]->getX(), ui->alturao->value(), canones[1]->getX(), ui->alturad->value(), balao.back()->getTiempo());
            if (getVelocidad_inicial() < 400 && getAngulo() < 90){
                balaod.push_back(new bala_uno(getAngulo(), getVelocidad_inicial(), (0.005 * ui->distancia->value())));
                balaod.back()->setPos(0, limite_y - ui->alturao->value());
                scene->addItem(balaod.back());
            }
        }
    }

    if(comienzo == true){
        if (balad.size() == 0){
            defensivo_defiende_ofensivo(canones[0]->getX(), ui->alturao->value(), canones[1]->getX(), ui->alturad->value(),balao[0]->getVelocidad_inicial(),balao[0]->getFisicas_bala()->getVelx(), balao[0]->getFisicas_bala()->getVely(), balao.back()->getTiempo());
                if(getVelocidad_inicial() != 400 && getAngulo() != 90){
                balad.push_back(new bala_uno((270 - getAngulo()), getVelocidad_inicial(), (0.025 * ui->distancia->value())));
                balad.back()->setPos(ui->distancia->value(), limite_y - ui->alturad->value());
                scene->addItem(balad.back());
            }
        }
    }

    //-------------------------------------------------------------------------------------------------------------------------------------------


    //Opciones de los que quiere saber el usuario

    if (decision == 1){
        if(balad.size() > 0 && balao.size() > 0){
            if(sqrt(pow((balad.back()->getFisicas_bala()->getPosx() - balao.back()->getFisicas_bala()->getPosx()), 2)+pow((balad.back()->getFisicas_bala()->getPosy() - balao.back()->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                val = "La bala ofensiva no pudo impacta contra el cañon defensivo";
                QMessageBox::about (this, "Punto 1", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();

            }
            else if(sqrt(pow((canones[1]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value()){
                val = "La bala ofensiva si impacto contra el cañon defensivo";
                QMessageBox::about (this, "Punto 1", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }

            else if (balao[0]->getFisicas_bala()->getPosx() > canones[1]->getX() && balao[0]->getFisicas_bala()->getPosy() < canones[1]->getY()){
                val = "El proyectil ofensivo no golpeo al canon defensivo.";
                QMessageBox::about (this, "Punto 1", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }


        }
    }

    if (decision == 2){
        if(balad.size() > 0 && balao.size() > 0){
            if(sqrt(pow((balad.back()->getFisicas_bala()->getPosx() - balao.back()->getFisicas_bala()->getPosx()), 2)+pow((balad.back()->getFisicas_bala()->getPosy() - balao.back()->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                if(sqrt(pow((canones[0]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[0]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value() || sqrt(pow((canones[0]->getX() - balad[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[0]->getY()) - balad[0]->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                    val = "La bala defensiva tuvo exito y daño al canon ofensivo";
                    QMessageBox::about (this, "Punto 2", val);

                    for (int i = 0; i < balao.size(); i++){
                        scene->removeItem(balao.at(i));
                    }
                    balao.clear();
                    for (int i = 0; i < balad.size(); i++){
                        scene->removeItem(balad.at(i));
                    }
                    balad.clear();

                    timer->stop();
                }
                else if (sqrt(pow((canones[1]->getX() - balad[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balad[0]->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                    val = "El cañon defensivo fue destuido";
                    QMessageBox::about (this, "Punto 2", val);

                    for (int i = 0; i < balao.size(); i++){
                        scene->removeItem(balao.at(i));
                    }
                    balao.clear();
                    for (int i = 0; i < balad.size(); i++){
                        scene->removeItem(balad.at(i));
                    }
                    balad.clear();

                    timer->stop();
                }
                else{
                    val = "La bala defensiva tuvo exito pero no daño al canon ofensivo";
                    QMessageBox::about (this, "Punto 2", val);

                    for (int i = 0; i < balao.size(); i++){
                        scene->removeItem(balao.at(i));
                    }
                    balao.clear();
                    for (int i = 0; i < balad.size(); i++){
                        scene->removeItem(balad.at(i));
                    }
                    balad.clear();

                    timer->stop();
                }
            }

            else if(sqrt(pow((canones[1]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value()){
                val = "el canon defensivo no pudo defenderse";
                QMessageBox::about (this, "Punto 2", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }

            else if (balao[0]->getFisicas_bala()->getPosx() > canones[1]->getX() && balao[0]->getFisicas_bala()->getPosy() < canones[1]->getY()){
                val = "El proyectil ofensivo no golpeo al canon defensivo.";
                QMessageBox::about (this, "Punto 2", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }
        }
    }

    if (decision == 3){
        if(balad.size() > 0 && balao.size() > 0){
            if(sqrt(pow((balad.back()->getFisicas_bala()->getPosx() - balao.back()->getFisicas_bala()->getPosx()), 2)+pow((balad.back()->getFisicas_bala()->getPosy() - balao.back()->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                val = "La bala defensiva tuvo exito";
                QMessageBox::about (this, "Punto 3", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }

            else if(sqrt(pow((canones[1]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value() || sqrt(pow((canones[1]->getX() - balad[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balad[0]->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                val = "el canon defensivo no pudo defenderse";
                QMessageBox::about (this, "Punto 3", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }

            else if (balao[0]->getFisicas_bala()->getPosx() > canones[1]->getX() && balao[0]->getFisicas_bala()->getPosy() < canones[1]->getY()){
                val = "El proyectil ofensivo no golpeo al canon defensivo.";
                QMessageBox::about (this, "Punto 3", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }
        }
    }

    if (decision == 4){
        if(balad.size() > 0 && balao.size() > 0){
            if(sqrt(pow((balad.back()->getFisicas_bala()->getPosx() - balao.back()->getFisicas_bala()->getPosx()), 2)+pow((balad.back()->getFisicas_bala()->getPosy() - balao.back()->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                if(sqrt(pow((canones[1]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) > 0.05 * ui->distancia->value() || sqrt(pow((canones[0]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[0]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) > 0.05 * ui->distancia->value()){
                    if(sqrt(pow((canones[1]->getX() - balad[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balad[0]->getFisicas_bala()->getPosy()), 2)) > 0.025 * ui->distancia->value() || sqrt(pow((canones[0]->getX() - balad[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[0]->getY()) - balad[0]->getFisicas_bala()->getPosy()), 2)) > 0.025 * ui->distancia->value()){
                        val = "El cañon defensivo tuvo exito sin dañar ningun cañon";
                        QMessageBox::about (this, "Punto 4", val);

                        for (int i = 0; i < balao.size(); i++){
                            scene->removeItem(balao.at(i));
                        }
                        balao.clear();
                        for (int i = 0; i < balad.size(); i++){
                            scene->removeItem(balad.at(i));
                        }
                        balad.clear();

                        timer->stop();
                    }
                    else{
                        val = "el canon defensivo pudo protegerse pero se daño uno de los dos cañones";
                        QMessageBox::about (this, "Punto 4", val);

                        for (int i = 0; i < balao.size(); i++){
                            scene->removeItem(balao.at(i));
                        }
                        balao.clear();
                        for (int i = 0; i < balad.size(); i++){
                            scene->removeItem(balad.at(i));
                        }
                        balad.clear();

                        timer->stop();
                    }
                }
                else{
                    val = "el canon defensivo pudo protegerse pero se daño uno de los dos cañones";
                    QMessageBox::about (this, "Punto 4", val);

                    for (int i = 0; i < balao.size(); i++){
                        scene->removeItem(balao.at(i));
                    }
                    balao.clear();
                    for (int i = 0; i < balad.size(); i++){
                        scene->removeItem(balad.at(i));
                    }
                    balad.clear();

                    timer->stop();
                }
            }

            else if(sqrt(pow((canones[1]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value()){
                val = "el canon defensivo no pudo protegerse";
                QMessageBox::about (this, "Punto 4", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }

            else if (balao[0]->getFisicas_bala()->getPosx() > canones[1]->getX() && balao[0]->getFisicas_bala()->getPosy() < canones[1]->getY()){
                val = "El proyectil ofensivo no golpeo al canon defensivo.";
                QMessageBox::about (this, "Punto 4", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }
        }
    }

    if (decision == 5){
        if(balad.size() > 0 && balao.size() > 0){
            if(sqrt(pow((balad.back()->getFisicas_bala()->getPosx() - balao.back()->getFisicas_bala()->getPosx()), 2)+pow((balad.back()->getFisicas_bala()->getPosy() - balao.back()->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                if(sqrt(pow((canones[1]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value() || sqrt(pow((canones[1]->getX() - balad[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balad[0]->getFisicas_bala()->getPosy()), 2)) <= 0.025 * ui->distancia->value()){
                    val = "el canon defensivo fue destruido, los proyectiles para eliminar su contrataque tuvieron exito.";
                    QMessageBox::about (this, "Punto 5", val);

                    for (int i = 0; i < balao.size(); i++){
                        scene->removeItem(balao.at(i));
                    }
                    balao.clear();
                    for (int i = 0; i < balad.size(); i++){
                        scene->removeItem(balad.at(i));
                    }
                    balad.clear();

                    timer->stop();
                }
                else{
                    val = "el canon defensivo no fue destruido, los proyectiles para eliminar su contrataque no tuvieron exito.";
                    QMessageBox::about (this, "Punto 5", val);

                    for (int i = 0; i < balao.size(); i++){
                        scene->removeItem(balao.at(i));
                    }
                    balao.clear();
                    for (int i = 0; i < balad.size(); i++){
                        scene->removeItem(balad.at(i));
                    }
                    balad.clear();

                    timer->stop();
                }
            }

            else if(sqrt(pow((canones[1]->getX() - balao[0]->getFisicas_bala()->getPosx()), 2)+pow(((limite_y - canones[1]->getY()) - balao[0]->getFisicas_bala()->getPosy()), 2)) <= 0.05 * ui->distancia->value()){
                val = "el canon defensivo fue destruido, los proyectiles para eliminar su contrataque tuvieron exito.";
                QMessageBox::about (this, "Punto 5", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }

            else if (balao[0]->getFisicas_bala()->getPosx() > canones[1]->getX() && balao[0]->getFisicas_bala()->getPosy() < canones[1]->getY()){
                val = "El proyectil ofensivo no golpeo al canon defensivo.";
                QMessageBox::about (this, "Punto 5", val);

                for (int i = 0; i < balao.size(); i++){
                    scene->removeItem(balao.at(i));
                }
                balao.clear();
                for (int i = 0; i < balad.size(); i++){
                    scene->removeItem(balad.at(i));
                }
                balad.clear();

                timer->stop();
            }
        }
    }


    //---------------------------------------------------------------------------------------------------------------------------------------------------


    if(balaod.size() > 0){
        if(sqrt(pow((balad.back()->getFisicas_bala()->getPosx() - balaod.back()->getFisicas_bala()->getPosx()), 2)+ pow((balad.back()->getFisicas_bala()->getPosy() - balaod.back()->getFisicas_bala()->getPosy()), 2)) < 0.005 * ui->distancia->value()){
            for (int i = 0; i < balad.size(); i++){
                scene->removeItem(balad.at(i));
            }
            balad.clear();
            for (int i = 0; i < balaod.size(); i++){
                scene->removeItem(balaod.at(i));
            }
            balaod.clear();
        }
    }


    //Muestra el tiempo transcurrido y controla el tiempo de las balas
    tiempo += 0.1;
    ui->tiempo->setText(QString::number(tiempo));
    if (balao.size() > 0){
        balao[0]->setRastro(balao[0]->getRastro() + 1);
    }
    if (balad.size() > 0){
        balad[0]->setRastro(balao[0]->getRastro() + 1);
    }
    if (balaod.size() > 0){
        balaod[0]->setRastro(balao[0]->getRastro() + 1);
    }
    //------------------------------------------------------------------

}


void MainWindow::on_iniciar_clicked()
{
    if (opcion){
        if (balao.size() <= 0){
            if (escenario_creado){
                tiempo = 0;
                ofensivo_golpe_defensivo(0, ui->alturao->value(), ui->distancia->value(), ui->alturad->value());
                balao.push_back(new bala_uno(getAngulo(), getVelocidad_inicial(), (0.05 * ui->distancia->value())));
                balao.back()->setPos(0, limite_y - ui->alturao->value());
                scene->addItem(balao.back());

                timer->start(100);
            }
        }
    }
}

void MainWindow::on_escenario_clicked()
{
    escenario_creado = true;
    comienzo = false;
    timer->stop();
    for (int i =0; i < rastros.size(); i++){
        scene->removeItem(rastros.at(i));
    }
    rastros.clear();
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
    for (int i = 0; i < balaod.size(); i++){
        scene->removeItem(balaod.at(i));
    }
    balaod.clear();
    balad.clear();
    tiempo = 0;
    canones.push_back(new canon_uno(0, limite_y - ui->alturao->value(), 30, 30, 0.025*ui->distancia->value()));
    scene->addItem(canones.back());
    canones.push_back(new canon_uno(ui->distancia->value(), limite_y - ui->alturad->value(), 30, 30, 0.05*ui->distancia->value()));
    scene->addItem(canones.back());
}

void MainWindow::on_punto_1_clicked()
{
    decision = 1;
    opcion = true;
}

void MainWindow::on_punto_2_clicked()
{
    decision = 2;
    opcion = true;
}

void MainWindow::on_punto_3_clicked()
{
    decision = 3;
    opcion = true;
}

void MainWindow::on_punto_4_clicked()
{
    decision = 4;
    opcion = true;
}

void MainWindow::on_punto_5_clicked()
{
    decision = 5;
    opcion = true;
}
