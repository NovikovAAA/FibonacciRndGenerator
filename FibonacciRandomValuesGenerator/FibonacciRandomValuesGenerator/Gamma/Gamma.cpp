//
//  Gamma.cpp
//  FibonacciRandomValuesGenerator
//
//  Created by Артём Новиков on 02.11.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include "Gamma.hpp"
#include "iostream"

#define BlockSize 32
#define BitesInByte 8

#pragma mark - Init

Gamma::Gamma()
{
    this->divisionValue = 100000000000.0;
    this->numbersTranslator = NumbersTranslator(BlockSize);
    this->isDebug = false;
}

Gamma::Gamma(FibonacciGenerator generator, double divisionValue, bool isDebug)
{
    this->numbersTranslator = NumbersTranslator(BlockSize);
    this->generator = generator;
    this->divisionValue = divisionValue;
    this->isDebug = isDebug;
}

#pragma mark - Gamma

string Gamma::textGama(string text)
{
    int blocksCount = (int)text.length() * BitesInByte / BlockSize;
    blocksCount += (int)text.length() * BitesInByte % BlockSize != 0 ? 1 : 0;
    
    string resultString = "";
    for (int i = 0; i < blocksCount; i++)
    {
        for (int j = 0; j < BlockSize / BitesInByte; j++)
        {
            bool bitsArray[BlockSize] = {};
            int position = i * BlockSize / BitesInByte + j;
            char cryptedSymbol = text.length() > position ? text[position] : '\0';
            numbersTranslator.bitArrayFromDecimalValue(cryptedSymbol, bitsArray, BlockSize);
            
            bool generatedBitsArray[BlockSize] = {};
            unsigned int generatedValue = generator.generateValue() * divisionValue;
            
            numbersTranslator.bitArrayFromDecimalValue(generatedValue, generatedBitsArray, BlockSize);
            bitsArrayToByte(generatedBitsArray);
            
            if (isDebug)
            {
                numbersTranslator.printBitArray(bitsArray, BlockSize);
                numbersTranslator.printBitArray(generatedBitsArray, BlockSize);
            }
            
            gammaByte(bitsArray, generatedBitsArray);
            
            if (isDebug)
            {
                cout << "Gamma:" << endl;
                numbersTranslator.printBitArray(bitsArray, BlockSize);
            }

            bitsArrayToByte(bitsArray);
            
            if (isDebug)
            {
                cout << "Result:" << endl;
                numbersTranslator.printBitArray(bitsArray, BlockSize);
                cout << "---------------------------" << endl;
            }
            
            int symbolCode = numbersTranslator.decimalValueFromBitArray(bitsArray, BlockSize);
            char symbol = symbolCode;
            resultString += symbol;
        }
    }
    
    return resultString;
}

#pragma mark - Helpers

void Gamma::gammaByte(bool *bitsArray, bool *generatedBitsArray)
{
    for (int i = 0; i < BlockSize; i++)
    {
        bitsArray[i] ^= generatedBitsArray[i];
    }
}

void Gamma::bitsArrayToByte(bool *bitsArray)
{
    for (int i = 0; i < BlockSize - BitesInByte; i++)
    {
        bitsArray[i] = false;
    }
}
