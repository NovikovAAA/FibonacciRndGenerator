//
//  Gamma.hpp
//  FibonacciRandomValuesGenerator
//
//  Created by Артём Новиков on 02.11.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#ifndef Gamma_hpp
#define Gamma_hpp

#include <stdio.h>
#include <string>
#include "FibonacciGenerator.hpp"
#include "NumbersTranslator.hpp"

using namespace std;

class Gamma {
public:
    Gamma();
    Gamma(FibonacciGenerator generator, double divisionValue, bool isDebug);
    
    string textGama(string text);
    
    bool isDebug;
    
private:
    FibonacciGenerator generator;
    NumbersTranslator numbersTranslator;
    
    double divisionValue;
    
    void gammaByte(bool *bitsArray, bool *generatedBitsArray);
    void bitsArrayToByte(bool *bitsArray);
};

#endif /* Gamma_hpp */
