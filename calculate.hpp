#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bullpgia {
	
	/** store bull and Pgia.
		initialized zero.**/
	struct Replay{
		uint bull;
		uint pgia;
		string choice;	
		Replay():bull(0),pgia(0){			
		}
		
		 friend ostream& operator<< (ostream& os, const Replay& c);
	};
	
	
	
	Replay calculateBullAndPgia(const string& choice,const string& guess);
	
	
	
	
	
	
}


