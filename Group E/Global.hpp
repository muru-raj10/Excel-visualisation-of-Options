//Global.hpp
//To define some global functions

#ifndef Global_hpp
#define Global_hpp

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "OptionData.hpp"


namespace global	//To solve the problem of nameclashes in a global scope
{
	//Price functions
	double CallPrice(double S,double r,double sig,double K,double T,double b);	//Price of a general call option
	double PutPrice(double S,double r,double sig,double K,double T,double b);	//Price of a general put option

	void print(const vector<double>& myVector);		//a print function for vector

	vector<double> MeshArray(double Start, double h, double End); //Function that creates a mesh in 1 variable
	
	//Greeks
	double CallDelta(double S,double r,double sig,double K,double T, double b);	//Delta of call option
	double PutDelta(double S,double r,double sig,double K,double T, double b);	//Delta of Put option
	double Gamma(double S,double r,double sig,double K,double T, double b);		//Gamma of call and put options


}


#endif