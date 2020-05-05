//
// Created by yonatan on 27/04/2020.
//

#ifndef SOLVER_A_SOLVER_HPP
#define SOLVER_A_SOLVER_HPP
#include <cmath>

#include <complex>

using namespace std;
namespace solver {

    class RealVariable {
    private:

    public:
        double a;
        double b;
        double c;

        RealVariable(double a, double b, double c);

        RealVariable();

        friend RealVariable& operator+(RealVariable x, RealVariable y);
        friend RealVariable& operator+(RealVariable x, double y);
        friend RealVariable& operator+(double y,RealVariable x);

        friend RealVariable& operator*(double x, RealVariable y);
        friend RealVariable& operator*( RealVariable y, double x);
        friend RealVariable& operator*( RealVariable y, RealVariable x);

        friend RealVariable& operator/(RealVariable y,double x);

        friend RealVariable& operator^(RealVariable x, int num);
        friend RealVariable& operator^(double num ,RealVariable x);//*
       // friend RealVariable& operator^(double x, int num);//**

        friend RealVariable& operator==(RealVariable x, RealVariable y);
        friend RealVariable& operator==(RealVariable x, double y);
        friend RealVariable& operator==( double y,RealVariable x);

        friend RealVariable& operator-(RealVariable x, double y);
        friend RealVariable& operator-(double y,RealVariable x);
        friend RealVariable& operator-(RealVariable x, RealVariable y);
    };

    class ComplexVariable {
    private:

    public:
        complex<double> a;
        complex<double> b;
        complex<double> c;

        ComplexVariable();

        friend ComplexVariable& operator*(complex<double> x, ComplexVariable y);
        friend ComplexVariable& operator*(ComplexVariable x,complex<double> num);
       // friend ComplexVariable& operator*(ComplexVariable x,ComplexVariable y);//*

        friend ComplexVariable& operator-(ComplexVariable x, complex<double> y);
        friend ComplexVariable& operator-(ComplexVariable x, ComplexVariable y);
        friend ComplexVariable& operator-( complex<double> y,ComplexVariable x);

        friend ComplexVariable& operator+(ComplexVariable x, complex<double> y);
        friend ComplexVariable& operator+(ComplexVariable x, ComplexVariable y);
        friend ComplexVariable& operator+(complex<double> y,ComplexVariable x);

        friend ComplexVariable& operator==(ComplexVariable x, complex<double> y);
        friend ComplexVariable& operator==(ComplexVariable x, ComplexVariable y);
        friend ComplexVariable& operator==(complex<double> y,ComplexVariable x);
        friend ComplexVariable& operator/(ComplexVariable  x,double num);

        friend ComplexVariable& operator^(ComplexVariable x, int num);
       // friend ComplexVariable& operator^(int x, int num);//*

    };

    double solve(RealVariable x);
    std::complex<double> solve(ComplexVariable x);
}

#endif //SOLVER_A_SOLVER_HPP
