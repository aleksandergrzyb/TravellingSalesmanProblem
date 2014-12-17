//
//  main.cpp
//  travelling_salesman_problem
//
//  Created by Aleksander Grzyb on 14/12/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#include <iostream>
#include "AGCoordinationMatrix.h"
#include "AGTSAlgorithm.h"
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <time.h>

using namespace std;

double calculateAverage(vector<double>& results)
{
    double sum = 0.0;
    for (int i = 0; i < results.size(); i++) {
        sum += results[i];
    }
    return sum / (double)results.size();
}

double calculateMaximum(vector<double>& results) {
    double largestDistance = 0.0;
    for (int i = 0; i < results.size(); i++) {
        if (results[i] > largestDistance) {
            largestDistance = results[i];
        }
    }
    return largestDistance;
}

double calculateMinimum(vector<double>& results) {
    double smallestDistance = 999999999;
    for (int i = 0; i < results.size(); i++) {
        if (results[i] < smallestDistance) {
            smallestDistance = results[i];
        }
    }
    return smallestDistance;
}

double calculateStandardDeviation(vector<double>& results, double average)
{
    double sum = 0.0;
    for (int i = 0; i < results.size(); i++) {
        sum += pow((results[i] - average), 2);
    }
    sum = sum / results.size();
    sum = sqrt(sum);
    return sum;
}

int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    string names[] = {"berlin52", "eil76", "eil51", "pr76", "kroC100", "kroA100", "rat99", "st70"};
    double optimums[] = {7542, 538, 426, 108159, 20749, 21282, 1211, 675};
    double numberOfIterations[] = {10, 50, 100, 150, 200, 250, 300};
    
//    vector<double> beginnerSolutions;
//    vector<double> endSolutions;
    
