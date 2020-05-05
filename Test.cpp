#include "doctest.h"
#include "solver.hpp"
#include <string>
#include <complex>
#include <stdlib.h>

using namespace std;
using  solver::solve,solver:: RealVariable,solver::ComplexVariable;

TEST_CASE("real number"){
    RealVariable y;

    CHECK(solve((y^2)-3*y+2==1+2-3+3*y-2*y-y)==2);
    CHECK(solve(y*y-2*y+1==0)==1);
    CHECK(solve((y^2)-y==y*y+16)==-16);
    CHECK(solve((y^2)-3*y+2==0)==2);
    CHECK(solve((y^2)+y-16==y)==16);
    CHECK(solve((y^2)-3*y+2==(y^2)-(y^2)-y+y)==2);
    CHECK(solve(6*y+6*y==36)==1);
    CHECK(solve(3*(y^2)+2*y+4==3*(y^2)+2)==1);
    CHECK_THROWS(solve(16*(y^3)-1*2*y+2==-4));
    CHECK_THROWS(solve((y^22)-y*2*y+2*6*y==-2));

    CHECK(solve(2*y-4==18) == 11);
    CHECK(solve((y^2)==9)==3);
    CHECK(solve((y^2)-7*y+12)==4);
    CHECK(solve(y+10==10)==0);
    CHECK(solve(y+3 == 0) == -3);
    CHECK(solve((y^2)-y==0)==1);
    CHECK(solve((y^2)-6==30)==6);
    CHECK(solve((y^2)-8*y+16)==4);
    CHECK(solve((y^2)==16)==4);
    CHECK(solve((y^2)+4*y+4)==-2);

    CHECK_THROWS(solve(10*y+2==10*y));
    CHECK(solve((y^2)==64)==8);
    CHECK(solve(y*y==36)==6);
    CHECK_THROWS(solve(4*y+5==4*y));
    CHECK(solve(y*y==64)==8);
    CHECK(solve(3^2*y+3==3^2+30)==4);
    CHECK(solve(3*y+3*y-2==10)==2);
    CHECK((solve(2*2*y*y==8*8))==4);
    CHECK(solve(3*3*y*y==3*3*3*3)==3);
    CHECK(solve(5*5*y+5*5-5*y-5==0)==1);


    CHECK((solve((y^2)-y  == 2))==2);
    CHECK_THROWS(solve(4*(y^2)-y-48=3*(y^2)-12+3*y));
    CHECK(solve(16*y-7==-71)==-4);
    CHECK_THROWS(solve(121*(y^2)-110*y==4));
    CHECK(solve(2*y-12==10)==11);
    CHECK_THROWS(solve(42*(y^2)-69*y+20=7*(y^2)-6));
    CHECK_THROWS(solve(28*(y^2)+27==99*y-6));
    CHECK((solve(3*2*2*y*y-6-6==0))==1);
    CHECK_THROWS(solve(82*(y^2)+19*y-17==1));
    CHECK((solve((y^2)-y - 2 == 0))==2);

    CHECK_THROWS(solve(2*(y^2)+21*y==-34));
    CHECK_THROWS(solve(9*(y^2)+8*(y^2)+23*y==-23));
    CHECK_THROWS(solve(5*y+5==5*y+5));
    CHECK_THROWS(solve(y*y+6*y+11==(y^2)+y+5*y+11));
    CHECK_THROWS(solve(y+y+y-3*y+9==9));
    CHECK_THROWS(solve((6^2)*y+3==(6^2)*y));
    CHECK_THROWS(solve(5^2*(y^2)+60*y+12==-13));
    CHECK_THROWS(solve(y*y==y^2));
    CHECK_THROWS(solve(y*y+9==(y^2)+8));
    CHECK_THROWS(solve(y*y+4*y+10==(y^2)+y+3*y+10));

}


