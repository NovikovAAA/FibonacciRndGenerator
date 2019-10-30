//
//  LinearFeedBackShiftRegisterGenerator.cpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include "LinearFeedBackShiftRegisterGenerator.hpp"
#include "math.h"

#pragma mark - Init

LinearFeedBackShiftRegisterGenerator::LinearFeedBackShiftRegisterGenerator(int key, int *polynomial, int size, int polySize) : linearRegister(key, polynomial, size, polySize)
{
}

#pragma mark - Generator

void LinearFeedBackShiftRegisterGenerator::generateValue(bool *bitArray, int N)
{
    for (int i = 0; i < N; i++)
    {
        bitArray[i] = linearRegister.generateBit();
    }
}

#pragma mark - Helpers

//long LinearFeedBackShiftRegisterGenerator::convertToDecimal(char *binaryValuesArray)
//{
//    long sum = 0;
//    for (int i = 0; i < WordSize; i++)
//    {
//        if (binaryValuesArray[i] == '1')
//        {
//            sum += pow(2, WordSize - 1 - i);
//        }
//    }
//    return sum;
//}
