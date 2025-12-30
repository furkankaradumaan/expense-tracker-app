// --- FinanceManager.h ---
#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H
#include <vector>
#include "Transaction.h"
#include "IStorage.h"

class TransactionManager {
private:
    std::vector<Transaction> transactions;
    IStorage* storage; // Raw pointer for abstraction
    int nextId;

public:
    TransactionManager(IStorage* storageStrategy);
    ~TransactionManager(); // Memory cleanup

    void addRecord(double amount, std::string date, std::string category, TransactionType type);
    void listAll() const;
    void filterByDate(std::string date) const;
    void filterByMonth(std::string monthYear) const;
    void generateReport(std::string monthYear) const;
    void deleteRecord(int id);
};
#endif

