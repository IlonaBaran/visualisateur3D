#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QMainWindow>

#include <QObject>
#include <QWidget>

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include <QMouseEvent>
#include <QWheelEvent>



class triangle : public QObject
{
    Q_OBJECT

public:
    triangle();
    void drawTriangle();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);

private:
    QPointF lastMousePos;
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    float translationZ = -2.0f;
    float scale = 1.0f;
};


#endif // TRIANGLE_H
