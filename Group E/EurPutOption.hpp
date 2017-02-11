//EurPutOption.hpp
//Derived class of EuropeanOptions. Generic inheritance

#ifndef EurPutOption_hpp
#define EurPutOption_hpp

#include <iostream>
#include <string>
#include <cmath>

#include "EuropeanOptions.hpp"
#include "stdlib.h"
using namespace std;

class EurPutOption : public EuropeanOptions
{
private:
	string optType;	// Option name (call) is constant. But instead of making it const,
					//declared it as private so that it is not modifyable by users. 
					//No modifying member functions

public:
	
	//Constructors and destructors
	EurPutOption();
	EurPutOption(const EurPutOption & o2);
	virtual ~EurPutOption();

	//Assignment operator	 
	EurPutOption& operator = (const EurPutOption& option2);

	//Accessing Functions	//Normal inline 
	string TypeOfOption() const;

	//Member functions					//Const functions do not change the value of data member
	double Price() const;				//To determine Put option price
	double Price(const struct OptionData& Opt, double U);	//To determine Put option price using Struct
	double ParityPrice() const;			//To determine put option price using put-call parity
	bool Arbitrage();					//To determine if an arbitrage opportunity exist

	//Greeks
	double Delta() const;						//To determine delta of put option
	double DeltaApprox(double h) const;			//To approximate delta of put option
	double OptionGammaApprox(double h) const;	//To approximate gamma of put option
};
//Normal Inline function
inline string EurPutOption::TypeOfOption() const { return optType; }

#endif