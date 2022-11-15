//
// Created by yuval on 11/15/22.
//

#include<stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


bool isNumber(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[0]) == false) {
            return false;
        }
        if (i > 0 && (s[i] == ' ' && s[i - 1] == ' ')) {
            return false;
        }
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] == '.') {
            if (isdigit(s[i + 1]) == false) {
                return false;
            }
            continue;
        }


        if (isdigit(s[i]) == false)
            return false;
    }
    return true;
}


void print(std::vector<double> const &vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector.at(i) << ' ';
    }
    cout << "" << endl;

}

/**
vector<double> insert_To_Vector() {
    double input;
    vector<double> vector;

    // user can add element as much as they want.
    while (cin >> input) {

        if (input == '32') {
            continue;
        }

        //checking if the user input is a digit or not.
        if (!isdigit((int) input)) {
            cout << "Illegal input try again!" << endl;
            continue;
        }
        // adding the checked input into the vector.
        vector.push_back(input);
    }
    return vector;
};
 **/


vector<double> insert_To_Vector1() {
    string input;
    double number;
    vector<double> vector;
    getline(cin, input);
    if (!isNumber(input)) {
        cout << "Illegal format" << endl;
        exit(0);
    }
    istringstream vectorStream(input);
    while (vectorStream >> number) {
        vector.push_back(number);
    }
    return vector;


};


int main() {
    vector<double> vector1;
    vector<double> vector2;

    vector1 = insert_To_Vector1();
    vector2 = insert_To_Vector1();
    print(vector1);
    print(vector2);
    if (vector1.size() != vector2.size()) {
        cout << "The vectors is not the same size!" << endl;
        return 0;
    }
    print(vector1);
    print(vector2);

    return 0;
}