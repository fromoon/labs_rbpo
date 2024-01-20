module Vorobeva1bib18007:F3;

namespace RBPO {
	namespace Lab2 {
		namespace Variant3 {
			namespace Task4 {
				double f3(unsigned long long);
			};
		};
	};
};

double RBPO::Lab2::Variant3::Task4::f3(unsigned long long n) {
	double sum = a(0);
	for (unsigned long long i = 0; i < n; sum += a(++i));
	return sum;
};