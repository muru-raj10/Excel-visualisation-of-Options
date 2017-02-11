//OptionData.hpp
//To define struct to input option data

#ifndef OptionData_hpp
#define OptionData_hpp

//Encapsulate all data in one place with the exception of Underlying Stock price S
struct OptionData
{//Option data + behaviour(all public)
	double r;
	double sig;
	double K;
	double T;
	double b;
};


#endif