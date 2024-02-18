//write include statements

#include <iostream>
#include "decisions.h"

int main() 
{
    int choice;
    int grade;

    std::cout << "MAIN MENU\n"
                 "1-Letter grade using if\n"
                 "2-Letter grade using switch\n"
                 "3-Exit\n"
                 "Enter your choice: ";
    std::cin >> choice;

    switch (choice) 
	{
        case 1:
            std::cout << "Enter numerical grade: ";
            std::cin >> grade;
            if (grade >= 0 && grade <= 100)
                std::cout << "Letter grade using if: " << get_letter_grade_using_if(grade) << std::endl;
            else
                std::cout << "Number is out of range!" << std::endl;
            break;
        case 2:
            std::cout << "Enter numerical grade: ";
            std::cin >> grade;
            if (grade >= 0 && grade <= 100)
                std::cout << "Letter grade using switch: " << get_letter_grade_using_switch(grade) << std::endl;
            else
                std::cout << "Number is out of range!" << std::endl;
            break;
        case 3:
            return 0;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
