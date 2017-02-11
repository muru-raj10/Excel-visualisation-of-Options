//EuropeanOptions.hpp
//Abstract Base Class for European call and put options

#ifndef EuropeanOptions_hpp
#define EuropeanOptions_hpp

#include <iostream>
#include <string>
#include <cmath>

#include "stdlib.h"
using namespace std;

class EuropeanOptions
{
protected:

	//Protected functions to initialise variables and copy variables. Accessible by derived class
	void init();				// To Initialise all default values
	void copy(const EuropeanOptions& o2);	//To copy the values

	//Data members for an option. Protected members to be accessible by derived class
	double S;		// Stock Price 
	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double b;		// Cost of carry

public:

	//Constructors and destructors
	EuropeanOptions();
	EuropeanOptions(const EuropeanOptions & o2);
	virtual ~EuropeanOptions();

	//Assignment operator
	EuropeanOptions& operator = (const EuropeanOptions& option2);

	//Accessing functions	//Normal inline functions
	double StockPrice() const;
	double InterestRate() const;
	double Volatility() const;
	double Strike() const;
	double Expiry() const;
	double CostOfCarry() const;

	//Modifiers //Default inline functions
	void StockPrice(double newS) {S=newS;};
	void InterestRate(double newr) {r=newr;};
	void Volatility(double newsig) {sig=newsig;};
	void Strike(double newK) {K=newK;};
	void Expiry(double newT) {T=newT;};
	void CostOfCarry(double newb) {b=newb;};

	//Using polymorphism to define different behaviours for functions
	//Other member function(Pure virtual functions since Price will be overridden by either put price or call price)
	virtual double Price() const=0;					//Price function to determine the price in derived class
	virtual double Price(const struct OptionData& Opt, double U)=0;		//To determine price using Struct in derived class

	//Function to determine put price given call price or vice versa
	virtual double ParityPrice() const=0;		
	virtual bool Arbitrage()=0;			//To tell if there are any arbitrage opportunities

	//Greeks
	virtual double Delta() const=0;
	virtual double OptionGamma() const;		//Not a pure virtual function as Gamma is similar for both calls and puts

	//Formulas for approxmiating Greeks
	virtual double DeltaApprox(double h) const=0;			
	virtual double OptionGammaApprox(double h) const=0;


};
//Normal inline functions
inline double EuropeanOptions::StockPrice() const {return S; }
inline double EuropeanOptions::InterestRate() const { return r; }
inline double EuropeanOptions::Volatility() const { return sig; }
inline double EuropeanOptions::Strike() const { return K; }
inline double EuropeanOptions::Expiry() const { return T; }
inline double EuropeanOptions::CostOfCarry() const { return b; }


#endif