#include "func.h"
#include <iostream>

int main() 
{
    int choice;
    std::string dna;
    do {
        std::cout << "Menu\n1- Get GC Content\n2- Get DNA Complement\n3- Exit\nEnter your choice: ";
        std::cin >> choice;
        switch (choice) 
        {
            case 1:
                std::cout << "Enter DNA string: ";
                std::cin >> dna;
                std::cout << "GC Content: " << get_gc_content(dna) << "%\n";
                break;
            case 2:
                std::cout << "Enter DNA string: ";
                std::cin >> dna;
                std::cout << "DNA Complement: " << get_dna_complement(dna) << "\n";
                break;
            case 3:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (true);

    return 0;
}
