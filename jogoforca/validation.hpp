#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace Forca {
	using namespace std;

	bool not_hit(const string& secret_word, const map<char, bool>& hit_letters);

	bool has_letter(const char& guess, const string& palavra_secreta);
}