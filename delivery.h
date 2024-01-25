#include <cmath>
#include <iostream>
#include <limits>
#include <vector>


// Project created by Adolfo Hernandez.


#ifndef DELIVERY_PROTOTYPES_H
#define DELIVERY_PROTOTYPES_H


int dataValidate(int inputValue);


int negativeValidate(int inputValue);


int numberOfCustomers();


std::vector<std::pair<int, int>> greedyAlgorithm(
const std::pair<int, int>& depotCoordinates,
std::vector<std::pair<int, int> >& customerCoordinates,
std::vector<double>& distanceToCustomer
);


void addCustomerCoord(
int coordinateX,
int coordinateY,
std::vector<std::pair<int, int> >& customerCoordinates
);


bool duplicateValidation(
int coordinateX,
int coordinateY,
const std::pair<int, int>& depotCoordinates,
const std::vector<std::pair<int, int> >& customerCoordinates
);


void distanceForCustomer(
const std::pair<int, int>& depotCoordinates,
const std::vector<std::pair<int, int> >& customerCoordinates,
std::vector<double>& distanceToCustomer
);


bool isDuplicate = false;
auto depotX = 0;
auto depotY = 0;
auto customerX = 0;
auto customerY = 0;
auto totalDistance = 0.0;


#endif //DELIVERY_PROTOTYPES_H