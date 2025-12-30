#include "TransactionManager.h"
#include <iostream>
using namespace std;

TransactionManager::TransactionManager(IStorage* storageStrategy)
: storage(storageStrategy), nextId(1) {
    transactions = storage->load();
    if (!transactions.empty()) {
        nextId = transactions.back().getId() + 1;
    }
}

TransactionManager::~TransactionManager() {
    delete storage; // Releasing raw pointer
}

void TransactionManager::addRecord(double amount, string date, string category, TransactionType type) {
    transactions.push_back(Transaction(nextId++, amount, date, category, type));
    storage->save(transactions);
}

void TransactionManager::listAll() const {
    if (transactions.empty()) { cout << "There is no any transaction records." << endl; return; }
    for (const auto& t : transactions) cout << t << endl;
}

void TransactionManager::filterByDate(string date) const {
    for (const auto& t : transactions) {
        if (t.getDate() == date) cout << t << endl;
    }
}

void TransactionManager::filterByMonth(string monthYear) const {
    for (const auto& t : transactions) {
        // If the monthYear string exists in date string
        if (t.getDate().find(monthYear) != string::npos) cout << t << endl;
    }
}

void TransactionManager::generateReport(string monthYear) const {
    double income = 0;
    double expense = 0;
    for (const auto& t : transactions) {
        if (t.getDate().find(monthYear) != string::npos) {
            if (t.getType() == INCOME) income += t.getAmount();
            else expense += t.getAmount();
        }
    }
    cout << "\nReport for " << monthYear << endl
         << "Total income    : " << income << endl 
	 << "Total expense   : " << expense << endl 
	 << "Net       	     : " << (income - expense) << endl;
}

void TransactionManager::deleteRecord(int id) {
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (it->getId() == id) {// Record found
            transactions.erase(it); // Remove the record
            storage->save(transactions); // Update the data file, save the records again.
            cout << "\nRecord deleted successfully." << endl;
            return;
        }
    }
    cout << "\nID number could not found." << endl;
}

