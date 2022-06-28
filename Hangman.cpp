#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

const int SIZE = 30;

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::tolower;
using std::string;
using std::ifstream;
using std::ifstream;
using std::left;
using std::setw;
//using std::fixed;
//using std::setprecision;

string getWord();
void printBoard(int);
void printBlanks(string, string);
bool isWon(string, string);
int randomNumber(int);

string wordList[SIZE] = { "" };

int main()
{
	//open wordlist.txt and copy the words to wordList array
	string temp;

	ifstream inFile("wordlist.txt");
	if (!inFile)
	{
		cout << "Error: -1 //Wordlist not found. (wordlist.txt)" << endl;
	}
	//inFile.ignore(255, '\n'); To ignore the header

	int i = 0;
	while (!inFile.eof())
	{
		inFile >> temp;
		wordList[i] = temp;
		i++;
	}
	inFile.close();

	//variables
	int playerLives = 7;

	char c;//l or w (letter or word) switch case at line 86
	char guess = '\n';//if letter whas chosen it stores the letter 
	string sGuess = "";//stores what the player types in

	string word = getWord();//target word

	string guessed = "";//guessed letters
	string guessedWords = "";//guesses words

	while (playerLives > 0)
	{
		if (isWon(word, guessed))
		{
			cout << "\n...................................You Won...................................";
			return 0;
		}

		printBoard(playerLives);
		cout << endl << endl;

		printBlanks(word, guessed);

		cout << "\n\nLetters Guessed: " << guessed << endl;

		cout << "\nWords Guessed:\n" << guessedWords << endl;

		cout << "\n\nEnter l to enter a letter guess,enter w to enter a word guess: ";

		cin >> c;
		c = tolower(c);

		switch (c)
		{
			case 'l'://letter
			{
				cout << "\n\nEnter a letter(lowercase): ";
				cin >> sGuess;

				if (sGuess.length() > 1)
				{
					cout << "You didn't enter a letter." << endl;
					continue;
				}

				guess = sGuess[0];
				guessed += guess;

				if (word.find(guess) != -1)//if at least one letter is guessed correctly 
				{
					continue;
				}
				else
				{
					playerLives--;
				}
				break;
			}
			case 'w'://word
			{
				cout << "\n\nEnter a word(lowercase): ";
				cin >> sGuess; 

				if (sGuess.length() != word.length())
				{
					if (sGuess.length() > word.length())
					{
						cout << "Your guess has to much letters\n\n";
					}
					else
					{
						cout << "Your guess doesn't have enough letters\n\n";
					}
					continue;
				}

				guessedWords += sGuess + "\n";

				if (sGuess == word)//if the word is guessed correctly
				{
					guessed += sGuess;
					continue;
				}
				else
				{
					playerLives--;
				}
				break;
			}
			default:
			{
				cout << "\n\nPlease enter l or w.";
				continue;
			}
		}
	}
	printBoard(playerLives);
	cout << "...................................You Lost...................................";

	return 0;
}

string getWord()
{
	string random = wordList[randomNumber(SIZE)];
	return random;
}

void printBoard(int lives)
{
	switch (lives)
	{
		case 0:
		{
			cout << "\t\t\t|------|" << endl;
			cout << "\t\t\t|      0" << endl;
			cout << "\t\t\t|     /|\\" << endl;
			cout << "\t\t\t|      |" << endl;
			cout << "\t\t\t|     / \\" << endl;

			cout << "\t\t\t|" << endl;
			cout << "\t\t\t|_" << endl;
			break;
		}
		case 1:
		{
			cout << "\t\t\t|------|" << endl;
			cout << "\t\t\t|      0" << endl;
			cout << "\t\t\t|     /|\\" << endl;
			cout << "\t\t\t|      |" << endl;
			cout << "\t\t\t|       \\" << endl;

			cout << "\t\t\t|" << endl;
			cout << "\t\t\t|_" << endl;
			break;
		}
		case 2:
		{
			cout << "\t\t\t|------|" << endl;
			cout << "\t\t\t|      0" << endl;
			cout << "\t\t\t|     /|\\" << endl;
			cout << "\t\t\t|      |" << endl;
			cout << "\t\t\t|      " << endl;

			cout << "\t\t\t|" << endl;
			cout << "\t\t\t|_" << endl;
			break;
		}
		case 3:
		{
			cout << "\t\t\t|------|" << endl;
			cout << "\t\t\t|      0" << endl;
			cout << "\t\t\t|     /|\\" << endl;
			cout << "\t\t\t|      " << endl;
			cout << "\t\t\t|      " << endl;

			cout << "\t\t\t|" << endl;
			cout << "\t\t\t|_" << endl;
			break;
		}
		case 4:
		{
			cout << "\t\t\t|------|" << endl;
			cout << "\t\t\t|      0" << endl;
			cout << "\t\t\t|      |\\" << endl;
			cout << "\t\t\t|      " << endl;
			cout << "\t\t\t|      " << endl;

			cout << "\t\t\t|" << endl;
			cout << "\t\t\t|_" << endl;
			break;
		}
		case 5:
		{
			cout << "\t\t\t|------|" << endl;
			cout << "\t\t\t|      0" << endl;
			cout << "\t\t\t|      |" << endl;
			cout << "\t\t\t|      " << endl;
			cout << "\t\t\t|      " << endl;

			cout << "\t\t\t|" << endl;
			cout << "\t\t\t|_" << endl;
			break;
		}
		case 6:
		{
			cout << "\t\t\t|------|" << endl;
			cout << "\t\t\t|      0" << endl;
			cout << "\t\t\t|      " << endl;
			cout << "\t\t\t|      " << endl;
			cout << "\t\t\t|      " << endl;

			cout << "\t\t\t|" << endl;
			cout << "\t\t\t|_" << endl;
			break;
		}
		case 7:
		{
			cout << "\t\t\t|------|" << endl;
			cout << "\t\t\t|    " << endl;
			cout << "\t\t\t|      " << endl;
			cout << "\t\t\t|      " << endl;
			cout << "\t\t\t|      " << endl;

			cout << "\t\t\t|" << endl;
			cout << "\t\t\t|_" << endl;
			break;
		}
	}
}

bool isWon(string chosen, string guessed)
{
	int chosenSize = chosen.size();
	string c = "";
	for (int i = 0; i < chosenSize; i++)
	{
		if (guessed.find(chosen[i]) != -1)
		{
			c += chosen[i];
		}
	}
	return c == chosen;
}

void printBlanks(string chosen, string guessed)
{
	int chosenSize = chosen.size();
	for (int i = 0; i < chosenSize; i++)
	{
		if (guessed.find(chosen[i]) != -1)
		{
			cout << chosen[i] << " ";
		}
		else
		{
			cout << "_ ";
		}
	}
}

int randomNumber(int limit)
{
	srand(time(NULL));
	int random = rand() % limit + 1;
	return random;
}