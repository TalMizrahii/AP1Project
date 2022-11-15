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
    int i = 0;
    // Check if the first or last char in the input is ' ' and if the first char is '-'.
    if ((isdigit(s[i]) == false && s[i] != '-') || isdigit(s[s.length() - 1]) == false) {
        return false;
    }
    // Check each char of the user input.
    for (i = 1; i < s.length(); i++) {
        // Checking if the user input has 2 spaces neighbors.
        if ((s[i] == ' ' && s[i - 1] == ' ')) {
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
        // Checking if the chars are in valid negative format
        if (s[i] == '-') {
            // If we have '-' we must get a space in the prev char, otherwise not in format.
            if (i == s.length() - 1 || (s[i] == '-' && s[i - 1] != ' ')) {
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


/**
 * Creating a vector from user's input and checking if its valid.
 * @return Return a valid vector by the specified format of the task.
 */
vector<double> insert_To_Vector() {
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
    // Creating a vector from the user input string.
    istringstream vectorStream(input);
    while (vectorStream >> number) {
        vector.push_back(number);
    }
    return vector;
}

/**
 * The function check if the vectors we created have the same size.
 * @param v1 the vector we created from the user input.
 * @param v2 the vector we created from the user input.
 */
void size_Comparison(const vector<double> &v1, const vector<double> &v2) {
    // Checking if the vectors have the same size.
    if (v1.size() != v2.size()) {
        cout << "The vectors are not equally sized." << endl;
        exit(0);
    }
}


/**
 * This is the main function of the program, creating 2 vectors and checking validation.
 *
 * @return return 0 if the program run without issues.
 */
int main() {
    // Creating two vectors from the user's inputs.
    vector<double> vector1 = insert_To_Vector();
    vector<double> vector2 = insert_To_Vector();
    // Calling a function that check if the vectors have the same size.
    size_Comparison(vector1, vector2);
    // Creating a Distance instance.
    Distances D;
    // Printing all distances calculations.
    D.printAll(vector1, vector2);
    return 0;
}