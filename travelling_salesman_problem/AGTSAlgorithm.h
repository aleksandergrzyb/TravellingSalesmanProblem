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
    AGTSAlgorithm(AGCoordinationMatrix *coordinationMatrix) : coordinationMatrix(coordinationMatrix), numberOfSteps(0) {}
    ~AGTSAlgorithm();
    double routeDistance() const;
    double begginerRouteDistance() const;
    int routeSize() const;
    void createRandomRoute();
    void createNearestNeighbourRoute();
    void createGreedyRoute();
    void createSteepestRoute();
    void performTwoOpt(int cityOne, int cityTwo);
    void getRoute(std::vector<int>& route);
    int numberOfSteps;
    int numberOfEvaluations;
private:
    void reset();
    void preform2Opt(int& cityOne, int& cityTwo);
    int getNearestNeighbour(const int& city, std::set<int>& cities);
    std::vector<int> route;
    std::vector<int> begginerRoute;
    AGCoordinationMatrix *coordinationMatrix;
};

#endif /* defined(__travelling_salesman_problem__AGTSAlgorithm__) */
