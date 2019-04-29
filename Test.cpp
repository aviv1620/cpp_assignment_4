/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {
	
	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}
		
		//my test:
		//empty value
		testcase.setname("test empty value");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("",""), "0,0");
		ConstantChooser cempty{""};
		ConstantGuesser gempty{""};
		testcase.CHECK_EQUAL(play(cempty, gempty, 0, 1), 1); // guesser wins	
		
		//single value
		testcase.setname("test single value");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("1","0"), "0,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("1","1"), "1,0");
		ConstantChooser c1{"1"};
		ConstantGuesser g0{"0"};
		ConstantGuesser g1{"1"};
		testcase.CHECK_EQUAL(play(c1, g1, 1, 1), 1); // guesser wins	
		testcase.CHECK_EQUAL(play(c1, g0, 1, 5), 6); // guesser loses 
		
		//bull
		testcase.setname("test bull");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("00","11"), "0,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("10","11"), "1,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("01","11"), "1,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("11","11"), "2,0");
		ConstantChooser c11{"11"};
		ConstantGuesser g11{"11"};
		testcase.CHECK_EQUAL(play(c11, g11, 2, 1), 1);	// guesser wins
		
		//Pgia
		testcase.setname("test Pgia");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("11","12"), "1,1");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("12","12"), "2,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("21","12"), "0,2");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("22","12"), "1,0");
		ConstantChooser c12{"12"};
		ConstantGuesser g12{"12"};
		testcase.CHECK_EQUAL(play(c12, g12, 2, 1), 1);	// guesser wins
		
		//SmartGuesser two digit
		testcase.setname("test smart SmartGuesser - two digit");
		ConstantChooser c99{"99"};
		ConstantChooser c00{"00"};
		testcase.CHECK_EQUAL(play(c99, smarty, 2, 100)<=10, true);
		
		//SmartGuesser one digit
		testcase.setname("test smart SmartGuesser - one digit");
		ConstantChooser c9{"9"};
		ConstantChooser c0{"0"};
		testcase.CHECK_EQUAL(play(c9, smarty, 1, 100)<=10, true);
		
		//SmartGuesser empty
		testcase.setname("test smart SmartGuesser - Gues empty");
		testcase.CHECK_EQUAL(play(cempty, smarty, 0, 100)<=10, true);

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

