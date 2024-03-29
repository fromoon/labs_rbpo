﻿module;
#include <cmath>
#include <ostream>
#include <complex>
export module Math;

export namespace Math {
	export class Complex
	{
	private:
		double m_re;
		double m_im;
	public:
		Complex(double num_real)
		{
			m_re = num_real;
			m_im = 0;
		}
		Complex()
		{
			m_re = 0;
			m_im = 0;
		}
		Complex(double num_real, double num_imag)
		{
			m_re = num_real;
			m_im = num_imag;
		}

		static Complex FromExponentialForm(double mod, double arg)
		{
			Complex temp_obj;
			temp_obj.m_re = mod * cos(arg);
			temp_obj.m_im = mod * sin(arg);
			return temp_obj;
		}
		static Complex FromAlgebraicForm(double num_real, double num_imag)
		{
			Complex alg_obj(num_real, num_imag);
			return alg_obj;
		}
		double Re() const
		{
			return m_re;
		}
		double Im() const
		{
			return m_im;
		}
		double Mod() const
		{
			return sqrt(m_re * m_re + m_im * m_im);
		}
		double Arg() const
		{
			return atan2(m_im, m_re);
		}

		explicit operator double() const {
			return (double)m_re;
		}
		Complex operator-()
		{
			Complex object{ *this };
			object.m_im *= -1;
			object.m_re *= -1;
			return object;
		}
		Complex& operator++()
		{
			m_re++;
			return *this;
		}
		Complex operator++(int inc)
		{
			Complex object{ *this };
			++*this;
			return object;
		}
		Complex& operator--()
		{
			m_re--;
			return *this;
		}
		Complex operator--(int dec)
		{
			Complex object{ *this };
			--*this;
			return object;
		}
		Complex& operator+=(Complex temp)
		{
			m_re += temp.m_re;
			m_im += temp.m_im;
			return *this;
		}
		Complex& operator-=(Complex temp) {
			m_re -= temp.m_re;
			m_im -= temp.m_im;
			return *this;
		}
		Complex& operator*=(Complex temp) {
			double realMI = m_re;
			double imagination = m_im;
			m_re = realMI * temp.m_re - imagination * temp.m_im;
			m_im = realMI * temp.m_im + imagination * temp.m_re;
			return *this;
		}
		Complex& operator/=(Complex temp) {
			double tre1 = m_re, tim1 = m_im;
			double tre2 = temp.m_re, tim2 = temp.m_im;
			m_re = (tre1 * tre2 + tim1 * tim2) / (pow(tre2, 2) + pow(tim2, 2));
			m_im = (tre2 * tim1 - tre1 * tim2) / (pow(tre2, 2) + pow(tim2, 2));
			return *this;
		}
		static void Cos(Complex& obj)
		{
			std::complex<double> temp;
			temp._Val[0] = obj.Re();
			temp._Val[1] = obj.Im();
			temp = cosh(temp);
			obj.m_re = temp.real();
			obj.m_im = temp.imag();
		}
		friend Complex operator+ (const Complex& first, const Complex& second);
		friend Complex operator- (const Complex& first, const Complex& second);
		friend Complex operator* (const Complex& first, const Complex& second);
		friend Complex operator/ (const Complex& first, const Complex& second);
		friend Complex operator ""i(long double num_imag);
		friend Complex operator ""i(unsigned long long num_imag);
		friend std::ostream& operator<<(std::ostream& stream, const Complex& temp);
	};
	export Complex operator+(const Complex& first, const Complex& second)
	{
		return Complex(first.m_re + second.m_re, first.m_im + second.m_im);
	}
	export Complex operator-(const Complex& first, const Complex& second)
	{
		return Complex(first.m_re - second.m_re, first.m_im - second.m_im);
	}
	export Complex operator*(const Complex& first, const Complex& second)
	{
		return Complex((first.m_re * second.m_re - first.m_im * second.m_im),
			(first.m_re * second.m_im + first.m_im * second.m_re));
	}
	export Complex operator/(const Complex& first, const Complex& second)
	{
		return Complex((first.m_re * second.m_re + first.m_im * second.m_im) /
			(second.m_re * second.m_re + second.m_im * second.m_im),
			(second.m_re * first.m_im - first.m_re * second.m_im) /
			(second.m_re * second.m_re + second.m_im * second.m_im));
	}
	export Complex operator""i(long double num_imag)
	{
		return Complex(0.0, static_cast<double>(num_imag));
	}
	export Complex operator""i(unsigned long long num_imag)
	{
		return Complex(0.0, static_cast<double>(num_imag));
	}
	export std::ostream& operator<<(std::ostream& stream, const Complex& temp)
	{
		if (temp.m_im < 0)
		{
			stream << temp.m_re << " " << temp.m_im << "i";
		}
		else
		{
			stream << temp.m_re << " + " << temp.m_im << "i";
		}
		return stream;
	}

	export int FindGreatestCommonDivisor(int a, int b)
	{
		int r;
		if (a < 0)
			a *= -1;
		if (b < 0)
			b *= -1;
		while (true)
		{
			if (b == 0)
				return a;
			r = a % b;
			a = b;
			b = r;
		}
	}
	export int FindLeastCommonMultiple(int a, int b) {
		return abs(a * b) / FindGreatestCommonDivisor(a, b);
	}

	export class Rational {
		int m_nominator;
		int m_denominator;

