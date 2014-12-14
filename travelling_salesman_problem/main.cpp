//
//  main.cpp
//  travelling_salesman_problem
//
//  Created by Aleksander Grzyb on 14/12/14.
//  Copyright (c) 2014 Aleksander Grzyb. All rights reserved.
//

#include <iostream>
#include "AGCoordinationMatrix.h"

using namespace std;

int main(int argc, const char * argv[]) {
    AGCoordinationMatrix *coordinationMatrix = new AGCoordinationMatrix("/Users/aleksandergrzyb/Dropbox/studies/studia_magisterskie/semestr_9/metaheurystyki_i_obliczenia_inspirowanie_biologicznie/sprawozdanie_1/travelling_salesman_problem/travelling_salesman_problem/pr107.tsp");
    cout << coordinationMatrix->getTitle() << endl;
    return 0;
}
