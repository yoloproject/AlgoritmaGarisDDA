// Garis Dengan Algoritma DDA
// Team	    : Yolo
// Tanggal  : 2 November 2017
// Di Ubah  : 2 November 2017

// Pustaka
#include <GL\freeglut.h> 
#include <GL\glut.h> // Pustaka window  
#include <iostream> // Header / Pustaka C++ input dan output

using namespace std;

//identifier fungsi
void init(); // Fungsi inisialisasi
void display(void); // Fungsi Display
void ddaOpenGl(void);

//  posisi window di layar
int win_x; // Posisi Layar X
int win_y; // Posisi Layar Y

//  ukuran window
int win_width = 400; // Tinggi Window
int win_height = 400; // Lebar Window

//  judul window
char *judul_win = "Aplikasi Pembuat Garis Dengan DDA";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	win_x = (glutGet(GLUT_SCREEN_WIDTH) - win_width) / 2;
	win_y = (glutGet(GLUT_SCREEN_HEIGHT) - win_height) / 2;
	glutInitWindowSize(win_width, win_height); //set ukuran window 
	glutInitWindowPosition(win_x, win_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_win);


	init();

	glutDisplayFunc(display); // fungsi display
	glutMainLoop(); // loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set background 
	glColor3f(1.0, 0.0, 0.0); //set warna titik
	glPointSize(5.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks  
	glLoadIdentity(); // set matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	ddaOpenGl(); //panggil fungsi ddaOpenGl
	glutSwapBuffers(); //swap buffer 
}

void ddaOpenGl(void) {
	int x1, y1, x2, y2;
	float x, y, dx, dy, steps, x_inc, y_inc;

	//tentukan titik awal dan akhir
	x2 = 0;
	y2 = 300;
	x1 = 500;
	y1 = 0;
	x = x1;
	y = y1;

	//hitung dx dan dy
	dx = x2 - x1;
	dy = y2 - y1;
	
	//hitung steps
	if (abs(dx) > abs(dy)) {
		steps = abs(dx);
		
	}
	else steps = abs(dy);

	//hitung perubahan nilai x (x_inc) dan y (y_inc)
	x_inc = dx / steps;
	y_inc = dy / steps;
	
	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y); // gambar titik awal
	int iterasi = 0;
	
	//perulangan untuk menggambar titik-titik 
	while (iterasi != steps)
	{	
		
	
		x += x_inc;
		y += y_inc;

		iterasi++;
		glVertex2i(x, y); // gambar 
	}

	glEnd();
	glFlush();
}
