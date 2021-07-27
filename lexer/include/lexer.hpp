#include <string>
#include <vector>
#include <../../func/include/func.hpp>
#include <iostream>

const std::string EmptyChars= " \t\n";
const std::string Digits= "0123456789";

const std::string T_INT= "T_INT";
const std::string T_FLOAT= "T_FLOAT";

class Token{
private:
    std::string id;
    std::string content;
    bool empty;
public:
    Token(std::string);
    Token(std::string,std::string);
    void Print();
};

class Lexer{
private:
    int index;
    std::vector<Token> tokens;
    std::pair<std::pair<std::string,std::string>,int> getFullNumber(std::string,int);
public:
    std::vector<Token> Parse(std::string,bool&);
    std::vector<Token> GetTokens();
};