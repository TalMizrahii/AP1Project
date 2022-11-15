//
// Created by yuval on 11/15/22.
//

#include<stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Distances.h"

using namespace std;

/**
 * Checking if the user input is in the right format.
 * @param s a string that the user entered.
 * @return boolean, True if the the string in the right format False otherwise.
 */
bool isNumber(string s) {
    // Check each char of the user input.
    for (int i = 0; i < s.length(); i++) {
        // Check if the first or last char in the input is ' '.
        if ((isdigit(s[0]) == false) || (isdigit(s[s.length() - 1]) == false)) {
            return false;
        }
        // Checking if the user input has 2 spaces neighbors.
        if (i > 0 && (s[i] == ' ' && s[i - 1] == ' ')) {
            return false;
        }
        // Checking if there is a space , if we have only 1 space, the format is still correct.
        if (s[i] == ' ') {
            continue;
        }
        // Checking if the user input a valid floating point number.
        if (s[i] == '.') {
            // Checking if not accessing out of scoping our array.
            if (i == s.length() - 1) {
                return false;
            }
            // If we have '.' we must get a number in the next char, otherwise not in format.
            if (isdigit(s[i + 1]) == false || isdigit(s[i - 1]) == false) {
                return false;
            }
            continue;
        }
        // Checking if the char is a digit.
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
    return true;
}

//DELETE
void print(std::vector<double> const &vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector.at(i) << ' ';
    }
    cout << "" << endl;
}


/**
 *
 * @return Return a valid vector by the specified format of the task.
 */
vector<double> insert_To_Vector1() {
    string input;
    double number;
    vector<double> vector;
    // Using a stream function to get a string from the user.
    getline(cin, input);
    // Send the string to be checked for validation.
    if (!isNumber(input)) {
        cout << "Illegal format" << endl;
        exit(0);
    }
    // Making a vector from the user input string.
    istringstream vectorStream(input);
    while (vectorStream >> number) {
        vector.push_back(number);
    }
    return vector;
}

/**
 *
 * @return return 0 if the program run without issues.
 */
int main() {
    // Creating two vectors from the user's inputs.
    vector<double> vector1= insert_To_Vector1();
    vector<double> vector2 = insert_To_Vector1();

    // Checking if the vectors have the same size.
    if (vector1.size() != vector2.size()) {
        cout << "The vectors is not the same size!" << endl;
        return 0;
    }

    Distances D;
    D.printAll(vector1, vector2);


    return 0;
}