#include <iostream>
#include <cmath>   // For ceil()
using namespace std;

/* Constant Rate Card */
const double CostPerHour = 18.50;
const double CostPerMinute = 0.40;
const double CostOfDinner = 20.70;

/* Event class demonstrating OOP */
class Event {
private:
    string eventName;
    string firstName, lastName;
    int numberOfGuests;
    int numberOfMinutes;

public:
    /* Function to take input */
    void getEventDetails() {
        cout << "Enter Event Name: ";
        cin >> eventName;

        cout << "Enter First Name: ";
        cin >> firstName;

        cout << "Enter Last Name: ";
        cin >> lastName;

        cout << "Enter Number of Guests: ";
        cin >> numberOfGuests;

        cout << "Enter Number of Minutes: ";
        cin >> numberOfMinutes;
    }

    /* Function to calculate and display event cost */
    void calculateCost() {
        // Calculate number of servers required
        int numberOfServers = ceil(numberOfGuests / 20.0);

        // Cost calculation for one server
        double cost1 = (numberOfMinutes / 60) * CostPerHour;
        double cost2 = (numberOfMinutes % 60) * CostPerMinute;
        double costForOneServer = cost1 + cost2;

        // Food cost
        double totalFoodCost = numberOfGuests * CostOfDinner;

        // Average cost per person
        double averageCost = totalFoodCost / numberOfGuests;

        // Total cost
        double totalCost = totalFoodCost + (costForOneServer * numberOfServers);

        // Deposit amount
        double depositAmount = totalCost * 0.25;

        // Display result
        cout << "\n========== EVENT COST ESTIMATION ==========\n";
        cout << "Event Name           : " << eventName << endl;
        cout << "Customer Name        : " << firstName << " " << lastName << endl;
        cout << "Number of Guests     : " << numberOfGuests << endl;
        cout << "Number of Servers    : " << numberOfServers << endl;
        cout << "Cost for One Server  : " << costForOneServer << endl;
        cout << "Total Food Cost      : " << totalFoodCost << endl;
        cout << "Average Cost/Person  : " << averageCost << endl;
        cout << "Total Event Cost     : " << totalCost << endl;
        cout << "Deposit Amount (25%) : " << depositAmount << endl;
        cout << "==========================================\n";
    }
};

int main() {
    Event e;

    cout << "===== EVENT ORGANISER PROJECT =====\n";

    // Get event input
    e.getEventDetails();

    // Calculate and display cost
    e.calculateCost();

    return 0;
}
