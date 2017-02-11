// NormalFunction.cpp
//
// Some exact formulae.
//
// (C) Datasim Education BV 2011
//
#ifndef NormalFunction_cpp
#define NormalFUnction_cpp

#include <cmath>
#include <iostream>
using namespace std;
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
using namespace boost::math;

using namespace boost::math;

//Annonymous namespace to prevent double definitions of the same function in other cpp files(in Global.cpp)
namespace
{
double N(double x)
{
	normal_distribution<> myNormal(0.0, 1.0); 

	return cdf(myNormal, x);
}

double n(double x)
{
	normal_distribution<> myNormal(0.0, 1.0); 

	return pdf(myNormal, x);
}

}
#endif
