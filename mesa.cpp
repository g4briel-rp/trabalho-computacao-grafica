#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define MESA 1

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

// Inicializa display lists
    glNewList(MESA, GL_COMPILE); // Mesa

// Use aqui as primitivas e transformacoes geometricas do OpenGL para modelar a mesa.
    glPushMatrix();
    glTranslatef(0.0, 15.0, 0.0);
    glScalef(5.0, -0.5, 10.0);
    glutWireCube(5.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10.0, -3.2, 0.0);
    glScalef(-0.3, 5.0, 0.3);
    glTranslatef(1.5, 0.9, 75.0);
    glutWireCube(5.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10.0, -3.2, 0.0);
    glScalef(-0.3, 5.0, 0.3);
    glTranslatef(-1.5, 0.9, 75.0);
    glutWireCube(5.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10.0, -3.2, 0.0);
    glScalef(-0.3, 5.0, 0.3);
    glTranslatef(1.5, 0.9, -75.0);
    glutWireCube(5.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10.0, -3.2, 0.0);
    glScalef(-0.3, 5.0, 0.3);
    glTranslatef(-1.5, 0.9, -75.0);
    glutWireCube(5.0);
    glPopMatrix();

    glEndList();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
// Chama o display list da mesa para exibi-la
    glPushMatrix();
    glCallList(MESA);
    glPopMatrix();
    glutSwapBuffers();
}

void perspectiva(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 100.0);
    gluLookAt(-10.0, 30.0, 50.0,0.0, -2.0, 0.0, 0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
}

void orto_cima(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-30.0,30.0, -30.0,30.0, 1.0,250.0);
    gluLookAt(0.0, 250.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
}

void orto_frontal(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-30.0,30.0, -30.0,30.0, 1.0,250.0);
    gluLookAt(0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(360, 360);

    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(perspectiva);

    glutInitWindowPosition(500, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(orto_cima);

    glutInitWindowPosition(900, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(orto_frontal);

    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
