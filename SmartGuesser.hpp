#include "Guesser.hpp"


class SmartGuesser: public bullpgia::Guesser {
		string choice;
	
	public:
		SmartGuesser(): choice("1234"){}
		string guess() override;
		void startNewGame(uint len) override;
	
		void learn(bullpgia::Replay reply) override;
};