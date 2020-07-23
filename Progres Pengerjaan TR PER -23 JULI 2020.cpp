#include <windows.h>
#include <GL/glut.h>
#include <math.h>


void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x,int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("TR GRAFKOM_L");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(1.0);
    glLineWidth(1.0f);
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f,0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);


//lapangan sepak bola
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-30,-25,40);
    glVertex3f(30,-25,40);
    glVertex3f(30,-25,-40);
    glVertex3f(-30,-25,-40);
    glEnd();


//GAWANG DEPAN
    glClearColor(1,1,1,0);//garis tengah
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(30,-24,0);
    glVertex3f(-30,-24,0);
    glVertex3f(30,-24,0);
    glVertex3f(-30,-24,0);
    glEnd();

// garis luar gawang
    glClearColor(1,1,1,0);//garis pertama
    glColor3f(1,0.8,1);
    glBegin(GL_LINES);
    glVertex3f(15,-24,25);
    glVertex3f(-15,-24,25);
    glVertex3f(15,-24,25);
    glVertex3f(-15,-24,25);
    glEnd();

    glPushMatrix(); // garis kanan
    glClearColor(1,1,1,0);
    glColor3f(0.8,1,1);
    glBegin(GL_LINES);
    glVertex3f(-15,-24,40);
    glVertex3f(-15,-24,25);
    glVertex3f(-15,-24,25);
    glVertex3f(-15,-24,40);
    glEnd();

    glPushMatrix(); // garis kiri
    glClearColor(1,1,1,0);
    glColor3f(0.8,1,1);
    glBegin(GL_LINES);
    glVertex3f(15,-24,40);
    glVertex3f(15,-24,25);
    glVertex3f(15,-24,25);
    glVertex3f(15,-24,40);
    glEnd();

    glClearColor(1,1,1,0);//garis kedua
    glColor3f(1,0.8,1);
    glBegin(GL_LINES);
    glVertex3f(23,-24,18);
    glVertex3f(-23,-24,18);
    glVertex3f(23,-24,18);
    glVertex3f(-23,-24,18);
    glEnd();


// garis luar gawang
    glClearColor(1,1,1,0);//garis pertama
    glColor3f(1,0.8,1);
    glBegin(GL_LINES);
    glVertex3f(15,-24,-25);
    glVertex3f(-15,-24,-25);
    glVertex3f(15,-24,-25);
    glVertex3f(-15,-24,-25);
    glEnd();

    glPushMatrix(); // garis kanan
    glClearColor(1,1,1,0);
    glColor3f(0.8,1,1);
    glBegin(GL_LINES);
    glVertex3f(-15,-24,-40);
    glVertex3f(-15,-24,-25);
    glVertex3f(-15,-24,-25);
    glVertex3f(-15,-24,-40);
    glEnd();


    glPushMatrix(); // garis kiri
    glClearColor(1,1,1,0);
    glColor3f(0.8,1,1);
    glBegin(GL_LINES);
    glVertex3f(15,-24,-40);
    glVertex3f(15,-24,-25);
    glVertex3f(15,-24,-25);
    glVertex3f(15,-24,-40);
    glEnd();

    glClearColor(1,1,1,0);//garis kedua
    glColor3f(1,0.8,1);
    glBegin(GL_LINES);
    glVertex3f(23,-24,-18);
    glVertex3f(-23,-24,-18);
    glVertex3f(23,-24,-18);
    glVertex3f(-23,-24,-18);
    glEnd();

    glPushMatrix(); // garis kanan
    glClearColor(1,1,1,0);
    glColor3f(0.8,1,1);
    glBegin(GL_LINES);
    glVertex3f(-23,-24,40);
    glVertex3f(-23,-24,18);
    glVertex3f(-23,-24,18);
    glVertex3f(-23,-24,40);
    glEnd();


    glPushMatrix(); // garis kiri
    glClearColor(1,1,1,0);
    glColor3f(0.8,1,1);
    glBegin(GL_LINES);
    glVertex3f(23,-24,40);
    glVertex3f(23,-24,18);
    glVertex3f(23,-24,18);
    glVertex3f(23,-24,40);
    glEnd();

    glPushMatrix(); // garis kanan
    glClearColor(1,1,1,0);
    glColor3f(0.8,1,1);
    glBegin(GL_LINES);
    glVertex3f(-23,-24,-40);
    glVertex3f(-23,-24,-18);
    glVertex3f(-23,-24,-18);
    glVertex3f(-23,-24,-40);
    glEnd();


    glPushMatrix(); // garis kiri
    glClearColor(1,1,1,0);
    glColor3f(0.8,1,1);
    glBegin(GL_LINES);
    glVertex3f(23,-24,-40);
    glVertex3f(23,-24,-18);
    glVertex3f(23,-24,-18);
    glVertex3f(23,-24,-40);
    glEnd();


    glPushMatrix();
    glClearColor(1,1,1,0);
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-10,-24,39);
    glVertex3f(10,-24,39);
    glVertex3f(10,-7,30);
    glVertex3f(-10,-7,30);//ATAP GAWANG
    glEnd();

    glPushMatrix();
    glClearColor(1,1,1,0);
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-10,-24,-39);
    glVertex3f(10,-24,-39);
    glVertex3f(10,-7,-30);
    glVertex3f(-10,-7,-30);//ATAP GAWANG BELAKANG
    glEnd();

    glPushMatrix(); //GARIS TIANG DEPAN KIRI KANAN
    glClearColor(1,1,1,0);
    glColor3f(1,0.5,0.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(10,-7,30);
    glVertex3f(10,-24,30);
    glVertex3f(-10,-7,30);
    glVertex3f(-10,-24,30);

    glPushMatrix(); //GARIS TIANG DEPAN KIRI KANAN B
    glClearColor(1,1,1,0);
    glColor3f(1,0.5,0.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(10,-7,-30);
    glVertex3f(10,-24,-30);
    glVertex3f(-10,-7,-30);
    glVertex3f(-10,-24,-30);



    glPushMatrix(); // GARIS KEDEPAN KIRI
    glClearColor(1,1,1,0);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(-10,-24,40);
    glVertex3f(-10,-24,30);
    glVertex3f(-10,-24,30);
    glVertex3f(-10,-24,40);
    glEnd();
    glPushMatrix(); // GARIS KEDEPAN KIRI B
    glClearColor(1,1,1,0);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(10,-24,-40);
    glVertex3f(10,-24,-30);
    glVertex3f(10,-24,-30);
    glVertex3f(10,-24,-40);
    glEnd();



    glPushMatrix();// GARIS KEDEPAN KANAN
    glClearColor(1,1,1,0);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(10,-24,40);
    glVertex3f(10,-24,30);
    glVertex3f(10,-24,30);
    glVertex3f(10,-24,40);
    glEnd();

    glPushMatrix();// GARIS KEDEPAN KANAN
    glClearColor(1,1,1,0);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(-10,-24,-40);
    glVertex3f(-10,-24,-30);
    glVertex3f(-10,-24,-30);
    glVertex3f(-10,-24,-40);
    glEnd();



//ATAP STADION
    glBegin(GL_POLYGON); //ATAP BENGKOK KEATAS KANAN
    glColor3ub(169,169,169);
    glVertex3f(77,60,-50);
    glVertex3f(77,60,50);
    glVertex3f(70,65,50);
    glVertex3f(70,65,-50);
    glEnd();
    glBegin(GL_POLYGON);// ATAP BENGKOK KEATAS KIRI
    glColor3ub(169,169,169);
    glVertex3f(-77,60,-50);
    glVertex3f(-77,60,50);
    glVertex3f(-70,65,50);
    glVertex3f(-70,65,-50);
    glEnd();
    glBegin(GL_POLYGON);// ATAP BENGKOK KEATAS BELAKANG
    glColor3ub(169,169,169);
    glVertex3f(20,60,92);
    glVertex3f(-20,60,92);
    glVertex3f(-20,65,87);
    glVertex3f(20,65,87);
    glEnd();
    glBegin(GL_POLYGON);// ATAP BENGKOK KEATAS DEPAN
    glColor3ub(169,169,169);
    glVertex3f(20,60,-92);
    glVertex3f(-20,60,-92);
    glVertex3f(-20,65,-87);
    glVertex3f(20,65,-87);
    glEnd();
    glBegin(GL_POLYGON);// ATAP BENGKOK KEATAS SISI
    glColor3ub(169,169,169);
    glVertex3f(77,60,50);
    glVertex3f(20,60,92);
    glVertex3f(20,65,87);
    glVertex3f(70,65,50);
    glEnd();
    glBegin(GL_POLYGON);// ATAP BENGKOK KEATAS SISI
    glColor3ub(169,169,169);
    glVertex3f(-20,60,92);
    glVertex3f(-77,60,50);
    glVertex3f(-70,65,50);
    glVertex3f(-20,65,87);
    glEnd();
    glBegin(GL_POLYGON);// ATAP BENGKOK KEATAS SISI
    glColor3ub(169,169,169);
    glVertex3f(-20,60,-92);
    glVertex3f(-77,60,-50);
    glVertex3f(-70,65,-50);
    glVertex3f(-20,65,-87);
    glEnd();

    glBegin(GL_POLYGON);// ATAP BENGKOK KEATAS SISI
    glColor3ub(169,169,169);
    glVertex3f(20,60,-92);
    glVertex3f(77,60,-50);
    glVertex3f(70,65,-50);
    glVertex3f(20,65,-87);
    glEnd();

    glBegin(GL_POLYGON); //ATAP BOLONG KANAN
    glColor3ub(169,169,169);
    glVertex3f(-70,65,50);
    glVertex3f(-70,65,-50);
    glVertex3f(-50,65,-50);
    glVertex3f(-50,65,50);
    glEnd();
    glBegin(GL_POLYGON); //ATAP BOLONG KIRI
    glColor3ub(169,169,169);
    glVertex3f(70,65,50);
    glVertex3f(70,65,-50);
    glVertex3f(50,65,-50);
    glVertex3f(50,65,50);
    glEnd();
    glBegin(GL_POLYGON); //ATAP BOLONG DEPAN
    glColor3ub(169,169,169);
    glVertex3f(-20,65,87);
    glVertex3f(20,65,87);
    glVertex3f(20,65,70);
    glVertex3f(-20,65,70);
    glEnd();
    glBegin(GL_POLYGON); //ATAP BOLONG DEPAN
    glColor3ub(169,169,169);
    glVertex3f(-20,65,-87);
    glVertex3f(20,65,-87);
    glVertex3f(20,65,-70);
    glVertex3f(-20,65,-70);
    glEnd();
    glBegin(GL_POLYGON); //ATAP BOLONG SISI BELAKANG
    glColor3ub(169,169,169);
    glVertex3f(20,65,-87);
    glVertex3f(70,65,-50);
    glVertex3f(50,65,-50);
    glVertex3f(20,65,-70);
    glEnd();

    glBegin(GL_POLYGON); //ATAP BOLONG SISI BELAKANG
    glColor3ub(169,169,169);
    glVertex3f(-20,65,87);
    glVertex3f(-70,65,50);
    glVertex3f(-50,65,50);
    glVertex3f(-20,65,70);
    glEnd();
    glBegin(GL_POLYGON); //ATAP BOLONG SISI BELAKANG
    glColor3ub(169,169,169);
    glVertex3f(20,65,87);
    glVertex3f(70,65,50);
    glVertex3f(50,65,50);
    glVertex3f(20,65,70);
    glEnd();
    glBegin(GL_POLYGON); //ATAP BOLONG SISI BELAKANG
    glColor3ub(169,169,169);
    glVertex3f(-20,65,-87);
    glVertex3f(-70,65,-50);
    glVertex3f(-50,65,-50);
    glVertex3f(-20,65,-70);
    glEnd();
    //PONDASI awal berwarna hitam
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(77,-26,-50);
    glVertex3f(77,-26,50);
    glVertex3f(20,-26,92);
    glVertex3f(-20,-26,92);

    glVertex3f(-77,-26,50);
    glVertex3f(-77,-26,-50);
    glVertex3f(-20,-26,-92);
    glVertex3f(20,-26,-92);
    glEnd();

    // GARIS HUBUNG alias dinding luar
    glBegin(GL_POLYGON);//KANAN
    glColor3ub(192,192,192);
    glVertex3f(77,60,-50);
    glVertex3f(77,60,50);
    glVertex3f(90,-26,50);
    glVertex3f(90,-26,-50);
    glEnd();



    //HIASAN DINDING KANAN
    glBegin(GL_POLYGON);//KANAN
    glColor3ub(255,228,213);
    glVertex3f(78,60,-40);
    glVertex3f(78,60,-35);
    glVertex3f(90,-26,-35);
    glVertex3f(90,-26,-40);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(78,60,0);
    glVertex3f(78,60,5);
    glVertex3f(90,-26,5);
    glVertex3f(90,-26,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(78,60,40);
    glVertex3f(78,60,35);
    glVertex3f(90,-26,35);
    glVertex3f(90,-26,40);
    glEnd();

    // HIASAN VERTIKAL
    glBegin(GL_POLYGON);//KANAN
    glColor3ub(255,228,213);
    glVertex3f(80,45,-50);
    glVertex3f(80,45,50);
    glVertex3f(90,43,50);
    glVertex3f(90,43,-50);
    glEnd();

    glBegin(GL_POLYGON);//KANAN
    glColor3ub(255,228,213);
    glVertex3f(87,0,-50);
    glVertex3f(87,0,50);
    glVertex3f(90,-5,50);
    glVertex3f(90,-5,-50);
    glEnd();


///////////////////////////////////////////////////////
    glBegin(GL_POLYGON);//KIRI
    glColor3ub(192,192,192);
    glVertex3f(-77,60,-50);
    glVertex3f(-77,60,50);
    glVertex3f(-90,-26,50);
    glVertex3f(-90,-26,-50);
    glEnd();

    //HIASAN DINDING KIRI
    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-78,60,-40);
    glVertex3f(-78,60,-35);
    glVertex3f(-90,-26,-35);
    glVertex3f(-90,-26,-40);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-78,60,0);
    glVertex3f(-78,60,5);
    glVertex3f(-90,-26,5);
    glVertex3f(-90,-26,0);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-78,60,40);
    glVertex3f(-78,60,35);
    glVertex3f(-90,-26,35);
    glVertex3f(-90,-26,40);
    glEnd();

    // HIASAN VERTIKAL
    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-80,45,-50);
    glVertex3f(-80,45,50);
    glVertex3f(-90,43,50);
    glVertex3f(-90,43,-50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-87,0,-50);
    glVertex3f(-87,0,50);
    glVertex3f(-90,-5,50);
    glVertex3f(-90,-5,-50);
    glEnd();




