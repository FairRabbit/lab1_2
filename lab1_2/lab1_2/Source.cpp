#include <iostream>
#include <vector>
using namespace std;
// first function
double fn1(double x) {
	return 2*x*x - 4*x + 3;
}
// second function
double fn2(double x) {
	return 3 + 4*x;
}
// integration (area)
double integ(double fn(double x),vector<double> point_fn) {
	double x1 = point_fn.at(0);
	double x2 = point_fn.back();
	double area = 0;
	double error = 0.01; //accuracy (segment lenght)
	double quantity = (x2 - x1) / error;
	for (int i = 1;i <= quantity; i += 1) {
		area += error * fn(x1 + error * (i - 0.5));
	}
	return area;
}
// integration limits (function intersection points)
vector<double> fnIL(double fn1(double x), double fn2(double x)) {
	vector<double> point;
	double error = 0.001; // accuracy
	for (double x = -10000; x <= 10000; x += 0.01) {
		if (abs(fn1(x) - fn2(x)) <= error) {
			point.push_back(x);
		}
	}
	return point;
}
//integration limits (point of intersection with the abscissa)
vector<double> fnIL(double fn(double x)) {
	vector<double> point;
	for (double x = -10000; x <= 10000;x += 0.01) {
		if(abs(fn(x)) < 0.0001){
			point.push_back(x);
		}
	}
	return point;
}
int main() {
	vector<double> point_fn, point_abscissa;
	double s1, s2, answer;

	point_fn = fnIL(fn1, fn2);

	cout << "function intersection points ";
	for (double el : point_fn) {
		cout << el << " ";
	}
	cout << endl;

	point_abscissa = fnIL(fn1);
	cout << "intersection points of the fn1 with the abscissa ";
	for (double el : point_abscissa) {
		cout << el << " ";
	}
	cout << endl;

	point_abscissa = fnIL(fn2);
	cout << "intersection points of the fn2 with the abscissa ";
	for (double el : point_abscissa) {
		cout << el << " ";
	}
	cout << endl;

	//area
	s1 = integ(fn1, point_fn);
	s2 = integ(fn2, point_fn);
	answer = abs(s1-s2);
	cout << "are: " << answer;
	return 0;
}