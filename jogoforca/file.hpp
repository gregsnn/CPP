#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace Forca {
	using namespace std;

	vector<string> read_file();

	void save_file(const vector<string>& words_file);
}