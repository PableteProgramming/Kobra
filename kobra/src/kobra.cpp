#include <kobra.hpp>

int main(){
    bool running=true;
    while(running){
        std::cout<<"kobra > ";
        std::string input;
        std::getline(std::cin,input);
        if (input=="exit"){
            break;
        }
        std::cout<<input<<std::endl;
    }
    return 0;
}