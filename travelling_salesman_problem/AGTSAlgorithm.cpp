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

using namespace std;

void AGTSAlgorithm::createRandomRoute()
{
    this->reset();
    for (int i = 0; i < this->coordinationMatrix->numberOfCities(); i++) {
        this->route.push_back(i);
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

int AGTSAlgorithm::routeSize() const
{
    return (int)this->route.size();
}

void AGTSAlgorithm::reset()
{
    this->route.clear();
}

void AGTSAlgorithm::createNearestNeighbourTour()
{
    this->reset();
    set<int> citiesSet;
    set<int>::iterator it;
    for (int i = 0; i < this->coordinationMatrix->numberOfCities(); i++) {
        citiesSet.insert(i);
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
        double distance = this->coordinationMatrix->getDistance(city, newCity);
        if (distance < minimumDistance) {
            nearestCity = newCity;
            minimumDistance = distance;
        }
    }
    return nearestCity;
}




















