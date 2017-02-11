//EurPutOption.cpp
//To declare functions from EurPutOption.hpp

#ifndef EurPutOption_cpp
#define EurPutOption_cpp

#include <iostream>
#include <string>
#include <cmath>

#include "stdlib.h"
#include "EurPutOption.hpp"
#include "EuropeanOptions.hpp"
#include "Global.hpp"
#include "OptionData.hpp"
using namespace std;
using global::CallPrice;
using global::PutPrice;
using global::PutDelta;

EurPutOption:: EurPutOption() : EuropeanOptions(), optType("P")	//Call option //Default Constructor
{

}

EurPutOption::EurPutOption(const EurPutOption& o2) : EuropeanOptions(o2), optType(o2.optType)
{ 
	//Copy constructor
}

EurPutOption::~EurPutOption()	//Destructor
{
	
}

EurPutOption& EurPutOption::operator = (const EurPutOption& option2)	//Assignment operator
{
	if (this == &option2) return *this;
	{
		EuropeanOptions::operator=(option2);
		optType=option2.optType;
	}
	return *this;
}

double EurPutOption::Price() const		//Use global function for put option price
{
	cout << "Put option price: ";
	return PutPrice(S,r,sig,K,T,b);
}

double EurPutOption::ParityPrice() const	//Use put-call parity formula
{
	cout << "Put option price from Put-Call Parity: ";
	return CallPrice(S,r,sig,K,T,b)+K*exp(-r*T)-S;
}

bool EurPutOption::Arbitrage() 
{
	double epsilon = PutPrice(S,r,sig,K,T,b)-CallPrice(S,r,sig,K,T,b)-K*exp(-r*T)+S;

	return (epsilon>0.00001);		//To take care of rounding errors 
}

double EurPutOption::Price(const struct OptionData& Opt, double U)
{
	//Assign values of the struct to an Object of EurPutOption and pass it to the function in main
	r=Opt.r;
	sig=Opt.sig;
	K=Opt.K;
	T=Opt.T;
	b=Opt.b;

	//cout << "Put option price: ";
	return PutPrice(U,r,sig,K,T,b);
}

double EurPutOption::Delta() const	//Use global function for put option delta
{
	cout<<"Put Option Delta: ";
	return PutDelta(S,r,sig,K,T,b);
}

double EurPutOption::DeltaApprox(double h) const	//Function to approximate Delta
{
	cout<<"Approximate value for Put Delta is: ";
	return (PutPrice(S+h,r,sig,K,T,b)-PutPrice(S-h,r,sig,K,T,b))/(2*h);
}

double EurPutOption::OptionGammaApprox(double h) const	//Function to approximate Call option gamma
{
	cout<<"Approximate value for Gamma is: ";
	return (PutPrice(S+h,r,sig,K,T,b)-(2*PutPrice(S,r,sig,K,T,b))+PutPrice(S-h,r,sig,K,T,b))/(h*h);
}


#endif