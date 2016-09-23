#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timeconversion.h"
#include <QDebug>
#include <QTimer>

MainWindow::    MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    TimeConversion time = TimeConversion();
    this->currentTime = time.getInternetTime();
    ;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(logTime()));
    timer->start(1000);

    ui->setupUi(this);
    updateTimeDisplay();
}

void MainWindow::logTime(){
    QString timeNow = TimeConversion().getInternetTime();
    if(timeNow != currentTime) {
        this->currentTime = timeNow;
        updateTimeDisplay();
    }
}

void MainWindow::updateTimeDisplay() {
    ui->displayTime->setText(this->currentTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}
