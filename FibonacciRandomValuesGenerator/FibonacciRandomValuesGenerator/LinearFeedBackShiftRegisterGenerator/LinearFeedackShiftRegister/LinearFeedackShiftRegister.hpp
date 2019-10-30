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
    int polinomialSize;
    int keySize;
    
    int *polynomial;
    
public:
    int key;
    
    LinearFeedackShiftRegister();
    LinearFeedackShiftRegister(int key, int polynomial[], int size, int polySize);
    
    bool generateBit();
};

#endif /* LineaFeedackShiftRegister_hpp */
