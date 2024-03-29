// Timer callback function 2
#include <GL/glut.h>
//#include <time.h>

unsigned char PALETTE[16][3] = {
	{255, 255, 255},	// white
	{0, 255, 255},		// cyan
	{255, 0, 255},		// purple
	{0,0,255},			// blue
	{192,192,192},		// light gray
	{128,128,128},		// dark gray
	{0,128,128},		// dark cyan
	{128,0,128},		// dark purple
	{0,0,128},			// dark blue
	{255,255,0},		// yellow
	{0,255,0},			// green
	{128,128,0},		// dark yellow
	{0,128,0},			// dark green
	{255,0,0},			// red
	{128,0,0},			// dark red
	{0,0,0}				// back
};

GLfloat Delta = 0.0;
GLint Index = 0;
GLfloat Red = 0.0;
GLfloat Green = 0.0;
GLfloat Blue = 0.0;

void MyDisplay() {
	Red = PALETTE[Index][0] / 255.0f;
	Green = PALETTE[Index][1] / 255.0f;
	Blue = PALETTE[Index][2] / 255.0f;
	glColor3f(Red, Green, Blue);

	glBegin(GL_LINES);
	glVertex3f(-1.0 + Delta, 1.0, 0.0);
	glVertex3f(1.0 - Delta, -1.0, 0.0);
	glVertex3f(-1.0, -1.0 + Delta, 0.0);
	glVertex3f(1.0, 1.0 - Delta, 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyTimer(int Value) {
	if (Delta < 2.0f) {
		Delta = Delta + 0.01;
	}
	else {
		Delta = 0.0;
		if (++Index >= 15)
			Index = 0;
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glutPostRedisplay();
	glutTimerFunc(10, MyTimer, 1);
}
void InitSetting(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Timer Animation Sample");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char **argv) {
	InitSetting(argc, argv);

	glutTimerFunc(10, MyTimer, 1);

	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}