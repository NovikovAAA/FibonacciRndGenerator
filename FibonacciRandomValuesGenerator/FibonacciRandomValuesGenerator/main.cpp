//
//  main.cpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include <iostream>
#include "LinearFeedBackShiftRegisterGenerator.hpp"

int main(int argc, const char * argv[]) {
    int startRegisterValues[17] = {1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1};
    int polynomial[3] = {17, 14};
    //x^17+x^14+1
    
    LinearFeedBackShiftRegisterGenerator(startRegisterValues, polynomial, 17);
    
    return 0;
}
