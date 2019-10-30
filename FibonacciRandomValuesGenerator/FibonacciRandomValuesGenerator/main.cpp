//
//  main.cpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include <iostream>
#include "LinearFeedBackShiftRegisterGenerator.hpp"

#define WordSize 32

using namespace std;

void printBitArray(bool *bitArray, int size);

int main(int argc, const char * argv[]) {
    int polynomial[3] = {17, 14};
    //x^17+x^14+1
    
    LinearFeedBackShiftRegisterGenerator generator(1898, polynomial, 17, 2);
    
    bool *bitArray = new bool[WordSize];
    generator.generateValue(bitArray, WordSize);
    
    printBitArray(bitArray, WordSize);
    
    return 0;
}

#pragma mark - Helpers

void printBitArray(bool *bitArray, int size) {
    for (int i = 0; i < size; i++) {
        cout << bitArray[i];
    }
    cout << endl;
}
