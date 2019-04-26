#include "Guesser.hpp"


class SmartGuesser: public bullpgia::Guesser {
	
	public:string guess() override {
		std::string r="";
		for (uint i=0; i<this->length; ++i) {
			char c = '0' + (rand()%10);
			r += c;
		}
		return r;
	}
};