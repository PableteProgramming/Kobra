#include <../../func/include/func.hpp>

bool CharInString(char c, std::string s){
    for(int i=0; i<s.size();i++){
        if(s[i]==c){
            return true;
        }
    }
    return false;
}