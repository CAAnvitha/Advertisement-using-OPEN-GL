#include <iostream>
#include <time.h>
#include <math.h>
#include <stdio.h>




// Apple Specific Compatibility Issues
#ifdef __APPLE__
#include "GLUT/glut.h"
#else
#include "GL\glut.h"
#endif

// Define the value of PI, upto 12 decimal places
#define PI 3.141592653589



// ID to detect which scene the story is in.
int SCENE_ID;
GLfloat cx=1000;
GLfloat summary_para1_fade;
GLfloat summary_para2_fade,summary_para3_fade,summary_para4_fade,summary_para5_fade,summary_para6_fade,summary_para7_fade,summary_para8_fade;
GLfloat dx=1425;
GLfloat ex=200;
GLfloat sx=-150;

// Function to Draw Circle
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;
    
    glBegin(GL_POLYGON);
    {
        for (int i = 0; i <= 50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta), rad * sin(theta));
        }
    }
    glEnd();
}


void drawCircle(GLfloat x, GLfloat y,
                GLfloat r, GLfloat g, GLfloat b,
                GLfloat sx, GLfloat sy,
                GLfloat radius) {
    glPushMatrix();
    
    glTranslatef(x, y, 0);
    glScalef(sx, sy, 0);
    
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();
    
    glPopMatrix();
}

// Function to Draw Semi Circle
void drawSemiCircle(GLfloat tx, GLfloat ty,
                    GLfloat sx, GLfloat sy,
                    GLfloat r, GLfloat g, GLfloat b,
                    GLfloat radius,
                    GLfloat start_angle, GLfloat end_angle) {
    glPushMatrix();
    
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);
    
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (GLfloat i = start_angle; i < end_angle; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();
    
    glPopMatrix();
}

// Function to Draw Arc
void drawArc(GLfloat tx, GLfloat ty,
             GLfloat sx, GLfloat sy,
             GLfloat r, GLfloat g, GLfloat b) {
    glPushMatrix();
    
    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);
    
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3ub(r, g, b);
    for (GLfloat i = 90; i < 270; i++)
        glVertex2f(15 * sin(i * PI / 180), 15 * cos(i * PI / 180));
    glEnd();
    glPointSize(1);
    
    glPopMatrix();
}
void drawText1(float x, float y, float r, float g, float b, const char *string)
{
    int j = strlen(string);
    //    glLineWidth(20.0);
    
    glColor3f(r, g, b);//1.0, 0.24902, 0.0
    
    glRasterPos2f(x, y);
    for (int i = 0; i < j; i++) {
        
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}

void print(const char *string,
           GLfloat r, GLfloat g, GLfloat b, GLfloat a,
           GLint x, GLint y,
           GLfloat w, GLfloat h,
           GLfloat strokeSize) {
    glPushMatrix();
    
    glColor4f(r, g, b, a);
    glTranslatef(x, y, 0);
    glScalef(w, h, 0);
    
    glPointSize(strokeSize);
    glLineWidth(strokeSize);
    
    while (*string)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *string++);
    
    glPopMatrix();
    
    glLineWidth(1);
    glPointSize(1);
}

 /* Scene 0 - Introduction Screen
 */
