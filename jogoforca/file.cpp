#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "file.hpp"

using namespace std;

namespace Forca {
	vector<string> read_file()
	{
		ifstream file;
		file.open("words.txt");

		vector<string> words_file;

		if (file.is_open())
		{
			int quantity_words;
			file >> quantity_words;

			for (int i = 0; i < quantity_words; i++)
			{
				string word;
				file >> word;
				words_file.push_back(word);
			}
			file.close();
		}
		else
		{
			cout << "Unable to open file" << endl;
			exit(0);
		}

		return words_file;
	}

	void save_file(const vector<string>& words_file)
	{
		ofstream file;
		file.open("words.txt");
		if (file.is_open())
		{
			file << words_file.size() << endl;
			for (string word : words_file)
			{
				file << word << endl;
			}
			file.close();
			cout << "File saved successfully" << endl;
		}
		else
		{
			cout << "Unable to open file" << endl;
			exit(0);
		}
	}
}