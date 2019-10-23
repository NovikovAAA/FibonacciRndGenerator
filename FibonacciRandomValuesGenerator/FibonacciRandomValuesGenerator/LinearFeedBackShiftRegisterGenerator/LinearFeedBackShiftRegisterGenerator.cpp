//
//  LinearFeedBackShiftRegisterGenerator.cpp
//  lab4
//
//  Created by Артём Новиков on 23.10.2019.
//  Copyright © 2019 Артём Новиков. All rights reserved.
//

#include "LinearFeedBackShiftRegisterGenerator.hpp"

#pragma mark - Init

LinearFeedBackShiftRegisterGenerator::LinearFeedBackShiftRegisterGenerator()
{
    this->linearRegister = new LinearFeedackShiftRegister();
}

LinearFeedBackShiftRegisterGenerator::LinearFeedBackShiftRegisterGenerator(int *initialRegisterValues, int *polynomial, int size)
{
    this->linearRegister = new LinearFeedackShiftRegister(initialRegisterValues, polynomial, size);
}

#pragma mark - Generator

int LinearFeedBackShiftRegisterGenerator::generateValue()
{
    return 0;
}

#pragma mark - Helpers

int LinearFeedBackShiftRegisterGenerator::convertToDecimal()
{
    return 0;
}
