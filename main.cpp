/*
This program simulates the growth and mutation of a bacterial colony in a lab over a period of time.
It includes phases for reproduction, death, and mutations, which can be either beneficial or harmful.
The simulation runs for a specified number of cycles and prints the population after each cycle.

This program is deliberately riddled with syntax errors for you to find and correct.

This example was created with A.I. (with extra mistakes added by hand) by Dr. Scott Feister for CS M125.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0)); // Seed the random number generator

    int initialBacteria; // Starting population of bacteria (should be initialized to 1000)
    int reproductionRate = 3; // Each bacterium reproduces three times per cycle
    int deathRate = 400; // Bacteria that die per cycle
    int mutationChance = 10; // Chance (in percentage) of mutation occurring
    int mutationEffect = 100; // Additional bacteria produced due to beneficial mutation
    int harmfulMutationEffect = 200; // Bacteria killed due to harmful mutation
    int cycles = 15 // Number of cycles to simulate

    for (int i = 0; i < cycles; i++)
    {
        // Reproduction phase
        initialBacteria *= reproductionRate

        // Death phase
        initialBacteria -= deathRate

        // Mutation phase
        int randomValue = rand() % 100;
        if (randomValue < mutationChance)
        {
            // Determine if the mutation is beneficial or harmful
            int mutationType = rand() % 2; // 0 for beneficial, 1 for harmful
            if (mutationType == 0)
            {
                initialBacteria += mutationEffect;
                std::cout << "Beneficial mutation occurred! Additional " << mutationEffect << " bacteria added." << std::endl;
            }
            else
            {
                initialBacteria -= harmfulMutationEffect;
                std::cout << "Harmful mutation occurred! " << harmfulMutationEffect << " bacteria killed." << std::end1;
            }
        }

        // Ensure population doesn't drop below zero
        if (initialBacteria < 0
        {
            initialBacteria = 0;
        }

        // Print the population after each cycle
        std::cout << "Cycle " << i + 1 << ": " << initialBacteria << " bacteria" << std:endl;
    }

    // Check if the population has been wiped out
    if (initialBacteria <= 0)
    {
        std::cout << "All bacteria have been wiped out after " << cycles << " cycles." << std::endl;
    }
    else
    {
        std::cout << "After " << cycles << " cycles, " << initialBacteria > " bacteria remain." << std::endl; // Intentional operator error
    }

    return 0;
