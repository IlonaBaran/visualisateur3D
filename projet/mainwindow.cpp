#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
using namespace glm;


#include "mainwindow.h"
#include "triangle.h"

#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *button = findChild<QPushButton*>("addLayer");
    if (button) {
        connect(button, &QPushButton::clicked, this, &MainWindow::drawTriangle);
    }

    QOpenGLWidget *openGLWidgetWindow = findChild<QOpenGLWidget*>("openGLWidget");
    if (openGLWidgetWindow) {
        connect(openGLWidgetWindow, &QOpenGLWidget::aboutToCompose, this, &MainWindow::drawTriangle);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawTriangle()
{
    triangle triangle;
    triangle.drawTriangle();
}
