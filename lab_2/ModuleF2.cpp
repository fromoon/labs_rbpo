
module Vorobeva1bib18007:F2;
namespace RBPO {
	namespace Lab2 {
		namespace Variant3 {
			namespace Task4 {
				double f2(double);
			};
		};
	};
};

double RBPO::Lab2::Variant3::Task4::f2(double x) {
	if (x <= -3) {
		return -x * x - 1.1 * x + 9;
	}
	else {
		return log(x + 3) / (x * x + 9);
	}
}