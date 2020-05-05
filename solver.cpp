//
// Created by yonatan on 27/04/2020.
//
#include <iostream>
#include "solver.hpp"
using namespace solver;
solver::RealVariable::RealVariable():a(0),b(1),c(0) {}
solver::RealVariable::RealVariable(double num1,double num2,double num3):a(num1),b(num2),c(num3){}
RealVariable& solver::operator^(solver::RealVariable x, int num){
   RealVariable *k = new RealVariable();
   if(num == 2 ){
       k->a= 1 ;
       k->b=  0 ;
       k->c = 0 ;
   }else if ( num == 1 ){
       k->a = 0 ;
       k->b = 1;
       k->c = 0;
   } else if (num == 0 ){
       k->a=  0 ;
       k->b = 0 ;
       k->c = 1;
   }else throw std::invalid_argument("there is no pow up to 2");
    return *k;
}
RealVariable& solver::operator^(double num ,solver::RealVariable x){
    throw std::invalid_argument("there is no pow up to 2");
}
RealVariable& solver::operator*(double num, solver::RealVariable x){
   RealVariable* n = new RealVariable() ;
    n->b = num * x.b;
   return *n;
}
RealVariable& solver::operator*(solver::RealVariable y, solver::RealVariable x){
   RealVariable* n = new RealVariable() ;
    n->a = x.a+y.a;
    if(x.a+y.a > 2) throw std::invalid_argument("there is no pow up to 2");
    n->b =   x.b;
    n->c =   x.c;
   return *n;
}
RealVariable& solver::operator*( solver::RealVariable x,double num){
   RealVariable* n = new RealVariable() ;
    n->b = num * x.b;
   return *n;
}
RealVariable& solver::operator==(solver::RealVariable x,solver::RealVariable y){
    RealVariable* n = new RealVariable();
    n->c=x.c-y.c;
    n->b=x.b-y.b;
    n->a=x.a-y.a;
    return *n;
}
RealVariable& solver::operator==(solver::RealVariable x,double num){
    RealVariable* n = new RealVariable();
    n->a=x.a;
    n->b=x.b;
    n->c=x.c-num;
    return *n;
}
RealVariable& solver::operator==(double num,solver::RealVariable x){
    RealVariable* n = new RealVariable();
    n->a=x.a;
    n->b=x.b;
    n->c=x.c-num;
    return *n;
}
RealVariable& solver::operator/(solver::RealVariable x,double num){
    if(num == 0.0) throw std::invalid_argument("cant diving by 0");
    RealVariable* n = new RealVariable();
    n->a=x.a/num;
    n->b=x.b/num;
    n->c=x.c/num;
    return *n;
}
RealVariable& solver::operator+(solver::RealVariable y,solver::RealVariable x){
    RealVariable* n= new RealVariable();
    n->a= y.a+x.a;
    n->b= y.b+x.b;
    n->c= y.c+x.c;
    return *n;
}
RealVariable& solver::operator+(solver::RealVariable x, double y) {
    RealVariable* n = new RealVariable() ;
    n->a=x.a;
    n->b=x.b;
    n->c = x.c + y ;
    return *n;
}
RealVariable& solver::operator+(double y,solver::RealVariable x) {
    RealVariable* n = new RealVariable() ;
    n->a=x.a;
    n->b=x.b;
    n->c = x.c + y ;
    return *n;
}
RealVariable& solver::operator-(solver::RealVariable y,solver::RealVariable x){
    RealVariable* n= new RealVariable();
    n->a= y.a-x.a;
    n->b= y.b-x.b;
    n->c= y.c-x.c;
    return *n;
}
RealVariable& solver::operator-(double y,solver::RealVariable x) {
    RealVariable* n = new RealVariable() ;
    n->a=x.a;
    n->b=-x.b;
    n->c = x.c + y ;
    return *n;
}
RealVariable& solver::operator-(solver::RealVariable x, double y) {
    RealVariable* n = new RealVariable() ;
    n->a=x.a;
    n->b=x.b;
    n->c = x.c - y ;
    return *n;
}
RealVariable& RealVariable::operator()(RealVariable& rv)
{
    RealVariable* ret;
    ret->b = 0;

    ret->a = rv.a;
    ret->b = rv.b;
    ret->c = rv.c;

    return *ret;

}
double solver::solve(RealVariable x){
    if(x.a==0){
        if(x.b == 0 ) throw std::invalid_argument("cant diving by 0");
        double ans = -(x.c)/x.b;
        return ans;
    }
    else if(x.a!=0){
        double delta = pow(x.b,2.0)-4*x.a*x.c;
        if(delta>0){
            double ans = (-x.b + sqrt(delta))/2*x.a;
            return ans;
        } else if (delta==0){
            double ans = (-x.b)/2*x.a;
            return ans;
        }
        else{
            throw std::invalid_argument("There is no real solution");
        }
    }
    return 0.0;
}
solver::ComplexVariable::ComplexVariable():a(0.0,0.0),b(1.0,0.0),c(0.0,0.0) {}
ComplexVariable& solver::operator*(complex<double>  num, solver::ComplexVariable x){
    ComplexVariable* n = new ComplexVariable() ;
    n->b = num * x.b;
    return *n;
}
ComplexVariable& solver::operator*(solver::ComplexVariable x,complex<double>  num){
    ComplexVariable* n = new ComplexVariable() ;
    n->b = num * x.b;
    return *n;
}
ComplexVariable& solver::operator^(solver::ComplexVariable x, int num){
    ComplexVariable *k = new ComplexVariable();
    if(num == 2 ){
        k->a= 1,0 ;
        k->b=  0,0 ;
        k->c = 0,0 ;
    }else if ( num == 1 ){
        k->a = 0 ;
        k->b = 1.0;
        k->c = 0;
    } else if (num == 0 ){
        k->a=  0 ;
        k->b = 0 ;
        k->c = 1;
    }
    else throw std::invalid_argument("there is no pow up to 2");
    return *k;
}
ComplexVariable& solver::operator+(solver::ComplexVariable x, complex<double>  y) {
    ComplexVariable* n = new ComplexVariable() ;
    n->a=x.a;
    n->b=x.b;
    n->c = x.c + y ;
    return *n;
}
ComplexVariable& ComplexVariable::operator()(ComplexVariable& var)
{
    ComplexVariable* ans;

    return *ans;

}
ComplexVariable& solver::operator+(solver::ComplexVariable x, solver::ComplexVariable y) {
    ComplexVariable* n = new ComplexVariable() ;
    n->a=x.a+y.a;
    n->b=x.b+y.b;
    n->c = x.c + y.c ;
    return *n;
}
ComplexVariable& solver::operator+( complex<double>  y,solver::ComplexVariable x) {
    ComplexVariable* n = new ComplexVariable() ;
    n->a=x.a;
    n->b=x.b;
    n->c = x.c + y ;
    return *n;
}
ComplexVariable& solver::operator==(solver::ComplexVariable x, complex<double>  num){
    ComplexVariable* n = new ComplexVariable() ;
    n->a=x.a;
    n->b=x.b;
    n->c=x.c-num;
    return *n;
}
ComplexVariable& solver::operator/(solver::ComplexVariable  x,double num){
    ComplexVariable* n = new ComplexVariable();
    if(num == 0.0) throw std::invalid_argument("cant diving by 0");
    n->a=x.a/num;
    n->b=x.b/num;
    n->c=x.c/num;
    return *n;
}

