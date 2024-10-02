#include "DataParser.h"
#include <string>

using namespace std;

int main() {

    string inputFile = "text.txt";

    DataParser dataParser;
    dataParser.readFromFile(inputFile);

    return 0;
}
