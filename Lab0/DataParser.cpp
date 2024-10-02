#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include "DataWriter.h"
#include "DataParser.h"
#include <algorithm>
#include <vector>

using namespace std;

DataWriter dataWriter;

void DataParser::readFromFile(string inputFile) {

    fstream file(inputFile);

    string str;
    while (getline(file, str)) {
        separate(str);
    }

    sortedWords = sorting(wordsMap);

    dataWriter.fillCSV(sortedWords);

    file.close();
}

void DataParser::separate(string str) {
    stringstream ss(str);
    string word;

    while (ss >> word) {

        string new_word;

        for (char c : word) 
            if (isalnum(static_cast<char>(c)))
                new_word += tolower(static_cast<char>(c));
        

        if (wordsMap.find(new_word) != wordsMap.end()) 
            wordsMap[new_word]++;
        else 
            wordsMap[new_word] = 1;
    }
}

vector<pair<string, int>> DataParser::sorting(map<string, int>& wordsMap) {
    vector<pair<string, int>> sortedWords(wordsMap.begin(), wordsMap.end());

    sort(sortedWords.begin(), sortedWords.end());

    return sortedWords;
}
