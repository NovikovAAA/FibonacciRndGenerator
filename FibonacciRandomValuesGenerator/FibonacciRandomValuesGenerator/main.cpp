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
#include "Gamma.hpp"

#define WordSize 32
#define DivisionValue 100000000000.0

using namespace std;

#pragma mark - Helpers

double* generateInputValuesForFibonacciGenerator(int countOfInputValues, int seed)
{
    bool *bitArray = new bool[WordSize];
    int polynomial[3] = {17, 14}; //x^17+x^14+1
    
    LinearFeedBackShiftRegisterGenerator generator(seed, polynomial, 17, 2, false);
    NumbersTranslator translator(WordSize);
    
    double *inputValues = new double[countOfInputValues];
    for (int i = 0; i < countOfInputValues; i++)
    {
        generator.generateValue(bitArray, WordSize);
        //printBitArray(bitArray, WordSize);
        
        double value = translator.decimalValueFromBitArray(bitArray, WordSize);
        //cout << (unsigned int)value << endl;
        inputValues[i] = value / DivisionValue;
    }
    return inputValues;
}

FibonacciGenerator createFibonacciGenerator(int lagA, int lagB, int seed)
{
    int countOfInputValues = max(lagA, lagB);
    double *inputValues = generateInputValuesForFibonacciGenerator(countOfInputValues, seed);
    
    FibonacciGenerator fibonacciGenerator(lagA, lagB, inputValues, countOfInputValues);
    return fibonacciGenerator;
}

#pragma mark - Main

int main(int argc, const char * argv[])
{
    string inputText = "";
    cout << "Введите шифруемую информацию:" << endl;
    getline(cin, inputText);
    
    FibonacciGenerator fibonacciGenerator(createFibonacciGenerator(17, 5, 1898));
    
    Gamma gamma(fibonacciGenerator, DivisionValue, false);
    string resultString = gamma.textGama(inputText);
    cout << "Crypted " << resultString << endl;
    
    FibonacciGenerator fibonacciGeneratorDecrypt(createFibonacciGenerator(17, 5, 1898));
    Gamma gammaDecrypt(fibonacciGeneratorDecrypt, DivisionValue, false);
    
    cout << endl << endl;
    cout << "Decrypted " << gammaDecrypt.textGama(resultString) << endl;
    
    return 0;
}
