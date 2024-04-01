#include "bezier_curve.h"

//bezier_curve::bezier_curve(double StX,double StY,double MiX,double MiY,double EnX,double EnY)
//{
//	Start.comps(StX, StY); Middle.comps(MiX, MiY); End.comps(EnX, EnY);
//}

bezier_curve::bezier_curve(vector<2, double> Start, vector<2, double> Middle, vector<2, double> End)
{
	this->Start = Start; this->Middle = Middle; this->End = End; flag = 1;
}
bezier_curve::bezier_curve(vector<2, double> Start, vector<2, double> Middle, vector<2, double> Middle2, vector<2, double> End)
{
	this->Start = Start; this->Middle = Middle; this->End = End; this->Middle2 = Middle2; flag = 2;
}
double bezier_curve::begin() const
{
	return Start.X;
}

double bezier_curve::end() const
{
	return End.X;
}
vector<2, double> bezier_curve::Function2(double t) {
	vector<2, double> Result;
	Result[0] = pow((1 - t), 3) * Start[0] + 3 * t * pow((1 - t), 2) * Middle[0] + 3 * t * t * (1 - t) * Middle2[0] + pow(t, 3) * End[0];
	Result[1] = pow((1 - t), 3) * Start[1] + 3 * t * pow((1 - t), 2) * Middle[1] + 3 * t * t * (1 - t) * Middle2[1] + pow(t, 3) * End[1];
	return Result;
}
vector<2, double> bezier_curve::Function(double t) {
	vector<2, double> Result;
	Result[0] = pow((1 - t), 2) * Start[0] + 2 * t * (1 - t) * Middle[0] + pow(t, 2) * End[0];
	Result[1] = pow((1 - t), 2) * Start[1] + 2 * t * (1 - t) * Middle[1] + pow(t, 2) * End[1];
	return Result;  
}
void bezier_curve::Build() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (double t = 0; t < 1.01; t += 0.01) {
		vector<2, double> V;
		switch (flag) {
		case 1:
			 V = Function(t); break;
		case 2:
			 V = Function2(t); break;
		}
		
		glVertex2d(V[0],V[1]);
	}
	glEnd();
}
