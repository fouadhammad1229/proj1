#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

// Struct to hold the results and manage output order
struct Result {
    string value;
    int count;
    int index;

    // For sorting results: higher count first, and for the same count, earlier index.
    bool operator<(const Result& other) const {
        if (count != other.count)
            return count > other.count;
        return index < other.index;
    }
};

// Helper function to output the top N results
void outputResults(const string& title, map<string, int>& counts, int topN) {
    vector<Result> results;
    int idx = 0;

    if (counts.size() == 0) {
        return; // Don't print anything if there are no results to display
    }

    // Move the map contents into a vector of Result structs for sorting
    for (const auto& entry : counts) {
        results.push_back({entry.first, entry.second, idx++});
    }

    // Sorts the results
    sort(results.begin(), results.end());

    // Outputs the results for display in terminal
    cout << "Total " << counts.size() << " different " << title << ", " << min((int)counts.size(), topN) << " most used " << title << ":\n";
    for (int i = 0; i < min((int)results.size(), topN); ++i) {
        cout << "No. " << i << ": " << results[i].value << "\t" << results[i].count << endl;
    }
}

// Function to count letters in the input
int letterCount(string str) {
    map<string, int> charCount;
    
    // Actually counts the letters in a string
    for (int i = 0; i < str.length(); i++) {
        charCount[string(1, str[i])]++; // Count each character!! specifically!!
    }

    // Output the character counts
    outputResults("characters", charCount, 10);
    return charCount.size(); // Return total unique characters
}

// Function to count words in the input
int counterWords(string str) {
    map<string, int> wordCount;
    string token;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            token += tolower(str[i]); // Collect word (lowercase included)
        } else {
            if (!token.empty()) {
                wordCount[token]++;
                token.clear(); // Clear after counting the word
            }
        }
    }

    if (!token.empty()) {
        wordCount[token]++;
    }

    // Output the word counts
    outputResults("words", wordCount, 10);
    return wordCount.size(); // Return total unique words
}

// Function to count numbers in the input
int counterNumbers(string str) {
    map<string, int> numberCount;
    string token;
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            token += str[i]; // Collect number
        } else {
            if (!token.empty()) {
                numberCount[token]++;
                token.clear(); // Clear after counting the number
            }
        }
    }

    if (!token.empty()) {
        numberCount[token]++;
    }

    // Output the number counts
    outputResults("numbers", numberCount, 10);
    return numberCount.size(); // Return total unique numbers
}

// Main function
int main() {
    string str;

    // Reading input from the user
    while (getline(cin, str)) {
        map<string, int> charCount, wordCount, numberCount;

        // Count characters, words, and numbers
        int charTotal = letterCount(str);
        int wordTotal = counterWords(str);
        int numberTotal = counterNumbers(str);

        // Output results for characters
        if (charTotal > 0) {
            outputResults("characters", charCount, 10);
        }

        // Output results for words
        if (wordTotal > 0) {
            outputResults("words", wordCount, 10);
        }

        // Output results for numbers
        if (numberTotal > 0) {
            outputResults("numbers", numberCount, 10);
        }
    }    
    return 0;
}

