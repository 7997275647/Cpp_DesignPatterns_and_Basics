#include "../Inc/Vector.hpp"
#include <iostream>
#include <vector>



void vectorDataTypePractice(){
    std:: vector<int> myVec;
    myVec.push_back(10);
    myVec.push_back(25);
    myVec.push_back(35);
    myVec.push_back(10);
    myVec.push_back(25);
    myVec.push_back(35);
    myVec.push_back(10);
    myVec.push_back(25);
    myVec.push_back(35);
    std:: cout << "Vector size: " << myVec.size() << std::endl;
    std:: cout << "Vector capcity: " << myVec.capacity() << std::endl;
    myVec.push_back(15);
     std:: cout << "Vector size: " << myVec.size() << std::endl;
    std:: cout << "Vector capcity: " << myVec.capacity() << std::endl;
    if(myVec.empty()){
        std:: cout<< "vector is empty" << std::endl;
    }
    else{
        std:: cout << "Vector first value is " << myVec.front() << std::endl;
        std:: cout << "Vector lat value is " << myVec.back() << std::endl;
        std:: cout << "Vector size: " << myVec.size() << std::endl;
        myVec.pop_back();
        std:: cout << "Vector first value is " << myVec.front() << std::endl;
        std:: cout << "Vector lat value is " << myVec.back() << std::endl;
        std:: cout << "Vector size: " << myVec.size() << std::endl;
         std:: cout << "Vector capcity: " << myVec.capacity() << std::endl;

    }

}
