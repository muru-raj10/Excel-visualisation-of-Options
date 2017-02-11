//EuropeanOptions.cpp
//Defining Functions of EuropeanOptions.hpp

#ifndef EuropeanOptions_cpp
#define EuropeanOptions_cpp

#include <iostream>
#include <string>
#include <cmath>

#include "stdlib.h"
#include "EuropeanOptions.hpp"
#include "Global.hpp"
#include "OptionData.hpp"
using namespace std;
using global::Gamma;

void EuropeanOptions::init()	//Function to inlitialise
{
	S=60.0;
	r = 0.08;
	sig= 0.3;
	K = 65.0;
	T = 0.25;
	b = r;			// Black and Scholes stock option model (1973)
}

void EuropeanOptions::copy( const EuropeanOptions& o2)	//Function to copy
{
	S=o2.S;
	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	b	= o2.b;
	
}


EuropeanOptions::EuropeanOptions()	//Default European option
{
	init();
}

EuropeanOptions::EuropeanOptions(const EuropeanOptions& o2)
{ 
	// Copy constructor
	copy(o2);
}

EuropeanOptions::~EuropeanOptions()
{
	//Destructor
}

EuropeanOptions& EuropeanOptions::operator = (const EuropeanOptions& option2)	//Assignment operator
{
	if (this == &option2) return *this;

	copy (option2);

	return *this;
}

double EuropeanOptions::OptionGamma() const
{
	cout<<"Option Gamma: ";
	return Gamma(S,r,sig,K,T,b);		//Implement global function
}


#endif