
#include <iostream>
using namespace std;
const int MAX_SLOTS = 10;
int parkingSlots[MAX_SLOTS];
void initializeParkingSlots();
void displayParkingSlots();
void parkCar();
void removeCar();

int main() {
    int choice;
    initializeParkingSlots();

    do {
        cout << "\nCar Parking System\n";
        cout << "1. Display Parking Slots\n";
        cout << "2. Park Car\n";
        cout << "3. Remove Car\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayParkingSlots();
                break;
            case 2:
                parkCar();
                break;
            case 3:
                removeCar();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void initializeParkingSlots() {
    for (int i = 0; i < MAX_SLOTS; ++i) {
        parkingSlots[i] = 0; 
    }
}

void displayParkingSlots() {
    cout << "\nParking Slots Status:\n";
    for (int i = 0; i < MAX_SLOTS; ++i) {
        cout << "Slot " << i + 1 << ": " << (parkingSlots[i] ? "Occupied" : "Empty") << endl;
    }
}

void parkCar() {
    int slot;
    cout << "Enter the slot number to park the car (1-" << MAX_SLOTS << "): ";
    cin >> slot;
    if (slot < 1 || slot > MAX_SLOTS) {
        cout << "Invalid slot number.\n";
    } else if (parkingSlots[slot - 1]) {
        cout << "Slot " << slot << " is already occupied.\n";
    } else {
        parkingSlots[slot - 1] = 1; 
        cout << "Car parked in slot " << slot << ".\n";
    }
}

void removeCar() {
    int slot;
    cout << "Enter the slot number to remove the car from (1-" << MAX_SLOTS << "): ";
    cin >> slot;
    if (slot < 1 || slot > MAX_SLOTS) {
        cout << "Invalid slot number.\n";
    } else if (!parkingSlots[slot - 1]) {
        cout << "Slot " << slot << " is already empty.\n";
    } else {
        parkingSlots[slot - 1] = 0; 
        cout << "Car removed from slot " << slot << ".\n";
    }
}


