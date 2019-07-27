// �������� �ݹ�

#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	//�÷� ���ۿ� �ʱ�ȭ ���� ����
	glColor3f(0.5, 0.5, 0.5);		//ȸ��

	glBegin(GL_POLYGON);			//�簢��

	glVertex3f(-0.5, -0.5, 0.0);	//���ϴ� ��ǥ
	glVertex3f(0.5, -0.5, 0.0);		//���ϴ� ��ǥ
	glVertex3f(0.5, 0.5, 0.0);		//���� ��ǥ
	glVertex3f(-0.5, 0.5, 0.0);		//�»�� ��ǥ
	glEnd();
	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0* HeightFactor, -1.0, 1.0);
}

int main(int argc, char **argv) {

	// ������ �ʱ�ȭ
	glutInit(&argc, argv); // GLUT ������ �Լ�
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	
	// ������ ����
	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(0.0, 0.0, 0.0, 1.0); // GL ���� ���� ����
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0 , 1.0, -1.0, 1.0); // ���翵 ����?
	glutDisplayFunc(MyDisplay);// �ݹ� �Լ� ���
	glutMainLoop(); //�̺�Ʈ ������ ����


	return 0;

	
}