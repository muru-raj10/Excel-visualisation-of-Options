//Global.cpp
//To define the functions declared in Global.hpp

#ifndef Global_cpp
#define Global_cpp

#include <iostream>
#include <string>
#include <cmath>
#include "NormalFunction.cpp"
#include "OptionData.hpp"

using namespace boost::math;


namespace global
{

double CallPrice(double S,double r,double sig,double K,double T,double b)
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return (S * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));
}

double PutPrice(double S,double r,double sig,double K,double T,double b) 
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T)* N(-d2)) - (S * exp((b-r)*T) * N(-d1));
}


void print(const vector<double>& myVector)	//a print function for vector
{
	vector<double>::const_iterator i;

	for (i = myVector.begin(); i != myVector.end(); ++i)
	{
		cout << *i << ",";
	}
	cout<< endl;
}
//A Mesh Array function
vector<double> MeshArray(double Start, double h, double End)	//creating a mesh
{
	vector<double> mesh;

	for(double i=Start; i<=End; i+=h)
		mesh.push_back(i);

	return mesh;
}

double CallDelta(double S,double r,double sig,double K,double T, double b)	//delta for call option
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * N(d1);
}

double PutDelta(double S,double r,double sig,double K,double T, double b)		//delta for put option
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return exp((b-r)*T) * (N(d1) - 1.0);
}

double Gamma(double S,double r,double sig,double K,double T, double b)		//Gamma function for options
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(S/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	return (n(d1) * exp((b-r)*T)) / (S*tmp);
}

}


#endif