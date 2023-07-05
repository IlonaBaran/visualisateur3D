#include "triangle.h"
#include <QObject>


#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

triangle::triangle()
{

}

/*
void triangle::drawTriangle()
{
    // Obtenez le contexte OpenGL
    QOpenGLFunctions* glFunctions = QOpenGLContext::currentContext()->functions();

    // Définissez les coordonnées des sommets du triangle
    GLfloat vertices[] = {
        0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    // Créez un objet de tampon OpenGL pour stocker les données des sommets
    QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.allocate(vertices, sizeof(vertices));

    // Créez un programme de shaders OpenGL
    QOpenGLShaderProgram shaderProgram;
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex,
                                          "attribute vec3 aPosition;"
                                          "void main() {"
                                          "    gl_Position = vec4(aPosition, 1.0);"
                                          "}");
    shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment,
                                          "void main() {"
                                          "    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
                                          "}");
    shaderProgram.link();

    // Configurez le tampon de sommets comme attribut de position
    shaderProgram.bind();
    shaderProgram.enableAttributeArray("aPosition");
    shaderProgram.setAttributeBuffer("aPosition", GL_FLOAT, 0, 3, 0);

    // Appliquer les transformations
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity();  // Réinitialiser la matrice de modèle à l'identité
    modelMatrix.rotate(rotationX, 1.0f, 0.0f, 0.0f);
    modelMatrix.rotate(rotationY, 0.0f, 1.0f, 0.0f);
    modelMatrix.translate(0.0f, 0.0f, translationZ);
    modelMatrix.scale(scale);

    // Passez la matrice de modèle au shader
    int modelMatrixLoc = shaderProgram.uniformLocation("modelMatrix");
    shaderProgram.setUniformValue(modelMatrixLoc, modelMatrix);

    // Effacez l'écran avec une couleur de fond
    glFunctions->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glFunctions->glClear(GL_COLOR_BUFFER_BIT);

    // Dessinez le triangle
    vbo.bind();
    shaderProgram.bind();
    glFunctions->glDrawArrays(GL_TRIANGLES, 0, 3);
    vbo.release();
    shaderProgram.release();

    // Mettre à jour le widget OpenGL

    //QOpenGLWidget* openGLWidgetWindow = findChild<QOpenGLWidget*>("openGLWidget");
    //if (openGLWidgetWindow) {
    //    openGLWidgetWindow->update();
    //}

}
*/

 void triangle::drawTriangle()
{
     // Obtenez le contexte OpenGL
     QOpenGLFunctions* glFunctions = QOpenGLContext::currentContext()->functions();

     // Définissez les coordonnées des sommets du triangle
     GLfloat vertices[] = {
         0.0f,  0.5f, 0.0f,
         -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f
     };

     // Créez un objet de tampon OpenGL pour stocker les données des sommets
     QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
     vbo.create();
     vbo.bind();
     vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
     vbo.allocate(vertices, sizeof(vertices));

     // Créez un programme de shaders OpenGL
     QOpenGLShaderProgram shaderProgram;
     shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex,
                                           "attribute vec3 aPosition;"
                                           "void main() {"
                                           "    gl_Position = vec4(aPosition, 1.0);"
                                           "}");
     shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment,
                                           "void main() {"
                                           "    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
                                           "}");
     shaderProgram.link();

     // Configurez le tampon de sommets comme attribut de position
     shaderProgram.bind();
     shaderProgram.enableAttributeArray("aPosition");
     shaderProgram.setAttributeBuffer("aPosition", GL_FLOAT, 0, 3, 0);

     // Effacez l'écran avec une couleur de fond
     glFunctions->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
     glFunctions->glClear(GL_COLOR_BUFFER_BIT);

     // Dessinez le triangle
     glFunctions->glDrawArrays(GL_TRIANGLES, 0, 3);

     // Libérez les ressources
     shaderProgram.release();
     vbo.release();
}

/*
La fonction mousePressEvent(QMouseEvent* event) est une fonction événementielle de la classe MainWindow
qui est appelée lorsque l'utilisateur appuie sur un bouton de la souris. Son rôle est de stocker la position
 actuelle de la souris dans la variable lastMousePos. Cette position sera utilisée ultérieurement pour
calculer le déplacement de la souris dans la fonction mouseMoveEvent(QMouseEvent* event), afin d'effectuer
 des transformations sur l'affichage du widget OpenGL en fonction des mouvements de la souris.
*/
void triangle::mousePressEvent(QMouseEvent* event)
{
    lastMousePos = event->pos();
}

void triangle::mouseMoveEvent(QMouseEvent* event)
{
    int dx = event->position().x() - lastMousePos.x();
    int dy = event->position().y() - lastMousePos.y();

    rotationX += dy;
    rotationY += dx;

    lastMousePos = event->position();

    QOpenGLWidget* openGLWidgetWindow = findChild<QOpenGLWidget*>("openGLWidget");
    if (openGLWidgetWindow) {
        openGLWidgetWindow->update();
    }
}

void triangle::wheelEvent(QWheelEvent* event)
{
    QPoint numDegrees = event->angleDelta() / 8;
    float numSteps = numDegrees.y() / 15.0f;

    scale *= std::pow(1.2f, numSteps);

    QOpenGLWidget* openGLWidgetWindow = findChild<QOpenGLWidget*>("openGLWidget");
    if (openGLWidgetWindow) {
        openGLWidgetWindow->update();
    }
}

