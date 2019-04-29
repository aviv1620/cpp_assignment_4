#include "calculate.hpp"

namespace bullpgia {
	
	ostream& operator<< (ostream& os, const Replay& c) {
		os << c.bull << ',' << c.pgia;
		return os;
	}
	
	Replay calculateBullAndPgia(const string& choice,const string& guess){			
		uint CL = choice.length(); // CL = choice length.
		uint GL = guess.length(); // GL = guess length.
		
		if( CL != GL) //Illegal guess and choice.
			throw string( "choice length is " + to_string(CL) + " but guess length is " + to_string(GL) );
		
		//calculate.
		Replay replay;
		
		for(uint i=0; i < CL ;i++){
			//cout << choice[i] << " result " << choice.find(guess[i]) << endl;
			if(guess[i] == choice[i])//have Bull.
				replay.bull++;
			else if( choice.find(guess[i]) != string::npos)//have Pgia. //have problem with digit 0;
				replay.pgia++;
		}
		
		return replay;
	}
	
	
}