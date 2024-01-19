#include <iostream>
#include <complex>
import Math;
using namespace Math;

int main()
{
	setlocale(LC_ALL, "rus");
	double re, im;
	std::cout << "task 1:" << std::endl;
	std::cout << "¬ведите реальную часть числа: "; std::cin >> re;
	std::cout << "¬ведите мнимую часть числа: "; std::cin >> im;
	Complex c_num(re, im);

	double vver, nizz;
	std::cout << "\ntask 2:" << std::endl;
	std::cout << "¬ведите числитель числа: "; std::cin >> vver;
	std::cout << "¬ведите знаменатель числа: "; std::cin >> nizz;
	Rational r_num(vver, nizz);

	double d_num;
	std::cout << "\ntask 3:" << std::endl;
	std::cout << "¬ведите число: "; std::cin >> d_num;

	std::cout << "\nanswer:" << std::endl;
	std::cout << "f(" << c_num << ") = " << f(c_num) << std::endl;
	std::cout << "f(" << r_num << ") = " << f(r_num) << std::endl;
	std::cout << "f(" << d_num << ") = " << f(d_num) << std::endl;
	return 0;
}