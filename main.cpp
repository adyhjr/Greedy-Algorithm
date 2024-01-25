#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

#include "delivery.h"


int main() {


// Pair containing coordinates of origin depot.
std::pair<int, int> depotCoordinates;


// Containers holding coordinates of customers as well as distances
std::vector<std::pair<int, int> > customerCoordinates;
std::vector<double> distanceToCustomer;
// Asks user for X coordinates of depot and validates input.
std::cout << "Enter X coordinate for depot: ";
std::cin >> depotX;
dataValidate(depotX);
negativeValidate(depotX);


// Asks user for Y coordinates of depot and validates input.
std::cout << "Enter Y coordinate for depot: ";
std::cin >> depotY;
dataValidate(depotY);
negativeValidate(depotY);


// Coordinates are stored in vector
depotCoordinates = {depotX, depotY};


// Value returned from function is stored in variable
auto totalCustomers = numberOfCustomers();


// For loop repeats adding coordinates for each customer, all values validated
for (int i = 1; i <= totalCustomers; i++) {
do {
// Takes and validates X value
std::cout << "Enter coordinate X for customer: ";
std::cin >> customerX;
dataValidate(customerX);
negativeValidate(customerX);


// Takes and validates Y value
std::cout << "Enter coordinate Y for customer: ";
std::cin >> customerY;
dataValidate(customerY);
negativeValidate(customerY);
// Variables stores true or false depending on logic in boolean function
// If duplicate coordinates are found, user must enter input again.
isDuplicate = duplicateValidation(customerX, customerY, depotCoordinates, customerCoordinates);
if (isDuplicate) {
std::cout << "Duplicate coordinates. Enter again: ";
}
// Will continue to loop until boolean returns true
} while (isDuplicate);


addCustomerCoord(customerX, customerY, customerCoordinates);
}


// Stores distance for customer in vector
distanceForCustomer(depotCoordinates, customerCoordinates, distanceToCustomer);


// Prints total distance
for (const auto &distance : distanceToCustomer) {
totalDistance += distance;
}
std::cout << "Total Distance: " << totalDistance << std::endl;


// Displays optimal route using function
std::vector<std::pair<int, int>> route = greedyAlgorithm(depotCoordinates, customerCoordinates, distanceToCustomer);
std::cout << "Final Route: ";
for (const auto& coord : route) {
std::cout << "(" << coord.first << "," << coord.second << ") ";
}


return 0;
}
