#include "../Inc/Vector.hpp"
#include <iostream>
#include <vector>

void vectorDataTypePractice(){
    std:: vector <int> myVector;
    if(myVector.empty()){
        std::cout << "The vector is empty." << std::endl;
    }
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(40);
    myVector.push_back(50);
    myVector.push_back(60);

    for(int x : myVector){
        std::cout << x << std::endl;
    }

    myVector.pop_back();
    myVector.erase(std::find(myVector.begin(), myVector.end(), 20));

    for(int x : myVector){
        std::cout << x << std::endl;
    }

}
