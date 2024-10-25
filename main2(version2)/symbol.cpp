#include "symbol.h"

Symbol::Symbol(const std::string& name) : name(name) {}

std::string Symbol::getName() const {
    return name;
}

std::string Symbol::toString() const {
    return name;
}

std::vector<Symbol> createSymbols(char prefix, int count) {
    std::vector<Symbol> symbols;
    for (int i = 0; i < count; ++i) {
        symbols.emplace_back(std::string(1, prefix) + std::to_string(i));
    }
    return symbols;
}

std::vector<Symbol> createSymbols(const std::string& prefix, int count) {
    std::vector<Symbol> symbols;
    for (int i = 0; i < count; ++i) {
        symbols.emplace_back(prefix + std::to_string(i));
    }
    return symbols;
}
