#ifndef TEAPOTOPENGLWIDGET_H
#define TEAPOTOPENGLWIDGET_H


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>

class Teapotopenglwidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Teapotopenglwidget(QWidget *parent = nullptr);
    ~Teapotopenglwidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    float rotationX;
    float rotationY;
    QPoint lastMousePosition;
};

#endif // TEAPOTOPENGLWIDGET_H