///////////////////////////////////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);//DEPAN
    glColor3ub(192,192,192);
    glVertex3f(20,60,92);
    glVertex3f(-20,60,92);
    glVertex3f(-20,-26,105);
    glVertex3f(20,-26,105);
    glEnd();

    glBegin(GL_POLYGON);//DEPAN
    glColor3ub(255,228,213);
    glVertex3f(2,60,95);
    glVertex3f(-2,60,95);
    glVertex3f(-2,-26,105);
    glVertex3f(2,-26,105);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(20,45,95);
    glVertex3f(-20,45,95);
    glVertex3f(-20,40,97);
    glVertex3f(20,40,97);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(20,20,98);
    glVertex3f(-20,20,98);
    glVertex3f(-20,15,100);
    glVertex3f(20,15,100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(20,-6,103);
    glVertex3f(-20,-6,103);
    glVertex3f(-20,-11,105);
    glVertex3f(20,-11,105);
    glEnd();

///////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);//BELAKANG
    glColor3ub(192,192,192);
    glVertex3f(20,60,-92);
    glVertex3f(-20,60,-92);
    glVertex3f(-20,-26,-105);
    glVertex3f(20,-26,-105);
    glEnd();

    glBegin(GL_POLYGON);//BELAKANG
    glColor3ub(255,228,213);
    glVertex3f(2,60,-95);
    glVertex3f(-2,60,-95);
    glVertex3f(-2,-26,-105);
    glVertex3f(2,-26,-105);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(20,45,-95);
    glVertex3f(-20,45,-95);
    glVertex3f(-20,40,-97);
    glVertex3f(20,40,-97);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(20,20,-98);
    glVertex3f(-20,20,-98);
    glVertex3f(-20,15,-100);
    glVertex3f(20,15,-100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(20,-6,-103);
    glVertex3f(-20,-6,-103);
    glVertex3f(-20,-11,-105);
    glVertex3f(20,-11,-105);
    glEnd();

////////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);//SISI KIRI
    glColor3ub(192,192,192);
    glVertex3f(-20,60,92);
    glVertex3f(-77,60,50);
    glVertex3f(-90,-26,50);
    glVertex3f(-20,-26,105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-20,45,97);
    glVertex3f(-77,45,52);
    glVertex3f(-90,40,52);
    glVertex3f(-20,40,105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-22,-6,100);
    glVertex3f(-80,-6,54);
    glVertex3f(-92,-11,54);
    glVertex3f(-22,-11,105);
    glEnd();
/////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);//SISI KANAN
    glColor3ub(192,192,192);
    glVertex3f(-20,60,-92);
    glVertex3f(-77,60,-50);
    glVertex3f(-90,-26,-50);
    glVertex3f(-20,-26,-105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(20,45,97);
    glVertex3f(77,45,52);
    glVertex3f(90,40,52);
    glVertex3f(20,40,105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(22,-6,100);
    glVertex3f(80,-6,54);
    glVertex3f(92,-11,54);
    glVertex3f(22,-11,105);
    glEnd();
/////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);//SISI KIRI B
    glColor3ub(192,192,192);
    glVertex3f(20,60,92);
    glVertex3f(77,60,50);
    glVertex3f(90,-26,50);
    glVertex3f(20,-26,105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(20,45,-97);
    glVertex3f(77,45,-52);
    glVertex3f(90,40,-52);
    glVertex3f(20,40,-105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(22,-6,-100);
    glVertex3f(80,-6,-54);
    glVertex3f(92,-11,-54);
    glVertex3f(22,-11,-105);
    glEnd();
/////////////////////////////////////////////////////////////////////////////////////////

    glBegin(GL_POLYGON);//SISI KANAN B
    glColor3ub(192,192,192);
    glVertex3f(20,60,-92);
    glVertex3f(77,60,-50);
    glVertex3f(90,-26,-50);
    glVertex3f(20,-26,-105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-20,45,-97);
    glVertex3f(-77,45,-52);
    glVertex3f(-90,40,-52);
    glVertex3f(-20,40,-105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,228,213);
    glVertex3f(-22,-6,-100);
    glVertex3f(-80,-6,-54);
    glVertex3f(-92,-11,-54);
    glVertex3f(-22,-11,-105);
    glEnd();
/////////////////////////////////////////////////////////////////////////////////////////

//litasan maraton atas
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-40,-25,40.1);
    glVertex3f(40,-25,40.1);
    glVertex3f(40,-25,48);
    glVertex3f(-40,-25,48);
    glEnd();

    //lintasan maraton bawah
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-40,-25,-40.1);
    glVertex3f(40,-25,-40.1);
    glVertex3f(40,-25,-48);
    glVertex3f(-40,-25,-48);
    glEnd();

    //octagon atas maraton
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-40,-25,-48);
    glVertex3f(40,-25,-48);
    glVertex3f(20,-25,-55);
    glVertex3f(-20,-25,-55);
    glEnd();

    //octagon bawah maraton
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-40,-25,48);
    glVertex3f(40,-25,48);
    glVertex3f(20,-25,55);
    glVertex3f(-20,-25,55);
    glEnd();

    //sisi kiri lintasan maraton
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-30,-25,40);
    glVertex3f(-30,-25,-40);
    glVertex3f(-40,-25,-40);
    glVertex3f(-40,-25,40);
    glEnd();
    //sisi kanan lintasan maraton
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(30,-25,40);
    glVertex3f(30,-25,-40);
    glVertex3f(40,-25,-40);
    glVertex3f(40,-25,40);
    glEnd();

    //pagar kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-40,-25,48);
    glVertex3f(-40,-25,-48);
    glVertex3f(-40,-15,-48);
    glVertex3f(-40,-15,48);
    glEnd();
    //pagar kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(40,-25,48);
    glVertex3f(40,-25,-48);
    glVertex3f(40,-15,-48);
    glVertex3f(40,-15,48);
    glEnd();

    //pagar BAWAH
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-20,-25,55);
    glVertex3f(20,-25,55);
    glVertex3f(20,-15,55);
    glVertex3f(-20,-15,55);
    glEnd();

    //pagar ATAS
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-20,-25,-55);
    glVertex3f(20,-25,-55);
    glVertex3f(20,-15,-55);
    glVertex3f(-20,-15,-55);
    glEnd();

    //Tribun kanan
    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(45,-25,48);
    glVertex3f(45,-25,-48);
    glVertex3f(50,5,-48);
    glVertex3f(50,5,48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(60,5,48);
    glVertex3f(60,5,-48);
    glVertex3f(65,25,-48);
    glVertex3f(65,25,48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(75,25,48);
    glVertex3f(75,25,-48);
    glVertex3f(75,60,-48);
    glVertex3f(75,60,48);
    glEnd();
    //pembatas tribun 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(74,25,2);
    glVertex3f(74,25,-2);
    glVertex3f(74,60,-2);
    glVertex3f(74,60,2);
    glEnd();
    //epmbatas tribun 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(59,5,2);
    glVertex3f(59,5,-2);
    glVertex3f(64,25,-2);
    glVertex3f(64,25,2);
    glEnd();

    //epmbatas tribun 3
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(50,5,2);
    glVertex3f(50,5,-2);
    glVertex3f(40,-25,-2);
    glVertex3f(40,-25,2);
    glEnd();


    //lurus KANAN
    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(50,5,48);
    glVertex3f(50,5,-48);
    glVertex3f(60,5,-48);
    glVertex3f(60,5,48);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(65,25,48);
    glVertex3f(65,25,-48);
    glVertex3f(75,25,-48);
    glVertex3f(75,25,48);
    glEnd();

    // kursi kanan
    //1

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-3,-30);
    glVertex3f(43,-3,-44);
    glVertex3f(48,-3,-44);
    glVertex3f(48,-3,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-3,-30);
    glVertex3f(43,-3,-44);
    glVertex3f(43,-8,-44);
    glVertex3f(43,-8,-30);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-8,-30);
    glVertex3f(43,-8,-44);
    glVertex3f(47,-8,-44);
    glVertex3f(47,-8,-30);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-3,30);
    glVertex3f(43,-3,44);
    glVertex3f(48,-3,44);
    glVertex3f(48,-3,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-3,30);
    glVertex3f(43,-3,44);
    glVertex3f(43,-8,44);
    glVertex3f(43,-8,30);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-8,30);
    glVertex3f(43,-8,44);
    glVertex3f(47,-8,44);
    glVertex3f(47,-8,30);
    glEnd();
    // 2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-3,-20);
    glVertex3f(43,-3,-7);
    glVertex3f(48,-3,-7);
    glVertex3f(48,-3,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-3,-20);
    glVertex3f(43,-3,-7);
    glVertex3f(43,-8,-7);
    glVertex3f(43,-8,-20);
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(43,-8,-20);
    glVertex3f(43,-8,-7);
    glVertex3f(47,-8,-7);
    glVertex3f(47,-8,-20);
    glEnd();

    // 4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-3,20);
    glVertex3f(43,-3,7);
    glVertex3f(48,-3,7);
    glVertex3f(48,-3,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-3,20);
    glVertex3f(43,-3,7);
    glVertex3f(43,-8,7);
    glVertex3f(43,-8,20);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(43,-8,20);
    glVertex3f(43,-8,7);
    glVertex3f(47,-8,7);
    glVertex3f(47,-8,20);
    glEnd();

    // kursi lantai 2
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,15,-30);
    glVertex3f(58,15,-44);
    glVertex3f(61,15,-44);
    glVertex3f(61,15,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,20,-30);
    glVertex3f(58,20,-44);
    glVertex3f(58,15,-44);
    glVertex3f(58,15,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,20,-30);
    glVertex3f(58,20,-44);
    glVertex3f(61,20,-44);
    glVertex3f(61,20,-30);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,15,30);
    glVertex3f(58,15,44);
    glVertex3f(61,15,44);
    glVertex3f(61,15,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,20,30);
    glVertex3f(58,20,44);
    glVertex3f(58,15,44);
    glVertex3f(58,15,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,20,30);
    glVertex3f(58,20,44);
    glVertex3f(61,20,44);
    glVertex3f(61,20,30);
    glEnd();


    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,15,-20);
    glVertex3f(58,15,-7);
    glVertex3f(61,15,-7);
    glVertex3f(61,15,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,20,-20);
    glVertex3f(58,20,-7);
    glVertex3f(58,15,-7);
    glVertex3f(58,15,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,20,-20);
    glVertex3f(58,20,-7);
    glVertex3f(61,20,-7);
    glVertex3f(61,20,-20);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,15,20);
    glVertex3f(58,15,7);
    glVertex3f(61,15,7);
    glVertex3f(61,15,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,20,20);
    glVertex3f(58,20,7);
    glVertex3f(58,15,7);
    glVertex3f(58,15,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(58,20,20);
    glVertex3f(58,20,7);
    glVertex3f(61,20,7);
    glVertex3f(61,20,20);
    glEnd();


    // kursi lantai 3
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(72,30,-30);
    glVertex3f(72,30,-44);
    glVertex3f(72,35,-44);
    glVertex3f(72,35,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,35,-30);
    glVertex3f(75,35,-44);
    glVertex3f(72,35,-44);
    glVertex3f(72,35,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,30,-30);
    glVertex3f(75,30,-44);
    glVertex3f(72,30,-44);
    glVertex3f(72,30,-30);
    glEnd();

    //5

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(72,45,-30);
    glVertex3f(72,45,-44);
    glVertex3f(72,50,-44);
    glVertex3f(72,50,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,50,-30);
    glVertex3f(75,50,-44);
    glVertex3f(72,50,-44);
    glVertex3f(72,50,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,45,-30);
    glVertex3f(75,45,-44);
    glVertex3f(72,45,-44);
    glVertex3f(72,45,-30);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(72,45,30);
    glVertex3f(72,45,44);
    glVertex3f(72,50,44);
    glVertex3f(72,50,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,50,30);
    glVertex3f(75,50,44);
    glVertex3f(72,50,44);
    glVertex3f(72,50,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,45,30);
    glVertex3f(75,45,44);
    glVertex3f(72,45,44);
    glVertex3f(72,45,30);
    glEnd();
    //3

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(72,30,30);
    glVertex3f(72,30,44);
    glVertex3f(72,35,44);
    glVertex3f(72,35,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,35,30);
    glVertex3f(75,35,44);
    glVertex3f(72,35,44);
    glVertex3f(72,35,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,30,30);
    glVertex3f(75,30,44);
    glVertex3f(72,30,44);
    glVertex3f(72,30,30);
    glEnd();

    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(72,30,-20);
    glVertex3f(72,30,-7);
    glVertex3f(72,35,-7);
    glVertex3f(72,35,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,35,-20);
    glVertex3f(75,35,-7);
    glVertex3f(72,35,-7);
    glVertex3f(72,35,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,30,-20);
    glVertex3f(75,30,-7);
    glVertex3f(72,30,-7);
    glVertex3f(72,30,-20);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(72,30,20);
    glVertex3f(72,30,7);
    glVertex3f(72,35,7);
    glVertex3f(72,35,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,35,20);
    glVertex3f(75,35,7);
    glVertex3f(72,35,7);
    glVertex3f(72,35,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,30,20);
    glVertex3f(75,30,7);
    glVertex3f(72,30,7);
    glVertex3f(72,30,20);
    glEnd();

    //7
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(72,45,-20);
    glVertex3f(72,45,-7);
    glVertex3f(72,50,-7);
    glVertex3f(72,50,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,50,-20);
    glVertex3f(75,50,-7);
    glVertex3f(72,50,-7);
    glVertex3f(72,50,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,45,-20);
    glVertex3f(75,45,-7);
    glVertex3f(72,45,-7);
    glVertex3f(72,45,-20);
    glEnd();

    //9

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(72,45,20);
    glVertex3f(72,45,7);
    glVertex3f(72,50,7);
    glVertex3f(72,50,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(75,50,20);
    glVertex3f(75,50,7);
    glVertex3f(72,50,7);
    glVertex3f(72,50,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(75,45,20);
    glVertex3f(75,45,7);
    glVertex3f(72,45,7);
    glVertex3f(72,45,20);
    glEnd();



    //Tribun kIRI
    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-45,-25,48);
    glVertex3f(-45,-25,-48);
    glVertex3f(-50,5,-48);
    glVertex3f(-50,5,48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-60,5,48);
    glVertex3f(-60,5,-48);
    glVertex3f(-65,25,-48);
    glVertex3f(-65,25,48);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-75,25,48);
    glVertex3f(-75,25,-48);
    glVertex3f(-75,60,-48);
    glVertex3f(-75,60,48);
    glEnd();
    //pembatas tribun 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-74,25,2);
    glVertex3f(-74,25,-2);
    glVertex3f(-74,60,-2);
    glVertex3f(-74,60,2);
    glEnd();
    //epmbatas tribun 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-59,5,2);
    glVertex3f(-59,5,-2);
    glVertex3f(-64,25,-2);
    glVertex3f(-64,25,2);
    glEnd();

    //epmbatas tribun 3
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-50,5,2);
    glVertex3f(-50,5,-2);
    glVertex3f(-40,-25,-2);
    glVertex3f(-40,-25,2);
    glEnd();

    //lurus KIRI atau ALAS
    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(-50,5,48);
    glVertex3f(-50,5,-48);
    glVertex3f(-60,5,-48);
    glVertex3f(-60,5,48);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(-65,25,48);
    glVertex3f(-65,25,-48);
    glVertex3f(-75,25,-48);
    glVertex3f(-75,25,48);
    glEnd();

    // kursi kiri lantai 1
    //1

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-3,-30);
    glVertex3f(-43,-3,-44);
    glVertex3f(-48,-3,-44);
    glVertex3f(-48,-3,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-3,-30);
    glVertex3f(-43,-3,-44);
    glVertex3f(-43,-8,-44);
    glVertex3f(-43,-8,-30);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-8,-30);
    glVertex3f(-43,-8,-44);
    glVertex3f(-47,-8,-44);
    glVertex3f(-47,-8,-30);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-3,30);
    glVertex3f(-43,-3,44);
    glVertex3f(-48,-3,44);
    glVertex3f(-48,-3,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-3,30);
    glVertex3f(-43,-3,44);
    glVertex3f(-43,-8,44);
    glVertex3f(-43,-8,30);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-8,30);
    glVertex3f(-43,-8,44);
    glVertex3f(-47,-8,44);
    glVertex3f(-47,-8,30);
    glEnd();
    // 2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-3,-20);
    glVertex3f(-43,-3,-7);
    glVertex3f(-48,-3,-7);
    glVertex3f(-48,-3,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-3,-20);
    glVertex3f(-43,-3,-7);
    glVertex3f(-43,-8,-7);
    glVertex3f(-43,-8,-20);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-8,-20);
    glVertex3f(-43,-8,-7);
    glVertex3f(-47,-8,-7);
    glVertex3f(-47,-8,-20);
    glEnd();

    // 4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-3,20);
    glVertex3f(-43,-3,7);
    glVertex3f(-48,-3,7);
    glVertex3f(-48,-3,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-3,20);
    glVertex3f(-43,-3,7);
    glVertex3f(-43,-8,7);
    glVertex3f(-43,-8,20);
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-43,-8,20);
    glVertex3f(-43,-8,7);
    glVertex3f(-47,-8,7);
    glVertex3f(-47,-8,20);
    glEnd();

    // kursi lantai 2
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,15,-30);
    glVertex3f(-58,15,-44);
    glVertex3f(-61,15,-44);
    glVertex3f(-61,15,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,20,-30);
    glVertex3f(-58,20,-44);
    glVertex3f(-58,15,-44);
    glVertex3f(-58,15,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,20,-30);
    glVertex3f(-58,20,-44);
    glVertex3f(-61,20,-44);
    glVertex3f(-61,20,-30);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,15,30);
    glVertex3f(-58,15,44);
    glVertex3f(-61,15,44);
    glVertex3f(-61,15,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,20,30);
    glVertex3f(-58,20,44);
    glVertex3f(-58,15,44);
    glVertex3f(-58,15,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,20,30);
    glVertex3f(-58,20,44);
    glVertex3f(-61,20,44);
    glVertex3f(-61,20,30);
    glEnd();


    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,15,-20);
    glVertex3f(-58,15,-7);
    glVertex3f(-61,15,-7);
    glVertex3f(-61,15,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,20,-20);
    glVertex3f(-58,20,-7);
    glVertex3f(-58,15,-7);
    glVertex3f(-58,15,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,20,-20);
    glVertex3f(-58,20,-7);
    glVertex3f(-61,20,-7);
    glVertex3f(-61,20,-20);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,15,20);
    glVertex3f(-58,15,7);
    glVertex3f(-61,15,7);
    glVertex3f(-61,15,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,20,20);
    glVertex3f(-58,20,7);
    glVertex3f(-58,15,7);
    glVertex3f(-58,15,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-58,20,20);
    glVertex3f(-58,20,7);
    glVertex3f(-61,20,7);
    glVertex3f(-61,20,20);
    glEnd();


    // kursi lantai 3
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-72,30,-30);
    glVertex3f(-72,30,-44);
    glVertex3f(-72,35,-44);
    glVertex3f(-72,35,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,35,-30);
    glVertex3f(-75,35,-44);
    glVertex3f(-72,35,-44);
    glVertex3f(-72,35,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,30,-30);
    glVertex3f(-75,30,-44);
    glVertex3f(-72,30,-44);
    glVertex3f(-72,30,-30);
    glEnd();

    //5

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-72,45,-30);
    glVertex3f(-72,45,-44);
    glVertex3f(-72,50,-44);
    glVertex3f(-72,50,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,50,-30);
    glVertex3f(-75,50,-44);
    glVertex3f(-72,50,-44);
    glVertex3f(-72,50,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,45,-30);
    glVertex3f(-75,45,-44);
    glVertex3f(-72,45,-44);
    glVertex3f(-72,45,-30);
    glEnd();
    //8
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-72,45,30);
    glVertex3f(-72,45,44);
    glVertex3f(-72,50,44);
    glVertex3f(-72,50,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,50,30);
    glVertex3f(-75,50,44);
    glVertex3f(-72,50,44);
    glVertex3f(-72,50,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,45,30);
    glVertex3f(-75,45,44);
    glVertex3f(-72,45,44);
    glVertex3f(-72,45,30);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-72,30,30);
    glVertex3f(-72,30,44);
    glVertex3f(-72,35,44);
    glVertex3f(-72,35,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,35,30);
    glVertex3f(-75,35,44);
    glVertex3f(-72,35,44);
    glVertex3f(-72,35,30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,30,30);
    glVertex3f(-75,30,44);
    glVertex3f(-72,30,44);
    glVertex3f(-72,30,30);
    glEnd();

    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-72,30,-20);
    glVertex3f(-72,30,-7);
    glVertex3f(-72,35,-7);
    glVertex3f(-72,35,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,35,-20);
    glVertex3f(-75,35,-7);
    glVertex3f(-72,35,-7);
    glVertex3f(-72,35,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,30,-20);
    glVertex3f(-75,30,-7);
    glVertex3f(-72,30,-7);
    glVertex3f(-72,30,-20);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-72,30,20);
    glVertex3f(-72,30,7);
    glVertex3f(-72,35,7);
    glVertex3f(-72,35,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,35,20);
    glVertex3f(-75,35,7);
    glVertex3f(-72,35,7);
    glVertex3f(-72,35,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,30,20);
    glVertex3f(-75,30,7);
    glVertex3f(-72,30,7);
    glVertex3f(-72,30,20);
    glEnd();

    //7
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-72,45,-20);
    glVertex3f(-72,45,-7);
    glVertex3f(-72,50,-7);
    glVertex3f(-72,50,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,50,-20);
    glVertex3f(-75,50,-7);
    glVertex3f(-72,50,-7);
    glVertex3f(-72,50,-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,45,-20);
    glVertex3f(-75,45,-7);
    glVertex3f(-72,45,-7);
    glVertex3f(-72,45,-20);
    glEnd();

    //9

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-72,45,20);
    glVertex3f(-72,45,7);
    glVertex3f(-72,50,7);
    glVertex3f(-72,50,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,50,20);
    glVertex3f(-75,50,7);
    glVertex3f(-72,50,7);
    glVertex3f(-72,50,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-75,45,20);
    glVertex3f(-75,45,7);
    glVertex3f(-72,45,7);
    glVertex3f(-72,45,20);
    glEnd();

    //batas tribun
    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(40,-25,48);
    glVertex3f(40,-25,-48);
    glVertex3f(45,-25,-48);
    glVertex3f(45,-25,48);
    glEnd();

    //batas tribun
    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex3f(-40,-25,48);
    glVertex3f(-40,-25,-48);
    glVertex3f(-45,-25,-48);
    glVertex3f(-45,-25,48);
    glEnd();

    //BATAS atas
    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(-20,-25,55);
    glVertex3f(20,-25,55);
    glVertex3f(20,-25,60);
    glVertex3f(-20,-25,60);
    glEnd();

    //BATAS BAWAH
    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(-20,-25,-55);
    glVertex3f(20,-25,-55);
    glVertex3f(20,-25,-60);
    glVertex3f(-20,-25,-60);
    glEnd();

    //TRIBUN DEPAN
    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-20,-25,60);
    glVertex3f(20,-25,60);
    glVertex3f(20,5,65);
    glVertex3f(-20,5,65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-20,5,75);
    glVertex3f(20,5,75);
    glVertex3f(20,25,80);
    glVertex3f(-20,25,80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-20,25,90);
    glVertex3f(20,25,90);
    glVertex3f(20,60,90);
    glVertex3f(-20,60,90);
    glEnd();

    // kursi tribun depan

    //Kursi belakang
    //lantai 1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,-10,60);
    glVertex3f(-5,-10,60);
    glVertex3f(-5,-10,55);
    glVertex3f(-15,-10,55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,-10,55);
    glVertex3f(-5,-10,55);
    glVertex3f(-5,-5,55);
    glVertex3f(-15,-5,55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,-5,60);
    glVertex3f(-5,-5,60);
    glVertex3f(-5,-5,55);
    glVertex3f(-15,-5,55);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,-10,60);
    glVertex3f(15,-10,60);
    glVertex3f(15,-10,55);
    glVertex3f(5,-10,55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,-10,55);
    glVertex3f(15,-10,55);
    glVertex3f(15,-5,55);
    glVertex3f(5,-5,55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,-5,60);
    glVertex3f(15,-5,60);
    glVertex3f(15,-5,55);
    glVertex3f(5,-5,55);
    glEnd();





    //lantai 2
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,20,75);
    glVertex3f(-5,20,75);
    glVertex3f(-5,20,70);
    glVertex3f(-15,20,70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,20,70);
    glVertex3f(-5,20,70);
    glVertex3f(-5,15,70);
    glVertex3f(-15,15,70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,15,75);
    glVertex3f(-5,15,75);
    glVertex3f(-5,15,70);
    glVertex3f(-15,15,70);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,20,75);
    glVertex3f(15,20,75);
    glVertex3f(15,20,70);
    glVertex3f(5,20,70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,20,70);
    glVertex3f(15,20,70);
    glVertex3f(15,15,70);
    glVertex3f(5,15,70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,15,75);
    glVertex3f(15,15,75);
    glVertex3f(15,15,70);
    glVertex3f(5,15,70);
    glEnd();
    //lantai 3
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,30,85);
    glVertex3f(-5,30,85);
    glVertex3f(-5,30,90);
    glVertex3f(-15,30,90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,30,85);
    glVertex3f(-5,30,85);
    glVertex3f(-5,35,85);
    glVertex3f(-15,35,85);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,35,85);
    glVertex3f(-5,35,85);
    glVertex3f(-5,35,90);
    glVertex3f(-15,35,90);
    glEnd();
    //3

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,45,85);
    glVertex3f(-5,45,85);
    glVertex3f(-5,45,90);
    glVertex3f(-15,45,90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,45,85);
    glVertex3f(-5,45,85);
    glVertex3f(-5,50,85);
    glVertex3f(-15,50,85);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,50,85);
    glVertex3f(-5,50,85);
    glVertex3f(-5,50,90);
    glVertex3f(-15,50,90);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,30,85);
    glVertex3f(15,30,85);
    glVertex3f(15,30,90);
    glVertex3f(5,30,90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,30,85);
    glVertex3f(15,30,85);
    glVertex3f(15,35,85);
    glVertex3f(5,35,85);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,35,85);
    glVertex3f(15,35,85);
    glVertex3f(15,35,90);
    glVertex3f(5,35,90);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,45,85);
    glVertex3f(15,45,85);
    glVertex3f(15,45,90);
    glVertex3f(5,45,90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,45,85);
    glVertex3f(15,45,85);
    glVertex3f(15,50,85);
    glVertex3f(5,50,85);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,50,85);
    glVertex3f(15,50,85);
    glVertex3f(15,50,90);
    glVertex3f(5,50,90);
    glEnd();

    //////////////////////

    //TRIBUN BELAKANG
    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-20,-25,-60);
    glVertex3f(20,-25,-60);
    glVertex3f(20,5,-65);
    glVertex3f(-20,5,-65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-20,5,-75);
    glVertex3f(20,5,-75);
    glVertex3f(20,25,-80);
    glVertex3f(-20,25,-80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255, 255,0);
    glVertex3f(-20,25,-90);
    glVertex3f(20,25,-90);
    glVertex3f(20,60,-90);
    glVertex3f(-20,60,-90);
    glEnd();

    //Kursi belakang
    //lantai 1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,-10,-60);
    glVertex3f(-5,-10,-60);
    glVertex3f(-5,-10,-55);
    glVertex3f(-15,-10,-55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,-10,-55);
    glVertex3f(-5,-10,-55);
    glVertex3f(-5,-5,-55);
    glVertex3f(-15,-5,-55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,-5,-60);
    glVertex3f(-5,-5,-60);
    glVertex3f(-5,-5,-55);
    glVertex3f(-15,-5,-55);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,-10,-60);
    glVertex3f(15,-10,-60);
    glVertex3f(15,-10,-55);
    glVertex3f(5,-10,-55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,-10,-55);
    glVertex3f(15,-10,-55);
    glVertex3f(15,-5,-55);
    glVertex3f(5,-5,-55);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,-5,-60);
    glVertex3f(15,-5,-60);
    glVertex3f(15,-5,-55);
    glVertex3f(5,-5,-55);
    glEnd();
    //lantai 2
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,20,-75);
    glVertex3f(-5,20,-75);
    glVertex3f(-5,20,-70);
    glVertex3f(-15,20,-70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,20,-70);
    glVertex3f(-5,20,-70);
    glVertex3f(-5,15,-70);
    glVertex3f(-15,15,-70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,15,-75);
    glVertex3f(-5,15,-75);
    glVertex3f(-5,15,-70);
    glVertex3f(-15,15,-70);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,20,-75);
    glVertex3f(15,20,-75);
    glVertex3f(15,20,-70);
    glVertex3f(5,20,-70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,20,-70);
    glVertex3f(15,20,-70);
    glVertex3f(15,15,-70);
    glVertex3f(5,15,-70);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,15,-75);
    glVertex3f(15,15,-75);
    glVertex3f(15,15,-70);
    glVertex3f(5,15,-70);
    glEnd();
    //lantai 3
    //1
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,30,-85);
    glVertex3f(-5,30,-85);
    glVertex3f(-5,30,-90);
    glVertex3f(-15,30,-90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,30,-85);
    glVertex3f(-5,30,-85);
    glVertex3f(-5,35,-85);
    glVertex3f(-15,35,-85);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,35,-85);
    glVertex3f(-5,35,-85);
    glVertex3f(-5,35,-90);
    glVertex3f(-15,35,-90);
    glEnd();
    //3

    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,45,-85);
    glVertex3f(-5,45,-85);
    glVertex3f(-5,45,-90);
    glVertex3f(-15,45,-90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,45,-85);
    glVertex3f(-5,45,-85);
    glVertex3f(-5,50,-85);
    glVertex3f(-15,50,-85);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(-15,50,-85);
    glVertex3f(-5,50,-85);
    glVertex3f(-5,50,-90);
    glVertex3f(-15,50,-90);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,30,-85);
    glVertex3f(15,30,-85);
    glVertex3f(15,30,-90);
    glVertex3f(5,30,-90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,30,-85);
    glVertex3f(15,30,-85);
    glVertex3f(15,35,-85);
    glVertex3f(5,35,-85);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,35,-85);
    glVertex3f(15,35,-85);
    glVertex3f(15,35,-90);
    glVertex3f(5,35,-90);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,45,-85);
    glVertex3f(15,45,-85);
    glVertex3f(15,45,-90);
    glVertex3f(5,45,-90);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,45,-85);
    glVertex3f(15,45,-85);
    glVertex3f(15,50,-85);
    glVertex3f(5,50,-85);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(5,50,-85);
    glVertex3f(15,50,-85);
    glVertex3f(15,50,-90);
    glVertex3f(5,50,-90);
    glEnd();

    //GARIS TRIBUN DEPAN
    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(-20,5,65);
    glVertex3f(20,5,65);
    glVertex3f(20,5,75);
    glVertex3f(-20,5,75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(-20,25,80);
    glVertex3f(20,25,80);
    glVertex3f(20,25,90);
    glVertex3f(-20,25,90);
    glEnd();

    // GARIS TRIBUN BELAKANG
    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(-20,5,-65);
    glVertex3f(20,5,-65);
    glVertex3f(20,5,-75);
    glVertex3f(-20,5,-75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
    glVertex3f(-20,25,-80);
    glVertex3f(20,25,-80);
    glVertex3f(20,25,-90);
    glVertex3f(-20,25,-90);
    glEnd();

    //DINDING TRIBUN SISI kiri
    glBegin(GL_QUADS);// ATAS
    glColor3f(255, 255,0);
    glVertex3f(-75,25,-48);
    glVertex3f(-20,25,-90);
    glVertex3f(-20,60,-90);
    glVertex3f(-75,60,-48);
    glEnd();

    glBegin(GL_QUADS);//TENGAH
    glColor3f(255, 255,0);
    glVertex3f(-65,25,-48);
    glVertex3f(-20,25,-80);
    glVertex3f(-20,5,-75);
    glVertex3f(-60,5,-48);
    glEnd();

    glBegin(GL_POLYGON);//BAWAH
    glColor3f(255, 255,0);
    glVertex3f(-20,5,-65);
    glVertex3f(-20,-25,-60);
    glVertex3f(-20,-15,-55);
    glVertex3f(-50,5,-48);
    glEnd();
    glBegin(GL_POLYGON);//BAWAH
    glColor3f(255, 255,0);
    glVertex3f(-50,5,-48);
    glVertex3f(-45,-25,-48);
    glVertex3f(-40,-15,-48);
    glVertex3f(-20,-15,-55);
    glEnd();

    //DINDING TRIBUN  belkang kanan
    glBegin(GL_QUADS);// atas
    glColor3f(255, 255,0);
    glVertex3f(75,25,-48);//sudut bawah kanan, keatas,luas kebelakang
    glVertex3f(20,25,-90);//sudut bawah kri, keatas ,kebekang
    glVertex3f(20,60,-90);// sudut kiri atas,tinggi,tinggi
    glVertex3f(75,60,-48);// sudut kanan kiri
    glEnd();
    glBegin(GL_QUADS);//TENGAH
    glColor3f(255, 255,0);
    glVertex3f(65,25,-48);
    glVertex3f(20,25,-80);
    glVertex3f(20,5,-75);
    glVertex3f(60,5,-48);
    glEnd();

    glBegin(GL_POLYGON);//BAWAH
    glColor3f(255, 255,0);
    glVertex3f(20,5,-65);
    glVertex3f(20,-25,-60);
    glVertex3f(20,-15,-55);
    glVertex3f(50,5,-48);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(255, 255,0);
    glVertex3f(50,5,-48);
    glVertex3f(45,-25,-48);
    glVertex3f(40,-15,-48);
    glVertex3f(20,-15,-55);
    glEnd();

    // kursi belakang
    //kiri
    //lantai tengah
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(40,13,-59);
    glVertex3f(50,13,-52);
    glVertex3f(50,18,-52);
    glVertex3f(40,18,-59);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(40,13,-59);
    glVertex3f(50,13,-52);
    glVertex3f(53,13,-52);
    glVertex3f(43,13,-59);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(50,18,-52);
    glVertex3f(40,18,-59);
    glVertex3f(43,18,-59);
    glVertex3f(53,18,-52);
    glEnd();



    //kANAN
    //lantai tengah
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-40,13,-59);
    glVertex3f(-50,13,-52);
    glVertex3f(-50,18,-52);
    glVertex3f(-40,18,-59);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-40,13,-59);
    glVertex3f(-50,13,-52);
    glVertex3f(-53,13,-52);
    glVertex3f(-43,13,-59);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-50,18,-52);
    glVertex3f(-40,18,-59);
    glVertex3f(-43,18,-59);
    glVertex3f(-53,18,-52);
    glEnd();

    //lantai tengah
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(40,13,59);
    glVertex3f(50,13,52);
    glVertex3f(50,18,52);
    glVertex3f(40,18,59);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(40,13,59);
    glVertex3f(50,13,52);
    glVertex3f(53,13,52);
    glVertex3f(43,13,59);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(50,18,52);
    glVertex3f(40,18,59);
    glVertex3f(43,18,59);
    glVertex3f(53,18,52);
    glEnd();

    //lantai tengah
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-40,13,59);
    glVertex3f(-50,13,52);
    glVertex3f(-50,18,52);
    glVertex3f(-40,18,59);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-40,13,59);
    glVertex3f(-50,13,52);
    glVertex3f(-53,13,52);
    glVertex3f(-43,13,59);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-50,18,52);
    glVertex3f(-40,18,59);
    glVertex3f(-43,18,59);
    glVertex3f(-53,18,52);
    glEnd();


    // 2
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(20,13,-74);
    glVertex3f(30,13,-67);
    glVertex3f(30,18,-67);
    glVertex3f(20,18,-74);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(20,13,-74);
    glVertex3f(30,13,-67);
    glVertex3f(33,13,-67);
    glVertex3f(23,13,-74);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(30,18,-67);
    glVertex3f(20,18,-74);
    glVertex3f(23,18,-74);
    glVertex3f(33,18,-67);
    glEnd();

    // 2
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-20,13,-74);
    glVertex3f(-30,13,-67);
    glVertex3f(-30,18,-67);
    glVertex3f(-20,18,-74);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-20,13,-74);
    glVertex3f(-30,13,-67);
    glVertex3f(-33,13,-67);
    glVertex3f(-23,13,-74);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-30,18,-67);
    glVertex3f(-20,18,-74);
    glVertex3f(-23,18,-74);
    glVertex3f(-33,18,-67);
    glEnd();

    // 2
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(20,13,74);
    glVertex3f(30,13,67);
    glVertex3f(30,18,67);
    glVertex3f(20,18,74);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(20,13,74);
    glVertex3f(30,13,67);
    glVertex3f(33,13,67);
    glVertex3f(23,13,74);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(30,18,67);
    glVertex3f(20,18,74);
    glVertex3f(23,18,74);
    glVertex3f(33,18,67);
    glEnd();

    // 2
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-20,13,74);
    glVertex3f(-30,13,67);
    glVertex3f(-30,18,67);
    glVertex3f(-20,18,74);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-20,13,74);
    glVertex3f(-30,13,67);
    glVertex3f(-33,13,67);
    glVertex3f(-23,13,74);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-30,18,67);
    glVertex3f(-20,18,74);
    glVertex3f(-23,18,74);
    glVertex3f(-33,18,67);
    glEnd();

    //2
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(65,30,-52);
    glVertex3f(55,30,-60);
    glVertex3f(55,35,-60);
    glVertex3f(65,35,-52);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(65,30,-52);
    glVertex3f(55,30,-60);
    glVertex3f(59,30,-60);
    glVertex3f(69,30,-52);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(65,35,-52);
    glVertex3f(55,35,-60);
    glVertex3f(59,35,-60);
    glVertex3f(69,35,-52);
    glEnd();

    //2
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-65,30,-52);
    glVertex3f(-55,30,-60);
    glVertex3f(-55,35,-60);
    glVertex3f(-65,35,-52);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-65,30,-52);
    glVertex3f(-55,30,-60);
    glVertex3f(-59,30,-60);
    glVertex3f(-69,30,-52);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-65,35,-52);
    glVertex3f(-55,35,-60);
    glVertex3f(-59,35,-60);
    glVertex3f(-69,35,-52);
    glEnd();

    //2
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(65,30,52);
    glVertex3f(55,30,60);
    glVertex3f(55,35,60);
    glVertex3f(65,35,52);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(65,30,52);
    glVertex3f(55,30,60);
    glVertex3f(59,30,60);
    glVertex3f(69,30,52);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(65,35,52);
    glVertex3f(55,35,60);
    glVertex3f(59,35,60);
    glVertex3f(69,35,52);
    glEnd();

    //2
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-65,30,52);
    glVertex3f(-55,30,60);
    glVertex3f(-55,35,60);
    glVertex3f(-65,35,52);
    glEnd();
    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-65,30,52);
    glVertex3f(-55,30,60);
    glVertex3f(-59,30,60);
    glVertex3f(-69,30,52);
    glEnd();

    glBegin(GL_POLYGON);//alas
    glColor3ub(255,0,0);
    glVertex3f(-65,35,52);
    glVertex3f(-55,35,60);
    glVertex3f(-59,35,60);
    glVertex3f(-69,35,52);
    glEnd();


    //3
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(65,45,-52);
    glVertex3f(55,45,-60);
    glVertex3f(55,50,-60);
    glVertex3f(65,50,-52);
    glEnd();
    glBegin(GL_POLYGON);// alas
    glColor3ub(255,0,0);
    glVertex3f(65,45,-52);
    glVertex3f(55,45,-60);
    glVertex3f(60,45,-60);
    glVertex3f(69,45,-52);
    glEnd();
    glBegin(GL_POLYGON);// alas
    glColor3ub(255,0,0);
    glVertex3f(55,50,-60);
    glVertex3f(65,50,-52);
    glVertex3f(69,50,-52);
    glVertex3f(60,50,-60);
    glEnd();

    //3
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-65,45,-52);
    glVertex3f(-55,45,-60);
    glVertex3f(-55,50,-60);
    glVertex3f(-65,50,-52);
    glEnd();
    glBegin(GL_POLYGON);// alas
    glColor3ub(255,0,0);
    glVertex3f(-65,45,-52);
    glVertex3f(-55,45,-60);
    glVertex3f(-60,45,-60);
    glVertex3f(-69,45,-52);
    glEnd();
    glBegin(GL_POLYGON);// alas
    glColor3ub(255,0,0);
    glVertex3f(-55,50,-60);
    glVertex3f(-65,50,-52);
    glVertex3f(-69,50,-52);
    glVertex3f(-60,50,-60);
    glEnd();

    //3
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(65,45,52);
    glVertex3f(55,45,60);
    glVertex3f(55,50,60);
    glVertex3f(65,50,52);
    glEnd();
    glBegin(GL_POLYGON);// alas
    glColor3ub(255,0,0);
    glVertex3f(65,45,52);
    glVertex3f(55,45,60);
    glVertex3f(60,45,60);
    glVertex3f(69,45,52);
    glEnd();
    glBegin(GL_POLYGON);// alas
    glColor3ub(255,0,0);
    glVertex3f(55,50,60);
    glVertex3f(65,50,52);
    glVertex3f(69,50,52);
    glVertex3f(60,50,60);
    glEnd();

    //3
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-65,45,52);
    glVertex3f(-55,45,60);
    glVertex3f(-55,50,60);
    glVertex3f(-65,50,52);
    glEnd();
    glBegin(GL_POLYGON);// alas
    glColor3ub(255,0,0);
    glVertex3f(-65,45,52);
    glVertex3f(-55,45,60);
    glVertex3f(-60,45,60);
    glVertex3f(-69,45,52);
    glEnd();
    glBegin(GL_POLYGON);// alas
    glColor3ub(255,0,0);
    glVertex3f(-55,50,60);
    glVertex3f(-65,50,52);
    glVertex3f(-69,50,52);
    glVertex3f(-60,50,60);
    glEnd();



    //4
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(40,30,-72);
    glVertex3f(27,30,-82);
    glVertex3f(27,35,-82);
    glVertex3f(40,35,-72);
    glEnd();

    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(27,35,-82);
    glVertex3f(40,35,-72);
    glVertex3f(45,35,-72);
    glVertex3f(31,35,-82);

    glEnd();

    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(40,30,-72);
    glVertex3f(27,30,-82);
    glVertex3f(32,30,-82);
    glVertex3f(45,30,-72);
    glEnd();

    //4
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-40,30,-72);
    glVertex3f(-27,30,-82);
    glVertex3f(-27,35,-82);
    glVertex3f(-40,35,-72);
    glEnd();

    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-27,35,-82);
    glVertex3f(-40,35,-72);
    glVertex3f(-45,35,-72);
    glVertex3f(-31,35,-82);

    glEnd();

    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-40,30,-72);
    glVertex3f(-27,30,-82);
    glVertex3f(-32,30,-82);
    glVertex3f(-45,30,-72);
    glEnd();

    //4
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(40,30,72);
    glVertex3f(27,30,82);
    glVertex3f(27,35,82);
    glVertex3f(40,35,72);
    glEnd();

    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(27,35,82);
    glVertex3f(40,35,72);
    glVertex3f(45,35,72);
    glVertex3f(31,35,82);

    glEnd();

    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(40,30,72);
    glVertex3f(27,30,82);
    glVertex3f(32,30,82);
    glVertex3f(45,30,72);
    glEnd();

    //4
    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-40,30,72);
    glVertex3f(-27,30,82);
    glVertex3f(-27,35,82);
    glVertex3f(-40,35,72);
    glEnd();

    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-27,35,82);
    glVertex3f(-40,35,72);
    glVertex3f(-45,35,72);
    glVertex3f(-31,35,82);

    glEnd();

    glBegin(GL_POLYGON);// atas
    glColor3ub(255,0,0);
    glVertex3f(-40,30,72);
    glVertex3f(-27,30,82);
    glVertex3f(-32,30,82);
    glVertex3f(-45,30,72);
    glEnd();


    //1
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(40,45,-72);
    glVertex3f(27,45,-82);
    glVertex3f(27,50,-82);
    glVertex3f(40,50,-72);
    glEnd();
    glBegin(GL_POLYGON);//alas duduk
    glColor3ub(255,0,0);
    glVertex3f(40,45,-72);
    glVertex3f(27,45,-82);
    glVertex3f(30,45,-82);
    glVertex3f(43,45,-72);
    glEnd();

    glBegin(GL_POLYGON);//alas duduk
    glColor3ub(255,0,0);
    glVertex3f(40,50,-72);
    glVertex3f(27,50,-82);
    glVertex3f(30,50,-82);
    glVertex3f(43,50,-72);
    glEnd();

    //1
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-40,45,-72);
    glVertex3f(-27,45,-82);
    glVertex3f(-27,50,-82);
    glVertex3f(-40,50,-72);
    glEnd();
    glBegin(GL_POLYGON);//alas duduk
    glColor3ub(255,0,0);
    glVertex3f(-40,45,-72);
    glVertex3f(-27,45,-82);
    glVertex3f(-30,45,-82);
    glVertex3f(-43,45,-72);
    glEnd();

    glBegin(GL_POLYGON);//alas duduk
    glColor3ub(255,0,0);
    glVertex3f(-40,50,-72);
    glVertex3f(-27,50,-82);
    glVertex3f(-30,50,-82);
    glVertex3f(-43,50,-72);
    glEnd();

    //1
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(40,45,72);
    glVertex3f(27,45,82);
    glVertex3f(27,50,82);
    glVertex3f(40,50,72);
    glEnd();
    glBegin(GL_POLYGON);//alas duduk
    glColor3ub(255,0,0);
    glVertex3f(40,45,72);
    glVertex3f(27,45,82);
    glVertex3f(30,45,82);
    glVertex3f(43,45,72);
    glEnd();

    glBegin(GL_POLYGON);//alas duduk
    glColor3ub(255,0,0);
    glVertex3f(40,50,72);
    glVertex3f(27,50,82);
    glVertex3f(30,50,82);
    glVertex3f(43,50,72);
    glEnd();


    //1
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-40,45,72);
    glVertex3f(-27,45,82);
    glVertex3f(-27,50,82);
    glVertex3f(-40,50,72);
    glEnd();
    glBegin(GL_POLYGON);//alas duduk
    glColor3ub(255,0,0);
    glVertex3f(-40,45,72);
    glVertex3f(-27,45,82);
    glVertex3f(-30,45,82);
    glVertex3f(-43,45,72);
    glEnd();

    glBegin(GL_POLYGON);//alas duduk
    glColor3ub(255,0,0);
    glVertex3f(-40,50,72);
    glVertex3f(-27,50,82);
    glVertex3f(-30,50,82);
    glVertex3f(-43,50,72);
    glEnd();


    //BATAS DINDING SISI
    glBegin(GL_QUADS);//ATAS
    glColor3ub(169,169,169);
    glVertex3f(-75,25,-48);
    glVertex3f(-20,25,-90);
    glVertex3f(-20,25,-80);
    glVertex3f(-65,25,-48);
    glEnd();

    glBegin(GL_QUADS);//TENGAH
    glColor3ub(169,169,169);
    glVertex3f(-60,5,-48);
    glVertex3f(-20,5,-75);
    glVertex3f(-20,5,-65);
    glVertex3f(-50,5,-48);
    glEnd();

    //BATAS DINDING SISI
    glBegin(GL_QUADS);//ATAS
    glColor3ub(169,169,169);
    glVertex3f(75,25,-48);
    glVertex3f(20,25,-90);
    glVertex3f(20,25,-80);
    glVertex3f(65,25,-48);
    glEnd();

    glBegin(GL_QUADS);//TENGAH
    glColor3ub(169,169,169);
    glVertex3f(60,5,-48);
    glVertex3f(20,5,-75);
    glVertex3f(20,5,-65);
    glVertex3f(50,5,-48);
    glEnd();

    glBegin(GL_QUADS);//SEGITIGA KANAN
    glColor3f(0.6,0.5,1.0);
    glVertex3f(40,-15,48);
    glVertex3f(40,-15,-48);
    glVertex3f(45,-25,-48);
    glVertex3f(45,-25,48);
    glEnd();
    glBegin(GL_QUADS);//SEGITIGA
    glColor3f(0.6,0.5,1.0);
    glVertex3f(-40,-15,48);
    glVertex3f(-40,-15,-48);
    glVertex3f(-45,-25,-48);
    glVertex3f(-45,-25,48);
    glEnd();
    glBegin(GL_QUADS);//SEGITIGA
    glColor3f(0.6,0.5,1.0);
    glVertex3f(-20,-25,-60);
    glVertex3f(20,-25,-60);
    glVertex3f(20,-15,-55);
    glVertex3f(-20,-15,-55);
    glEnd();
    glBegin(GL_QUADS);//SEGITIGA
    glColor3f(0.6,0.5,1.0);
    glVertex3f(-20,-25,60);
    glVertex3f(20,-25,60);
    glVertex3f(20,-15,55);
    glVertex3f(-20,-15,55);
    glEnd();
    //
    //DINDING TRIBUN SISI DEPAN
    glBegin(GL_QUADS);// ATAS
    glColor3f(255, 255,0);
    glVertex3f(-75,25,48);
    glVertex3f(-20,25,90);
    glVertex3f(-20,60,90);
    glVertex3f(-75,60,48);
    glEnd();

    glBegin(GL_QUADS);//TENGAH
    glColor3f(255, 255,0);
    glVertex3f(-65,25,48);
    glVertex3f(-20,25,80);
    glVertex3f(-20,5,75);
    glVertex3f(-60,5,48);
    glEnd();

    glBegin(GL_POLYGON);//BAWAH
    glColor3f(255, 255,0);
    glVertex3f(-20,5,65);
    glVertex3f(-20,-25,60);
    glVertex3f(-20,-15,55);
    glVertex3f(-50,5,48);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(255, 255,0);
    glVertex3f(-50,5,48);
    glVertex3f(-45,-25,48);
    glVertex3f(-40,-15,48);
    glVertex3f(-20,-15,55);
    glEnd();

    ////
    //DINDING TRIBUN SISI
    glBegin(GL_QUADS);// ATAS
    glColor3f(255, 255,0);
    glVertex3f(75,25,48);
    glVertex3f(20,25,90);
    glVertex3f(20,60,90);
    glVertex3f(75,60,48);
    glEnd();

    glBegin(GL_QUADS);//TENGAH
    glColor3f(255, 255,0);
    glVertex3f(65,25,48);
    glVertex3f(20,25,80);
    glVertex3f(20,5,75);
    glVertex3f(60,5,48);
    glEnd();

    glBegin(GL_POLYGON);//BAWAH
    glColor3f(255, 255,0);
    glVertex3f(20,5,65);
    glVertex3f(20,-25,60);
    glVertex3f(20,-15,55);
    glVertex3f(50,5,48);
    glEnd();
    glBegin(GL_POLYGON);//BAWAH
    glColor3f(255, 255,0);
    glVertex3f(50,5,48);
    glVertex3f(45,-25,48);
    glVertex3f(40,-15,48);
    glVertex3f(20,-15,55);
    glEnd();

    ///
    //BATAS DINDING SISI
    glBegin(GL_QUADS);//ATAS
    glColor3ub(169,169,169);
    glVertex3f(-75,25,48);
    glVertex3f(-20,25,90);
    glVertex3f(-20,25,80);
    glVertex3f(-65,25,48);
    glEnd();

    glBegin(GL_QUADS);//TENGAH
    glColor3ub(169,169,169);
    glVertex3f(-60,5,48);
    glVertex3f(-20,5,75);
    glVertex3f(-20,5,65);
    glVertex3f(-50,5,48);
    glEnd();
    //
    //BATAS DINDING SISI
    glBegin(GL_QUADS);//ATAS
    glColor3ub(169,169,169);
    glVertex3f(75,25,48);
    glVertex3f(20,25,90);
    glVertex3f(20,25,80);
    glVertex3f(65,25,48);
    glEnd();

    glBegin(GL_QUADS);//TENGAH
    glColor3ub(169,169,169);
    glVertex3f(60,5,48);
    glVertex3f(20,5,75);
    glVertex3f(20,5,65);
    glVertex3f(50,5,48);
    glEnd();

    //TAMAN
    glBegin(GL_POLYGON);// KANAN
    glColor3ub(210,180,140);
    glVertex3f(77,-26,-50);
    glVertex3f(77,-26,50);
    glVertex3f(90,-26,92);
    glVertex3f(90,-26,-50);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(77,-26,-50);
    glVertex3f(20,-26,-92);
    glVertex3f(20,-26,-105);
    glVertex3f(90,-26,-105);
    glVertex3f(90,-26,-50);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(77,-26,50);
    glVertex3f(20,-26,92);
    glVertex3f(20,-26,105);
    glVertex3f(90,-26,105);
    glVertex3f(90,-26,50);
    glEnd();

    glBegin(GL_POLYGON);// KIRI
    glColor3ub(210,180,140);
    glVertex3f(-77,-26,-50);
    glVertex3f(-77,-26,50);
    glVertex3f(-90,-26,92);
    glVertex3f(-90,-26,-50);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-77,-26,-50);
    glVertex3f(-20,-26,-92);
    glVertex3f(-20,-26,-105);
    glVertex3f(-90,-26,-105);
    glVertex3f(-90,-26,-50);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-77,-26,50);
    glVertex3f(-20,-26,92);
    glVertex3f(-20,-26,105);
    glVertex3f(-90,-26,105);
    glVertex3f(-90,-26,50);
    glEnd();

    // TAMAN DEPAN BELAKANG
    glBegin(GL_POLYGON);
    glColor3ub(210,180,140);
    glVertex3f(20,-26,-92);
    glVertex3f(20,-26,-105);
    glVertex3f(-20,-26,-105);
    glVertex3f(-20,-26,-92);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(210,180,140);
    glVertex3f(20,-26,92);
    glVertex3f(20,-26,105);
    glVertex3f(-20,-26,105);
    glVertex3f(-20,-26,92);
    glEnd();

