#include "B_Spline.h"

double b_spline::Cox_de_boor(int i, int p, double u)
{
    
    if (p == 0) {
        if (u >= u_points[i] && u < u_points[i+1]) return 1;
        else return 0;
    }
    else {
        //double b = N_points[p - 1][i]; double c = N_points[p - 1][i + 1];
        u = (u >= u_points[i] && u < u_points[i + 1])?1:0;
        double A = (N_points[p - 1][i]==0)?0:((u - u_points[i]) / (u_points[i + p] - u_points[i]))* N_points[p-1][i];
        double B = (N_points[p - 1][i+1] == 0) ? 0 : ((u_points[i + p + 1] - u) / (u_points[i + p + 1] - u_points[i + 1])) * N_points[p -1][i + 1];
        /*double A = ((u - u_points[i]) / (u_points[i + p] - u_points[i]))* N_points[p-1][i];
        double B = ((u_points[i + p + 1] - u) / (u_points[i + p + 1] - u_points[i + 1])) * N_points[p -1][i + 1];*/
        return A + B;
        //return (((u - u_points[i]) / (u_points[i + p] - u_points[i])) * N_points[i][p - 1])+ (((u_points[i+p+1]-u) / (u_points[i + p+1] - u_points[i+1])) * N_points[i+1][p - 1]);
    }
    
}

double b_spline::C_function(double u,int value)
{
    double C = 0;
    for (int i = 0; i < NP_h ; i++) {
        double Debug = N_points[i][NP_h];
        C += N_points[i][NP_h] * Points[i][value];
    }
    return C;
}

void b_spline::init_N_points(int x, int y)
{
    N_points = new double*[x];
    for (int i = 0; i < y; i++) {
        N_points[i] = new double[x - i];
    }
}

void b_spline::Calculate_N_points(double u)
{
    for (int i = 0; i < NP_h; i++) {
        for (int j = 0; j < Nodes-i-1; j++) {
            N_points[i][j] = Cox_de_boor(j, i, u);
        }
    }
}
void b_spline::DebugMatrix() {
    double Debug[10][10];
    for (int i = 0; i < NP_h; i++) {
        for (int j = 0; j < Nodes - i; j++) {
            Debug[i][j] = N_points[i][j];
        }
    }
    
}

void b_spline::Destroy_the_equivalents(int nU)
{
    plots_len= 0;
    double value = u_points[0];
    for (int i = 0; i < nU; i++) {
        if (u_points[i] == value) { value = u_points[i]; plots_len++; }
    }
    plots = new double[plots_len];
    int j = 0; plots[0] = u_points[0];
    for (int i = 0; i < nU; i++) {
        if (u_points[i] != plots[j] && j < plots_len) { j++; plots[j] = u_points[i]; }
    }
}

void b_spline::Построить() {
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 0, 0);
    for (int i = 0; i < plots_len-1 ; i++) {
        for (double x = plots[i]; x <= plots[i + 1]; x += 0.01) {
            Calculate_N_points(x);
            DebugMatrix();
            vector<2, double> PNT;
            PNT[0] = C_function(x, 0);
            PNT[1] = C_function(x, 1);
            glVertex2d(PNT[0], PNT[1]);
        }
    }
    glEnd();
}

double b_spline::begin() const{
    return 0;
}
double b_spline::end() const {
    return 0;
}

void b_spline::drawPoints()
{
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < Points_col; i++) {
        glVertex2d(Points[i][0], Points[i][1]);
    }
    glEnd();
}

b_spline::~b_spline() {
    delete[] Points;
    delete[] u_points;
    for (int i = 0; i < NP_h; i++) {
        delete[] N_points[i];
    }
    delete[] N_points;
    delete[] plots;
}


b_spline::b_spline(double *U, vector<2,double> *P,int nP, int nU)
{
    u_points = new double[nU];
    Points = new vector<2, double>[nP];
    Points_col = nP;
    for (int pointr = 0; pointr < nU; pointr++) {
        u_points[pointr] = U[pointr];
    }
    for (int pointr = 0; pointr < nP; pointr++) {
        Points[pointr] = P[pointr];
    }
    double ODNC = u_points[0];//onределение степкни
    int begin_p=0;
    for (int i = 1; i < nU; i++) {
        if (ODNC == u_points[i]) begin_p++;
        else break;
    }
    Degree = begin_p-1;
    Nodes = nP + begin_p + 1;
    NP_h = begin_p;
    init_N_points(Nodes, begin_p);
    Destroy_the_equivalents(nU);
}
