/* Tugas 7 Grafika Komputer - Pohon
Oleh :
Ridwan Effendi 10108479
Anggi Mondera Amino 10108501
Mochamad Ali Sukwan 10108474
Ressky Agassy 10108511
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/glut.h>       

typedef float	M3DVector3f[3];	

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


#define DRAW_FIRST    0
#define DRAW_SECOND   1
#define DRAW_THIRD    2
#define DRAW_FOURTH   3
#define DRAW_FIFTH    4
int iMethod = DRAW_FIRST;   
int i=0, moving[5] = { 3, 0, 2, 1, 0};

void m3dCrossProduct(M3DVector3f result, const M3DVector3f u, const M3DVector3f v)
{
	result[0] = u[1]*v[2] - v[1]*u[2];
	result[1] = -u[0]*v[2] + v[0]*u[2];
	result[2] = u[0]*v[1] - v[0]*u[1];
}

void m3dFindNormal(M3DVector3f result, const M3DVector3f point1, const M3DVector3f point2, 
							const M3DVector3f point3)
{
	M3DVector3f v1,v2;

	v1[0] = point1[0] - point2[0];
	v1[1] = point1[1] - point2[1];
	v1[2] = point1[2] - point2[2];

	v2[0] = point2[0] - point3[0];
	v2[1] = point2[1] - point3[1];
	v2[2] = point2[2] - point3[2];

	m3dCrossProduct(result, v1, v2);
}

void ProcessMenu(int value)
{ 
    iMethod = value;   
    glutPostRedisplay(); 
}

void draw_branch(GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
	GLUquadricObj *pObj;
	pObj =gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);
	
	glPushMatrix();
	gluSphere(pObj, size, 26, 13);
	gluCylinder(pObj, size, size, length, 26, 13);
	glTranslatef(0.0f, 0.0f, length);
	gluSphere(pObj, size, 26, 13);
	glPopMatrix();	
}

void divide_branch(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
	if(n){
		if(n<4)
		glColor3ub(0, 255, 0); //daun
		else glColor3ub(92, 51, 23); //ranting
		glPushMatrix();
		draw_branch(size, length, x, y, z); //batang
		glTranslatef(0.0, 0.0, length);
		glRotatef(45, 0.0, 1.0, 0.0);
		divide_branch(n-1, size*0.7, length*0.7, x, y, z); //ranting kanan
		glRotatef(-90, 0.0, 1.0, 0.0);
		divide_branch(n-1, size*0.7, length*0.7, x, y, z ); //ranting kiri
		glPopMatrix();
	}
	else
		draw_branch(size, length, x, y, z);
}

void divide_branch_second(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
	if(n){
		if(n<2)
		glColor3ub(0, 100, 0); //warna hijau gelap yang cerah (bright)
		else glColor3ub(92, 64, 51); //warna coklat (ranting)

		glPushMatrix();
		draw_branch(size, length, x, y, z);
		glTranslatef(0.0, 0.0, length);
		glRotatef(45, 0.0, 1.0, 0.0);
		divide_branch_second(n-1, size*0.7, length*0.7, x, y, z);
		glRotatef(-90, 0.0, 1.0, 0.0);
		divide_branch_second(n-1, size*0.7, length*0.7, x, y, z );
		glRotatef(-90, 1.0, 0.0, 1.0);
		divide_branch_second(n-1, size*0.7, length*0.7, x, y, z );
		glRotatef(90, 0.0, 01.0, 0.0);
		divide_branch_second(n-1, size*0.7, length*0.7, x, y, z );
		glPopMatrix();
	}
	else{
		glPushMatrix();
		glScalef(2.0, 0.5, 1.0);
		draw_branch(size, length, x, y, z);
		glPopMatrix();
	}
}

void divide_branch_third(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
	if(n){
		if(n<4)
		glColor3ub(107, 79, 65);
		else glColor3ub(92, 64, 51);

		glPushMatrix();
		draw_branch(size, length, x, y, z);
		glTranslatef(0.0, 0.0, length);
		glRotatef(45, 0.0, 1.0, 0.0);
		divide_branch_third(n-1, size*0.7, length*0.7, x, y, z);
		if(n>3){
		glRotatef(-90, 0.0, 1.0, 0.0);
		divide_branch_third(n-1, size*0.5, length*0.5, x, y, z );
		if(n>2){
		glRotatef(-90, 1.0, 0.0, 1.0);
		divide_branch_third(n-1, size*0.7, length*0.3, x, y, z );
		if(n>1){
		glRotatef(90, 0.0, 01.0, 0.0);
		divide_branch_third(n-1, size*0.6, length*0.7, x, y, z );
		}}}
		glPopMatrix();
	}
	else{
		glPushMatrix();
		glColor3ub(0, 100, 0); 
		glScalef(2.0, 0.5, 1.0);
		draw_branch(0.5, 0.3, x, y, z);
		glPopMatrix();
	}
}

void divide_branch_fourth(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
	if(n){
		if(n<2)
		glColor3ub(47, 79, 47); 
		else glColor3ub(109, 91, 64);
		glPushMatrix();
		draw_branch(size, length, x, y, z);
		glTranslatef(0.0, 0.0, length*0.4);
		glPushMatrix(); 
		glRotatef(100, 0.0, 1.0, 0.0);
		divide_branch_fourth(n-1, size*0.9, length*0.5, x, y, z); 
		glRotatef(-200, 0.0, 1.0, 0.0);
		divide_branch_fourth(n-1, size*0.9, length*0.5, x, y, z );
		glPopMatrix(); 
		glTranslatef(0.0, 0.0, length*0.2);
		glPushMatrix();
		glRotatef(100, 0.0, 1.0, 0.0);
		divide_branch_fourth(n-1, size*0.9, length*0.3, x, y, z);
		glRotatef(-200, 0.0, 1.0, 0.0);
		divide_branch_fourth(n-1, size*0.9, length*0.3, x, y, z );
		glPopMatrix();
		glTranslatef(0.0, 0.0, length*0.2);
		glPushMatrix();
		glRotatef(100, 0.0, 1.0, 0.0);
		divide_branch_fourth(n-1, size*0.9, length*0.15, x, y, z);
		glRotatef(-200, 0.0, 1.0, 0.0);
		divide_branch_fourth(n-1, size*0.9, length*0.15, x, y, z );
		glPopMatrix();
		glTranslatef(0.0, 0.0, length*0.1);
		glPushMatrix(); 
		divide_branch_fourth(n-1, size*0.9, length*0.1, x, y, z);
		glPopMatrix(); 
		glPopMatrix(); 
	}
	else{
		draw_branch(size, length, x, y, z);
	}
}

void draw_branch_fifth(GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glScalef(0.50f, 3.0f, 1.0f);
	draw_branch(size, length, 0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, length);
	glRotatef(50, 0.0, 1.0, 0.0);
	draw_branch(size, length*0.7, 0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, length*0.7);
	glRotatef(50, 0.0, 1.0, 0.0);
	draw_branch(size*0.5, length*0.5, 0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, length*0.5);
	glRotatef(50, 0.0, 1.0, 0.0);
	draw_branch(size*0.3, length*0.3, 0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, length*0.3);
	glRotatef(50, 0.0, 1.0, 0.0);
	draw_branch(size*0.3, length*0.1, 0.0, 0.0, 0.0);
		

	glPopMatrix();	
}

void divide_branch_fifth(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{

	if(n){
		if(n<2)
		glColor3ub(0, 100, 0);
		else glColor3ub(92, 64, 51);

		glPushMatrix();
		draw_branch_fifth(size, length, x, y, z);
		glTranslatef(0.0, 0.0, length);
		glRotatef(30, 0.0, 1.0, 0.0);
		divide_branch_fifth(n-1, size*0.7, length*1.5, x, y, z);
		glRotatef(-60, 0.0, 1.0, 0.0);
		divide_branch_fifth(n-1, size*0.7, length*1.5, x, y, z );
		glRotatef(-60, 1.0, 0.0, 1.0);
		divide_branch_fifth(n-1, size*0.7, length*1.5, x, y, z );
		glRotatef(60, 0.0, 01.0, 0.0);
		divide_branch_fifth(n-1, size*0.7, length*1.5, x, y, z );
		glPopMatrix();
	}
	else{
		glColor3ub(0, 100, 0);
		draw_branch_fifth(size, length, x, y, z);
	}
}

void RenderScene(void)
{
	M3DVector3f vNormal;


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch(iMethod){ 

	case DRAW_FIRST:
	{
	glPushMatrix();
	//glTranslatef(-10.0f, 10.0f, 0.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	//glScalef(0.5, 0.5, 0.5);
	divide_branch(9, 1, 5, 0.0, 0.0, 0.0);             
	glPopMatrix();
	glutSwapBuffers();
	}
	break;
	
    case DRAW_SECOND:
	{
	glPushMatrix();
	//glTranslatef(10.0f, 0.0f, 0.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	//glScalef(0.5, 0.5, 0.5);
	divide_branch_second(5, 1, 5, 0.0, 0.0, 0.0);             
	glPopMatrix();
	glutSwapBuffers();
	}
	break;
	
    case DRAW_THIRD:
	{
	glPushMatrix();
	//glTranslatef(10.0f, 0.0f, 0.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	//glScalef(0.5, 0.5, 0.5);
	divide_branch_third(6, 0.5, 7, 0.0, 0.0, 0.0);             
	glPopMatrix();
	glutSwapBuffers();
	}
	break;
	
    case DRAW_FOURTH:
	{
	
	glPushMatrix();
	//glTranslatef(10.0f, 0.0f, 0.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	//glScalef(0.5, 0.5, 0.5);
	divide_branch_fourth(3, 0.3, 13, 0.0, 0.0, 0.0);             
	glPopMatrix();
	glutSwapBuffers();
	}
	break;
	
    case DRAW_FIFTH:
	{
	glPushMatrix();
	//glTranslatef(10.0f, 0.0f, 0.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	//glScalef(0.5, 0.5, 0.5);
	divide_branch_fifth(3, 0.3, 1, 0.0, 0.0, 0.0);             
	glPopMatrix();
	glutSwapBuffers();
	}
	break;
	
	}
}

 
void SetupRC()
{
    GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);		
    glEnable(GL_CULL_FACE);		

    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);
	
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);


    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 128);
    

    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f ); //putih
	//		219;219;112 kuning
	glClearColor(0.85f, 0.85f, 0.430f, 1.0f);
    
    glEnable(GL_NORMALIZE);
}


