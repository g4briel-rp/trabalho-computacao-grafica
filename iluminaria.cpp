#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define LUMINARIA 1

GLUquadricObj *q;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    q = gluNewQuadric();
// Inicializa display lists
    glNewList(LUMINARIA, GL_COMPILE); // Luminaria

    glPushMatrix();
    glTranslatef (-5.0, 0.0, 0.0);
    glRotatef(135.0, 0.0, 1.0, 0.0);
    glRotatef(-35.0, 1.0, 0.0, 0.0);
    gluCylinder(q, 5.0, 1.0, 10.0, 9.0, 3.0);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 3.0, 1.0);
    glTranslatef(2.0, 2.0, -7.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(q, 1.0, 1.0, 10.0, 5.0, 5.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef (2.0, -24.0, -8.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluDisk(q, 1.0, 3.0, 9, 2);
    glPopMatrix();

    glEndList();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
// Chama o display list da luminaria para exibi-la
    glPushMatrix();
    glCallList(LUMINARIA);
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
        gluDeleteQuadric(q);
        exit(0);
        break;
    }
}

int main(int argc, char** argv)
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
}
