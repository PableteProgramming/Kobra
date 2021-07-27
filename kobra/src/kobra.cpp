#include <kobra.hpp>

int main(){
    bool running=true;
    Lexer lexer;
    while(running){
        std::cout<<"kobra > ";
        std::string input;
        std::getline(std::cin,input);
        if (input=="exit"){
            break;
        }
        //std::cout<<input<<std::endl;
        bool error=false;
        std::vector<Token> tokens= lexer.Parse(input,error);
        if(!error){
            std::cout<<"[";
            for(int i=0; i<tokens.size();i++){
                tokens[i].Print();
                std::cout<<";";
            }
            std::cout<<"\b"<<std::endl;
        }
    }
    return 0;
}