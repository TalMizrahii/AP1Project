//
// Created by tal on 11/15/22.
//

#include "Distances.h"


/**
 * A constructor for the class.
 */
Distances::Distances() {

}

/**
 * Calculating the Euclidean distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Euclidean distance between the two vectors.
 */
double Distances::euclideanDistance(vector<double> v1, vector<double> v2) {
    // Setting the result to 0.
    double result = 0;
    // Iterating over the indexes in each vector, calculating the subtraction between them and adding to result.
    for (int i = 0; i < v1.size(); i++) {
        result += pow(v1[i] - v2[i], 2);
    }
    // Returning the square root of the result.
    return sqrt(result);
}

/**
 * Calculating the Taxicab Geometry distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Taxicab Geometry distance between the two vectors.
 */
double Distances::taxicabDistance(vector<double> v1, vector<double> v2) {
    // Setting the result to 0.
    double result = 0;
    // Iterating over the indexes in each vector.
    for (int i = 0; i < v1.size(); i++) {
        // Calculating the subtraction between them in absolute value and adding to result.
        result += fabs(v1[i] - v2[i]);
    }
    // Returning the result.
    return result;
}

/**
 * Calculating the Chebyshev distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Chebyshev distance between the two vectors.
 */
double Distances::chebyshevDistance(vector<double> v1, vector<double> v2) {
    // Setting the maximum to the first couple of points.
    double max = fabs(v1[0] - v2[0]);
    double temp;
    // Iterating over the indexes in each vector.
    for (int i = 1; i < v1.size(); i++) {
        // Setting the temp to be the value of distance between v1[i] to v2[i].
        temp = fabs(v1[0] - v2[0]);
        // If temp is bigger than max, max is now temp.
        if (temp > max)
            max = temp;
    }
    // Return the maximum value.
    return max;
}

/**
 * Calculating the Canberra distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Canberra distance between the two vectors.
 */
double Distances::canberraDistance(vector<double> v1, vector<double> v2) {
    // Setting the result to 0.
    double result = 0;
    // Iterating over the indexes in each vector.
    for (int i = 0; i < v1.size(); i++) {
        // Avoiding division by 0.
        if(v1[i] == 0 && v2[i] == 0){
            continue;
        }
        // Calculating the subtraction between them in absolute value, dividing by each index in absolut value,
        // and adding to result.
        result += fabs(v1[i] - v2[i]) / (fabs(v1[i]) + fabs(v2[i]));
    }
    // Returning the result.
    return result;
}


double Distances::minkowskiDistance(vector<double> v1, vector<double> v2) {
    // Setting the result to 0.
    double result = 0;
    // The constant value of the exponent P in the Minkowski algorithm.
    const int P = 2;
    // Iterating over the indexes in each vector.
    for (int i = 0; i < v1.size(); i++) {
        // Calculating the subtraction between them in absolute value and adding to result.
        result += pow(fabs(v1[i] - v2[i]), P);
    }
    // Returning the result.
    return pow(result, 1/P);
}

Distances::~Distances() {

}
