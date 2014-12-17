//
//  AGTSAlgorithm.cpp
//  travelling_salesman_problem
//
//  Created by Aleksander Grzyb on 14/12/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#include "AGTSAlgorithm.h"
#include <algorithm>
#include <stdlib.h>
#include <cmath>

using namespace std;

AGTSAlgorithm::~AGTSAlgorithm()
{
    this->route.clear();
}

void AGTSAlgorithm::createRandomRoute()
{
    this->reset();
    this->numberOfSteps = 0;
    for (int i = 0; i < this->coordinationMatrix->numberOfCities(); i++) {
        this->route.push_back(i);
        this->numberOfSteps++;
    }
    random_shuffle(this->route.begin() + 1, this->route.end());
}

double AGTSAlgorithm::routeDistance() const
{
    double distance = 0.0;
    int routeSize = (int)this->route.size();
    int city1, city2;
    for (int i = 0; i < routeSize - 1; i++) {
        city1 = this->route[i];
        city2 = this->route[i + 1];
        distance += this->coordinationMatrix->getDistance(city1, city2);
    }
    // Add distance to the beginning city
    city1 = this->route[routeSize - 1];
    city2 = this->route[0];
    distance += this->coordinationMatrix->getDistance(city1, city2);
    return distance;
}

double AGTSAlgorithm::begginerRouteDistance() const
{
    double distance = 0.0;
    int routeSize = (int)this->begginerRoute.size();
    int city1, city2;
    for (int i = 0; i < routeSize - 1; i++) {
        city1 = this->begginerRoute[i];
        city2 = this->begginerRoute[i + 1];
        distance += this->coordinationMatrix->getDistance(city1, city2);
    }
    // Add distance to the beginning city
    city1 = this->begginerRoute[routeSize - 1];
    city2 = this->begginerRoute[0];
    distance += this->coordinationMatrix->getDistance(city1, city2);
    return distance;
}

int AGTSAlgorithm::routeSize() const
{
    return (int)this->route.size();
}

void AGTSAlgorithm::reset()
{
    this->route.clear();
    this->begginerRoute.clear();
}

void AGTSAlgorithm::createNearestNeighbourRoute()
{
    this->reset();
    this->numberOfSteps = 0;
    set<int> citiesSet;
    set<int>::iterator it;
    for (int i = 0; i < this->coordinationMatrix->numberOfCities(); i++) {
        citiesSet.insert(i);
        this->numberOfSteps++;
    }
    int city = rand() % this->coordinationMatrix->numberOfCities();
    for (int i = 0; i < this->coordinationMatrix->numberOfCities(); i++) {
        this->route.push_back(city);
        it = citiesSet.find(city);
        citiesSet.erase(it);
        city = this->getNearestNeighbour(city, citiesSet);
    }
}

int AGTSAlgorithm::getNearestNeighbour(const int& city, std::set<int>& cities)
{
    int nearestCity = 0;
    double minimumDistance = 99999999;
    set<int>::iterator it;
    for (it = cities.begin(); it != cities.end(); it++) {
        int newCity = *it;
        if (newCity == city) {
            continue;
        }
        this->numberOfSteps++;
        double distance = this->coordinationMatrix->getDistance(city, newCity);
        if (distance < minimumDistance) {
            nearestCity = newCity;
            minimumDistance = distance;
        }
    }
    return nearestCity;
}

void AGTSAlgorithm::createGreedyRoute()
{
    this->numberOfSteps = 0;
    this->numberOfEvaluations = 0;
    this->reset();
    this->createRandomRoute();
    this->begginerRoute = this->route;
    this->numberOfSteps = this->routeSize();
    int iterationsWithoutImprovement = 0;
    while (iterationsWithoutImprovement < 10) {
        for (int i = 0; i < this->routeSize() - 1; i++) {
            for (int j = 1; j < this->routeSize(); j++) {
                vector<int> tempRoute = this->route;
                this->numberOfSteps++;
                double currentDistance = this->routeDistance();
                this->numberOfEvaluations++;
                this->performTwoOpt(i, j);
                double newDistance = this->routeDistance();
                this->numberOfEvaluations++;
                if (newDistance < currentDistance) {
                    iterationsWithoutImprovement = 0;
                }
                else {
                    this->route = tempRoute;
                }
            }
        }
        iterationsWithoutImprovement++;
    }
}

void AGTSAlgorithm::createSteepestRoute()
{
    this->numberOfSteps = 0;
    this->numberOfEvaluations = 0;
    this->reset();
    this->createRandomRoute();
    this->begginerRoute = this->route;
    this->numberOfSteps = this->routeSize();
    int iterationsWithoutImprovement = 0;
    while (iterationsWithoutImprovement < 3) {
        double bestDistance = 0;
        int cityOneWithBestDistance = 0, cityTwoWithBestDistance = 0;
        for (int i = 0; i < this->routeSize() - 1; i++) {
            for (int j = 1; j < this->routeSize(); j++) {
                vector<int> tempRoute = this->route;
                double currentDistance = this->routeDistance();
                this->numberOfSteps++;
                this->numberOfEvaluations++;
                this->performTwoOpt(i, j);
                double newDistance = this->routeDistance();
                this->numberOfEvaluations++;
                if (newDistance < currentDistance) {
                    iterationsWithoutImprovement = 0;
                    bestDistance = newDistance;
                    cityOneWithBestDistance = i;
                    cityTwoWithBestDistance = j;
                }
                this->route = tempRoute;
            }
        }
        this->performTwoOpt(cityOneWithBestDistance, cityTwoWithBestDistance);
        iterationsWithoutImprovement++;
    }
}

void AGTSAlgorithm::performTwoOpt(int cityOne, int cityTwo)
{
    if (cityTwo < cityOne) {
        int temp = cityTwo;
        cityTwo = cityOne;
        cityOne = temp;
    }
    int loopIterations = (cityTwo + cityOne) * 0.5;
    if ((cityTwo - cityOne) % 2 == 0) {
        loopIterations = (cityTwo - cityOne) * 0.5;
    }
    else {
        loopIterations = floor((cityTwo - cityOne) * 0.5) + 1;
    }
    for (int i = 0; i <= loopIterations; i++) {
        swap(this->route[cityOne + i], this->route[cityTwo - i]);
    }
}

void AGTSAlgorithm::getRoute(std::vector<int> &route)
{
    route = this->route;
}
















