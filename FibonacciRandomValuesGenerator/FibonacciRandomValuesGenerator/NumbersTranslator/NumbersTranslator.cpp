//
//  NumbersTranslator.cpp
//  FibonacciRandomValuesGenerator
//
//  Created by Артём Новиков on 31.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include "NumbersTranslator.hpp"
#include <iostream>

using namespace std;

NumbersTranslator::NumbersTranslator()
{
    this->wordSize = 32;
}

NumbersTranslator::NumbersTranslator(int wordSize)
{
    this->wordSize = wordSize;
}

unsigned int NumbersTranslator::decimalValueFromBitArray(bool *bitArray, int size)
{
    unsigned int value = 0;
    for (int i = 0; i < size; i++)
    {
        if (bitArray[i])
        {
            value += pow(2, wordSize - 1 - i);
        }
    }
    return value;
}

void NumbersTranslator::bitArrayFromDecimalValue(unsigned int value, bool *bitArray, int size)
{
    int counter = 0;
    
    bool *tempBitArray = new bool[32];
    while (value != 0 && counter < wordSize)
    {
        tempBitArray[counter] = value % 2;
        value /= 2;
        counter++;
    }
    
    for (int i = 0; i < wordSize - counter; i++)
    {
        bitArray[i] = 0;
    }
    
    for (int i = wordSize - counter; i < wordSize; i++)
    {
        bitArray[i] = tempBitArray[counter - (i - (wordSize - counter)) - 1];
    }
}

void NumbersTranslator::printBitArray(bool *bitArray, int size)
{
    for (int i = 0; i < size; i++) {
        cout << bitArray[i];
    }
    cout << endl;
}
