#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define CHAO 1
#define MESA 2
#define CADEIRA_E 3
#define CADEIRA_D 4
#define LUMINARIA 5
#define GARRAFA 6
#define TACA 7

GLUquadricObj *q;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    q = gluNewQuadric();

// Inicializa display lists para criação do chão
    glNewList(CHAO, GL_COMPILE);

// Criação da malha formada por triangulos adjacentes e as Transformações geometricas utilizadas
    glPushMatrix();
    glTranslatef(-44.0, -11.5, -65.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_STRIP);
    for(float y = 1.0; y < 100.0; y += 5.0){
        for(float x = 1.0; x < 100.0; x += 5.0){
            glVertex3f (x, y, 0.0);
            glVertex3f (5.0 + x, y, 0.0);
            glVertex3f (x, 5.0 + y, 0.0);
            glVertex3f (5.0 + x, 5.0 + y, 0.0);
        }
    }
    glEnd();
    glPopMatrix();

    glEndList();

// Inicializa display lists para criação da mesa
    glNewList(MESA, GL_COMPILE); // Mesa

//Criação da tabua da mesa.
    glPushMatrix();
    glTranslatef(0.0, 10.0, 0.0);
    glScalef(5.0, 0.5, 10.0);
    glutWireCube(5.0);
    glPopMatrix();

// Criação do pé da mesa

//pé esquerdo inferior
    glPushMatrix();
    glTranslatef(-8.0, -1.4, 20.0);
    glScalef(0.5, 4.0, 0.5);
    glutWireCube(5.0);
    glPopMatrix();

//pé direito inferior
    glPushMatrix();
    glTranslatef(8.0, -1.4, 20.0);
    glScalef(0.5, 4.0, 0.5);
    glutWireCube(5.0);
    glPopMatrix();

//pé esquerdo superior
    glPushMatrix();
    glTranslatef(-8.0, -1.4, -20.0);
    glScalef(0.5, 4.0, 0.5);
    glutWireCube(5.0);
    glPopMatrix();

//pé direito superior
    glPushMatrix();
    glTranslatef(8.0, -1.4, -20.0);
    glScalef(0.5, 4.0, 0.5);
    glutWireCube(5.0);
    glPopMatrix();

    glEndList();

// Inicializa display lists para criação da cadeira da esquerda
    glNewList(CADEIRA_E, GL_COMPILE);

//pé direito inferior
    glPushMatrix();
    glTranslatef(-13.5, -6.5, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 5.0, 1.0);
    glutWireCube(2.0);
    glPopMatrix();

//pé direito superior
    glPushMatrix();
    glTranslatef(-17.0, -6.5, -5.5);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 5.0, 1.0);
    glutWireCube(2.0);
    glPopMatrix();

//pé esquerdo inferior
    glPushMatrix();
    glTranslatef(-19.5, -6.5, 3.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 5.0, 1.0);
    glutWireCube(2.0);
    glPopMatrix();

//pé esquerdo superior
    glPushMatrix();
    glTranslatef(-22.5, -6.5, -2.5);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 5.0, 1.0);
    glutWireCube(2.0);
    glPopMatrix();

//banco
    glPushMatrix();
    glTranslatef(-18.0, 0.0, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 0.25, 1.0);
    glutSolidCube(12.0);
    glPopMatrix();

//encosto
    glPushMatrix();
    glTranslatef(-20.5, 7.5, -4.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(1.0, 0.25, 1.0);
    glutSolidCube(12.0);
    glPopMatrix();

    glEndList();

// Inicializa display lists para criação da cadeira da direita
    glNewList(CADEIRA_D, GL_COMPILE);

//pé direito inferior
    glPushMatrix();
    glTranslatef(22.5, -6.5, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 5.0, 1.0);
    glutWireCube(2.0);
    glPopMatrix();

//pé direito superior
    glPushMatrix();
    glTranslatef(19.0, -6.5, -5.5);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 5.0, 1.0);
    glutWireCube(2.0);
    glPopMatrix();

//pé esquerdo inferior
    glPushMatrix();
    glTranslatef(16.5, -6.5, 3.5);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 5.0, 1.0);
    glutWireCube(2.0);
    glPopMatrix();

//pé esquerdo superior
    glPushMatrix();
    glTranslatef(13.5, -6.5, -1.5);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 5.0, 1.0);
    glutWireCube(2.0);
    glPopMatrix();

