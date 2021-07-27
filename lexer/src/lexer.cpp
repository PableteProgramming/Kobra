#include <../../lexer/include/lexer.hpp>

Token::Token(std::string _id){
    id=_id;
    content="";
    empty=true;
}

Token::Token(std::string _id, std::string _content){
    id=_id;
    content= _content;
    empty=false;
}

void Token::Print(){
    if(empty){
        std::cout<<id;
    }
    else{
        std::cout<<"{"<<id<<":"<<content<<"}";
    }
}

std::vector<Token> Lexer::Parse(std::string text, bool& error){
    index=0;
    error=false;
    tokens.clear();
    while(index<text.size()){
        if(CharInString(text[index],EmptyChars)){
            //nothing
        }
        else if(text[index]=='+'){
            tokens.push_back(Token("PLUS"));
        }
        else if(text[index]=='-'){
            tokens.push_back(Token("MINUS"));
        }
        else if(text[index]=='*'){
            tokens.push_back(Token("MULTIPLICATION"));
        }
        else if(text[index]=='/'){
            tokens.push_back(Token("DIVISION"));
        }
        else if(CharInString(text[index],Digits)){
            std::pair<std::pair<std::string,std::string>,int> r= getFullNumber(text,index);
            tokens.push_back(Token(r.first.first,r.first.second));
            index= r.second-1;
            //std::cout<<"index: "<<index<<std::endl;
        }
        else{
            std::cout<<"symbol '" << text[index] <<"' not recognized !"<<std::endl;
            error=true;
            return tokens;
            //char not recognize
        }
        index++;
    }
    return tokens;
}

std::vector<Token> Lexer::GetTokens(){
    return tokens;
}

std::pair<std::pair<std::string,std::string>,int> Lexer::getFullNumber(std::string s,int index){
    std::string r="";
    bool point=false;
    for(int i=index;i<s.size();i++){
        if(CharInString(s[i],Digits)){
            r+= s[i];
        }
        else if(s[i]=='.'){
            point=true;
            r+= s[i];
        }
        else{
            //std::cout<<"num: "<<r<<std::endl;
            if(point){
                return std::make_pair(std::make_pair(T_FLOAT,r),i);
            }
            else{
                return std::make_pair(std::make_pair(T_INT,r),i);
            }
        }
    }
    //std::cout<<"num: "<<r<<std::endl;
    if(point){
        return std::make_pair(std::make_pair(T_FLOAT,r),s.size());
    }
    else{
        return std::make_pair(std::make_pair(T_INT,r),s.size());
    }
}