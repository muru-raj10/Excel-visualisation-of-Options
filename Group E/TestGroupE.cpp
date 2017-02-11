//Test file for Group E. Similar to group A. We want the output as an excel file. 
//Batch 1 is stock options. Let C and P denote calls and puts for each batch. Batch1C is a call option for batch 1
//We will only be using Batch 1.
//Required to add the folder "Murugaraj Odiathevar Level 9 HW submission" under additional
//include libraries under project properties, VC++Directories


#include "EuropeanOptions.hpp"
#include "Global.hpp"
#include "OptionData.hpp"
#include "EurCallOption.hpp"
#include "EurPutOption.hpp"

#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"

#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <string>

using namespace std;
using namespace global;



int main()
{
	EurCallOption Batch1C;				//Testing Batch 1C, Batch 1 call option

	Batch1C.StockPrice(60.0);			
	Batch1C.Expiry(0.25);
	Batch1C.InterestRate(0.08);
	Batch1C.Volatility(0.3);
	Batch1C.Strike(65.0);
	Batch1C.CostOfCarry(0.08);

	cout<<"Option type: "<<Batch1C.TypeOfOption()<<endl;	//To test and call option type.
	cout<< Batch1C.Price() <<endl;		//Output price of call option
	cout<<Batch1C.ParityPrice()<<endl;	//Output price of call option from put-call parity. To be the same.	
	cout<<"Aribitrage opportunities available: "<<Batch1C.Arbitrage()<<endl;//Check for arbitrage opportunities

	EurPutOption Batch1P;				//Testing Batch 1P

	Batch1P.StockPrice(60.0);
	Batch1P.Expiry(0.25);
	Batch1P.InterestRate(0.08);
	Batch1P.Volatility(0.3);
	Batch1P.Strike(65.0);
	Batch1P.CostOfCarry(0.08);

	cout<< Batch1P.Price() <<endl;
	cout<< Batch1P.ParityPrice()<<endl;
	cout<<"Aribitrage opportunities available: "<<Batch1P.Arbitrage()<<endl;

	/////////////////////////////////////////////////////////////////////////////////////////
	//Mesh size for underlying Stock price. Let the _S indicate it is a mesh for stock price
	double h_S=0;
	double Start_S=0;
	double End_S=0;
	 //user input
	cout<< "Enter Starting value for underlying stock price S: "<<endl;
	cin>> Start_S;

	cout<< "Enter Mesh Size: "<<endl;
	cin>> h_S ; 

	cout<< "Enter Ending value for S: "<<endl;
	cin>> End_S;

	vector<double> mesh_S = MeshArray(Start_S,h_S,End_S);
	cout<<"Your mesh for S"<<endl;
	print(mesh_S);

	//Option prices at each mesh point of underlying Stock price S for Batch 1. Call and Put
	vector<double> OptionPrice_B1C_S;	//Option price of Batch 1 call, under mesh of stock prices

	for (int i= 0; i< mesh_S.size(); ++i)
	{
		OptionPrice_B1C_S.push_back(CallPrice(mesh_S[i],0.08,0.3,65,0.25,0.08)); 
	}
	cout<<"Call Option prices for Batch 1 along mesh points of S"<<endl;
	print(OptionPrice_B1C_S);

	vector<double> OptionPrice_B1P_S;	//option price of Batch 1 put, under mesh of stock prices

	for (int i= 0; i< mesh_S.size(); ++i)
	{
		OptionPrice_B1P_S.push_back(PutPrice(mesh_S[i],0.08,0.3,65,0.25,0.08)); 
	}
	cout<<"Put Option prices for Batch 1 along mesh points of S"<<endl;
	print(OptionPrice_B1P_S);

	//We print the option price for call and put above to check with the excel output

	long N = mesh_S.size();

	// Create abscissa x array
	Vector<double, long> x(N,0.0);	//double is data type, long is index type
	
	x[x.MinIndex()] = mesh_S[0];
	x[x.MaxIndex()] = mesh_S[N-1];
	for (long j = x.MinIndex()+1; j <= x.MaxIndex()-1; ++j)
	{
		x[j] = x[j-1] + h_S;
	}

	Vector<double, long> vec1(N,0.0);		
	for (long j = vec1.MinIndex(); j <= vec1.MaxIndex(); ++j)
	{
		vec1[j] = OptionPrice_B1C_S[j];
	}

	Vector<double, long> vec2(N,0.0);
	for (long j = vec2.MinIndex(); j <= vec2.MaxIndex(); ++j)
	{
		vec2[j] = OptionPrice_B1P_S[j];
	}

	try 
	{
		printPairExcel(x,vec1, vec2, 
						string("V against S"), string("Underlying Price, S"), string("Option Price, V"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}


}