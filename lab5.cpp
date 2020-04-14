#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
//функция (интеграл)
double f(double x)
{
	return 1/((1+x)*sqrt(x));
}

//Метод прямоугольников
double rectangles(double a, double b, double h)
{
	double sum = 0;
	double x;
	
//Формула метода
	for(x = a + h * 0.5; x < b; x += h)
		sum += f(x);
	sum *= h;
	
	return sum;
}

int main(int argc, char ** argv)
{  ofstream fout("ans1.dat");
	double a = 0.0, b = 1.0; 
    double h = 0.5; // задаём шаг интегрирования
	double errrect;
	do {
		double rect = rectangles(a, b, h);
		
		h /= 2;
		
		double divrect = rectangles(a, b, h); 
		
		errrect = abs(rect - divrect)/3.; // вычисляем погрешность
	} while (errrect > 1e-4);
	cout << "Integ=" << rectangles(a, b, h) << " " <<"Error=" << errrect;
	fout << rectangles(a, b, h) << " " << errrect;
    fout.close();
	return 0;
}
