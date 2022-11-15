//
// Created by tal on 11/15/22.
//

#ifndef AP1PROJECT_DISTANCES_H
#define AP1PROJECT_DISTANCES_H

#include <vector>
#include <cmath>

using namespace std;

class Distances {

public:
    // The constructor of the class.
    Distances();
    // The Destructor of the class.
    ~Distances();
    // Calculates the Euclidean distance.
    double euclideanDistance(vector<double> v1, vector<double> v2);
    // Calculates the Taxicab distance.
    double taxicabDistance(vector<double> v1, vector<double> v2);
    // Calculates the Chebyshev distance.
    double chebyshevDistance(vector<double> v1, vector<double> v2);
    // Calculates the Canberra distance.
    double canberraDistance(vector<double> v1, vector<double> v2);
    // Calculates the minkowski distance.
    double minkowskiDistance(vector<double> v1, vector<double> v2);


};


#endif //AP1PROJECT_DISTANCES_H
