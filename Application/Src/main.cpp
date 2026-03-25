#include<iostream>
#include "../Inc/main.hpp"


int main(){
    std::cout << "Hello World!" << std::endl;
    Move moveCommand;
    moveCommand.execute();
    moveCommand.undo();
    getchar();
    return 0;
}
