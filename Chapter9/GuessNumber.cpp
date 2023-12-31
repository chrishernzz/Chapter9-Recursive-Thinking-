#include "GuessNumber.h"

//precondition: going to call the default constructor class
//postcondition: going to then initialize the privates 
GuessNumber::GuessNumber(): randomNumber(0){}

//precondition: going to get the randomNumber 
//postcondition: going to return the private randomNumber
int GuessNumber::getRandomNumber() const {
    return randomNumber;
}
//precondition: going to get the new randomNumber
//postcondition: going to set the private randomNumber with the new randomNumber member
void GuessNumber::setRandomNumber(int newRandomNumber) {
    randomNumber = newRandomNumber;
}

//precondition: going to pass in three arguments (parameters) 
//postcondition: going to then call the private randomNumber, going to ask if the number is right, if number is larger or smaller, then recursive
void GuessNumber::numberGuess(int min, int max, int guessCount){
    randomNumber = rand() % (max - min + 1) + min;

    cout << "\n\tIs your number " << randomNumber<<"? ";
    char choice = inputChar("(Y-yes or N-no): ", static_cast<string>("YN"));
    //preincrement to keep tack of the guesses
    ++guessCount;

    if (toupper(choice) == 'N'){
        cout << "\n\tIs your number larger than " << randomNumber<<"? ";
        char smallOrLarger = inputChar("(Y-yes or N-no): ", static_cast<string>("YN"));
        if (toupper(smallOrLarger) == 'Y'){
            //if statement that checks if the random is greater than the max or equal, if it is error, it cannot be
            if (randomNumber >= max) {
                cout << "\n\tERROR: Guess is out of range!\n";
                return;                                          // STOP or BASE case
            }
            //recursive
            numberGuess(randomNumber + 1, max,guessCount);
        }
        else{
            //same thing here but now for the min
            if (randomNumber <= min) {
                cout << "\n\tERROR: Guess is out of range!\n";
                return;                                         // STOP or BASE case
            }
            //recursive
            numberGuess(min, randomNumber - 1,guessCount);
        }
    }
    else{
        cout << "\n\tNumber of guesses: " << guessCount<<"\n"; // STOP or BASE case
    }

}
