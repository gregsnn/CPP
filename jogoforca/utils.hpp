#pragma once
#include <string>
#include <map>
#include <array>
#include <vector>

namespace Forca {
	using namespace std;

	void add_word();

	string sort_words();

	void guessing(map<char, bool>& hit_letters, array<char, 5>& wrong_guesses,
		const string& secret_word, int& wrong_guesses_index);
}