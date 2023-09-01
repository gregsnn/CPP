#include <iostream>
#include <string>
#include <map>
#include <array>
#include "validation.hpp"
#include "print.hpp"
#include "file.hpp"
#include "utils.hpp"

using namespace std;

static string secret_word = "";
static map<char, bool> hit_letters;
static array<char, 5> wrong_guesses;
static int wrong_guesses_index = 0;

int main()
{
	Forca::header();

	cout << wrong_guesses.size() << endl;

	secret_word = Forca::sort_words();

	while (Forca::not_hit(secret_word, hit_letters) && wrong_guesses_index < wrong_guesses.size())
	{
		Forca::print_wrong_guesses(wrong_guesses);

		Forca::print_letter(secret_word, hit_letters);

		Forca::guessing(hit_letters, wrong_guesses, secret_word, wrong_guesses_index);
	}

	Forca::footer(secret_word, hit_letters);
}