//banco
    glPushMatrix();
    glTranslatef(18.0, 0.0, 0.0);
    glRotatef(30.0, 0.0, 1.0, 0.0);
    glScalef(1.0, 0.25, 1.0);
    glutSolidCube(12.0);
    glPopMatrix();

//encosto
    glPushMatrix();
    glTranslatef(22.5, 7.5, -2.0);
    glRotatef(60.0, 0.0, -1.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(1.0, 0.25, 1.0);
    glutSolidCube(12.0);
    glPopMatrix();

    glEndList();

// Inicializa display lists para criação da luminaria
    glNewList(LUMINARIA, GL_COMPILE);

//proteção da lampada
    glPushMatrix();
    glTranslatef (-24.5, 19.5, -39.5);
    glRotatef(-160.0, 0.0, 1.0, 0.0);
    gluCylinder(q, 5.0, 1.0, 10.0, 9.0, 3.0);
    glPopMatrix();

//haste
    glPushMatrix();
    glTranslatef(-28.0, 20.5, -50.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(1.0, 1.0, 3.2);
    gluCylinder(q, 1.0, 1.0, 10.0, 5.0, 5.0);
    glPopMatrix();

//pé
    glPushMatrix();
    glTranslatef (-28.0, -11.5, -50.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluDisk(q, 1.0, 3.0, 10.0, 5.0);
    glPopMatrix();

//lampada
    glPushMatrix();
    glTranslatef (-26.5, 19.5, -45.0);
    gluSphere(q, 2.5, 10.0, 10.0);
    glPopMatrix();

    glEndList();

// Inicializa display lists para criação da garrafa
    glNewList(GARRAFA, GL_COMPILE);

//cilindro inferior
    glPushMatrix();
    glTranslatef(-5.0, 17.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(q, 1.5, 1.5, 6.0, 10.0, 5.0);
    glPopMatrix();

//cilindro mediano
    glPushMatrix();
    glTranslatef(-5.0, 20.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(q, 0.5, 1.5, 3.0, 10.0, 5.0);
    glPopMatrix();

//cilindro superior
    glPushMatrix();
    glTranslatef(-5.0, 21.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(q, 0.5, 0.5, 1.0, 10.0, 5.0);
    glPopMatrix();

//tampa
    glPushMatrix();
    glTranslatef(-5.05, 21.75, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutWireTorus(0.25, 0.5, 10.0, 5.0);
    glPopMatrix();

    glEndList();

// Inicializa display lists para criação da taça
    glNewList(TACA, GL_COMPILE);

//cilindro superior
    glPushMatrix();
    glTranslatef(0.0, 16.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(q, 1.5, 0.5, 2.5, 10.0, 5.0);
    glPopMatrix();

//cilindro inferior
    glPushMatrix();
    glTranslatef (0.0, 14.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(q, 0.5, 0.5, 2.5, 10.0, 5.0);
    glPopMatrix();

//base da taça
    glPushMatrix();
    glTranslatef (0.0, 11.5, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluDisk(q, 0.0, 1.0, 10.0, 5.0);
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

// Chama o display list da mesa para exibi-lo
    glPushMatrix();
    glCallList(MESA);
    glPopMatrix();

// Chama o display list das cadeiras para exibi-lo
    glPushMatrix();
    glCallList(CADEIRA_E);
    glPopMatrix();

    glPushMatrix();
    glCallList(CADEIRA_D);
    glPopMatrix();

// Chama o display list da luminaria para exibi-lo
    glPushMatrix();
    glCallList(LUMINARIA);
    glPopMatrix();

// Chama o display list da garrafa para exibi-lo
    glPushMatrix();
    glCallList(GARRAFA);
    glPopMatrix();

//Chama o display list da taça para exibi-lo
    glPushMatrix();
    glCallList(TACA);
    glPopMatrix();

    glutSwapBuffers();
}

void perspectiva(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 200.0);
    gluLookAt(-10.0, 30.0, 50.0,0.0, -2.0, 0.0, 0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
}

void orto_cima(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-60.0, 60.0, -60.0, 60.0, 1.0, 250.0);
    gluLookAt(0.0, 250.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
}

void orto_frontal(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-30.0, 30.0, -30.0, 30.0, 1.0, 250.0);
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
    glutInitWindowSize(400, 400);

    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(perspectiva);

    glutInitWindowPosition(600, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(orto_cima);

    glutInitWindowPosition(1100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(orto_frontal);

    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
