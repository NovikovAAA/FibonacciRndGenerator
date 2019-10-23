//
//  LineaFeedackShiftRegister.cpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include "LinearFeedackShiftRegister.hpp"
#include <iostream>

using namespace std;

#pragma mark - Init

LinearFeedackShiftRegister::LinearFeedackShiftRegister()
{
    this->size = 4;
    
    this->registerValue = new int[4];
    for (int i = 0; i < size; i++)
    {
        this->registerValue[i] = 1;
    }
    
    this->polynomial = new int[2];
    this->polynomial[0] = 4;
    this->polynomial[1] = 3;
}

LinearFeedackShiftRegister::LinearFeedackShiftRegister(int *initialRegisterValue, int *polynomial, int size)
{
    this->size = size;
    this->registerValue = initialRegisterValue;
    this->polynomial = polynomial;
}
