#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "DataWriter.h"

using namespace std;

static const string CSV_PATH = "output.csv";

void DataWriter::fillCSV(vector<pair<string, int>>& sortedWords) {

    fstream writer(CSV_PATH);

    if (writer.is_open()) {
        for (auto& entry : sortedWords) {
            writer << entry.first << ", " << entry.second << endl;
        }
        writer.close();
    }
    else {
        cerr << "Не удалось открыть файл " << CSV_PATH << endl;
    }
}