// JALAN RAYA
    glBegin(GL_POLYGON);// KANAN
    glColor3ub(119,136,153);
    glVertex3f(110,-26,-155);
    glVertex3f(110,-26,155);
    glVertex3f(130,-26,155);
    glVertex3f(130,-26,-155);
    glEnd();

    glBegin(GL_POLYGON);// KIRI
    glColor3ub(119,136,153);
    glVertex3f(-110,-26,-155);
    glVertex3f(-110,-26,155);
    glVertex3f(-130,-26,155);
    glVertex3f(-130,-26,-155);
    glEnd();

    glBegin(GL_POLYGON);//
    glColor3ub(119,136,153);
    glVertex3f(130,-26,-130);
    glVertex3f(130,-26,-155);
    glVertex3f(-130,-26,-155);
    glVertex3f(-130,-26,-130);
    glEnd();

    glBegin(GL_POLYGON);//
    glColor3ub(119,136,153);
    glVertex3f(130,-26,130);
    glVertex3f(130,-26,155);
    glVertex3f(-130,-26,155);
    glVertex3f(-130,-26,130);
    glEnd();

//JALAN 3D

    glBegin(GL_QUADS);// KANAN
    glColor3ub(222,184,135);
    glVertex3f(0,-35,-40);
    glVertex3f(0,-35,40);
    glVertex3f(130,-35,40);
    glVertex3f(130,-35,-40);
    glEnd();

    glBegin(GL_QUADS);// KIRI
    glColor3ub(222,184,135);
    glVertex3f(0,-35,-40);
    glVertex3f(0,-35,40);
    glVertex3f(-130,-35,40);
    glVertex3f(-130,-35,-40);
    glEnd();

    glBegin(GL_QUADS);//
    glColor3ub(222,184,135);
    glVertex3f(130,-35,-40);
    glVertex3f(130,-35,-155);
    glVertex3f(-130,-35,-155);
    glVertex3f(-130,-35,-40);
    glEnd();
    glBegin(GL_QUADS);//
    glColor3ub(222,184,135);
    glVertex3f(130,-35,40);
    glVertex3f(130,-35,155);
    glVertex3f(-130,-35,155);
    glVertex3f(-130,-35,40);
    glEnd();



