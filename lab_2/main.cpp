#include <iostream>
using namespace std;
import Vorobeva1bib18007;

enum Choice {
	Task1 = '1', Task2 = '2', Task3 = '3', Task4 = '4', Task5 = '5'
};

int main()
{
	setlocale(LC_ALL, "rus");
	char qq;
	do
	{
		cout << "\nВведите номер выполняемого задания [v - выход]: "; cin >> qq;
		switch ((Choice)qq) {
			unsigned long long n; double x, eps;
		case Task1:
			cout << "Введите x, n и e для выполнения 1 задания: "; cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant3::Task1::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant3::Task1::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant3::Task1::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant3::Task1::f4(eps) << endl;
			break;
		case Task2:
			cout << "Введите x, n и e для выполнения 2 задания: "; cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant3::Task2::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant3::Task2::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant3::Task2::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant3::Task2::f4(eps) << endl;
			break;
		case Task3:
			cout << "Введите x, n и e для выполнения 3 задания: "; cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant3::Task3::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant3::Task3::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant3::Task3::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant3::Task3::f4(eps) << endl;
			break;
		case Task4:
			cout << "Введите x, n и e для выполнения 4 задания: "; cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant3::Task4::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant3::Task4::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant3::Task4::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant3::Task4::f4(eps) << endl;
			break;
		case Task5:
			cout << "Введите x, n и e для выполнения 5 задания: "; cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant3::Task5::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant3::Task5::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant3::Task5::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant3::Task5::f4(eps) << endl;
			break;
		case 'v':
			break;
		default:
			cout << "Повторите ввод, введя корректные данные." << endl;
			break;
		}
	} while (qq != 'v');
	return 0;
};
