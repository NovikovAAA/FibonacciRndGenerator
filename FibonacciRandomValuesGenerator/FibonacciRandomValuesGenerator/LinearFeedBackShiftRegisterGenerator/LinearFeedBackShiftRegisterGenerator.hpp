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

class LinearFeedBackShiftRegisterGenerator {
private:
    LinearFeedackShiftRegister *linearRegister;
    
    int convertToDecimal();
    
public:
    LinearFeedBackShiftRegisterGenerator();
    LinearFeedBackShiftRegisterGenerator(int initialRegisterValues[], int polynomial[], int size);
    
    int generateValue();
};

#endif /* LinearFeedBackShiftRegisterGenerator_hpp */