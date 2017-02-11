//EurCallOption.cpp
//To declare functions from EurCallOption.hpp

#ifndef EurCallOption_cpp
#define EurCallOption_cpp

#include <iostream>
#include <string>
#include <cmath>

#include "stdlib.h"
#include "EurCallOption.hpp"
#include "EuropeanOptions.hpp"
#include "Global.hpp"
#include "OptionData.hpp"
using namespace std;
using global::CallPrice;
using global::PutPrice;
using global::CallDelta;

EurCallOption:: EurCallOption() : EuropeanOptions(), optType("C")	//Call option 
{
	//Default Constructor. 
}

EurCallOption::EurCallOption(const EurCallOption& o2) : EuropeanOptions(o2), optType(o2.optType)
{ 
	//Copy constructor
}

EurCallOption::~EurCallOption()	//Destructor
{

}

EurCallOption& EurCallOption::operator = (const EurCallOption& option2)	//Assigmnent operator
{
	if (this == &option2) return *this;
	{
		EuropeanOptions::operator=(option2);
		optType=option2.optType;				
	}
	return *this;
}

double EurCallOption::Price() const	//Use global function for Call option Price
{
	cout<<"Call Option Price: ";
	return CallPrice(S,r,sig,K,T,b);
}

double EurCallOption::ParityPrice() const	//Use put-call parity formula
{
	cout << "Call option price from Put-Call Parity: ";
	return PutPrice(S,r,sig,K,T,b)+S-K*exp(-r*T);
}

bool EurCallOption::Arbitrage() 
{
	double epsilon = CallPrice(S,r,sig,K,T,b)-PutPrice(S,r,sig,K,T,b)-S+K*exp(-r*T);
	
	return (epsilon>0.00001);		//To take care of rounding errors 
}


double EurCallOption::Price(const struct OptionData& Opt, double U)
{
	//Assign values of the struct to an Object of EurCallOption and pass it to the function in main
	r=Opt.r;
	sig=Opt.sig;
	K=Opt.K;
	T=Opt.T;
	b=Opt.b;

	//cout << "Call option price: ";
	return CallPrice(U,r,sig,K,T,b);
}

//Use global function for call option delta
double EurCallOption::Delta() const
{
	cout<<"Call Option Delta: ";
	return CallDelta(S,r,sig,K,T,b);
}

//Function to approximate Delta
double EurCallOption::DeltaApprox(double h) const
{
	cout<<"Approximate value for Call Delta is: ";
	return (CallPrice(S+h,r,sig,K,T,b)-CallPrice(S-h,r,sig,K,T,b))/(2*h);
}

//Function to approximate Call option gamma
double EurCallOption::OptionGammaApprox(double h) const
{
	cout<<"Approximate value for Gamma is: ";
	return (CallPrice(S+h,r,sig,K,T,b)-(2*CallPrice(S,r,sig,K,T,b))+CallPrice(S-h,r,sig,K,T,b))/(h*h);
}



#endif