//    vector<double> solutions;
//    
//    AGCoordinationMatrix *coordinationMatrix = new AGCoordinationMatrix("/Users/aleksandergrzyb/Dropbox/studies/studia_magisterskie/semestr_9/metaheurystyki_i_obliczenia_inspirowanie_biologicznie/sprawozdanie_1/travelling_salesman_problem/travelling_salesman_problem/berlin52.tsp");
//    AGTSAlgorithm *tsAlgorithm = new AGTSAlgorithm(coordinationMatrix);
//    
//    for (int i = 0; i < 7; i++) {
//        for (int a = 0; a < numberOfIterations[i]; a++) {
//            tsAlgorithm->createGreedyRoute();
//            solutions.push_back(tsAlgorithm->routeDistance());
//        }
//        cout << "Number of iterations: " << numberOfIterations[i] << endl;
//        cout << "Average: " << calculateAverage(solutions) << endl;
//        cout << "Best: " << calculateMinimum(solutions) << endl;
//        solutions.clear();
//    }
    
    
//    Task 3
//    for (int i = 0; i < 200; i++) {
//        tsAlgorithm->createSteepestRoute();
//        beginnerSolutions.push_back(tsAlgorithm->begginerRouteDistance());
//        endSolutions.push_back(tsAlgorithm->routeDistance());
//    }
//    
//    for (int i = 0; i < beginnerSolutions.size(); i++) {
//        cout << beginnerSolutions[i] << endl;
//    }
//    
//    for (int i = 0; i < endSolutions.size(); i++) {
//        cout << endSolutions[i] << endl;
//    }
    
    
//    Task 2
    for (int i = 0; i < 8; i++) {
        string wholePath = "/Users/aleksandergrzyb/Dropbox/studies/studia_magisterskie/semestr_9/metaheurystyki_i_obliczenia_inspirowanie_biologicznie/sprawozdanie_1/travelling_salesman_problem/travelling_salesman_problem/";
        wholePath += names[i];
        wholePath += ".tsp";
        
        AGCoordinationMatrix *coordinationMatrix = new AGCoordinationMatrix(wholePath.c_str());
        AGTSAlgorithm *tsAlgorithm = new AGTSAlgorithm(coordinationMatrix);
        
        vector<double> results;
//        double average = 0.0;
//        double time = 0.0;
//        clock_t start = 0.0;
//        clock_t end = 0.0;
    
//        for (int a = 0; a < 200; a++) {
//            if (a == 0) {
//                start = clock();
//            }
//            tsAlgorithm->createRandomRoute();
//            if (a == 0) {
//                end = clock();
//                time = (double)(end - start);
//            }
//            results.push_back(tsAlgorithm->routeDistance() - optimums[i]);
//        }
//        average = calculateAverage(results);
//        cout << names[i] << " " << " Random " << "Time: " << time / CLOCKS_PER_SEC << endl;
//        cout << names[i] << " " << " Random " << "Number of Steps: " << tsAlgorithm->numberOfSteps << endl;
//        cout << names[i] << " " << " Random " << "Average: " << average << endl;
//        cout << names[i] << " " << " Random " << "Max: " << calculateMaximum(results) << endl;
//        cout << names[i] << " " << " Random " << "Standard Deviation: " << calculateStandardDeviation(results, average) << endl;
//        results.clear();
//        average = 0.0;
//        time = 0.0;
        
        
        
//        for (int a = 0; a < 200; a++) {
//            if (a == 0) {
//                start = clock();
//            }
//            tsAlgorithm->createNearestNeighbourRoute();
//            if (a == 0) {
//                end = clock();
//                time = (double)(end - start);
//            }
//            results.push_back(tsAlgorithm->routeDistance() - optimums[i]);
//        }
//        average = calculateAverage(results);
//        cout << names[i] << " " << " NearestNeighbour " << "Time: " << time / CLOCKS_PER_SEC << endl;
//        cout << names[i] << " " << " NearestNeighbour " << "Number of Steps: " << tsAlgorithm->numberOfSteps << endl;
//        cout << names[i] << " " << " NearestNeighbour " << "Average: " << average << endl;
//        cout << names[i] << " " << " NearestNeighbour " << "Max: " << calculateMaximum(results) << endl;
//        cout << names[i] << " " << " NearestNeighbour " << "Standard Deviation: " << calculateStandardDeviation(results, average) << endl;
//        results.clear();
//        average = 0.0;
//        time = 0.0;
        
        
        
        for (int a = 0; a < 200; a++) {
//            if (a == 0) {
//                start = clock();
//            }
            tsAlgorithm->createGreedyRoute();
//            if (a == 0) {
//                end = clock();
//                time = (double)(end - start);
//            }
//            results.push_back(tsAlgorithm->routeDistance() - optimums[i]);
        }
//        average = calculateAverage(results);
//        cout << names[i] << " " << " Greedy " << "Time: " << time / CLOCKS_PER_SEC << endl;
//        cout << names[i] << " " << " Greedy " << "Number of Steps: " << tsAlgorithm->numberOfSteps << endl;
        cout << names[i] << " " << " Greedy " << "Number of Evaluations: " << tsAlgorithm->numberOfEvaluations << endl;
//        cout << names[i] << " " << " Greedy " << "Average: " << average << endl;
//        cout << names[i] << " " << " Greedy " << "Max: " << calculateMaximum(results) << endl;
//        cout << names[i] << " " << " Greedy " << "Standard Deviation: " << calculateStandardDeviation(results, average) << endl;
//        results.clear();
//        average = 0.0;
//        time = 0.0;
        
        
        
        for (int a = 0; a < 200; a++) {
//            if (a == 0) {
//                start = clock();
//            }
            tsAlgorithm->createSteepestRoute();
//            if (a == 0) {
//                end = clock();
//                time = (double)(end - start);
//            }
//            results.push_back(tsAlgorithm->routeDistance() - optimums[i]);
        }
//        average = calculateAverage(results);
//        cout << names[i] << " " << " Steepest " << "Time: " << time / CLOCKS_PER_SEC << endl;
//        cout << names[i] << " " << " Steepest " << "Number of Steps: " << tsAlgorithm->numberOfSteps << endl;
        cout << names[i] << " " << " Steepest " << "Number of Evaluations: " << tsAlgorithm->numberOfEvaluations << endl;
//        cout << names[i] << " " << " Steepest " << "Average: " << average << endl;
//        cout << names[i] << " " << " Steepest " << "Max: " << calculateMaximum(results) << endl;
//        cout << names[i] << " " << " Steepest " << "Standard Deviation: " << calculateStandardDeviation(results, average) << endl;
//        results.clear();
//        average = 0.0;
//        time = 0.0;
        
        delete coordinationMatrix;
        delete tsAlgorithm;
    }
    return 0;
}
