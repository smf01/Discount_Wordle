# Discount_Wordle
A simple C++ version of Wordle.

Just like the popular game, this program accepts a five-letter input from the user and checks it against a
randomly-selected word from the NYT-approved Wordle word list. Instead of green, yellow or gray squares telling
the user if they have any correct letters, this program uses "0" for green (i.e. correct letter, correct location),
"/" for yellow (correct letter, wrong location), and "X" for gray (incorrect letter). The user has six tries to
guess the word. This program does not yet account for double letters (i.e. if the word is "aloud" and the user
guesses "hello," the ouput will read XX///, despite there only being one "l" in "aloud").

Download the .cpp and .txt files. The only change that should need to be made is the path to where you save
wordle.txt on line 27.