	public:
		void normalize()
		{
			int nod = FindGreatestCommonDivisor(m_nominator, m_denominator);
			m_nominator /= nod;
			m_denominator /= nod;
			if (m_denominator < 0) {
				m_denominator *= -1;
				m_nominator *= -1;
			}
		}

		Rational()
		{
			m_nominator = 0;
			m_denominator = 1;
		}
		Rational(int _nominator, int _denominator) {
			m_denominator = _denominator;
			m_nominator = _nominator;
			normalize();
		}
		Rational(int _nominator) {
			m_nominator = _nominator;
			m_denominator = 1;
		}
		int Nominator() const {
			return m_nominator;
		}
		int Denominator() const {
			return m_denominator;
		}
		explicit operator double() const {
			return double(m_nominator) / m_denominator;
		}
		Rational operator-() {
			Rational object{ *this };
			object.m_nominator *= -1;
			return object;
		}
		Rational& operator++ () {
			m_nominator += m_denominator;
			return *this;
		}
		Rational operator++ (int _param) {
			Rational object{ *this };
			(*this).m_nominator += m_denominator;
			return object;
		}
		Rational& operator-- () {
			m_nominator -= m_denominator;
			return *this;
		}
		Rational operator-- (int _param) {
			Rational object{ *this };
			(*this).m_nominator -= m_denominator;
			return object;
		}
		Rational& operator+=(Rational temp) {
			int new_den = FindLeastCommonMultiple(m_denominator, temp.m_denominator);
			m_nominator = new_den / m_denominator * m_nominator;
			m_nominator += new_den / temp.m_denominator * temp.m_nominator;
			m_denominator = new_den;
			normalize();
			return *this;
		}
		Rational& operator-=(Rational temp) {
			int new_d = FindGreatestCommonDivisor(m_denominator, temp.m_denominator);
			m_nominator = new_d / m_denominator * m_nominator;
			m_nominator -= new_d / temp.m_denominator * temp.m_nominator;
			m_denominator = new_d;
			normalize();
			return *this;
		}
		Rational& operator*=(Rational temp) {
			m_denominator *= temp.m_denominator;
			m_nominator *= temp.m_nominator;
			normalize();
			return *this;
		}
		Rational& operator/=(Rational temp) {
			m_denominator *= temp.m_nominator;
			m_nominator *= temp.m_denominator;
			normalize();
			return *this;
		}

		friend Rational operator+ (const Rational& first, const Rational& second);
		friend Rational operator- (const Rational& first, const Rational& second);
		friend Rational operator* (const Rational& first, const Rational& second);
		friend Rational operator/(const Rational& first, const Rational& second);
		friend bool operator==(const Rational& first, const Rational& second);
		friend bool operator>(const Rational& first, const Rational& second);
		friend bool operator<(const Rational& first, const Rational& second);
		friend bool operator>=(const Rational& first, const Rational& second);
		friend bool operator<=(const Rational& first, const Rational& second);
		friend std::ostream& operator<<(std::ostream& stream, const Rational& temp);
	};

	export Rational operator+ (const Rational& first, const Rational& second) {
		int denominator = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
		int nominator = denominator / first.m_denominator * first.m_nominator;
		nominator += denominator / second.m_denominator * second.m_nominator;
		return Rational{ nominator, denominator };
	}

	export Rational operator-(const Rational& first, const Rational& second)
	{
		int denominator = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
		int nominator = denominator / first.m_denominator * first.m_nominator;
		nominator -= denominator / second.m_denominator * second.m_nominator;
		return Rational{ nominator, denominator };
	}

	export Rational operator*(const Rational& first, const Rational& second)
	{
		return Rational{ first.m_nominator * second.m_nominator, second.m_denominator * first.m_denominator };
	}

	export Rational operator/(const Rational& first, const Rational& second)
	{
		return Rational{ first.m_nominator * second.m_denominator,first.m_denominator * second.m_nominator };
	}

	export bool operator==(const Rational& first, const Rational& second)
	{
		return first.m_nominator == second.m_nominator && first.m_denominator == second.m_denominator;
	}

	export bool operator>(const Rational& first, const Rational& second)
	{
		int den = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
		return den / first.m_denominator * first.m_nominator > den / second.m_denominator * second.m_nominator;
	}
	export bool operator<(const Rational& first, const Rational& second)
	{
		int den = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
		return den / first.m_denominator * first.m_nominator < den / second.m_denominator * second.m_nominator;
	}
	export bool operator>=(const Rational& first, const Rational& second)
	{
		int den = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
		return den / first.m_denominator * first.m_nominator >= den / second.m_denominator * second.m_nominator;
	}
	export bool operator<=(const Rational& first, const Rational& second)
	{
		int den = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
		return den / first.m_denominator * first.m_nominator <= den / second.m_denominator * second.m_nominator;
	}

	export std::ostream& operator<<(std::ostream& stream, const Rational& temp) {
		stream << temp.m_nominator << "/" << temp.m_denominator;
		return stream;
	}

	export Complex f(const Complex& z)
	{
		Complex a(2, 0);
		Complex ans = 1 + z;
		Complex::Cos(ans);
		return Complex(z / a) + ans;
	}

	export Rational f(const Rational& r)
	{
		Rational a(2, 1);
		double vver = r.Nominator(), nizz = r.Denominator();
		double ans = (1 + vver / nizz);
		return Rational(r / a) + cosh(ans);;
	}

	export double f(const double& x)
	{
		double a = 2.0;
		return double(x / a) + cosh(1 + x);;
	}
}