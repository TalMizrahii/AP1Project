//
// Created by tal on 11/15/22.
//

#include "Distances.h"

Distances::Distances() {

}

double Distances::euclideanDistance(vector<double> v1, vector<double> v2) {
    double result = 0;
    for (int i = 0; i < v1.size(); i++){
        result += pow(v1[i] - v2[i], 2);
    }
    return sqrt(result);
}

double Distances::taxicabDistance(vector<double> v1, vector<double> v2) {
    return 0;
}

double Distances::chebyshevDistance(vector<double> v1, vector<double> v2) {
    return 0;
}

double Distances::canberraDistance(vector<double> v1, vector<double> v2) {
    return 0;
}

double Distances::minkowskiDistance(vector<double> v1, vector<double> v2) {
    return 0;
}

Distances::~Distances() {

}
