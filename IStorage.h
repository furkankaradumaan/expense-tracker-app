#ifndef ISTORAGE_H
#define ISTORAGE_H

#include <vector>
#include "Transaction.h"

// Thisis a base class for Storage Strategies.
// Any class that will store the Transaction data in somewhere must inherit
// from this class.
// By using this design, we can add different Storage Strategies in the future
// For example, we may store the transactions into a CSV file or a JSON file later.
// Just we need to write a seperate class for that which inherits from this base class.
class IStorage {
public:
    virtual ~IStorage() {} 
    virtual void save(const std::vector<Transaction>& transactions) = 0; 
    virtual std::vector<Transaction> load() = 0;
};

#endif
