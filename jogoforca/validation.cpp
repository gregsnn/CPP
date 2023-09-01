#include <iostream>
#include "validation.hpp"

namespace Forca {
	bool not_hit(const string& secret_word, const map<char, bool>& hit_letters)
	{
		for (char letter : secret_word)
		{
			if (hit_letters.find(letter) == hit_letters.end())
			{
				return true;
			}
		}
		return false;
	}

	bool has_letter(const char& guess, const string& secret_word)
	{
		for (char letter : secret_word)
		{
			if (guess == letter)
			{
				return true;
			}
		}

		return false;
	}
}