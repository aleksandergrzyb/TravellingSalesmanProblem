//
//  AGCoordinationMatrix.cpp
//  travelling_salesman_problem
//
//  Created by Aleksander Grzyb on 14/12/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#include "AGCoordinationMatrix.h"
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

AGCoordinationMatrix::AGCoordinationMatrix(string filepath)
{
    ifstream file;
    file.open(filepath.c_str());
    if (!file) {
        cout << "Error opening file.";
    }
    int lineNumber = 0;
    while (!file.eof()) {
        lineNumber++;
        char buff[255];
        file.getline(buff, 128);
        vector<string> tokens;
        string text(buff);
        this->tokenize(tokens, text, " ");
        if (tokens[0] == "NAME") {
            this->title = tokens[2];
        }
        if (lineNumber < 7 || (tokens.size() == 1 && text != "EOF")) {
            continue;
        }
        if (text == "EOF") {
            break;
        }
        int x = atoi(tokens[1].c_str());
        int y = atoi(tokens[2].c_str());
        pair<int, int> n(x, y);
        this->coordinations.push_back(n);
    }
    file.close();
    this->setDestinationMatrix();
}

string AGCoordinationMatrix::getTitle() const
{
    return this->title;
}

void AGCoordinationMatrix::tokenize(std::vector<std::string>& tokens, const std::string& text, const std::string& delimiter)
{
    size_t next_pos = 0;
    size_t init_pos = text.find_first_not_of(delimiter, next_pos);
    while (next_pos != string::npos && init_pos != string::npos) {
        next_pos = text.find(delimiter, init_pos);
        string token = text.substr(init_pos, next_pos - init_pos);
        tokens.push_back(token);
        init_pos = text.find_first_not_of( delimiter, next_pos );
    }
}

void AGCoordinationMatrix::setDestinationMatrix()
{
    for (int i = 0; i < this->coordinations.size(); i++) {
        pair<int, int> city1 = this->coordinations[i];
        int x1 = city1.first;
        int y1 = city1.second;
        for (int j = i + 1; j < this->coordinations.size(); j++) {
            pair<int, int> city2 = this->coordinations[j];
            int x2 = city2.first;
            int y2 = city2.second;
            double distance = sqrt((double)(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0)));
            pair<int, int> p(i, j);
            this->destinationMatrix[p] = distance;
        }
    }
}

int AGCoordinationMatrix::numberOfCities() const
{
    return (int)this->coordinations.size();
}

double AGCoordinationMatrix::getDistance(int city1, int city2)
{
    if (city1 < city2) {
        pair<int, int> p(city1, city2);
        return this->destinationMatrix[p];
    }
    else {
        pair<int, int> p(city2, city1);
        return this->destinationMatrix[p];
    }
}



