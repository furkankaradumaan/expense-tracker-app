#include "Transaction.h"
#include <iomanip> // Enables use of input manipulators
using namespace std;

Transaction::Transaction(int id, double amount, string date, string category, TransactionType type)
    : id(id), amount(amount), date(date), category(category), type(type) {}

int Transaction::getId() const { return id; }
double Transaction::getAmount() const { return amount; }
string Transaction::getDate() const { return date; }
string Transaction::getCategory() const { return category; }
TransactionType Transaction::getType() const { return type; }

ostream& operator<<(ostream& os, const Transaction& t) {
    string typeLabel = (t.type == INCOME) ? "[INCOME] " : "[EXPENSE]";
    os << left << setw(10) << typeLabel 
       << " | ID: " << setw(4) << t.id 
       << " | Date: " << setw(11) << t.date 
       << " | Amt: " << fixed << setprecision(2) << setw(9) << t.amount 
       << " | Cat: " << t.category;
    return os;
}

string Transaction::serialize() const {
    return to_string(id) + "," + to_string(amount) + "," + 
           date + "," + category + "," + (type == INCOME ? "0" : "1");
}
