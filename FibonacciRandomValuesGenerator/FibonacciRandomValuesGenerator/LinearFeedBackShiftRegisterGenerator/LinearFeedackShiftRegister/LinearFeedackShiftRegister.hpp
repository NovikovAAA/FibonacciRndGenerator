//
//  LineaFeedackShiftRegister.hpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#ifndef LinearFeedackShiftRegister_hpp
#define LinearFeedackShiftRegister_hpp

#include <stdio.h>

class LinearFeedackShiftRegister
{
private:
    int size;
    
    int *registerValue;
    int *polynomial;
    
public:
    LinearFeedackShiftRegister();
    LinearFeedackShiftRegister(int initialRegisterValues[], int polynomial[], int size);
};

#endif /* LineaFeedackShiftRegister_hpp */
