#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

/// @brief Used to denote squaring in the Euclidean formula
const int cSquarePower = 2;


/// @brief Used to validate and clear the cin state in case of invalid input;
/// @param inputValue input value from the user.
/// @return new validated state.
int dataValidate (int inputValue) {
while(std::cin.fail()) {
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::cout << "Invalid Input, please try again: ";
std::cin >> inputValue;
}
return inputValue;
}
/// @brief Ensures value input is positive, loops if negative.
/// @param inputValue Input value from the user.
/// @return Positive value returned.
int negativeValidate (int inputValue) {
while (inputValue < 0) {
std::cout << "Negative value not allowed, try again: ";
std::cin >> inputValue;
}
return inputValue;
}
/// @brief Takes the number of customers, validates value.
/// @return Number of customers.
int numberOfCustomers (){
auto customerInput = 0;
std::cout << "Enter the number of customers: ";
std::cin >> customerInput;
customerInput = dataValidate(customerInput);
customerInput = negativeValidate(customerInput);
return customerInput;
}


/// @brief Adds coordinates to paired vector.
/// @param coordinateX: Input coordinate x of customer.
/// @param coordinateY: Input coordinate y of customer.
/// @param customerCoordinates: Paired vector containing coordinates of customer
void addCustomerCoord(int coordinateX, int coordinateY, std::vector<std::pair<int, int> >& customerCoordinates) {
std::pair<int, int> inputCoordinate(coordinateX, coordinateY);
customerCoordinates.push_back(inputCoordinate);
}


/// @brief Boolean functions returns true if coordinates appear to be duplicated.
/// @param customerCoordinates: Paired vector containing customer coordinates.
/// @param depotCoordinates: Paired vector containing origin coordinates of depot.
/// @param coordinateX: Input coordinate x of customer.
/// @param coordinateY: Input coordinate y of customer.
/// @return True state if values equal depot coordinates.
/// @return False state is values are not direct duplicates.
bool duplicateValidation(int coordinateX, int coordinateY, const std::pair<int, int>& depotCoordinates, const std::vector<std::pair<int, int> >& customerCoordinates) {
if (depotCoordinates.first == coordinateX && depotCoordinates.second == coordinateY) { 
return true;
}


for (const auto& coordinates : customerCoordinates) {
if (coordinates.first == coordinateX && coordinates.second == coordinateY) {
return true;
}
}


return false;
}


/// @brief calculates distance using Euclidean formula, stores values in vector.
/// @param customerCoordinates: Paired vector containing customer coordinates.
/// @param depotCoordinates: Paired vector containing origin coordinates of depot.
/// @param distanceToCustomer: Vector containing distance from depot to customer.
void distanceForCustomer(const std::pair<int, int>& depotCoordinates, const std::vector<std::pair<int, int> >& customerCoordinates, std::vector<double>& distanceToCustomer) {
for (const auto& customer : customerCoordinates) {
double distance = std::sqrt(std::pow((customer.first - depotCoordinates.first), cSquarePower) +
std::pow((customer.second - depotCoordinates.second), cSquarePower));
distanceToCustomer.push_back(distance);
}
}
/// @brief Greedy approach algorithm to calculate best possible route based on distance.
/// @param distanceToCustomer: Vector containing distance.
/// @param customerCoordinates: Paired vector containing customer coordinates.
/// @param depotCoordinates: Paired vector containing origin coordinates of depot.
/// @return Optimal route is returned.
std::vector<std::pair<int, int> > greedyAlgorithm(const std::pair<int, int>& depotCoordinates, std::vector<std::pair<int, int> >& customerCoordinates, std::vector<double>& distanceToCustomer) {
std::vector<std::pair<int, int> > route;
route.push_back(depotCoordinates); // Starting from depot


while (!customerCoordinates.empty()) {
// Find nearest customer's index
auto minDistanceIterator = std::min_element(distanceToCustomer.begin(), distanceToCustomer.end());
int nearestCustomerIndex = std::distance(distanceToCustomer.begin(), minDistanceIterator);


// Add nearest customer to the route
route.push_back(customerCoordinates[nearestCustomerIndex]);


// Remove nearest customer from the list
customerCoordinates.erase(customerCoordinates.begin() + nearestCustomerIndex);
distanceToCustomer.erase(minDistanceIterator);


// Clear distanceToCustomer vector and Recalculate distances for remaining customers from current position
distanceToCustomer.clear();
distanceForCustomer(depotCoordinates, customerCoordinates, distanceToCustomer);
}


route.push_back(depotCoordinates); // Returning to depot
return route;
}
/// @deprecated Used to print distance of each customer. Test Code.
// Function prints distance for each customer.
/* for (const auto &distance : distanceToCustomer) {
std::cout << "Distance: " << distance << ' ' << std::endl;
} */
