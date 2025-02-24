#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>    
using namespace std;

unordered_map<string, unordered_map<string, int>> userDictionary;

void processFullSentence(const vector<string>& sentence) {
    if (sentence.size() < 2) {
        return; // Need at least two words for a mapping
    }
    for (size_t i = 1; i < sentence.size(); ++i) {
        userDictionary[sentence[i - 1]][sentence[i]]++;
    }
}

void updateDictionary(const vector<string>& sentence) {
    if (sentence.size() < 2) {
        return; // Need at least two words for a mapping
    }
    size_t lastIndex = sentence.size() - 1;
    const string &prevWord = sentence[lastIndex - 1];
    const string &currentWord = sentence[lastIndex];
    userDictionary[prevWord][currentWord]++;
}

vector<string> recommendWords(const string &prevWord) {
    vector<string> suggestions;
    if (userDictionary.find(prevWord) != userDictionary.end()) {
        const unordered_map<string, int>& nextWords = userDictionary[prevWord];
        vector<pair<string, int>> nextWordsVec(nextWords.begin(), nextWords.end());
        
        // Sort by frequency in descending order
        sort(nextWordsVec.begin(), nextWordsVec.end(), 
             [](const pair<string, int>& a, const pair<string, int>& b) {
                 return a.second > b.second;
             });
        
        
        for (size_t i = 0; i < nextWordsVec.size() && i < 4; i++) {
            suggestions.push_back(nextWordsVec[i].first);
        }
    }
    return suggestions;
}

int main() {

    ifstream infile("sentences.txt");
    if (!infile) {
        cerr << "Error: Could not open sentences.txt" << endl;
    } else {
        string line;
        while (getline(infile, line)) {
            istringstream iss(line);
            vector<string> words;
            string word;
            while (iss >> word) {
                words.push_back(word);
            }
            processFullSentence(words);
        }
        infile.close();
    }
    
    cout << "Initial dictionary loaded from sentences.txt." << endl;
    
    string userInput;
    vector<string> sentence;

    cout << "Enter words to build a sentence (or type 'exit' to end): " << endl;
    
    while (true) {
        // Optional: clear the console (platform-dependent)
        system("CLS"); // Uncomment if targeting Windows only
        
        string lastWord = sentence.empty() ? "" : sentence.back();
        vector<string> suggestions = recommendWords(lastWord);
        
        // Print suggestions
        cout << "\nSuggestions for the previous word '" << lastWord << "':" << endl;
        for (size_t i = 0; i < suggestions.size(); ++i) {
            cout << i + 1 << ". " << suggestions[i] << endl;
        }
        
        // Print the current sentence
        cout << "Current sentence:";
        for (const string &word : sentence) {
            cout << " " << word;
        }
        cout << "\n\nEnter a word or a suggestion number: ";
        
        cin >> userInput;
        
        // Check if the user wants to exit
        if (userInput == "exit") {
            break;
        }
        
        // Check if the user pressed a number corresponding to a suggestion
        if (userInput.size() == 1 && isdigit(userInput[0])) {
            int selection = userInput[0] - '0';
            if (selection > 0 && selection <= static_cast<int>(suggestions.size())) {
                sentence.push_back(suggestions[selection - 1]);
                updateDictionary(sentence);
                continue;
            }
        }
        
        // Otherwise, treat the input as a new word
        sentence.push_back(userInput);
        updateDictionary(sentence);
    }
    
    cout << "\nProgram ended." << endl;
    return 0;
}
