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
#include <numeric> // IWYU pragma: keep

int main()
{
    srand(time(0)); // Seed the random number generator

    const int reproductionRate = 3; // Each bacterium reproduces three times per cycle
    const int deathRate = 400; // Bacteria that die per cycle
    const int mutationChance = 10; // Chance (in percentage) of mutation occurring
    const int mutationEffect = 100; // Additional bacteria produced due to beneficial mutation
    const int harmfulMutationEffect = 200; // Bacteria killed due to harmful mutation
    const int cycles = 15; // Number of cycles to simulate

    unsigned long bacteria = 1000; // Starting population of bacteria

    for (int i = 0; i < cycles; i++)
    {
        // Reproduction phase
        bacteria = std::mul_sat<unsigned long>(bacteria, reproductionRate);

        // Death phase
        bacteria = std::sub_sat<unsigned long>(bacteria, deathRate);

        // Mutation phase
        int randomValue = rand() % 100;
        if (randomValue < mutationChance)
        {
            // Determine if the mutation is beneficial or harmful
            int mutationType = rand() % 2; // 0 for beneficial, 1 for harmful
            if (mutationType == 0)
            {
                bacteria = std::add_sat<unsigned long>(bacteria, mutationEffect);
                std::cout << "Beneficial mutation occurred! Additional " << mutationEffect << " bacteria added." << std::endl;
            }
            else
            {
                bacteria = std::sub_sat<unsigned long>(bacteria, harmfulMutationEffect);
                std::cout << "Harmful mutation occurred! " << harmfulMutationEffect << " bacteria killed." << std::endl;
            }
        }

        // Ensure population doesn't drop below zero
        if (bacteria < 0)
        {
            bacteria = 0;
        }

        // Print the population after each cycle
        std::cout << "Cycle " << i + 1 << ": " << bacteria << " bacteria" << std::endl;
    }

    // Check if the population has been wiped out
    if (bacteria <= 0)
    {
        std::cout << "All bacteria have been wiped out after " << cycles << " cycles." << std::endl;
    }
    else
    {
        std::cout << "After " << cycles << " cycles, " << bacteria << " bacteria remain." << std::endl;
    }

    return 0;
}
