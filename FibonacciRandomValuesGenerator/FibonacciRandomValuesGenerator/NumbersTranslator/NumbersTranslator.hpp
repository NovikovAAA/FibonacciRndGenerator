//
//  NumbersTranslator.hpp
//  FibonacciRandomValuesGenerator
//
//  Created by Артём Новиков on 31.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#ifndef NumbersTranslator_hpp
#define NumbersTranslator_hpp

#include <stdio.h>
#include "math.h"

class NumbersTranslator
{
public:
    NumbersTranslator();
    NumbersTranslator(int wordSize);
    
    unsigned int decimalValueFromBitArray(bool *bitArray, int size);
    void bitArrayFromDecimalValue(unsigned int value, bool *bitArray, int size);
    
private:
    int wordSize;
};

#endif /* NumbersTranslator_hpp */
