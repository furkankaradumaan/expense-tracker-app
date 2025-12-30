#include "TextFileStorage.h"
#include <fstream>
#include <sstream>
using namespace std;

TextFileStorage::TextFileStorage(string filename) : filename(filename) {}

void TextFileStorage::save(const vector<Transaction>& transactions) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& t : transactions) {
            outFile << t.serialize() << endl;
        }
        outFile.close();
    }
}

vector<Transaction> TextFileStorage::load() {
    vector<Transaction> data;
    ifstream inFile(filename);
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string sId, sAmount, date, category, sType;
        // Read all the fields of transaction as string 
	getline(ss, sId, ','); // read characters until encountering a comma
	getline(ss, sAmount, ',');
        getline(ss, date, ',');
	getline(ss, category, ',');
        getline(ss, sType, ',');
	// validate all fields are not empty string
        if (!sId.empty() && !sAmount.empty() && !category.empty() && !sType.empty()) {
            TransactionType type = (sType == "0") ? INCOME : EXPENSE;
            data.push_back(Transaction(stoi(sId), stod(sAmount), date, category, type));
        }
    }
    return data;
}
