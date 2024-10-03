#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

// Struct to hold results for sorting
struct Result {
    string value;
    int count;
    int index;

    // Sorting by higher count first, and for the same count, by earlier index
    bool operator<(const Result& other) const {
        if (count != other.count)
            return count > other.count;
        return index < other.index;
    }
};

// Function to output the top N results
void outputResults(const string& title, map<string, int>& counts, int topN) {
    vector<Result> results;
    int idx = 0;

    // If no results, return without printing anything
    if (counts.empty()) return;

    // Transfer map data into a vector for sorting
    for (const auto& entry : counts) {
        results.push_back({entry.first, entry.second, idx++});
    }

    // Sort the results by count and index
    sort(results.begin(), results.end());

    // Output the top N sorted results
    cout << "Total " << counts.size() << " different " << title << ", " 
         << min((int)counts.size(), topN) << " most used " << title << ":\n";
    for (int i = 0; i < min((int)results.size(), topN); ++i) {
     // Handle special characters for better readability
        string displayValue = results[i].value;
        if (displayValue == "\n") {
            displayValue = "\\n";
        } else if (displayValue == " ") {
            displayValue = " ";
        }
        cout << "No. " << i << ": " << displayValue << "\t" << results[i].count << endl;
	}
}

// Function to count and store characters
void letterCount(const string& str, map<string, int>& charCount) {
    for (char ch : str) {
        if (ch == ' ' || ch == '\n' || isalnum(ch) || ispunct(ch)) {
            charCount[string(1, ch)]++;
        }
    }
}

// Function to count and store words
void counterWords(const string& str, map<string, int>& wordCount) {
    string token;
    for (char ch : str) {
        if (isalpha(ch)) {
            token += tolower(ch); // Convert letters to lowercase
        } else {
            if (!token.empty()) {
                wordCount[token]++;
                token.clear(); // Clear after processing a word
            }
        }
    }
    // Handle the last word, if any
    if (!token.empty()) {
        wordCount[token]++;
    }
}

// Function to count and store numbers
void counterNumbers(const string& str, map<string, int>& numberCount) {
    string token;
    for (char ch : str) {
        if (isdigit(ch)) {
            token += ch; // Collect digits
        } else {
            if (!token.empty()) {
                numberCount[token]++;
                token.clear(); // Clear after processing a number
            }
        }
    }
    // Handle the last number, if any
    if (!token.empty()) {
        numberCount[token]++;
    }
}

// Main function
int main() {
    string str;
    map<string, int> charCount, wordCount, numberCount;

    // Reading input from the user line by line
    while (getline(cin, str)) {
        str += '\n';
	
	// Count characters, words, and numbers in the input
        letterCount(str, charCount);
        counterWords(str, wordCount);
        counterNumbers(str, numberCount);
    }

    // Output the top 10 characters, words, and numbers
    outputResults("characters", charCount, 10);
    cout << endl;
    outputResults("words", wordCount, 10);
    cout << endl;
    outputResults("numbers", numberCount, 10);

    return 0;
}

