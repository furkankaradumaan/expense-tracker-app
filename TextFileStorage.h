#ifndef TEXTFILESTORAGE_H
#define TEXTFILESTORAGE_H
#include "IStorage.h"

class TextFileStorage : public IStorage {
private:
    std::string filename;
public:
    TextFileStorage(std::string filename);
    void save(const std::vector<Transaction>& transactions) override;
    std::vector<Transaction> load() override;
};
#endif
