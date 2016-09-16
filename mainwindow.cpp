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
    logTime(internetTime);
    connect(timer, SIGNAL(timeout()), this, SLOT(logTime(internetTime)));
    timer->start(1000);

    ui->setupUi(this);

}

void MainWindow::logTime(QString internetTime) {
    qInfo() << internetTime;
}

MainWindow::~MainWindow()
{
    delete ui;
}
