#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class DataParser {

public:
    void readFromFile(string inputFile);
    map<string, int> wordsMap;
    vector<pair<string, int>> sortedWords;
   

private:
    void separate(string str);
    vector<pair<string, int>> sorting(map<string, int>& wordsMap);
    
};
#endif
