#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGLWidget = new Teapotopenglwidget(this);
    setCentralWidget(openGLWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


