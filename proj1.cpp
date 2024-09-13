#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
using namespace std;

int counterWords(string str)
{
	// When the string is empty or null, return to 0.
	if (str.size() == 0) {
		return 0;
	}

	vector<string> words;

	string temp = "";

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ' || str[i] == '\\') {
			words.push_back(temp);
			temp = "";
		}
		else {
			temp += str[i]; // Stores str[i] onto the empty temp
		}
	}


	int counter = 1;

	for (int i = 0; i < words.size(); i++) {
		if (words[i].size() != 0)
			counter++;
	}


	// Count the amount of letters in a text
	
	int letters[26]{0};

	for (int i = 0; i < str.length(); i++) {
		letters[toupper(str[i]) - 65] += 1; // Add 1 to element holding a letter
	}

	for (int i = 0; i < 26; i++) {
		if(letters[i] > 0) {
			cout << char(65 + i) << ": Showed Up: " << letters[i] << endl;
		}
	}

	return counter;

}


int main() 
{
	/* Display Sector */

	string str;

	while (getline(cin,str)) {
		if (counterWords(str) == 0) {
			cout << "========" << endl;
		}
		else {

		cout << counterWords(str) << ": words in total." << endl;
	 	}
	}
	return 0;
}
