#include "teapotopenglwidget.h"
#include <GL/glu.h>
#include <GL/glut.h>
#include <QOpenGLShaderProgram>

Teapotopenglwidget::Teapotopenglwidget(QWidget *parent)
    : QOpenGLWidget(parent), rotationX(0.0f), rotationY(0.0f)
{
}

Teapotopenglwidget::~Teapotopenglwidget()
{
}

void Teapotopenglwidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
}

void Teapotopenglwidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, static_cast<double>(w) / static_cast<double>(h), 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Teapotopenglwidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);

    // 绘制茶壶
    glutSolidTeapot(1.0);
}

void Teapotopenglwidget::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();
}

void Teapotopenglwidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastMousePosition.x();
    int dy = event->y() - lastMousePosition.y();

    rotationX += dy;
    rotationY += dx;

    update();

    lastMousePosition = event->pos();
}
