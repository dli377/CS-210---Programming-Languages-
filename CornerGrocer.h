#ifndef CORNER_GROCER_H
#define CORNER_GROCER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>

/*
 * CornerGrocer class
 */
class CornerGrocer {
public:
    // Constructor to initialize CornerGrocer object
    CornerGrocer(const std::string& inputFileName);
    void run();

private:
    // A map to store the frequency of each item (string) with its count (int)
    std::map<std::string, int> itemFrequencies;
    // Read input file name
    std::string inputFileName;

    bool readData();

    // Create backup data file named "frequency.dat"
    void createBackupFile();

    // Display user menu options to the console
    void displayMenu();

    // Process user's choice
    void processUserChoice(int choice);

    // Prompt user for an item and displays its purchase frequency
    void getItemFrequency();

    // Print a list of all items and their corresponding frequencies
    void printAllFrequencies();

    // Prints a histogram representing the frequency of each item
    void printHistogram();
    
    // Utility function to get validated integer input from user within a specified range
    int getValidatedInput(int min, int max);
};

#endif