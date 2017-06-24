/* **************************************************
 * Developed by: Claire "Boof" Sharp
 * Description: This is a simple executable
 * library of basic utilities. It is designed to be
 * extendable.
 * 
 * Current functionalities -- 
 * Basic calculations
 * Simple Hi-Lo game with variable difficulty
 * 
 * 
 * Goals --
 * Basic file management
 * More simple games
 * Interfacing with other applications
 * Simple graphical UI implementation
 * 
 * This file is provided as free and publicly available
 * software. Feel free to use and modify it at your
 * own discretion.
 ************************************************** */

#include <iostream>
#include <string>
#include <random>
/* BEGIN MATH FUNCTIONS */
/* Function for managing basic arithmetic equations. */
float calc(std::string operation, float x, float y){
	if(operation=="add") {return (x+y);}
	if(operation=="sub") {return (x-y);}
	if(operation=="mult") {return (x*y);}
	if(operation=="div") {return (x/y);}
	return 0;
}

/* Function for finding common denominators. */
int denom(std::string operation, int x, int y){
	if(operation=="gcd") {
		for(int n=x;n>0;n--){
			if(((x%n)==0)&&((y%n)==0)){return n;}
		}
	}
	if(operation=="lcd") {
		for(int n=2;n<x;n++){
			if(((x%n)==0)&&((y%n)==0)){return n;}
		}
		return 1;
	}
	return 0;
}

/* Function for calculating exponents. */
int exp(int x, int y) {
	int z(1);
	for(int n(0);n<y;n++) {z*=x;}
	return z;
}
/* END MATH FUNCTIONS */

/* GAMES N STUFF */
void hiLoGame() {
	int userGuess(0), randNum(0), diffMod(0);
	std::random_device rnGen;
	std::string diff("null");
	while(diff=="null"){
		std::cout << "Choose a difficulty! (easy/med/hard)\n";
		std::cin >> diff;
		if(diff=="easy"){std::uniform_int_distribution<int> rnDist(1,16); diffMod=16; randNum = rnDist(rnGen);}
		else if(diff=="med"){std::uniform_int_distribution<int> rnDist(1,64); diffMod=64; randNum = rnDist(rnGen);}
		else if(diff=="hard"){std::uniform_int_distribution<int> rnDist(1,256); diffMod=256; randNum = rnDist(rnGen);}
		else{std::cout << "ERR: " << diff << " -- invalid command!\n"; diff="null";}
	}
	std::cout << "Guess a number! (1-" << diffMod <<")\n";
	while (userGuess != randNum) {
		std::cin >> userGuess;
		if(userGuess>randNum){std::cout << "Too high! Guess again: \n";}
		else if(userGuess<randNum){std::cout << "Too low! Guess again: \n";}
		else{std::cout << "Congrats! " << randNum << " is correct!\n\n"; break;}
	}
}
/* NOMORE GAMES */

int main() {
	/* Initializes and runs the interface. */
	std::string userInput("help");
	while(userInput != "quit"){
		std::cout << "Greetings!\nChoose a program to run: ";
		std::cin >> userInput;
		
		/* Mathematic operations management. */
		if(userInput=="calc"){
			std::cout << "Choose your operation.\n" 
			<< "Valid operations (case sensitive): add sub mult div gcd lcd exp\n";
			std::cin >> userInput;
			/* Arithmetic operation handler. */
			if(userInput=="add"||userInput=="sub"||userInput=="mult"||userInput=="div"){
				float x(0), y(0);
				std::cout << "Choose your first #\n";
				std::cin >> x;
				std::cout << "Choose your second #\n";
				std::cin >> y;
				if(userInput=="div"&&y==0){std::cout << "ERR: Can't divide by 0!\n";}
				else{std::cout << "The result is: " << calc(userInput,x,y) << "\n\n";}
			}
		
			else if(userInput=="gcd"||userInput=="lcd"){
				int x(0), y(0);
				std::cout << "Choose your first #\n";
				std::cin >> x;
				std::cout << "Choose your second #\n";
				std::cin >> y;
				std::cout << "The result is: " << denom(userInput,x,y) << "\n\n";
			}
		
			/* Exponential operation management. */
			else if(userInput=="exp"){
				int x(0), y(0);
				std::cout << "Choose your base #: ";
				std::cin >> x;
				std::cout << "Choose your exponent: ";
				std::cin >> y;
				std::cout << "The result is: " << exp(x,y) << "\n\n";
			}
			
			else{std::cout << "ERR: " << userInput << " -- invalid command!\n";}
		}
		
		else if(userInput=="game"){
			std::cout << "Choose a game! (case sensitive)\n"
			<< "Currently available: hi-lo\n";
			std::cin >> userInput;
			
			if(userInput=="hi-lo"){hiLoGame();}
			else{std::cout << "ERR: " << userInput << " -- invalid command!";}
		}
		
		/* Enables user to end the program using the interface. */
		else if(userInput=="quit"){break;}
		
		/* Defaults to running the 'help' command. */
		else {
			std::cout << "Valid commands (case sensitive):" << std::endl;
			std::cout << "calc game help quit\n\n";
		}
	}
	return 0;
}
