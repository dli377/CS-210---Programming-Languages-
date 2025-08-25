#include "CornerGrocer.h"

// Constructor implementation
CornerGrocer::CornerGrocer(const std::string& inputFileName) : inputFileName(inputFileName) {
    // Read data from object initialization
    if (readData()) {
        // If data is read successfully, create backup file
        createBackupFile();
    } else {
        // If data reading fails, print an error and exit
        std::cerr << "Error: Could not open or read the input file: " << inputFileName << std::endl;
        exit(1);
    }
}

// Main program loop
void CornerGrocer::run() {
    int choice = 0;
    // Loop until user chooses to exit
    while (choice != 4) {
        displayMenu();
        choice = getValidatedInput(1, 4);
        processUserChoice(choice);
    }
}

// Read data from the input file
bool CornerGrocer::readData() {
    std::ifstream inFile(this->inputFileName);
    std::string item;

    // Check if the file was opened successfully
    if (!inFile.is_open()) {
        return false;
    }

    // Read each line (item) from the file
    while (inFile >> item) {
        itemFrequencies[item]++;
    }

    inFile.close();
    return true;
}

// Creates backup data file
void CornerGrocer::createBackupFile() {
    std::ofstream outFile("frequency.dat");

    // Check if file was created successfully
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create backup file." << std::endl;
        return;
    }

    // Write each item and its frequency to the backup file.
    for (const auto& pair : itemFrequencies) {
        outFile << pair.first << " " << pair.second << std::endl;
    }

    outFile.close();
}

// Displays the user menu
void CornerGrocer::displayMenu() {
    std::cout << "\n==================================================\n";
    std::cout << "            Corner Grocer Menu\n";
    std::cout << "==================================================\n";
    std::cout << "1. Look up the frequency of a specific item\n";
    std::cout << "2. Print the frequency of all items\n";
    std::cout << "3. Print a histogram of item frequencies\n";
    std::cout << "4. Exit\n";
    std::cout << "==================================================\n";
    std::cout << "Enter your choice: ";
}

// Process user's menu choice
void CornerGrocer::processUserChoice(int choice) {
    switch (choice) {
    case 1:
        getItemFrequency();
        break;
    case 2:
        printAllFrequencies();
        break;
    case 3:
        printHistogram();
        break;
    case 4:
        std::cout << "Exiting program. Goodbye!\n";
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
}

// Get the frequency of a specific item from user input
void CornerGrocer::getItemFrequency() {
    std::string item;
    std::cout << "Enter the item you wish to look for: ";
    std::cin >> item;

    // Capitalize the first letter for consistency
    if (!item.empty()) {
        item[0] = toupper(item[0]);
        for (size_t i = 1; i < item.length(); ++i) {
            item[i] = tolower(item[i]);
        }
    }

    // Check if item exists in the map
    if (itemFrequencies.count(item)) {
        std::cout << "Frequency of " << item << ": " << itemFrequencies[item] << std::endl;
    } else {
        std::cout << "Item '" << item << "' not found." << std::endl;
    }
}

// Prints the frequency of all items
void CornerGrocer::printAllFrequencies() {
    std::cout << "\n--- All Item Frequencies ---\n";
    // Iterate through the map and print each item and its frequency
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "----------------------------\n";
}

// Prints a histogram of item frequencies
void CornerGrocer::printHistogram() {
    std::cout << "\n--- Item Frequency Histogram ---\n";
    // Iterate through the map and print a histogram bar for each item
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << " ";
        // Print asterisks corresponding to the frequency
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------\n";
}

// Get validated integer input from user
int CornerGrocer::getValidatedInput(int min, int max) {
    int choice;
    while (!(std::cin >> choice) || choice < min || choice > max) {
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        // Clear the error flag on cin
        std::cin.clear();
        // Discard the rest of the line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choice;
}

// Main function to run the program
int main() {
    CornerGrocer grocer("CS210_Project_Three_Input_File.txt");
    grocer.run();
    return 0;
}