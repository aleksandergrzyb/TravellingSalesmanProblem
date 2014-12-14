//
//  AGTSAlgorithm.h
//  travelling_salesman_problem
//
//  Created by Aleksander Grzyb on 14/12/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#ifndef __travelling_salesman_problem__AGTSAlgorithm__
#define __travelling_salesman_problem__AGTSAlgorithm__

#include <stdio.h>
#include <set>
#include "AGCoordinationMatrix.h"

class AGTSAlgorithm {
public:
    AGTSAlgorithm(AGCoordinationMatrix *coordinationMatrix) : coordinationMatrix(coordinationMatrix) {}
    double routeDistance() const;
    int routeSize() const;
    void createRandomRoute();
    void createNearestNeighbourTour();
    void performTwoOpt();
    void getTour(std::vector<int>& tour);
private:
    void reset();
    int getNearestNeighbour(const int& city, std::set<int>& cities);
    std::vector<int> route;
    AGCoordinationMatrix *coordinationMatrix;
};

#endif /* defined(__travelling_salesman_problem__AGTSAlgorithm__) */