//penghubung JALAN 3D
    glBegin(GL_POLYGON);//KIRI
    glColor3f(0.4,0.6,0.9);
    glVertex3f(-130,-26,155);
    glVertex3f(-130,-26,-155);
    glVertex3f(-130,-35,-155);
    glVertex3f(-130,-35,155);
    glEnd();

    glBegin(GL_POLYGON);//KANAN
    glColor3f(0.4,0.6,0.9);
    glVertex3f(130,-26,155);
    glVertex3f(130,-26,-155);
    glVertex3f(130,-35,-155);
    glVertex3f(130,-35,155);
    glEnd();

    glBegin(GL_POLYGON);//KIRI
    glColor3f(0.4,0.6,0.9);
    glVertex3f(-130,-26,155);
    glVertex3f(130,-26,155);
    glVertex3f(130,-35,155);
    glVertex3f(-130,-35,155);
    glEnd();

    glBegin(GL_POLYGON);//KIRI
    glColor3f(0.4,0.6,0.9);
    glVertex3f(-130,-26,-155);
    glVertex3f(130,-26,-155);
    glVertex3f(130,-35,-155);
    glVertex3f(-130,-35,-155);
    glEnd();

/////////////////////////////

    glBegin(GL_POLYGON);// GARIS JALAN
    glColor3f(1,1,1);
    glVertex3f(118,-24,-100);
    glVertex3f(118,-24,-70);
    glVertex3f(122,-24,-70);
    glVertex3f(122,-24,-100);
    glEnd();

    glBegin(GL_POLYGON);// KANAN
    glVertex3f(118,-24,-50);
    glVertex3f(118,-24,-20);
    glVertex3f(122,-24,-20);
    glVertex3f(122,-24,-50);
    glEnd();
    glBegin(GL_POLYGON);// KANAN
    glVertex3f(118,-24,0);
    glVertex3f(118,-24,30);
    glVertex3f(122,-24,30);
    glVertex3f(122,-24,0);
    glEnd();

    glBegin(GL_POLYGON);// KANAN
    glVertex3f(118,-24,50);
    glVertex3f(118,-24,90);
    glVertex3f(122,-24,90);
    glVertex3f(122,-24,50);
    glEnd();

    glBegin(GL_POLYGON);// GARIS JALAN KIRI
    glColor3f(1,1,1);
    glVertex3f(-118,-24,-100);
    glVertex3f(-118,-24,-70);
    glVertex3f(-122,-24,-70);
    glVertex3f(-122,-24,-100);
    glEnd();

    glBegin(GL_POLYGON);// KANAN
    glVertex3f(-118,-24,-50);
    glVertex3f(-118,-24,-20);
    glVertex3f(-122,-24,-20);
    glVertex3f(-122,-24,-50);
    glEnd();
    glBegin(GL_POLYGON);// KANAN
    glVertex3f(-118,-24,0);
    glVertex3f(-118,-24,30);
    glVertex3f(-122,-24,30);
    glVertex3f(-122,-24,0);
    glEnd();

    glBegin(GL_POLYGON);// KANAN
    glVertex3f(-118,-24,50);
    glVertex3f(-118,-24,90);
    glVertex3f(-122,-24,90);
    glVertex3f(-122,-24,50);
    glEnd();

    glBegin(GL_POLYGON);//
    glColor3f(1,1,1);
    glVertex3f(80,-24,-140);
    glVertex3f(80,-24,-145);
    glVertex3f(45,-24,-145);
    glVertex3f(45,-24,-140);
    glEnd();

    glBegin(GL_POLYGON);//
    glColor3f(1,1,1);
    glVertex3f(25,-24,-140);
    glVertex3f(25,-24,-145);
    glVertex3f(-25,-24,-145);
    glVertex3f(-25,-24,-140);
    glEnd();

    glBegin(GL_POLYGON);//
    glColor3f(1,1,1);
    glVertex3f(-45,-24,-140);
    glVertex3f(-45,-24,-145);
    glVertex3f(-80,-24,-145);
    glVertex3f(-80,-24,-140);
    glEnd();

    glBegin(GL_POLYGON);//
    glColor3f(1,1,1);
    glVertex3f(80,-24,140);
    glVertex3f(80,-24,145);
    glVertex3f(45,-24,145);
    glVertex3f(45,-24,140);
    glEnd();

    glBegin(GL_POLYGON);//
    glColor3f(1,1,1);
    glVertex3f(25,-24,140);
    glVertex3f(25,-24,145);
    glVertex3f(-25,-24,145);
    glVertex3f(-25,-24,140);
    glEnd();

    glBegin(GL_POLYGON);//
    glColor3f(1,1,1);
    glVertex3f(-45,-24,140);
    glVertex3f(-45,-24,145);
    glVertex3f(-80,-24,145);
    glVertex3f(-80,-24,140);
    glEnd();