void introduction() {
   glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1400, 0, 800);


	drawText1(400, 700,
		0.0, 0.0, 0.0,
		"COMPUTER GRAPHICS AND VISUALIZATION LABORATORY");
	drawText1(500, 650,
		0.0, 0.0, 0.0,
		"PROJECT TITLE: ANTI ACNE CREAM");
	drawText1(650, 500,
		0.0, 0.0, 0.0,
		"Submitted by:");
	drawText1(580, 450,
		0.0, 0.0, 0.0,
		"AISHWARYA G: 1DS16CS010 ");
	drawText1(580, 400,
		0.0, 0.0, 0.0,
		"C A ANVITHA: 1DS16CS029 ");
	drawText1(580, 350,
		0.0, 0.0, 0.0,
		"DEVIKA V D: 1DS16CS033 ");
	drawText1(600, 250,
		0.0, 0.0, 0.0,
		"Under the Guidance of:");
	drawText1(550, 200,
		0.0, 0.0, 0.0,
		"Mrs.Anitha M and Mrs.Swetha M D");
	drawText1(650, 150,
		0.0, 0.0, 0.0,
		"Dept of CSE");
	drawText1(630, 100,
		0.0, 0.0, 0.0,
		"DSCE,Bangalore");
	drawText1(640, 50,
		0.0, 0.0, 0.0,
		"Press n to start");
	glFlush();
}


 void drawWoman_scene1(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Darker Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		238,203,173, // Lighter Skin
		1, 1,
		30);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(485, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, -180, 0);

	// Left Eye
	drawCircle(505, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(508, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(530, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(532, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	drawArc(514, 388, .5, .3,
		20, 20, 20);

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(518, 405);
	glVertex2f(522, 398);
	glVertex2f(522, 398);
	glVertex2f(518, 395);
	glEnd();
	glLineWidth(1);
	
	// Arms
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(470, 360);
	glVertex2f(470, 240);
	glVertex2f(475, 360);
	glVertex2f(475, 240);
	glVertex2f(480, 360);
	glVertex2f(480, 240);

	glVertex2f(540, 360);
	glVertex2f(540, 240);
	glVertex2f(545, 360);
	glVertex2f(545, 240);
	glVertex2f(550, 360);
	glVertex2f(550, 240);
	glEnd();
	glLineWidth(1);

	// Top
	glBegin(GL_POLYGON);
	glColor3ub(top_r, top_g, top_b);
	glVertex2f(460, 370);
	glVertex2f(560, 370);
	glVertex2f(540, 300);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(skirt_r, skirt_g, skirt_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glVertex2f(560, 180);
	glVertex2f(460, 180);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(ribbon_r, ribbon_g, ribbon_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glLineWidth(1);

	// Legs
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(490, 180);
	glVertex2f(490, 150);
	glVertex2f(495, 180);
	glVertex2f(495, 150);

	glVertex2f(525, 180);
	glVertex2f(525, 150);
	glVertex2f(530, 180);
	glVertex2f(530, 150);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}

//bed
void bed(void)
{
	//bed head
	glColor3ub (77,40,26);
	glBegin(GL_POLYGON);
	glVertex3f (550, 650, 0);
	glVertex3f (850, 600, 0);
	glVertex3f (850, 250, 0);
	glVertex3f (550, 300, 0);
	glEnd();

	//bed leg
	glColor3ub (88,40,19);
	glBegin(GL_POLYGON);
	glVertex3f (250, 200, 0);
	glVertex3f (550, 150, 0);
	glVertex3f (550, 50, 0);
	glVertex3f (250, 100, 0);
	glEnd();

	//bed right side
	glColor3ub (128,55,36);
	glBegin(GL_POLYGON);
	glVertex3f (850, 250, 0);
	glVertex3f (550, 50, 0);
	glVertex3f (550, 150, 0);
	glVertex3f (850, 350, 0);
	glEnd();

	//bed right side - box left
	glColor3ub (77,40,26);
	glBegin(GL_POLYGON);
	glVertex3f (695, 160, 0);
	glVertex3f (555, 65, 0);
	glVertex3f (555, 140, 0);
	glVertex3f (695, 235, 0);
	glEnd();

	//bed right side - box left - handle
	glColor3ub (128,55,36);
	glBegin(GL_POLYGON);
	glVertex3f (650, 160, 0);
	glVertex3f (600, 125, 0);
	glVertex3f (600, 140, 0);
	glVertex3f (650, 175, 0);
	glEnd();

	//bed right side - 2nd box
	glColor3ub (77,40,26);
	glBegin(GL_POLYGON);
	glVertex3f (845, 260, 0);
	glVertex3f (705, 165, 0);
	glVertex3f (705, 240, 0);
	glVertex3f (845, 335, 0);
	glEnd();

	//bed right side - 2nd box - handle

	glColor3ub (128,55,36);
	glBegin(GL_POLYGON);
	glVertex3f (800, 260, 0);
	glVertex3f (750, 225, 0);
	glVertex3f (750, 240, 0);
	glVertex3f (800, 275, 0);
	glEnd();

	//bed rig
	//bed top right
	glColor3ub (198,40,40);
	glBegin(GL_POLYGON);
	glVertex3f (550, 150, 0);
	glVertex3f (850, 350, 0);
	glVertex3f (850, 400, 0);
	glVertex3f (550, 200, 0);
	glEnd();

	//bed leg left
	glColor3ub (177,160,140);
	glBegin(GL_POLYGON);
	glVertex3f (250, 200, 0);
	glVertex3f (250, 250, 0);
	glVertex3f (550, 450, 0);
	glVertex3f (550, 400, 0);

	glEnd();

	//bed leg top
	glColor3ub (183,28,28);
	glBegin(GL_POLYGON);
	glVertex3f (250, 200, 0);
	glVertex3f (550, 150, 0);
	glVertex3f (550, 200, 0);
	glVertex3f (250, 250, 0);
	glEnd();

	//bed sheet
	glColor3ub (244,67,55);
	glBegin(GL_POLYGON);
	glVertex3f (550, 200, 0.0);
	glVertex3f (250, 250, 0.0);
	glVertex3f (550, 450, 0.0);
	glVertex3f (850, 400, 0.0);
	glEnd();

	//bed pillo
	//bed pillo - left
	glColor3ub (255,245,157);
	glBegin(GL_POLYGON);
	glVertex3f (604, 375, 0.0);
	glVertex3f (500, 395, 0.0);
	glVertex3f (550, 435, 0.0);
	glVertex3f (655, 415, 0.0);
	glEnd();

	//bed pillo - left - side
	glColor3ub (255,145,0);
	glBegin(GL_POLYGON);
	glVertex3f (604, 375, 0.0);
	glVertex3f (655, 415, 0.0);
	glVertex3f (655, 405, 0.0);
	glVertex3f (604, 365, 0.0);
	glEnd();

	//bed pillo - left - bottom
	glColor3ub (255,145,0);
	glBegin(GL_POLYGON);
	glVertex3f (604, 375, 0.0);
	glVertex3f (500, 395, 0.0);
	glVertex3f (500, 385, 0.0);
	glVertex3f (604, 365, 0.0);
	glEnd();

	//bed pillo right
	glColor3ub (255,245,157);
	glBegin(GL_POLYGON);
	glVertex3f (737, 360, 0.0);
	glVertex3f (624, 375, 0.0);
	glVertex3f (675, 410, 0.0);
	glVertex3f (790, 390, 0.0);
	glEnd();

	//bed pillo right-side
	glColor3ub (255,145,0);
	glBegin(GL_POLYGON);
	glVertex3f (737, 360, 0.0);
	glVertex3f (790, 390, 0.0);
	glVertex3f (790, 380, 0.0);
	glVertex3f (737, 350, 0.0);
	glEnd();

	//bed pillo bottom
	glColor3ub (255,145,0);
	glBegin(GL_POLYGON);
	glVertex3f (737, 360, 0.0);
	glVertex3f (624, 375, 0.0);
	glVertex3f (624, 365, 0.0);
	glVertex3f (737, 350, 0.0);
	glEnd();

	//bed blanket
	glColor3ub (94,53,177);
	glBegin(GL_POLYGON);
	glVertex3f (550, 220, 0.0);
	glVertex3f (280, 260, 0.0);
	glVertex3f (400, 340, 0.0);
	glVertex3f (670, 300, 0.0);
	glEnd();
}

void drawWoman_scene3a(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Darker Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		238,203,173, // Lighter Skin
		1, 1,
		30);

	//Pimple
	drawCircle(500,395,
		255, 0, 0,
		1, 1,
		2.2);

	//Pimple
	drawCircle(530,395,
		255, 0, 0,
		1, 1,
		2.2);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(485, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, -180, 0);

	// Left Eye
	drawCircle(505, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(508, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(530, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(532, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glVertex2f(510, 385);
	glVertex2f(522, 385);
	glEnd();

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(518, 405);
	glVertex2f(522, 398);
	glVertex2f(522, 398);
	glVertex2f(518, 395);
	glEnd();
	glLineWidth(1);
	
	// Arms
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(470, 360);
	glVertex2f(470, 240);
	glVertex2f(475, 360);
	glVertex2f(475, 240);
	glVertex2f(480, 360);
	glVertex2f(480, 240);

	glVertex2f(540, 360);
	glVertex2f(540, 240);
	glVertex2f(545, 360);
	glVertex2f(545, 240);
	glVertex2f(550, 360);
	glVertex2f(550, 240);
	glEnd();
	glLineWidth(1);

	// Top
	glBegin(GL_POLYGON);
	glColor3ub(top_r, top_g, top_b);
	glVertex2f(460, 370);
	glVertex2f(560, 370);
	glVertex2f(540, 300);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(skirt_r, skirt_g, skirt_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glVertex2f(560, 180);
	glVertex2f(460, 180);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(ribbon_r, ribbon_g, ribbon_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glLineWidth(1);

	// Legs
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(490, 180);
	glVertex2f(490, 150);
	glVertex2f(495, 180);
	glVertex2f(495, 150);

	glVertex2f(525, 180);
	glVertex2f(525, 150);
	glVertex2f(530, 180);
	glVertex2f(530, 150);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}

void mirror()
{
	glColor3ub (98,47,29);
	glBegin(GL_POLYGON);
	glVertex3f (50, 150,0);
	glVertex3f (245, 230, 0);
	glVertex3f (245, 460, 0);
	glVertex3f (50, 400, 0);
	glEnd();

	//dressing table - front  - left part
	glColor3ub (42,23,15);
	glBegin(GL_POLYGON);
	glVertex3f (55, 160,0);
	glVertex3f (115, 185, 0);
	glVertex3f (115, 410, 0);
	glVertex3f (55, 390, 0);
	glEnd();

	//dressing table - front  - left part - front handel
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (70, 305,0);
	glVertex3f (75, 305, 0);
	glVertex3f (75, 255, 0);
	glVertex3f (70, 255, 0);
	glEnd();

	//dressing table - front  - left part - handel bottom
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (64, 262,0);
	glVertex3f (75, 262, 0);
	glVertex3f (75, 255, 0);
	glVertex3f (64, 255, 0);
	glEnd();

	//dressing table - front  - left part - handel top
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (64, 305,0);
	glVertex3f (75, 305, 0);
	glVertex3f (75, 310, 0);
	glVertex3f (64, 310, 0);
	glEnd();

	//dressing table side
	glColor3ub (42,23,15);
	glBegin(GL_POLYGON);
	glVertex3f (50, 150, 0);
	glVertex3f (20, 170, 0);
	glVertex3f (20, 420, 0);
	glVertex3f (50, 400, 0);
	glEnd();

	//dressing table - front  - middle part
	glColor3ub (42,23,15);
	glBegin(GL_POLYGON);
	glVertex3f (120, 185,0);
	glVertex3f (180, 210, 0);
	glVertex3f (180, 430, 0);
	glVertex3f (120, 410, 0);
	glEnd();

	//dressing table - front  - middle part - handel - top
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (135, 275,0);
	glVertex3f (140, 275, 0);
	glVertex3f (140, 323, 0);
	glVertex3f (135, 323, 0);
	glEnd();

	//dressing table - front  - middle part - handel - down
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (130, 328,0);
	glVertex3f (140, 328, 0);
	glVertex3f (140, 323, 0);
	glVertex3f (130, 323, 0);
	glEnd();
	//dressing table - front  - middle part - handel - top-down
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (130, 275,0);
	glVertex3f (140, 275, 0);
	glVertex3f (140, 280, 0);
	glVertex3f (130, 280, 0);
	glEnd();

	//dressing table - front  - right part
	glColor3ub (42,23,15);
	glBegin(GL_POLYGON);
	glVertex3f (185, 213,0);
	glVertex3f (240, 235, 0);
	glVertex3f (240, 450, 0);
	glVertex3f (185, 430, 0);
	glEnd();

	//dressing table - front  - right part - handel - top
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (200, 300,0);
	glVertex3f (205, 300, 0);
	glVertex3f (205, 343, 0);
	glVertex3f (200, 343, 0);
	glEnd();

	//dressing table - front  - right part - handel - down
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (194, 300,0);
	glVertex3f (205, 300, 0);
	glVertex3f (205, 295, 0);
	glVertex3f (194, 295, 0);
	glEnd();
	//dressing table - front  - right part - handel - top-down
	glColor3ub (255,255,255);
	glBegin(GL_POLYGON);
	glVertex3f (194, 343,0);
	glVertex3f (205, 343, 0);
	glVertex3f (205, 348, 0);
	glVertex3f (194, 348, 0);
	glEnd();

	//dressing table top
	glColor3ub (128,55,36);
	glBegin(GL_POLYGON);
	glVertex3f (20, 420,0);
	glVertex3f (50, 400, 0);
	glVertex3f (245,460, 0);
	glVertex3f (215,480, 0);
	glEnd();

	//dressing table glass frame
	glColor3ub (128,55,36);
	glBegin(GL_LINE_LOOP);
	glVertex3f (190, 470, 0);
	glVertex3f (48, 427, 0);
	glVertex3f (48, 770, 0);
	glVertex3f (190, 800, 0);
	glEnd();

	//dressing table glass
	glColor4f(255,255,255,0.4);
	glBegin(GL_POLYGON);
	glVertex3f (187, 470, 0);
	glVertex3f (53, 430, 0);
	glVertex3f (53, 767, 0);
	glVertex3f (187, 795, 0);
	glEnd();
	
	//dressing table glass frame-bottom
	glColor3ub (128,55,36);
	glBegin(GL_POLYGON);
	glVertex3f (190, 470, 0);
	glVertex3f (48, 427, 0);
	glVertex3f (48, 442, 0);
	glVertex3f (190, 485, 0);
	glEnd();
}
  
void drawWoman_scene3b(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);
	glRotatef(30.0,0.0,1.0,0.0);
	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Darker Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		238,203,173,// Lighter Skin
		1, 1,
		30);

	//Pimple
	drawCircle(490,395,
		255, 0, 0,
		1, 1,
		2.2);

	//Pimple
	drawCircle(520,395,
		255, 0, 0,
		1, 1,
		2.2);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(535, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, 0, 180);

	// Left Eye
	drawCircle(497, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(495, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(522, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(520, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(500, 385);
	glVertex2f(514, 385);
	glEnd();

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(510, 405);
	glVertex2f(502, 398);
	glVertex2f(502, 398);
	glVertex2f(510, 395);
	glEnd();
	glLineWidth(1);

	//Hand
	glBegin(GL_POLYGON);
	glColor3ub(238,203,173);
	glVertex2f(480, 340);
	glVertex2f(455, 290);
	glVertex2f(452, 305);
	glVertex2f(470, 360);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(238,203,173);
	glVertex2f(455, 290);
	glVertex2f(390, 310);
    glVertex2f(400, 320);
	glVertex2f(452, 305);
	glEnd();

	// Arms
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173);
	glVertex2f(540, 360);
	glVertex2f(540, 240);
	glVertex2f(545, 360);
	glVertex2f(545, 240);
	glVertex2f(550, 360);
	glVertex2f(550, 240);
	glEnd();
	glLineWidth(1);

	// Top
	glBegin(GL_POLYGON);
	glColor3ub(top_r, top_g, top_b);
	glVertex2f(460, 370);
	glVertex2f(560, 370);
	glVertex2f(540, 300);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(skirt_r, skirt_g, skirt_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glVertex2f(560, 180);
	glVertex2f(460, 180);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(ribbon_r, ribbon_g, ribbon_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glLineWidth(1);

	// Legs
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(490, 180);
	glVertex2f(490, 150);
	glVertex2f(495, 180);
	glVertex2f(495, 150);

	glVertex2f(525, 180);
	glVertex2f(525, 150);
	glVertex2f(530, 180);
	glVertex2f(530, 150);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}

void drawWoman_scene4a(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Darker Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		238,203,173, // Lighter Skin
		1, 1,
		30);

	//Pimple
	drawCircle(500,395,
		255, 0, 0,
		1, 1,
		2.2);

	//Pimple
	drawCircle(530,395,
		255, 0, 0,
		1, 1,
		2.2);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(485, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, -180, 0);

	// Left Eye
	drawCircle(505, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(508, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(530, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(532, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(506, 385);
	glVertex2f(523, 385);
	glEnd();

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(518, 405);
	glVertex2f(522, 398);
	glVertex2f(522, 398);
	glVertex2f(518, 395);
	glEnd();
	glLineWidth(1);

	// Arms
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(470, 360);
	glVertex2f(470, 240);
	glVertex2f(475, 360);
	glVertex2f(475, 240);
	glVertex2f(480, 360);
	glVertex2f(480, 240);

	glVertex2f(540, 360);
	glVertex2f(540, 240);
	glVertex2f(545, 360);
	glVertex2f(545, 240);
	glVertex2f(550, 360);
	glVertex2f(550, 240);
	glEnd();
	glLineWidth(1);

	// Top
	glBegin(GL_POLYGON);
	glColor3ub(top_r, top_g, top_b);
	glVertex2f(460, 370);
	glVertex2f(560, 370);
	glVertex2f(540, 300);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(skirt_r, skirt_g, skirt_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glVertex2f(560, 180);
	glVertex2f(460, 180);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(ribbon_r, ribbon_g, ribbon_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glLineWidth(1);

	// Legs
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(490, 180);
	glVertex2f(490, 150);
	glVertex2f(495, 180);
	glVertex2f(495, 150);

	glVertex2f(525, 180);
	glVertex2f(525, 150);
	glVertex2f(530, 180);
	glVertex2f(530, 150);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}

void drawWoman_scene4b(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);
	glRotatef(30.0,0.0,1.0,0.0);
	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Darker Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		238,203,173,// Lighter Skin
		1, 1,
		30);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(535, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, 0, 180);

	// Left Eye
	drawCircle(497, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(495, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(522, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(520, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	drawArc(507, 388, .5, .3,
		20, 20, 20);

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(510, 405);
	glVertex2f(502, 398);
	glVertex2f(502, 398);
	glVertex2f(510, 395);
	glEnd();
	glLineWidth(1);

	//Hand
	glBegin(GL_POLYGON);
	glColor3ub(238,203,173);
	glVertex2f(480, 340);
	glVertex2f(455, 290);
	glVertex2f(452, 305);
	glVertex2f(470, 360);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(238,203,173);
	glVertex2f(455, 290);
	glVertex2f(390, 310);
    glVertex2f(400, 320);
	glVertex2f(452, 305);
	glEnd();

	// Arms
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173);
	glVertex2f(540, 360);
	glVertex2f(540, 240);
	glVertex2f(545, 360);
	glVertex2f(545, 240);
	glVertex2f(550, 360);
	glVertex2f(550, 240);
	glEnd();
	glLineWidth(1);

	// Top
	glBegin(GL_POLYGON);
	glColor3ub(top_r, top_g, top_b);
	glVertex2f(460, 370);
	glVertex2f(560, 370);
	glVertex2f(540, 300);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(skirt_r, skirt_g, skirt_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glVertex2f(560, 180);
	glVertex2f(460, 180);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(ribbon_r, ribbon_g, ribbon_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glLineWidth(1);

	// Legs
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(490, 180);
	glVertex2f(490, 150);
	glVertex2f(495, 180);
	glVertex2f(495, 150);

	glVertex2f(525, 180);
	glVertex2f(525, 150);
	glVertex2f(530, 180);
	glVertex2f(530, 150);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}

void drawcream1(GLfloat tx, GLfloat ty,GLfloat tz,  GLfloat sx, GLfloat sy, GLfloat sz)
{
	GLfloat t[]={-90.0,0.0,0.0};
	glPushMatrix();
	glTranslatef(tx, ty, tz);
	glScalef(sx,sy,sz);
	
	glRotatef(90.0,0.0f,0.0f,1.0f);
	  glBegin(GL_POLYGON);
		   glColor3f(1.0,0.0,0.0);
		   glVertex2f(0,0);
		   glVertex2f(100,0);
		   glVertex2f(80,100);
		   glVertex2f(20,100);                                 
      glEnd();
      glBegin(GL_POLYGON);
	      glColor3f(0.0,0.0,1.0);
	      glVertex2f(20,100);
	      glVertex2f(80,100);
	      glVertex2f(80,120);
	      glVertex2f(20,120);
	  glEnd();
	  glPopMatrix();
}

void drawcream_scene5(GLfloat tx, GLfloat ty,GLfloat tz,  GLfloat sx, GLfloat sy, GLfloat sz)
{
	GLfloat t[]={-90.0,0.0,0.0};
	glPushMatrix();
	glTranslatef(tx, ty, tz);
	glScalef(sx,sy,sz);
	glRotatef(90.0,0.0f,0.0f,1.0f);
	  glBegin(GL_POLYGON);
	  glColor3f(1.0,0.0,0.0);
	   glVertex2f(0,0);
	   glVertex2f(100,0);
	   glVertex2f(80,100);
	   glVertex2f(20,100);                                 
    glEnd();
	glBegin(GL_POLYGON);
	  glColor3f(0.0,0.0,1.0);
	    glVertex2f(20,100);
	    glVertex2f(80,100);
	    glVertex2f(80,120);
	    glVertex2f(20,120);
    glEnd();
	glPopMatrix();
}

void  room_scene2()
  {
	glBegin(GL_POLYGON);
	glColor3ub(168, 90, 165);
	   glVertex2f(1400,800);
	   glColor3ub(239, 213, 238);
	   glVertex2f(500,800);
	   glColor3ub(135, 17, 129);
	   glVertex2f(500,250);
	   glColor3ub(135, 17, 129);
	   glVertex2f(1400,250);
	   glEnd();
	   glBegin(GL_POLYGON);
	glColor3ub(122, 124, 124);
	   glVertex2f(500,250);
	   glVertex2f(1400,250);
	   glColor3ub(64, 66, 66);
	    glVertex2f(1400,0);
	   glVertex2f(0,0);
	   glEnd();
	    glBegin(GL_POLYGON);
	glColor3ub(135, 17, 129);
	   glVertex2f(0,0);
	   glColor3ub(239, 213, 238);
	   glVertex2f(0,800);
	   glColor3ub(168, 90, 165);
	    glVertex2f(500,800);
		glColor3ub(135, 17, 129);
	   glVertex2f(500,250);
	   glEnd();
}

void drawWoman_scene2(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);
	glRotatef(-55.0,1.0f,0.0f,1.0f);

	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Darker Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		238,203,173, // Lighter Skin
		1, 1,
		30);

	//Pimple
	drawCircle(500,395,
		255, 0, 0,
		1, 1,
		2.2);

	//Pimple
	drawCircle(529,396,
		255, 0, 0,
		1, 1,
		2.2);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(485, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, -180, 0);

	// Left Eye
	drawCircle(505, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(508, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(530, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(532, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	drawArc(514, 388, .5, .3,
		20, 20, 20);

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(518, 405);
	glVertex2f(522, 398);
	glVertex2f(522, 398);
	glVertex2f(518, 395);
	glEnd();
	glLineWidth(1);

	// Arms
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(470, 360);
	glVertex2f(470, 240);
	glVertex2f(475, 360);
	glVertex2f(475, 240);
	glVertex2f(480, 360);
	glVertex2f(480, 240);

	glVertex2f(540, 360);
	glVertex2f(540, 240);
	glVertex2f(545, 360);
	glVertex2f(545, 240);
	glVertex2f(550, 360);
	glVertex2f(550, 240);
	glEnd();
	glLineWidth(1);

	// Top
	glBegin(GL_POLYGON);
	glColor3ub(top_r, top_g, top_b);
	glVertex2f(460, 370);
	glVertex2f(560, 370);
	glVertex2f(540, 300);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(skirt_r, skirt_g, skirt_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glVertex2f(560, 180);
	glVertex2f(460, 180);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(ribbon_r, ribbon_g, ribbon_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glLineWidth(1);

	// Legs
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(490, 180);
	glVertex2f(490, 150);
	glVertex2f(495, 180);
	glVertex2f(495, 150);

	glVertex2f(525, 180);
	glVertex2f(525, 150);
	glVertex2f(530, 180);
	glVertex2f(530, 150);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}

void  room()
  {

	glBegin(GL_POLYGON);
	 glColor3ub(27, 124,7);
	   glVertex2f(1400,800);
	   glColor3ub(88, 211, 63);
	   glVertex2f(500,800);
	   glColor3ub(27, 96, 13);
	   glVertex2f(500,250);
	  glColor3ub(27, 124,7);
	   glVertex2f(1400,250);
	   glEnd();

	   glBegin(GL_POLYGON);
	glColor3ub(122, 124, 124);
	   glVertex2f(500,250);
	   glVertex2f(1400,250);
	   glColor3ub(64, 66, 66);
	    glVertex2f(1400,0);
	   glVertex2f(0,0);
	   glEnd();

	    glBegin(GL_POLYGON);
		glColor3ub(27, 96, 13);
	   glVertex2f(0,0);
	   glColor3ub(88, 211, 63);
	   glVertex2f(0,800);
	   glColor3ub(27, 124,7);
	    glVertex2f(500,800);
		glColor3ub(27, 124,7);
	   glVertex2f(500,250);
	   glEnd();
}
void ac_clock()
{
	//clock
	drawCircle(710, 667,
		91, 94, 91, 
		1, 1,
		45);
	drawCircle(710, 667,
		255,255,255, 
		1, 1,
		35);
	//clock hands
	glBegin(GL_LINE_STRIP);
	glColor3ub(0,0,0);
	   glVertex2f(710,687);
	   glVertex2f(710,657);
	    glVertex2f(725,691);
	   glEnd();
	   //AC
	   glBegin(GL_POLYGON);
	glColor3ub(249, 249, 247);
	   glVertex2f(895,705);
	   glVertex2f(895,630);
	   glColor3ub(236, 237, 232);
	    glVertex2f(1140,630);
		glColor3ub(203, 204, 199);
	   glVertex2f(1140,705);
	   glEnd();
	   //AC down
	   glBegin(GL_POLYGON);
	glColor3ub(155, 155, 153);
	 glVertex2f(895,630);
	 glVertex2f(1140,630);
	 glColor3ub(153, 153, 149);
	  glVertex2f(1100,650);
	   glVertex2f(935,650);
	   glEnd();
	   //Ac line
	glBegin(GL_LINES);
	glColor3ub(68, 68, 67);
	   glVertex2f(1120,640);
	   glVertex2f(915,640);
	   glEnd();

}
void drawWoman_scene6(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(238,203,173); // Lighter Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		238,203,173, // Lighter Skin
		1, 1,
		30);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(485, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, -180, 0);


	// Left Eye
	drawCircle(505, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(508, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(530, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(532, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	drawArc(514, 388, .5, .3,
		20, 20, 20);

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(518, 405);
	glVertex2f(522, 398);
	glVertex2f(522, 398);
	glVertex2f(518, 395);
	glEnd();
	glLineWidth(1);
	
	// Arms
	glLineWidth(10);
	glBegin(GL_POLYGON);
	glColor3ub(238,203,173); // Lighter Skin

	glVertex2f(468, 350);
	
	glVertex2f(475, 370);
	glVertex2f(435, 455);
	glVertex2f(420, 450);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(238,203,173);
	glVertex2f(540, 360);
	glVertex2f(540, 240);
	glVertex2f(545, 360);
	glVertex2f(545, 240);
	glVertex2f(550, 360);
	glVertex2f(550, 240);
	glEnd();
	glLineWidth(1);

	// Top
	glBegin(GL_POLYGON);
	glColor3ub(255,0,255);
	glVertex2f(460, 370);
	glColor3ub(255,255,255);
	glVertex2f(560, 370);
	glColor3ub(238,130,238);
	glVertex2f(540, 300);
	glColor3ub(255,105,180);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(255,0,255);
	glVertex2f(480, 300);
	glColor3ub(255,255,255);
	glVertex2f(540, 300);
	glColor3ub(238,130,238);
	glVertex2f(610, 120);
	glColor3ub(255,105,180);
	glVertex2f(410, 120);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glPopMatrix();
}

void stage()
{	
	//background
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	   glVertex2f(0,0);
	   glVertex2f(1400,0);
	   glVertex2f(1400,800);
	   glVertex2f(0,800);
	 glEnd();
	
	//ramp-mat
	glBegin(GL_POLYGON);
	glColor3ub(178,34,34);
	   glVertex2f(380,0);
	   glColor3ub(178,34,34);
	   glVertex2f(1020,0);
	   glColor3ub(255,0,0);
	   glVertex2f(820,490);
	   glColor3ub(255,0,0);
	   glVertex2f(580,490);
	 glEnd();
	 //ramp-wall
	 glBegin(GL_POLYGON);
	glColor3ub(25,25,112);
	   glVertex2f(580,490);
	   glColor3ub(0,0,255);
	   glVertex2f(820,490);
	   glColor3ub(0,255,255);
	   glVertex2f(820,800);
	   glColor3ub(0,191,255);
	   glVertex2f(580,800);
	 glEnd();
}

void scene1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//sky
	glBegin(GL_POLYGON);
	glColor3ub(255,0,0);
	   glVertex2f(0,0);
	   glColor3ub(255,69,0);
	   glVertex2f(1400,0);
	   glColor3ub(255,215,0);
	   glVertex2f(1400,800);
	   glColor3ub(255,255,0);
	   glVertex2f(0,800);
	 glEnd();
	//road
	 glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	   glVertex2f(0,0);
	   glVertex2f(1400,0);
	   glVertex2f(1400,250);
	   glVertex2f(0,250);
	 glEnd();
	 //road-stripe
	 glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	   glVertex2f(0,230);
	   glVertex2f(1400,230);
	   glVertex2f(1400,240);
	   glVertex2f(0,240);
	 glEnd();
	 //road-mid2
	 glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	   glVertex2f(120,130);
	   glVertex2f(320,130);
	   glVertex2f(320,150);
	   glVertex2f(120,150);
	 glEnd();
	 //road-mid2
	 glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	   glVertex2f(600,130);
	   glVertex2f(800,130);
	   glVertex2f(800,150);
	   glVertex2f(600,150);
	 glEnd();
	 //road-mid3
	 glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	   glVertex2f(1100,130);
	   glVertex2f(1300,130);
	   glVertex2f(1300,150);
	   glVertex2f(1100,150);
	 glEnd();
	 //building
	 glBegin(GL_POLYGON);
	glColor3ub(27, 14, 132);
	   glVertex2f(500,250);
	   glColor3ub(122, 110, 221);
	   glVertex2f(500,700);
	   glVertex2f(900,700);
	   glColor3ub(45, 36, 117);
	   glVertex2f(900,250);
	 glEnd();
	 //building-door
	 glBegin(GL_POLYGON);
	glColor3ub(210,180,140);
	   glVertex2f(650,250);
	   glVertex2f(650,480);
	   glVertex2f(750,480);
	   glVertex2f(750,250);
	 glEnd();
	 //building-win1
	 glBegin(GL_POLYGON);
	glColor3ub(135,206,250);
	   glVertex2f(550,600);
	   glVertex2f(590,600);
	   glVertex2f(590,650);
	   glVertex2f(550,650);
	 glEnd();
	 //building-win2
	 glBegin(GL_POLYGON);
	glColor3ub(135,206,250);
	   glVertex2f(630,600);
	   glVertex2f(670,600);
	   glVertex2f(670,650);
	   glVertex2f(630,650);
	 glEnd();
	 //building-win3
	 glBegin(GL_POLYGON);
	glColor3ub(135,206,250);
	   glVertex2f(715,600);
	   glVertex2f(755,600);
	   glVertex2f(755,650);
	   glVertex2f(715,650);
	 glEnd();
	 //building-win4
	 glBegin(GL_POLYGON);
	glColor3ub(135,206,250);
	   glVertex2f(800,600);
	   glVertex2f(840,600);
	   glVertex2f(840,650);
	   glVertex2f(800,650);
	 glEnd();
	 //compound-1
	 glBegin(GL_POLYGON);
	glColor3ub(178,34,34);
	   glVertex2f(0,250);
	   glVertex2f(400,250);
	   glVertex2f(400,400);
	   glVertex2f(0,400);
	 glEnd();
	 //compound-2
	 glBegin(GL_POLYGON);
	glColor3ub(178,34,34);
	   glVertex2f(1000,250);
	   glVertex2f(1400,250);
	   glVertex2f(1400,400);
	   glVertex2f(1000,400);
	 glEnd();
	 //woman
	 drawWoman_scene1(sx, 100,0.8, 0.8,
		60, 60, 60,
		173,255,47, // top
		199,21,133, // ribbon
		 238,130,238// skirt
	);
	 //sun
	 drawCircle(150, 700,
		255,165,0, //color
		3,3,
		20);

	 glFlush();
}
void scene2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//sky
	glBegin(GL_POLYGON);
	glColor3ub(255,0,0);
	   glVertex2f(0,0);
	   glColor3ub(255,69,0);
	   glVertex2f(1400,0);
	   glColor3ub(255,215,0);
	   glVertex2f(1400,800);
	   glColor3ub(255,255,0);
	   glVertex2f(0,800);
	 glEnd();
	//road
	 glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	   glVertex2f(0,0);
	   glVertex2f(1400,0);
	   glVertex2f(1400,250);
	   glVertex2f(0,250);
	 glEnd();
	 //road-stripe
	 glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	   glVertex2f(0,230);
	   glVertex2f(1400,230);
	   glVertex2f(1400,240);
	   glVertex2f(0,240);
	 glEnd();
	 //road-mid2
	 glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	   glVertex2f(120,130);
	   glVertex2f(320,130);
	   glVertex2f(320,150);
	   glVertex2f(120,150);
	 glEnd();
	 //road-mid2
	 glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	   glVertex2f(600,130);
	   glVertex2f(800,130);
	   glVertex2f(800,150);
	   glVertex2f(600,150);
	 glEnd();
	 //road-mid3
	 glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	   glVertex2f(1100,130);
	   glVertex2f(1300,130);
	   glVertex2f(1300,150);
	   glVertex2f(1100,150);
	 glEnd();
	 //building
	 glBegin(GL_POLYGON);
	glColor3ub(27, 14, 132);
	   glVertex2f(500,250);
	   glColor3ub(122, 110, 221);
	   glVertex2f(500,700);
	   glVertex2f(900,700);
	   glColor3ub(45, 36, 117);
	   glVertex2f(900,250);
	 glEnd();
	 //building-door
	 glBegin(GL_POLYGON);
	glColor3ub(210,180,140);
	   glVertex2f(650,250);
	   glVertex2f(650,480);
	   glVertex2f(750,480);
	   glVertex2f(750,250);
	 glEnd();
	 //building-win1
	 glBegin(GL_POLYGON);
	glColor3ub(135,206,250);
	   glVertex2f(550,600);
	   glVertex2f(590,600);
	   glVertex2f(590,650);
	   glVertex2f(550,650);
	 glEnd();
	 //building-win2
	 glBegin(GL_POLYGON);
	glColor3ub(135,206,250);
	   glVertex2f(630,600);
	   glVertex2f(670,600);
	   glVertex2f(670,650);
	   glVertex2f(630,650);
	 glEnd();
	 //building-win3
	 glBegin(GL_POLYGON);
	glColor3ub(135,206,250);
	   glVertex2f(715,600);
	   glVertex2f(755,600);
	   glVertex2f(755,650);
	   glVertex2f(715,650);
	 glEnd();
	 //building-win4
	 glBegin(GL_POLYGON);
	glColor3ub(135,206,250);
	   glVertex2f(800,600);
	   glVertex2f(840,600);
	   glVertex2f(840,650);
	   glVertex2f(800,650);
	 glEnd();
	 //compound-1
	 glBegin(GL_POLYGON);
	glColor3ub(178,34,34);
	   glVertex2f(0,250);
	   glVertex2f(400,250);
	   glVertex2f(400,400);
	   glVertex2f(0,400);
	 glEnd();
	 //compound-2
	 glBegin(GL_POLYGON);
	glColor3ub(178,34,34);
	   glVertex2f(1000,250);
	   glVertex2f(1400,250);
	   glVertex2f(1400,400);
	   glVertex2f(1000,400);
	 glEnd();
	 
	 //sun
	 drawCircle(150, 700,
		255,165,0, //color
		3,3,
		20);

	 glFlush();
}

void scene3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	  room_scene2();
	glPushMatrix();	
   glTranslatef(300.0f,0.0f,0.f);
      bed();
  glPopMatrix();
   drawWoman_scene2(380, 450,0.8, 0.8,
		60, 60, 60,
		25,25,112, // top
		229, 49, 49, // ribbon
		229, 49, 49 // skirt
	);
		print("Let me take a nap!",
          0,0,1, summary_para8_fade, 470, 500, 0.2, 0.2, 4);
	
	glFlush();
}	

void scene4()
{
	glClear(GL_COLOR_BUFFER_BIT);
	room();
	ac_clock();
	drawWoman_scene3a(-220, 40,0.8, 0.8,
		60, 60, 60,
		25,25,112, // top
		229, 49, 49, // ribbon
		229, 49, 49 // skirt
	);
	glPushMatrix();
	glTranslatef(100.0f,-60.0f,0.0f);
	glScalef(0.7f,0.7f,0.7f);
	mirror();
	glPopMatrix();
	drawWoman_scene3b(-150, -95, 1.1, 1.1,
		60, 60, 60,
			25,25,112, // top
		229, 49, 49, // ribbon
		229, 49, 49 // skirt
	);
	print("Oh My God!",
          1, 1, 1, summary_para4_fade, 370, 500, 0.2, 0.2, 4);
	print("What is this...",
          1, 1, 1, summary_para4_fade, 370, 450, 0.2, 0.2, 4);

	 glFlush();
	 //glutSwapBuffers();
}

void scene5()
{
	
	  glClear(GL_COLOR_BUFFER_BIT);
	  room();
	 ac_clock();

	  glPushMatrix();
	    glTranslatef(100.0f,-60.0f,0.0f);
		glScalef(0.7f,0.7f,0.7f);
	   mirror();
	  glPopMatrix();
	    drawWoman_scene4a(200, 10, 1, 1,
		60, 60, 60,
		25,25,112, // top
		229, 49, 49, // ribbon
		229, 49, 49 // skirt
	);
     drawWoman_scene4b(cx, -20, 1.2, 1.2,
		64, 66, 64,
			165,42,42, // top
		77, 147, 242, // ribbon
		25,25,112 // skirt
	);
	    drawcream1(dx, 340.0f, 0.0f,0.35f,0.35f,0.35f);

		 print("Hey! Try this",
          1, 1, 1, summary_para2_fade, 1000, 550, 0.2, 0.2, 4);
		 print("Anti-acne cream",
          1, 1, 1, summary_para2_fade, 1000, 500, 0.2, 0.2, 4);
		glFlush();
		//glutSwapBuffers();
}

void scene6()
  {

	 glClear(GL_COLOR_BUFFER_BIT);
	  room();
	  ac_clock();
	  glPushMatrix();
	    glTranslatef(100.0f,-60.0f,0.0f);
		glScalef(0.7f,0.7f,0.7f);
	   mirror();
	  glPopMatrix();
	    drawWoman_scene4a(200, 10, 1, 1,
		60, 60, 60,
		25,25,112, // top
		229, 49, 49, // ribbon
		229, 49, 49 // skirt
	);
      

     drawWoman_scene4b(400, -20, 1.2, 1.2,
		64, 66, 64,
			165,42,42, // top
		77, 147, 242, // ribbon
		25,25,112 // skirt
	);
	  
	    drawcream1(dx, 340.0f, 0.0f,0.35f,0.35f,0.35f);

		print("Thank you! I'll",
          1, 1, 1, summary_para2_fade, 400, 550, 0.2,0.2, 4);
	print("try it right away",
          1, 1, 1, summary_para2_fade, 400, 500, 0.2,0.2, 4);
		glFlush();
  }
void scene7()
 {
	 glClear(GL_COLOR_BUFFER_BIT);
	 room();
	 ac_clock();
	  drawWoman_scene3a(-220, 40,0.8, 0.8,
		60, 60, 60,
		25,25,112, // top
		229, 49, 49, // ribbon
		229, 49, 49 // skirt
	);
	  drawcream_scene5(220.0f, 280.0f, 0.0f,0.2f,0.2f,0.2f);
	  glPushMatrix();
	    glTranslatef(100.0f,-60.0f,0.0f);
		glScalef(0.7f,0.7f,0.7f);
	   mirror();
	  glPopMatrix();
     drawWoman_scene3b(-150, -95, 1.1, 1.1,
		60, 60, 60,
			25,25,112, // top
		229, 49, 49, // ribbon
		229, 49, 49 // skirt
	);
	    drawcream_scene5(250.0f, 250.0f, 0.0f,0.3f,0.3f,0.3f);
   print("Hope this helps me",
          1, 1, 1, summary_para3_fade, 400, 450, 0.2,0.2, 4);
	print("in removing all marks",
          1, 1, 1, summary_para3_fade, 400, 400, 0.2,0.2, 4);
		glFlush();
}

void scene8()
{
	glClear(GL_COLOR_BUFFER_BIT);
	stage();
	drawWoman_scene6(180, ex,1.0, 1.0,
		60, 60, 60);
	glFlush();
	    print("Thank you for treating ",
          1, 1, 1, summary_para1_fade, 890, 550, 0.2, 0.2, 4);
    print("my skin so well.",
          1, 1, 1, summary_para1_fade, 890, 500, 0.2,0.2, 4);
	print("Louis Anti-acne",
          1, 1, 1, summary_para1_fade, 890, 450, 0.2,0.2, 4);
	print("cream is the best",
          1, 1, 1, summary_para1_fade, 890, 400, 0.2,0.2, 4);
	glFlush();
}

void scene9()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//background
	glBegin(GL_POLYGON);
	glColor3ub(25,25,112);
	   glVertex2f(0,0);
	   glColor3ub(0,0,255);
	   glVertex2f(1400,0);
	   glColor3ub(0,255,255);
	   glVertex2f(1400,800);
	   glColor3ub(0,191,255);
	   glVertex2f(0,800);
	 glEnd();
	//cream
	glBegin(GL_POLYGON);
	glColor3ub(178,34,34);
	   glVertex2f(250,270);
	   glColor3ub(255,0,0);
	   glVertex2f(400,270);
	   glColor3ub(255,160,122);
	   glVertex2f(500,600);
	   glColor3ub(255,0,0);
	   glVertex2f(150,600);
	 glEnd();
	 //cap
	 glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	   glVertex2f(250,200);
	   glColor3ub(0,0,0);
	   glVertex2f(400,200);
	   glColor3ub(105,105,105);
	   glVertex2f(400,270);
	   glColor3ub(0,0,0);
	   glVertex2f(250,270);
	 glEnd();
	 //tube-edge
	 glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	   glVertex2f(150,600);
	   glColor3ub(0,0,0);
	   glVertex2f(500,600);
	   glColor3ub(105,105,105);
	   glVertex2f(500,620);
	   glColor3ub(0,0,0);
	   glVertex2f(150,620);
	 glEnd();
	 drawText1(290, 500,
		0.0, 0.0, 0.0,
		"LOUIS");
	 drawText1(270, 400,
		0.0, 0.0, 0.0,
		"Anti-Acne ");
	 drawText1(297,350,
		0.0, 0.0, 0.0,
		"cream");
	 print("Anti-Acne Cream :- ",
          0,0,0, summary_para7_fade, 770, 550, 0.2, 0.2, 4);
    print("Helps in removing",
          1, 1, 1, summary_para6_fade, 770, 500, 0.2,0.2, 4);
	print("Acne and pimple",
          1, 1, 1, summary_para6_fade, 770, 450, 0.2,0.2, 4);
	print("That makes your skin",
          1, 1, 1, summary_para6_fade, 770, 400, 0.2,0.2, 4);
	print("Clear and Brighter",
          1, 1, 1, summary_para6_fade, 770, 350, 0.2,0.2, 4);
	 
	 glFlush();
}

void scene1a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene1();
} 

void scene2a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene2();
} 

void scene3a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene3();
} 

void scene4a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene4();
} 

void scene5a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene5();
} 

void scene6a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene6();
} 

void scene7a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene7();
}

void scene8a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene8();
}

void scene9a()
{ 
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
	scene9();
}
  
void update(int) {
    
	if (SCENE_ID == 1) {
        if(sx<250)
         sx = sx +3.0;
	}

	if (SCENE_ID == 3) {
        
	if(summary_para8_fade<1)
			 summary_para8_fade+= 0.03;
    }

	if (SCENE_ID == 4) {
        
	if(summary_para4_fade<1)
			 summary_para4_fade+= 0.01;
    }

    if (SCENE_ID == 5) {
        if(cx>400)
         cx = cx -3.0;
	if(dx>820)
         dx = dx -3.0;

	if(summary_para2_fade<1)
			 summary_para2_fade+= 0.005;
    }
	if (SCENE_ID ==6) {
       	if(summary_para5_fade<1)
			 summary_para5_fade+= 0.01;
    }
	if (SCENE_ID ==7) {
       	if(summary_para3_fade<1)
			 summary_para3_fade+= 0.03;
    }
	if (SCENE_ID == 8) {
         if(ex>-20)
			  ex = ex -3.0;
		  
		 if(summary_para1_fade<1)
			 summary_para1_fade+= 0.01;
    }
	if (SCENE_ID == 9) {
		  
		 if(summary_para7_fade<1)
			 summary_para7_fade+= 0.01;
		 if(summary_para6_fade<1)
			 summary_para6_fade+= 0.01;
    }
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
    
    // Summary
}



// Function to Render Scene
void renderScene() {
    // Switch to know which scene is playing
    switch (SCENE_ID) {
        case 0:
            introduction();
            break;
        case 1:
            scene1();
            break;
        case 2:
            scene2();
            break;
        case 3:
            scene3();
            break;
            
        case 4:
            scene4();
            break;
            
        case 5:
            scene5();
            break;
            
        case 6:
            scene6();
            break;
            
        case 7:
            scene7();
            break;
            
            case 8:
             scene8();
             break;

			 case 9:
             scene9();
             break;
             
        
    }
    
    // glFush sends it to the Display Buffer
    glFlush();
}

// Function to Handle Mouse Clicks
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        std::cout << x << "\t" << 800 - y << "\n";
}

// Keyboard Action
void keyPress(unsigned char key, int x, int y) {
    switch (key) {
            // Go to Previous Scene
        case 'b':
        case 'B':
            if (SCENE_ID == 0)
                break;
            SCENE_ID--;
            break;
            // Go to Next Scene
        case 'n':
        case 'N':
            if (SCENE_ID == 15)
                break;
            SCENE_ID++;
            break;
            // Quit Story
        case 'q':
        case 'Q':
            exit(0);
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
}

// Function to Initialize Screen
void initializeScreen() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1400, 0, 800);
}

// Main Function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1400, 800);
    glutCreateWindow("Louis Anti-Acne Cream");
    
    // Enables Transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    // Enable Smoothening
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    
    // Display Function
    glutDisplayFunc(renderScene);
    
    // Input Functions
    glutKeyboardFunc(keyPress);
    glutMouseFunc(mouseClick);
    
    initializeScreen();
    
    // Timer Function
    // every 25 milliseconds, update function is called
    glutTimerFunc(25, update, 0);
    
    glutMainLoop();
    
    return 0;
}
