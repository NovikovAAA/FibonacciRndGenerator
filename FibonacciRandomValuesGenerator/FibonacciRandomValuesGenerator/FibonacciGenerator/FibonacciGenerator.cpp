//
//  FibonacciGenerator.cpp
//  FibonacciRandomValuesGenerator
//
//  Created by Артём Новиков on 31.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include "FibonacciGenerator.hpp"
#include "iostream"
#include "stdlib.h"
#include "time.h"

using namespace std;

#pragma mark - Init

FibonacciGenerator::FibonacciGenerator()
{
    this->lagA = 17;
    this->lagB = 5;
    this->currentK = 18;
    this->startValuesSize = 17;
    
    srand(time_t(0));
    this->startedValues = new double[this->startValuesSize];
    for (int i = 0; i < this->startValuesSize; i++)
    {
        this->startedValues[i] = rand();
    }
}

FibonacciGenerator::FibonacciGenerator(int lagA, int lagB, double *startValues, int size)
{
    this->lagA = lagA;
    this->lagB = lagB;
    this->currentK = size;
    this->startValuesSize = size;
    
    this->startedValues = new double[size];
    for (int i = 0; i < size; i++)
    {
        this->startedValues[i] = startValues[i];
        cout << this->startedValues[i] << endl;
    }
}

#pragma mark - Generation

double FibonacciGenerator::generateValue()
{    
    double Yka = startedValues[currentK - lagA];
    double Ykb = startedValues[currentK - lagB];
    
    currentK++;
    
    double result;
    if (Yka >= Ykb)
    {
        result = Yka - Ykb;
        addNewElemToSequence(result);
        return result;
    }
    result = Yka - Ykb + 1;
    addNewElemToSequence(result);
    return result;
}

#pragma mark - Helpers

int FibonacciGenerator::indexOfElem(int firstValue, int secondValue)
{
    int index = firstValue - secondValue;
    return index < 0 ? startValuesSize + index : index;
}

void FibonacciGenerator::addNewElemToSequence(double elem)
{
    startValuesSize++;
    
    double *newValuesSequence = new double[startValuesSize];
    for (int i = 0; i < startValuesSize - 1; i++)
    {
        newValuesSequence[i] = startedValues[i];
    }
    newValuesSequence[startValuesSize - 1] = elem;
    
    delete [] startedValues;
    startedValues = newValuesSequence;
}
