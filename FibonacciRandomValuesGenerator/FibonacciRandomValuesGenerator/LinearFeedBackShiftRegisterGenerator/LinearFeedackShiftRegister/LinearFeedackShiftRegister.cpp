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
    this->size = 17;
    this->polinomialSize = 2;
    
    this->polynomial = new int[2];
    this->polynomial[0] = 4;
    this->polynomial[1] = 3;
    
    this->key = 49148;
    this->keySize = sizeof(this->key);
}

LinearFeedackShiftRegister::LinearFeedackShiftRegister(int key, int *polynomial, int size, int polySize)
{
    this->size = size;
    this->polinomialSize = polySize;
    
    this->polynomial = polynomial;
    
    this->key = key;
    this->keySize = sizeof(this->key) * 8 - 1;
}

#pragma mark - Register

bool LinearFeedackShiftRegister::generateBit()
{
    for (int i = 0; i < keySize + 1 - size; i++) {
        key &= ~(1 << (keySize - i));
    }
    
    bool value = key & (1 << 0);
    bool newBit = value;
    
    for (int i = 0; i < polinomialSize; i++) {
        int indexOfBit = polynomial[i] - 1;
        bool bit = key & (1 << indexOfBit);
        newBit ^= bit;
    }
    key = key >> 1;
    key = newBit ? key | (1 << (keySize - size + 1)) : key & ~(1 << (keySize - size + 1));
    
    return value;
}
