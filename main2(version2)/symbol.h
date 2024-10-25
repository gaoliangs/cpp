#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <vector>

class Symbol {
public:
    Symbol(const std::string& name);
    std::string getName() const;
    std::string toString() const;

private:
    std::string name;
};

std::vector<Symbol> createSymbols(char prefix, int count);
std::vector<Symbol> createSymbols(const std::string& prefix, int count);

#endif