ComplexVariable& solver::operator-(solver::ComplexVariable x, complex<double>  y) {
    ComplexVariable* n = new ComplexVariable() ;
    n->a=x.a;
    n->b=x.b;
    n->c = x.c - y ;
    return *n;
}
ComplexVariable& solver::operator-(solver::ComplexVariable x,solver::ComplexVariable y){
    ComplexVariable* n = new ComplexVariable();
    n->a = x.a -y.a;
    n->b = x.b - y.b;
    n->c = x.c - y.c;
    return *n;
}
ComplexVariable& solver::operator-(complex<double> y,solver::ComplexVariable x){
    ComplexVariable* n = new ComplexVariable();
    n->a=x.a;
    n->b=x.b;
    n->c =  y -x.c ;
    return *n;
}
ComplexVariable& solver::operator==(solver::ComplexVariable x, solver::ComplexVariable y){
    ComplexVariable* n = new ComplexVariable();
    n->c=x.c-y.c;
    n->b=x.b-y.b;
    n->a=x.a-y.a;
    return *n;
}
ComplexVariable& solver::operator==(complex<double> y,solver::ComplexVariable x){
    ComplexVariable* n = new ComplexVariable() ;
    n->a=x.a;
    n->b=x.b;
    n->c=x.c-y;
    return *n;
}
complex<double> solver::solve(ComplexVariable x) {
    complex<double> ans;
    if (x.a == 0.0) {
        if(x.b == 0.0) throw std::invalid_argument("cant diving by 0");
        ans = -(x.c) / x.b;
        return ans;
    } else if (x.a != 0.0) {
        complex<double> delta = pow(x.b, 2.0) - 4.0 * x.a * x.c;
        if (delta.imag() == 0) {
            if (delta.real() > 0.0) {
                ans = (-x.b + sqrt(delta)) / 2.0 * x.a;
                return ans;
            } else if (delta == 0.0) {
                ans = (-x.b) / 2.0 * x.a;
                return ans;
            } else if (delta.real() < 0.0) {
              ans = ((-x.b)+sqrt(delta))/(2.0*x.a);
              return ans;
            }
        }

        }
        return 0.0;
    }
