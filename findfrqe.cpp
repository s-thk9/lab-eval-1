#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>

using namespace std;

int main() {
    unordered_map<char, int> charFrequency;
    string paragraph;


    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    for (char c : paragraph) {

        char lowerChar = tolower(c);


        charFrequency[lowerChar]++;

    }

    cout << "Character frequencies:\n";
    for (const auto& entry : charFrequency) {
        cout << entry.first << ": " << entry.second << "\n";
    }

    return 0;
}
