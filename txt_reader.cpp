#include "txt_reader.h"



vector<2, double>* txt_points::Read_file(char *filename)
{
	std::ifstream file(filename);
	if (file) {
		double x; double y;
		while (true) {
			file >> x >> y;
			if (file.eof()) {
				Npoints++;
				break;
			}
			else Npoints++;
		}
	}
	file.close();
	Points = new vector<2, double>[Npoints];
	//std::ifstream ifile("TB.txt");
	file.open(filename);
	Npoints = 0;
	if (file) {
		
		while (true) {
			file >> Points[Npoints][0] >> Points[Npoints][1];
			if (file.eof()) {
				Npoints++;
				break;
			}
			else Npoints++;
		}
	}
	return Points;
}

int txt_points::get_points()
{
	return Npoints;
}

txt_points::~txt_points()
{
	delete[]Points;
}
