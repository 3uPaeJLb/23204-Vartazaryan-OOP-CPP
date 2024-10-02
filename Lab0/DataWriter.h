#ifndef DATAWRITER_H
#define DATAWRITER_H

#include <vector>

using namespace std;

class DataWriter {
public:
    void fillCSV(vector<pair<string, int>>& sortedWords);
};
#endif
