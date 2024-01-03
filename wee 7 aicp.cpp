#include <iostream>

#include <string>

using namespace std;

const int NUM_CHARITIES = 3;

// Function prototypes
void setupCharities(string charities[]);
int getCharityChoice();
double getShoppingBill();
double calculateDonation(double bill);
void recordAndTotalDonation(string charities[], double totals[]);
void showTotals(string charities[], double totals[]);
void displayGrandTotal(double grandTotal);

int main() {
    string charities[NUM_CHARITIES];
    double totals[NUM_CHARITIES] = {0.0};

    // Task 1 - Set up the donation system
    setupCharities(charities);

    // Task 2 - Record and total each donation
    recordAndTotalDonation(charities, totals);

    // Task 3 - Show the totals so far
    showTotals(charities, totals);

    return 0;
}

void setupCharities(string charities[]) {
    // Prompt the user to input the names of three charities
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << "Enter the name of Charity " << i + 1 << ": ";
        getline(cin, charities[i]);
    }
}

int getCharityChoice() {
    // Prompt the user to choose a charity (1, 2, or 3) or -1 to show totals
    int choice;
    cout << "Choose a charity (1, 2, 3) or enter -1 to show totals: ";
    cin >> choice;

    if (choice < -1 || choice > NUM_CHARITIES) {
        // Display an error message for invalid choices
        cout << "Invalid choice. Please enter 1, 2, 3, or -1.\n";
        return getCharityChoice();  // Recursively ask for input until a valid choice is entered
    }

    return choice;
}

double getShoppingBill() {
    // Prompt the user to enter the shopping bill amount
    double bill;
    cout << "Enter the shopping bill amount: $";
    cin >> bill;

    if (bill < 0) {
        // Display an error message for negative bill amounts
        cout << "Invalid bill amount. Please enter a positive value.\n";
        return getShoppingBill();  // Recursively ask for input until a valid bill amount is entered
    }

    return bill;
}

double calculateDonation(double bill) {
    // Calculate 1% of the shopping bill as the donation
    return 0.01 * bill;
}

void recordAndTotalDonation(string charities[], double totals[]) {
    // Record and total donations for one customer
    int choice = getCharityChoice();
    double bill = getShoppingBill();
    double donation = calculateDonation(bill);

    // Output the name of the charity and the amount donated
    cout << "Donating $" << fixed << donation << " to " << charities[choice - 1] << " charity.\n";

    totals[choice - 1] += donation;
}

void showTotals(string charities[], double totals[]) {
    // Display totals for each charity in descending order
    for (int i = 0; i < NUM_CHARITIES - 1; ++i) {
        for (int j = i + 1; j < NUM_CHARITIES; ++j) {
            if (totals[i] < totals[j]) {
                swap(totals[i], totals[j]);
                swap(charities[i], charities[j]);
            }
        }
    }

    // Output the charities' names and totals
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << charities[i] << " charity: $" << fixed << totals[i] << "\n";
    }

    // Calculate and display the grand total
    double grandTotal = totals[0] + totals[1] + totals[2];
    displayGrandTotal(grandTotal);
}

void displayGrandTotal(double grandTotal) {
    cout << "GRAND TOTAL DONATED TO CHARITY: $" << fixed << grandTotal << "\n";
}
