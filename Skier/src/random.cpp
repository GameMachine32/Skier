/*
   This code was written for the skier game.
*/
#include <stdio.h>
#ifndef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <time.h>
#include "random.h"
/** This is the namespace that contains functions to return random numbers. */
namespace random
{
    /// This function returns a random number from a certain range the user puts in.
    /// @param a (int), b (int)
    int randRange(int a, int b)
    {
        return rand() % b + a;
    }
    /// This function generates a seeded number to use random numbers off of
    /// @param number (int)
    void seed(int number)
    {
        srand(number);
    }
    /// This just sets up the random numbers
    void randomNumber()
    {
        rand();
    }
}
