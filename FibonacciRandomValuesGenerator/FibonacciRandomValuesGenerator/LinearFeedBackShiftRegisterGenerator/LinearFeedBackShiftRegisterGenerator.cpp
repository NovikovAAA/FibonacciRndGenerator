//
//  LinearFeedBackShiftRegisterGenerator.cpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include "LinearFeedBackShiftRegisterGenerator.hpp"
#include <iostream>

#define WordSize 32

using namespace std;

#pragma mark - Init

LinearFeedBackShiftRegisterGenerator::LinearFeedBackShiftRegisterGenerator(int key, int *polynomial, int size, int polySize, bool isDebug) : linearRegister(key, polynomial, size, polySize, isDebug)
{
    this->numbersTranslator = NumbersTranslator(WordSize);
    this->isDebug = isDebug;
}

#pragma mark - Generator

void LinearFeedBackShiftRegisterGenerator::generateValue(bool *bitArray, int N)
{
    for (int i = 0; i < N; i++)
    {
        bitArray[i] = linearRegister.generateBit();
    }
    
    if (isDebug)
    {
        cout << "------Result------" << endl;
        numbersTranslator.printBitArray(bitArray, WordSize);
        cout << "------------------" << endl;
    }
}
