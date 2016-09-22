#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timeconversion.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    TimeConversion time = TimeConversion();
    QString internetTime = time.getInternetTime();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(logTime()));
    timer->start(1000);

    ui->setupUi(this);

}

void MainWindow::logTime(){
    qInfo() << this->internetTime;
}

MainWindow::~MainWindow()
{
    delete ui;
}
