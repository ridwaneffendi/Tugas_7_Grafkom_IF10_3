/* Tugas 7 Grafika Komputer
   Oleh :             
        Ridwan Effendi		10108479
        Anggi Mondera Amino	10108501
        Mochamad Ali Sukwan	10108474
        Ressky Agassy		10108511
 */

#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

void kubus()
{

glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslated(-1.0,0.0,-1.0);
glScaled(0.45,0.45,0.45);
glutSolidCube(1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

}
void prisma(){
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslated(0.0,0.0,0.0);
glScaled(0.45,0.45,0.45);
glutSolidIcosahedron();
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();
}
void teko(){
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslated(0.6,0.0,-0.6);
glScaled(0.4,0.4,0.4);
glutSolidTeapot(1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();
}
void bola(){
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslated(-0.59,0.0,0.62);
glScaled(1.0,1.0,1.0);
glutSolidSphere(0.4,16,16);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();
}
void cone(){
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslated(-1.55,0.0,-0.45);
glScaled(0.4,0.4,0.4);
glutSolidCone(1.0, 2.0, 12, 12);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();
}
void donat(){
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslated(-0.35,0.0,-1.5);
glScaled(0.3,0.3,0.3);
glutSolidTorus(0.4, 0.8, 10, 50);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();  
}
void setMaterial()
{
GLfloat mat_ambient[] = {0.7f,0.7f,0.7f,1.0f}; 
GLfloat mat_diffuse[] = {0.6f,0.6f,0.6f,1.0f};
GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat mat_shininess[] = {50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
}


void setLighting()
{
//mensetting pencahayaan
GLfloat lightIntensity[] = {0.7f,0.7f,0.7f,1.0f};
GLfloat light_position[] = {2.0f,6.0f,3.0f,0.0f};
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
glLightfv(GL_LIGHT0,GL_POSITION,light_position);
}


void setViewport()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
double winHt = 1.0;
glOrtho(-winHt*64/48,winHt*64/48,-winHt,winHt,0.1,100.0);
}


void setCamera()
{

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(3.3,3.3,3.0,0,0.25,0,0.0,1.0,0.0);
}


void displayObject()
{
setMaterial();
setLighting();
setViewport();
setCamera();

glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
kubus();
prisma();
teko();
bola();
cone();
donat();
glFlush();
}


int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,100);
glutCreateWindow("Tugas 7 Grafika Komputer");
glutDisplayFunc(displayObject);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
glClearColor(1.0f,1.0f,1.0f,0.0f);
glViewport(0,0,640,480);
glutMainLoop();
}
