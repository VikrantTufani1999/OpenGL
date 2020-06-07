#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void displayName(void) {
void renderbitmap(float, float, void*, char*);

glColor3f(0.0, 0.0, 0.0);
char buf[100] = {0};
sprintf(buf, "Vikrant Tufani");
renderbitmap(600, 640, GLUT_BITMAP_TIMES_ROMAN_24, buf);
char buf1[100] = {0};
sprintf(buf1, "500061935");
renderbitmap(600, 620, GLUT_BITMAP_TIMES_ROMAN_24, buf1);
}

void renderbitmap(float x, float y, void *font, char *string) {
char *c;

glRasterPos2f(x, y);
for(c = string; *c != '\0'; c++)
glutBitmapCharacter(font, *c);
}

void drawcube(int n)
{
    if(n>0)
    {

     glPushMatrix();

     glTranslatef(-1,1.0,0);
     glFlush();
     glRotatef(0, 0.0, 0.0, 1.0);

     // 1/sqrt(2)=0.707
     glScalef(0.707,0.707,0.707);

     //recursion
     //glColor3f(1.0, 0.0, 0.0);
     drawcube(n-1);

     glPopMatrix();

     glPushMatrix();
     glTranslatef(1.0,1.0,0);
     glRotatef(0, 0.0, 0.0, 1.0);
     glScalef(0.707,0.707,0.707);
     //glColor3f(0.0, 1.0, 0.0);
     drawcube(n-1);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(-1.0,-1.0,0);
     glRotatef(0, 0.0, 0.0, 1.0);
     glScalef(0.707,0.707,0.707);
     //glColor3f(0.0, 0.0, 1.0);
     drawcube(n-1);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(1.0,-1.0,0);
     glRotatef(0, 0.0, 0.0, 1.0);
     glScalef(0.707,0.707,0.707);
     //glColor3f(1.0, 1.0, 0.0);
     drawcube(n-1);
     glPopMatrix();

     //draw a cube
     glutSolidCube(0.3);


    }
}

void treeInit(int n)
{
    // To change color of this figure
   glColor3f(1.0,0.0,0.0);
   drawcube(n);
}

void display (void)
{
    glClearColor (1.0,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    displayName();

    glLoadIdentity();

    gluLookAt (0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0);
    //To change number of iterations
    treeInit(8); // Change this


    glFlush();
}

void reshape (int w, int h)
{
    //reshaoe to aspect ratio
    glViewport (0, 0, 900, 700);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (100, 900 / 700, 1.0, 100.0);
    glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE);
    glutInitWindowSize (900, 700);
    glutInitWindowPosition (300, 100);
    glutCreateWindow ("Cube Fractal");
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutMainLoop ();
    return 0;
}

