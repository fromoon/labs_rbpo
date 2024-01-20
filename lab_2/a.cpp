module Vorobeva1bib18007;
#include <cmath>
namespace RBPO {
	namespace Lab2 {
		namespace Variant3 {
			namespace Task3 {
				double a(long long);
			};
		};
	};
};

double RBPO::Lab2::Variant3::Task3::a(long long i) {
	double numerator = pow(-1, i) * 3;
	double denominator = 2 * (i + 1);
	return numerator / denominator;
};