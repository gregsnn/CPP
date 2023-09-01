#include <iostream>
#include <cstdlib>
#include "file.hpp"
#include "validation.hpp"
#include "utils.hpp"

using namespace std;

namespace Forca {
	void add_word()
	{
		cout << "Do you want to add a new word to the game? (Y/N)" << endl;
		char response;
		cin >> response;
		response = toupper(response);

		if (response == 'Y')
		{
			string new_word;
			cout << "What is the new word?" << endl;
			cin >> new_word;

			vector<string> words_file = read_file();
			words_file.push_back(new_word);

			save_file(words_file);
		}
		else
		{
			cout << "Ok, bye!" << endl;
		}
	}

	string sort_words()
	{
		vector<string> words_file = read_file();

		srand(time(NULL));
		int random_number = rand() % words_file.size();

		return words_file[random_number];
	}

	void guessing(map<char, bool>& hit_letters, array<char, 5>& wrong_guesses,
		const string& palavra_secreta, int& wrong_guesses_index)
	{
		cout << "Guess a letter: ";
		char guess;
		cin >> guess;
		guess = toupper(guess);

		hit_letters[guess] = true;

		if (has_letter(guess, palavra_secreta))
		{
			cout << "You hit a letter" << endl;
		}
		else
		{
			cout << "You missed" << endl;
			wrong_guesses[wrong_guesses_index] = guess;
			wrong_guesses_index++;
		}
		cout << endl;
	}
}