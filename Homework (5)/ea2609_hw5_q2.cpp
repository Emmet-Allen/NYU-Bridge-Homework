#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	
	srand(time(0));

	int gameNumber, userNumber;
	int maxNumber, minNumber, guessesNumber; 
	bool gameOver; 

	gameNumber = ((rand() % 100) + 1);
	minNumber = 1;
	maxNumber = 100;
	guessesNumber = 5; //5 total guesses
	gameOver = false; 

	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;


	while (gameOver == false && guessesNumber > 0) {

		
		cout << "Range:" << "[" << minNumber << ", " << maxNumber << "], Number of guesses left: " << guessesNumber << endl;
		guessesNumber-= 1; //Decrements guesses from guessNumber on... e.g. 5, 4, 3,...
		cin >> userNumber;
		

		if (userNumber > gameNumber) {
			cout << "Wrong! My number is smaller!" << endl;
			//If the userNumber is less than the maxNumber in the range, reassign maxNumber to 1 minus userNumber
				if (userNumber < maxNumber) {
					maxNumber = userNumber - 1;
				}
				cout << endl;
		}

		else if (userNumber < gameNumber) {
			cout << "Wrong! My number is bigger!" << endl;
			//If the userNumber is greater than the maxNumber in the range, reassign maxNumber to 1 plus userNumber
				if (userNumber > minNumber) {
				minNumber = userNumber + 1;
				}
				cout << endl;
		}

		// Congrats Message 
		else if(userNumber == gameNumber) {
			gameOver = true;
			cout << "Congrats! You guessed my number in " << guessesNumber << " guesses." << endl; 
		}

	}
	
		// Logic for Game Over Message
		if(guessesNumber == 0){
		gameOver = true; 
		cout << "Out of guesses! My number is: " << gameNumber << endl;
		}


		return 0;

}