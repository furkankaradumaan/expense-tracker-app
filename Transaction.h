#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

// Enum for INCOME and EXPENSE
enum TransactionType { INCOME, EXPENSE };

class Transaction {
private:
    int id;
    double amount;
    std::string date;      // Format: DD/MM/YYYY
    std::string category;
    TransactionType type;

public:
    Transaction(int id, double amount, std::string date, std::string category, TransactionType type);

    // Getters
    int getId() const;
    double getAmount() const;
    std::string getDate() const;
    std::string getCategory() const;
    TransactionType getType() const;

    // Overloading stream insertion operator to display object data
    friend std::ostream& operator<<(std::ostream& os, const Transaction& t);
    
    // Serializes object data into a comma-separated string for file storage
    std::string serialize() const;
};

#endif
