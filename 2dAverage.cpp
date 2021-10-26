// Copyright (c) 2021 Trent Hodgins All rights reserved

// Created by Trent Hodgins
// Created on 10/26/2021
// This is the 2D Average program
// The program asks the user how many rows and cloumns they want
// The program generates random numbers between 1-50 to fill the rows/columns
// The program then figures out and displays the average of all the numbers

#include <iostream>
#include <random>


template <int rows, int columns>
int AvNumbers(int (&randomGrid)[rows][columns], int rowEle, int columnEle) {
    // this function adds up all the numbers in  a 2D array

    int average = 0;

    // process
    for (size_t rowVal = 0; rowVal < rows; rowVal++) {
        for (size_t columnVal = 0; columnVal < columns; columnVal++)
            average += randomGrid[rowVal][columnVal];
    }

    return average;
}


int main() {
    // this function uses a 2D array

    int randomNum = 0;
    int average;
    int divide = 0;
    const int rows = 1;
    const int columns = 2;
    int arr[rows][columns];

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(1, 50);

    // output
    for (int rowVal = 0; rowVal < rows; rowVal++) {
        for (int columnVal = 0; columnVal < columns; columnVal++) {
            randomNum = idist(rgen);
            arr[rowVal][columnVal] = randomNum;
            std::cout << randomNum << ", ";
        }
        std::cout << std::endl;
    }

    divide = rows * columns;
    average = AvNumbers(arr, rows, columns) / divide;
    std::cout << "" << std::endl;
    std::cout << "The average of all the numbers is: "
    << average << std::endl;
    std::cout << "\nDone." << std::endl;
}
