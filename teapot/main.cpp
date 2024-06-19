#include "mainwindow.h"
#include <GL/glut.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    //初始化GLUT库
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
