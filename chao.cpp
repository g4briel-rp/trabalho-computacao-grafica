#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define CHAO 1

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
// Inicializa display lists
    glNewList(CHAO, GL_COMPILE); // Chao

    glPushMatrix();
    glTranslatef(-25.0, 0.0, -30.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_STRIP);
    for(float y = 1.0; y < 40.0; y++){
        for(float x = 1.0; x < 40.0; x++){
            glVertex3f (x, y, 0.0);
            glVertex3f (10.0 + x, y, 0.0);
            glVertex3f (x, 10.0 + y, 0.0);
            glVertex3f (10.0 + x, 10.0 + y, 0.0);
        }
    }
    glEnd();
    glPopMatrix();

    glEndList();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
// Chama o display list do chao para exibi-lo
    glPushMatrix();
    glCallList(CHAO);
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
