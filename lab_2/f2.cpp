module;
#include <cmath>
module Vorobeva1bib18007;

namespace RBPO {
	namespace Lab2 {
		namespace Variant3 {
			namespace Task3 {
				double f2(double);
			};
		};
	};
};

double RBPO::Lab2::Variant3::Task3::f2(double x) {
	if (x <= -3) {
		return -x * x - 1.1 * x + 9;
	}
	else {
		return log(x + 3) / (x * x + 9);
	}
}