//
//  main.cpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include <iostream>
#include "LinearFeedBackShiftRegisterGenerator.hpp"
#include "FibonacciGenerator.hpp"
#include "NumbersTranslator.hpp"

#define WordSize 32

using namespace std;

void printBitArray(bool *bitArray, int size);

int main(int argc, const char * argv[])
{
    bool *bitArray = new bool[WordSize];
    int polynomial[3] = {17, 14}; //x^17+x^14+1
    
    LinearFeedBackShiftRegisterGenerator generator(1898, polynomial, 17, 2);
    NumbersTranslator translator(WordSize);
    
    int lagA = 17;
    int lagB = 5;
    int countOfInputValues = max(lagA, lagB);
    
    double *inputValues = new double[countOfInputValues];
    for (int i = 0; i < countOfInputValues; i++)
    {
        generator.generateValue(bitArray, WordSize);
        printBitArray(bitArray, WordSize);
        double value = translator.decimalValueFromBitArray(bitArray, WordSize);
        cout << (unsigned int)value << endl;
        inputValues[i] = value / 10000000000.00;
    }
    cout << "--------------------------------" << endl;
    FibonacciGenerator fibonacciGenerator(lagA, lagB, inputValues, countOfInputValues);
    cout << "--------------------------------" << endl;
    cout << "Generated values" << endl;
    cout << "--------------------------------" << endl;
    
    for (int i = 0; i < 244; i++)
    {
        cout << fibonacciGenerator.generateValue() << endl;
    }
    
    return 0;
}

#pragma mark - Helpers

void printBitArray(bool *bitArray, int size) {
    for (int i = 0; i < size; i++) {
        cout << bitArray[i];
    }
    cout << endl;
}
