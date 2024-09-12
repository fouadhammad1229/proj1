#include <iostream>
#include <stdio.h>
#include <vector>
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

	return counter;

}


int main() 
{
	/* Display Sector */

	string str;

	getline(cin, str);

	cout << "No of words: " << counterWords(str) << endl;

	return 0;
}

