#pragma once
#include <string>
#include "calculate.hpp"

namespace bullpgia{
	class Guesser{
		public:
			virtual std::string guess() = 0;
			
			virtual void startNewGame(uint len){
				length = len;
				
			}
			
			virtual void learn(Replay reply){}
			
		protected:
			uint length;
			
			
	};
	
}