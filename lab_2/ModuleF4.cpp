module Vorobeva1bib18007:F4;

namespace RBPO {
	namespace Lab2 {
		namespace Variant3 {
			namespace Task4 {
				double f4(double);
			};
		};
	};
};

double RBPO::Lab2::Variant3::Task4::f4(double eps) {
	double sum = a(0); unsigned long long i = 2;
	for (double temp = a(1), temp1 = a(2); eps < abs(temp - temp1); sum += temp, temp = temp1, temp1 = a(++i));
	return sum;
};