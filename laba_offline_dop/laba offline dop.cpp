#include <iostream>
#include <vector>
#include <fstream>
#define PI 3.14


class Circle {
private:
	std::vector<int> color;
	int X;
	int Y;
	int R;
public:
	int getX() {
		return X;
	}
	int getY() {
		return Y;
	}
	int getR() {
		return R;
	}
	std::vector<int> getColor() {
		return color;
	}

	void setX(int x) {
		X = x;
	}
	void setY(int y) {
		Y = y;
	}
	void setR(int r) {
		R = r;
	}
	void setColor(std::vector<int> col) {
		for (int i{ 0 }; i < 3; i++)
			color[i] = col[i];
	}
	Circle() {
		X = 0;
		Y = 0;
		R = 3;
		color = { 0,0,0 };
	}

	Circle(int x, int y, int r) {
		X = x;
		Y = y;
		R = r;

		for (int i{ 0 }; i < 3; i++)
			color.push_back(0);
	}

	Circle(int x, int y, int r, std::vector<int> vec) {
		X = x;
		Y = y;
		R = r;
		if (vec.size() >= 3) {
			for (int i{ 0 }; i < 3; i++)
				color.push_back(vec[i]);
		}
		else {
			for (int i{ 0 }; i < 3; i++)
				color.push_back(0);
		}

	}
	Circle(std::vector<int> vec) {
		X = 0;
		Y = 0;
		R = 3;
		if (vec.size() >= 3) {
			for (int i{ 0 }; i < 3; i++)
				color.push_back(vec[i]);
		}
		else {
			for (int i{ 0 }; i < 3; i++)
				color.push_back(0);
		}
	}
	double dlina();
	double square();
	void ColorRand();
};



double Circle::square() {
	double sqr = PI * R * R;
	return sqr;
}

double Circle::dlina() {
	double length = 2 * PI * R;
	return length;
}

void Circle::ColorRand() {
	for (int i{ 0 }; i < 3; i++)
		color[i] = rand() % 257;
}
int main() {

	srand(time(NULL));

	std::vector<int> new_vec = { 256,256,256 };

	Circle krug(4, 5, 10, new_vec);

	std::ofstream fout;
	try {
		fout.open("Circle.txt");
	}
	catch (std::exception& ex) {
		std::cout << "FILE OPENING ERROR";
		fout.close();
		return 0;
	}

	fout << "Initial data:" << std::endl;
	fout << "X = " << krug.getX() << std::endl;
	fout << "Y = " << krug.getY() << std::endl;
	fout << "R = " << krug.getR() << std::endl;
	fout << "R = " << krug.getColor()[0] << "," << " G = " << krug.getColor()[1] << "," << " B = " << krug.getColor()[2] << std::endl;
	fout << "Square = " << krug.square() << std::endl;
	fout << "Length = " << krug.dlina() << std::endl;

	krug.setX(13);
	krug.setY(19);
	krug.ColorRand();
	krug.setR(3);

	fout << std::endl << "Final data:" << std::endl;
	fout << "X = " << krug.getX() << std::endl;
	fout << "Y = " << krug.getY() << std::endl;
	fout << "R = " << krug.getR() << std::endl;
	fout << "R = " << krug.getColor()[0] << "," << " G = " << krug.getColor()[1] << "," << " B = " << krug.getColor()[2] << std::endl;
	fout << "Square = " << krug.square() << std::endl;
	fout << "Length = " << krug.dlina() << std::endl;

	std::cout << "The data was successfully written in the 'Circle.txt' file.";
	fout.close();

	return 0;
}


