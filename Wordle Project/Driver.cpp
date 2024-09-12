#include "Wordle.h"

int main()
{
    string keyWord = "";
    string userWord = "";
    int count = 0;
   

    keyWord = randomWord();

    cout << "Welcome to Wordle! Guess what the 5 letter word is!" << endl << endl;
    cout << "Here are the rules!: " << endl;
    cout << "\t 1. If an uppercase letter is printed, you guessed the right letter in the right spot! " << endl << endl;
    cout << "\t 2. If a lowecase letter is printed, you guessed the right letter in the wrong spot! " << endl << endl;
    cout << "\t 3. If a dash is printed, that letter is not within the key word. " << endl << endl;

    while(count < 7)
    {   
        cout << "Guess what the word is (enter your answer in uppercase): ";
        getline(cin, userWord);
        
        while(!isUpperCheck(userWord) || (userWord.length() != 5))
        {
            cout << "The word you entered is not upper case or it is not 5 letters, please re-enter your word: ";
            getline(cin, userWord);
            cout << endl;
        }

        cout << endl;

        if(userWord == keyWord)
        {
            cout << "You won! The word was " << keyWord << "!" << endl;
            return 0;
        }


        compareWord(keyWord,userWord);

        count++;

        cout << "You have " << 6 - count << " guesses left!" << endl;
    }

    cout << "AH rats, you're out of guesses! Try again another time champ." << endl;

    return 0;
}