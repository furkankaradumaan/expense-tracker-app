#include <iostream>
#include "TransactionManager.h"
#include "TextFileStorage.h"
#include "InputValidator.h"
using namespace std;

int main() {
    TransactionManager manager(new TextFileStorage("transactions.txt"));

    while (true) {
        cout << "\n1. Add New Income"
	     << "\n2. Add New Expense"
	     << "\n3. List All Records" 
	     << "\n4. List By Date"
	     << "\n5. List By Month"
	     << "\n6. Monthly Report"
	     << "\n7. Delete Record By ID"
	     << "\n0. Exit"
	     << endl;
        int choice = InputValidator::getInt("Your choice: ");
        if (choice == 0) break;
	 
	// Handle the case that user wants to add a new income or a new expense
	// record
        if (choice == 1 || choice == 2) {
            double amount = InputValidator::getDouble("Enter transaction amount: ");
            string date = InputValidator::getDate("Enter transaction date (DD/MM/YYYY): ");
            string category = InputValidator::getString("Enter category: ");
            manager.addRecord(amount, date, category, (choice == 1 ? INCOME : EXPENSE));
        } else if (choice == 3) { // List all records
            manager.listAll();
        } else if (choice == 4) { // List records by date
            manager.filterByDate(InputValidator::getDate("Enter date: "));
        } else if (choice == 5) { // list records by month
            manager.filterByMonth(InputValidator::getString("Enter month (MM/YYYY): "));
        } else if (choice == 6) {
            manager.generateReport(InputValidator::getString("Enter month (MM/YYYY): "));
        } else if (choice == 7) {
            manager.deleteRecord(InputValidator::getInt("Enter ID: "));
        }
    }
    return 0;
}
