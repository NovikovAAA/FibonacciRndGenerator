//
//  FibonacciGenerator.hpp
//  FibonacciRandomValuesGenerator
//
//  Created by Артём Новиков on 31.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#ifndef FibonacciGenerator_hpp
#define FibonacciGenerator_hpp

#include <stdio.h>

class FibonacciGenerator
{
public:
    FibonacciGenerator();
    FibonacciGenerator(const FibonacciGenerator &obj);
    FibonacciGenerator(int lagA, int lagB, double *startValues, int size);
    
    int lagA;
    int lagB;
    
    double *startedValues;
    int startValuesSize;
    
    int currentK;
    
    double generateValue();
private:
    int indexOfElem(int firstValue, int secondValue);
    void addNewElemToSequence(double elem);
};

#endif /* FibonacciGenerator_hpp */
