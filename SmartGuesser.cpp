#include "SmartGuesser.hpp"

std::string SmartGuesser::guess(){	
	return choice;
}

void SmartGuesser::startNewGame(uint len){
	Guesser::startNewGame(len);
	choice = string(len,'0');				
}

void SmartGuesser::learn(bullpgia::Replay reply){
	this->choice = reply.choice;
}
