#include "../Inc/CommandPattern.hpp"
#include<iostream>

void Move::execute(){
    std:: cout<< "Executing Move Command" << std::endl;
}

void Move::undo(){
    std:: cout<< "Undoing Move Command" << std::endl;

}