//ATAP DALAM LIGHTING
    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex3f(50,65,-50);
    glVertex3f(50,65,50);
    glVertex3f(30,55,50);
    glVertex3f(30,55,-50);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex3f(-50,65,-50);
    glVertex3f(-50,65,50);
    glVertex3f(-30,55,50);
    glVertex3f(-30,55,-50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex3f(20,65,70);
    glVertex3f(-20,65,70);
    glVertex3f(-20,65,50);
    glVertex3f(20,65,50);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex3f(20,65,-70);
    glVertex3f(-20,65,-70);
    glVertex3f(-20,65,-50);
    glVertex3f(20,65,-50);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex3f(-20,65,70);
    glVertex3f(-50,65,50);
    glVertex3f(-30,55,50);
    glVertex3f(-20,65,50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(169,169,169);
    glVertex3f(-20,65,-70);
    glVertex3f(-50,65,-50);
    glVertex3f(-30,55,-50);
    glVertex3f(-20,65,-50);
    glEnd();

    glBegin(GL_POLYGON);//PUNYA
    glColor3ub(169,169,169);
    glVertex3f(20,65,70);
    glVertex3f(50,65,50);
    glVertex3f(30,55,50);
    glVertex3f(20,65,50);
    glEnd();
    glBegin(GL_POLYGON);//PUNYA
    glColor3ub(169,169,169);
    glVertex3f(20,65,-70);
    glVertex3f(50,65,-50);
    glVertex3f(30,55,-50);
    glVertex3f(20,65,-50);
    glEnd();

    /*// BINGKAI LAMPU
        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex3f(-30,55,-50);
        glVertex3f(-30,55,-40);
        glVertex3f(-30,45,-40);
        glVertex3f(-30,45,-50);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex3f(-30,55,50);
        glVertex3f(-30,55,40);
        glVertex3f(-30,45,40);
        glVertex3f(-30,45,50);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex3f(30,55,-50);
        glVertex3f(30,55,-40);
        glVertex3f(30,45,-40);
        glVertex3f(30,45,-50);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex3f(30,55,50);
        glVertex3f(30,55,40);
        glVertex3f(30,45,40);
        glVertex3f(30,45,50);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex3f(20,65,70);
        glVertex3f(50,65,50);
        glVertex3f(30,55,50);
        glVertex3f(20,65,50);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex3f(20,65,-70);
        glVertex3f(50,65,-50);
        glVertex3f(30,55,-50);
        glVertex3f(20,65,-50);
        glEnd();

    // LAMPU DALAM
        glBegin(GL_POLYGON);
        glColor3ub(100,100,100);
        glVertex3f(-29,53,-48);
        glVertex3f(-29,53,-42);
        glVertex3f(-29,48,-42);
        glVertex3f(-29,48,-48);
        glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(100,100,100);
        glVertex3f(-29,53,48);
        glVertex3f(-29,53,42);
        glVertex3f(-29,48,42);
        glVertex3f(-29,48,48);
        glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(100,100,100);
        glVertex3f(29,53,-48);
        glVertex3f(29,53,-42);
        glVertex3f(29,48,-42);
        glVertex3f(29,48,-48);
        glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(100,100,100);
        glVertex3f(29,53,48);
        glVertex3f(29,53,42);
        glVertex3f(29,48,42);
        glVertex3f(29,48,48);
        glEnd();*/

//TAMAN2

    glBegin(GL_POLYGON);// KANAN
    glColor3ub(210,180,140);
    glVertex3f(90,-26,-105);
    glVertex3f(90,-26,105);
    glVertex3f(110,-26,105);
    glVertex3f(110,-26,-105);
    glEnd();

    glBegin(GL_POLYGON);// KIRI
    glColor3ub(210,180,140);
    glVertex3f(-90,-26,-105);
    glVertex3f(-90,-26,105);
    glVertex3f(-110,-26,105);
    glVertex3f(-110,-26,-105);
    glEnd();



    glBegin(GL_POLYGON);// BELAKANG
    glColor3ub(210,180,140);
    glVertex3f(110,-26,-105);
    glVertex3f(110,-26,-130);
    glVertex3f(-110,-26,-130);
    glVertex3f(-110,-26,-105);
    glEnd();

    glBegin(GL_POLYGON);// DEPAN
    glColor3ub(210,180,140);
    glVertex3f(110,-26,105);
    glVertex3f(110,-26,130);
    glVertex3f(-110,-26,130);
    glVertex3f(-110,-26,105);
    glEnd();
///////////////////////////////////////////////////////////////
//POHON

    glBegin(GL_POLYGON);// BATANG
    glColor3ub(139,69,19);
    glVertex3f(90,-26,105);
    glVertex3f(95,-26,105);
    glVertex3f(95,-5,105);
    glVertex3f(90,-5,105);
    glEnd();

    glBegin(GL_POLYGON);// BATANG
    glColor3ub(139,69,19);
    glVertex3f(-90,-26,105);
    glVertex3f(-95,-26,105);
    glVertex3f(-95,-5,105);
    glVertex3f(-90,-5,105);
    glEnd();


    glBegin(GL_POLYGON);// DAUN 1
    glColor3ub(0,255,0);
    glVertex3f(110,-5,105);
    glVertex3f(75,-5,105);
    glVertex3f(92.5,15,105);
    glEnd();
    glBegin(GL_POLYGON);// DAUN 1
    glColor3ub(0,255,0);
    glVertex3f(-110,-5,105);
    glVertex3f(-75,-5,105);
    glVertex3f(-92.5,15,105);
    glEnd();


    glBegin(GL_POLYGON);// DAUN 2
    glColor3ub(0,255,0);
    glVertex3f(105,11,105);
    glVertex3f(80,11,105);
    glVertex3f(92.5,30,105);
    glEnd();
    glBegin(GL_POLYGON);// DAUN 2
    glColor3ub(0,255,0);
    glVertex3f(-105,11,105);
    glVertex3f(-80,11,105);
    glVertex3f(-92.5,30,105);
    glEnd();


    glBegin(GL_POLYGON);// DAUN 3
    glColor3ub(0,255,0);
    glVertex3f(100,27,105);
    glVertex3f(85,27,105);
    glVertex3f(92.5,40,105);
    glEnd();
    glBegin(GL_POLYGON);// DAUN 3
    glColor3ub(0,255,0);
    glVertex3f(-100,27,105);
    glVertex3f(-85,27,105);
    glVertex3f(-92.5,40,105);
    glEnd();

//////////////////////////////////////////////////////////////



    glPushMatrix();
    glPopMatrix();

    glutSwapBuffers();

}
void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse (int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y)
{
    if(mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + xdiff;
        glLoadIdentity();
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0)
        tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(150.0, lebar / tinggi, 15.0, 500.0);
    glTranslatef(0.0,-5.0, -200.0);
    glMatrixMode(GL_MODELVIEW);
}
