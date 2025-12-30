#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H
#include <string>

class InputValidator {
public:
    static std::string getString(const std::string& prompt);
    static int getInt(const std::string& prompt);
    static double getDouble(const std::string& prompt);
    static std::string getDate(const std::string& prompt); // Validates format
};
#endif
