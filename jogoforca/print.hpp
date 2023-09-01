#pragma once
#include <iostream>
#include <string>
#include <map>
#include <array>

namespace Forca {
	using namespace std;

	inline void header()
	{
		cout << "*******************************" << endl;
		cout << "* WELCOME TO THE HANGMAN GAME *" << endl;
		cout << "*******************************" << endl;
		cout << endl;
	}

	void footer(const string& secret_word, const map<char, bool>& hit_letters);

	void print_letter(const string& secret_word, const map<char, bool>& hit_letters);

	void print_wrong_guesses(const array<char, 5>& wrong_guesses);
}