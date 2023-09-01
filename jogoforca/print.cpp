#include <iostream>
#include "utils.hpp"
#include "validation.hpp"
#include "print.hpp"

using namespace std;

namespace Forca {
	void footer(const string& secret_word, const map<char, bool>& hit_letters)
	{
		cout << "Game over" << endl;
		cout << "The secret word was: " << secret_word << endl;

		if (not_hit(secret_word, hit_letters))
		{
			cout << "You lose" << endl;
		}
		else
		{
			cout << "You win" << endl;

			add_word();
		}
	}

	void print_letter(const string& secret_word, const map<char, bool>& hit_letters)
	{
		for (char letter : secret_word)
		{
			if (hit_letters.find(letter) != hit_letters.end())
			{
				cout << letter << " ";
			}
			else
			{
				cout << "_ ";
			}
		}
		cout << endl;
	}

	void print_wrong_guesses(const array<char, 5>& wrong_guesses)
	{
		if (wrong_guesses.size() > 0)
		{
			cout << "Wrong guesses: ";

			for (char letter : wrong_guesses)
			{
				cout << letter << " ";
			}
			cout << endl;
		}
	}
}