#include <glut.h>
#include <iostream>

// Tamaño de la ventana
const int windowWidth = 800;
const int windowHeight = 600;

// Variables globales para las coordenadas
float x1, b1;
float x2, y2;


// Función para inicializar OpenGL
//configuramos el color de fondo y establecemos las coordenadas del plano cartesiano con gluOrtho2D
void initializeOpenGL()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo blanco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // Coordenadas del plano cartesiano
}

// Función para dibujar el plano cartesiano
void drawCartesianPlane()
{
    glColor3f(0.0, 0.0, 0.0); // Color negro

    glBegin(GL_LINES);

    // Eje X
    glVertex2f(-10.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);

    // Eje Y
    glVertex2f(0.0f, -10.0f);
    glVertex2f(0.0f, 10.0f);

    glEnd();
}

// Función para dibujar la recta basada en dos puntos
//dibujamos una linea roja basado en las coordenadas ingresados por un usuario. 
void drawLine()
{
    glColor3f(1.0, 0.0, 0.0); // Color rojo

    glBegin(GL_LINES);
    glVertex2f(x1, b1);
    glVertex2f(x2, y2);
    glEnd();
}

// Función de visualización
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCartesianPlane();
    drawLine();

    glFlush();
}

// Función principal
//solicitamos las coordenadas al usuario, luego calculamos la pendiente de la recta, se innicializa con glut y se configura la ventana
//entra al bucle principal de GLUT. 

int main(int argc, char** argv) {
    // Pedir coordenadas al usuario
    std::cout << "Ingrese la primera coordenada (x1 b1): ";
    std::cin >> x1 >> b1;


    std::cout << "Ingrese la segunda coordenada (x2 y2): ";
    std::cin >> x2 >> y2;

    // Calcular la pendiente de la recta
    if (x2 - x1 != 0) {
        float m = (y2 - b1) / (x2 - x1);
        std::cout << "La pendiente de la recta es: " << m << std::endl;
    }
    else {
        std::cout << "La recta es vertical, la pendiente es indefinida." << std::endl;
    }

    // Inicializar GLUT y crear ventana
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Plano Cartesiano con Recta");

    initializeOpenGL();
    // Registrar función de visualización
    glutDisplayFunc(display);

    // Iniciar el bucle principal de GLUT
    glutMainLoop();


    return 0;
}