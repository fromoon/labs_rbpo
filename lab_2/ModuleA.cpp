module Vorobeva1bib18007:A;

namespace RBPO {
	namespace Lab2 {
		namespace Variant3 {
			namespace Task4 {
				double a(long long);
			};
		};
	};
};

double RBPO::Lab2::Variant3::Task4::a(long long i) {
	return (i % 2 ? -1 : 1) * 3 / double(2 * i + 2);
};