TEST_CASE("complex number")
{
    ComplexVariable x;


    CHECK(solve(x==complex(-2.0,2.0))==complex(-2.0,2.0));
    CHECK(solve((x^2)+2*x+17==complex(0.0,0.0))==complex(-1.0,4.0));
    CHECK(solve(x+complex(-3.0,1.0)==0.0)==complex(3.0,-1.0));
    CHECK(solve(2*x==complex(-2.0,2.0))==complex(-1.0,1.0));
    CHECK(solve((x^2)+complex(12.0,0.0)+complex(4.0,0.0)==0)==complex(0.0,4.0));
    CHECK(solve(x+complex(-4.0,4.0)+x==0)==complex(2.0,-2.0));
    CHECK(solve((x^2)+(x^2)-(x^2)+complex(14.0,1.0)+complex(3.0,-1.0)==0)==complex(-1.0,4.0));
    CHECK(solve((x^2)+complex(64.0,0.0)==complex(0.0,-0.0))==complex(0.0,8.0));
    CHECK(solve((x^2)+x+x+complex(2.0,0.0)+complex(15.0,0.0)==0)==complex(-1.0,4.0));
    CHECK(solve(x+complex(2.0,2.0)==complex(-1.0,-1.0))==complex(-3.0,-3.0));

    CHECK(solve(x+2.0 == 0.0) == complex(-2.0,0.0));
    CHECK(solve(x+51.0==51.0)==complex(0.0,0.0));
    CHECK(solve(2*x+2*x+2.0+2.0==0.0)==complex(-1.0,0.0));
    CHECK(solve(x+x-3*x==10.0)==complex(-10.0,0.0));
    CHECK(solve(7*x-10*x==-6.0)==complex(2.0,0.0));
    CHECK(solve(2*x-3*x==0.0)==complex(0.0,0.0));
    CHECK(solve(12.0*x==36.0)==complex(3.0,0.0));
    CHECK(solve(3*(x)-5.0==10.0) == complex(5.0,0.0));
    CHECK(solve(7*x-6*x==3.0)==complex(3.0,0.0));
    CHECK(solve(10.0+18+7*x==0.0)==complex(-4.0,0.0));

    CHECK(solve(3*x*7+21 == complex(0.0, -21.0)) == complex(-1.0,-1.0));
    CHECK(solve(7+5-4*3*x == 18) == complex(-0.5,0.0));
    CHECK(solve(4*x+complex(4.0,12.0)==0)==complex(-1.0,-3.0));
    CHECK(solve(2*x-x*3 == 15) == complex(-15.0,0.0));
    CHECK(solve(4*3+4*3*x==18)==complex(0.5,0.0));
    CHECK(solve(56*x+8 == complex(8.0, -56.0)) == complex(0.0,-1.0));
    CHECK(solve(x+13 == 7) == complex(-6.0,0.0));
    CHECK(solve((x^2)+x+16==(x^2)-2*x+1)==complex(-5.0,0.0));
    CHECK(solve(x+2-x-2 == x) == complex(0.0,0.0));
    CHECK(solve(4*x+complex(2.0,4.0)+4==0)==complex(-1.5,-1.0));

    CHECK(solve(56*x+8 == complex(8.0, -56.0)) == complex(0.0,-1.0));
    CHECK(solve(40*x==10)==complex(0.25,0.0));
    CHECK(solve(12+3*4*x==20)==complex(0.75,0.0));
    CHECK(solve(4*x+12 == 0) == complex(-3.0,0.0));
    CHECK(solve(x+2-x-2 == x) == complex(0.0,0.0));
    CHECK(solve(x+x-2 == 10) == complex(6.0,0.0));
    CHECK(solve(4*x-8 == 10*x+complex(4.0, -12.0)) == complex(-2.0,2.0));
    CHECK(solve(6*x+8==complex(8.0,6.0))==complex(0.0,1.0));
    CHECK(solve(5*x == 6*x) == complex(0.0,0.0));
    CHECK(solve(4*x+12 == 0) == complex(-3.0,0.0));
    CHECK(solve(5*x-4*x==12)==complex(12.0,0.0));
    CHECK(solve(2*x==3*x)==complex(0.0,0.0));
    CHECK(solve(5*x == 6*x) == complex(0.0,0.0));
    CHECK(solve((x^2)+16*x+16==14*x+2*x)==complex(0.0,4.0));

    CHECK_THROWS(solve(2*(x^222)-6==6));
    CHECK_THROWS(solve(2*(x^22)*6==12));
    CHECK_THROWS(solve((x^311)+complex(6.0,0.0)==0) );
    CHECK_THROWS(solve(2*x-2*x+2-2==0));
    CHECK_THROWS(solve(2*x+4+complex(-3.0,-3.0)+(x^2)+(x^2)==complex(-3.0,-3.0)+(x^2)+(x^2)));
    CHECK_THROWS(solve((x^222)+4+complex(-2.0,-2.0)==0));
    CHECK_THROWS(solve(x+1-2+1+complex(1.0,1.0)==complex(1.0,1.0)));
    CHECK_THROWS(solve(12*x+complex(-6.0,0.0)==12*x+complex(-6.0,0.0)));
    CHECK_THROWS(solve(2*6*x+complex(-6.0,0.0)==2*6*x+complex(-6.0,0.0)));
    CHECK_THROWS(solve(11*x+complex(-7.0,9.0)==11*x+complex(-7.0,9.0)));

}