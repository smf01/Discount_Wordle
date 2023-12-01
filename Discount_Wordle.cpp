#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Wordle! Just like the popular game, this program accepts a five-letter input from the user and checks it against a
// randomly-selected word from the NYT-approved Wordle word list. Instead of green, yellow or gray squares telling
// the user if they have any correct letters, this program uses "0" for green (i.e. correct letter, correct location),
// "/" for yellow (correct letter, wrong location), and "X" for gray (incorrect letter). The user has six tries to
// guess the word. This program does not yet account for double letters (i.e. if the word is "aloud" and the user
// guesses "hello," the ouput will read XX///, despite there only being one "l" in "aloud").

void myGame() {

    vector<string> myList;
    string myWord;
    string userGuess;
    string result;
    int guesses = 0;

    ifstream myFile("PATH/TO/wordle.txt");

    while (myFile >> myWord) {
        myList.push_back(myWord);
    }
    
    srand((unsigned int)time(NULL));
    string answerWord = myList[rand() % (myList.size() + 1)];

    while (guesses < 6) {
        cout << "Guess a 5-letter word: ";
        cin >> userGuess;

        cout << "Guess " << guesses + 1 << ": " << userGuess << '\n';

    if (find(myList.begin(), myList.end(), userGuess) == myList.end()) { // "find" ensures the user's guess is a real word that exists in the word list.
        cout << "That wasn't a valid guess! Please enter a 5-letter word, all lower-case." << '\n';
        continue;
    }
    else {
        guesses++; // keep track of how many guesses the user has made
        if (userGuess == answerWord) {
            result += "00000";
            cout << result << '\n';
            cout << "Wow! You guessed the word in " << guesses << " tries!\n";
            break;
        }
        else {
            for (size_t i = 0 ; i < userGuess.length(); i++) { // step through the user's guess and compare each letter to the letters in the answer word.
                if (userGuess[i] == answerWord[i]) {
                    result += "0";
                }
                else if (answerWord.find(userGuess[i]) != std::string::npos) {
                    result += "/";
                }
                else {
                    result += "X";
                }
            }
            cout << result << '\n';
            result = "";
        }
    }
    }

    if (result != "00000") {
        cout << "Darn. You couldn't find the word. It was: " << answerWord << '\n';
    }
}

int main() {
    myGame();
}