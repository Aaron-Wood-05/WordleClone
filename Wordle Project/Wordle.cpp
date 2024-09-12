#include "Wordle.h"


string randomWord()
{
    ifstream iFile;
    string keyWord = "";
    int randomNum = 0;

    srand(time(0));

    randomNum = rand() % 12973;

    cout << "Random number: " << randomNum << endl; //testing random

    iFile.open("Words.txt");

    if(iFile.is_open())
    {
        for(int i = 0; i < randomNum; i++)
        {
             getline(iFile, keyWord);
        }
    }
    else
    {
        cout << "File could not properly be opened" << endl;
    }

    cout << "Key word: " << keyWord << endl; //testing the parsing to see if it got the word
    
    return keyWord;

}

void compareWord(string keyWord, string userWord)
{
   string temp = "-----";
   bool matched[5] = {false};
   char currentLetter = '-';

   for (int i = 0; i < 5; i++)
    {
        if (userWord[i] == keyWord[i])
        {
            temp[i] = keyWord[i];
            matched[i] = true; // Mark this letter as matched to prevent it from being counted twice
        }
    }

   for(int i = 0; i < 5; i++)
   {
        if(!matched[i]) //if the current key's letter  we're looking at is NOT matched 
        {
            for(int j = 0; j < 5; j++)
            {
                if(!matched[j] && (userWord[i] == keyWord [j])) //if the letter we're looking at isn't matched AND the userword at i is SOMEWHERE in keyword(j) 
                {
                    temp[i] = tolower(userWord[i]);
                }
            }     
        }
   }

   cout << "Here is the result of your guess: " << temp << endl << endl;

}

bool isUpperCheck(string userWord)
{
    for(int i = 0; i < 5; i++)
    {
        if(islower(userWord[i]))
        {
            return false;
        }
    }

    return true;
}

