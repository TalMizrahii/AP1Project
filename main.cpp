//
// Created by yuval on 11/15/22.
//

#include<stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;




vector<double> insert_To_Vector() {
    double input;
    vector<double> vector;

    // user can add element as much as they want.
    while (cin >> input) {
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


int main() {
    vector<double> vector1;
    vector<double> vector2;

    vector1 =insert_To_Vector();
    vector2 =insert_To_Vector();
    if (vector1.size() != vector2.size()){
        cout << "The vectors is not the same size!"<< endl;
        return 0;
    }



    return 0;
}