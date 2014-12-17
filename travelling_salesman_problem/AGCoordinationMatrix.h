//
//  AGCoordinationMatrix.h
//  travelling_salesman_problem
//
//  Created by Aleksander Grzyb on 14/12/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#ifndef __travelling_salesman_problem__AGCoordinationMatrix__
#define __travelling_salesman_problem__AGCoordinationMatrix__

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <tuple>

class AGCoordinationMatrix
{
public:
    AGCoordinationMatrix(std::string filepath);
    ~AGCoordinationMatrix(void);
    double getDistance(int city1, int city2);
    void setDestinationMatrix(std::map<std::pair<int, int>, double>& newDestinationMatrix);
    std::string getTitle() const;
    int numberOfCities() const;
private:
    void tokenize(std::vector<std::string>& tokens, const std::string& text, const std::string& delimiter);
    void setDestinationMatrix(void);
    std::string title;
    std::vector<std::pair<int, int>> coordinations;
    std::map<std::pair<int, int>, double> destinationMatrix;
};

#endif /* defined(__travelling_salesman_problem__AGCoordinationMatrix__) */
