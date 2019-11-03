//
//  LinearFeedBackShiftRegisterGenerator.hpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#ifndef LinearFeedBackShiftRegisterGenerator_hpp
#define LinearFeedBackShiftRegisterGenerator_hpp

#include <stdio.h>
#include "LinearFeedackShiftRegister.hpp"

class LinearFeedBackShiftRegisterGenerator
{
private:
    LinearFeedackShiftRegister linearRegister;
    NumbersTranslator numbersTranslator;
    
    long convertToDecimal(char *resultArray);
public:
    bool isDebug;
    
    LinearFeedBackShiftRegisterGenerator(int key, int polynomial[], int size, int polySize, bool isDebug);
    void generateValue(bool *bitArray, int N);
};

#endif /* LinearFeedBackShiftRegisterGenerator_hpp */
