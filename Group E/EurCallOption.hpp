//EurCallOptio.hpp
//derived class of european options.

#ifndef EurCallOption_hpp
#define EurCallOption_hpp

#include <iostream>
#include <string>
#include <cmath>

#include "EuropeanOptions.hpp"
#include "stdlib.h"
using namespace std;

class EurCallOption : public EuropeanOptions
{
private:
	string optType;	// Option name (call) is constant. But instead of making it const,
					//declared it as private so that it is not modifyable by users. 
					//No modifying member functions
public:
	//Constructors and destructors
	EurCallOption();
	EurCallOption(const EurCallOption & o2);
	virtual ~EurCallOption();

	//Assignment operator
	EurCallOption& operator = (const EurCallOption& option2);

	//Accessing Functions	//Normal inline 
	string TypeOfOption() const;

	//Member functions				//Const functions do not change the value of data member
	double Price() const;			//To determine call option price
	double Price(const struct OptionData& Opt, double U);	//To determine call option price using Struct
	double ParityPrice() const;		//To determine call option price using put-call parity
	bool Arbitrage();				//To determine if an arbitrage opportunity exist

	//Greeks
	double Delta() const;						//To determine delta of call option
	double DeltaApprox(double h) const;			//To approximate delta of call option
	double OptionGammaApprox(double h) const;	//To approximate gamma of call option

};
//Normal inline
inline string EurCallOption::TypeOfOption() const { return optType; }

#endif