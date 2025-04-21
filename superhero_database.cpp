// Obscure Superhero Database - Complete Program
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

const int SIZE = 10;

// Parallel arrays
string names[SIZE] = {
    "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Matter-Eater Lad", "Dogwelder",
    "Zeitgeist", "Color Kid", "Captain Planet", "Hellcow", "Doorman"
};

string powers[SIZE] = {
    "Control Squirrels", "Detachable Limbs", "Super Strength", "Eat Any Material", "Weld Dogs to Faces",
    "Acid Vomit", "Change Color of Objects", "Eco Powers", "Vampire Cow", "Teleportation"
};

string weaknesses[SIZE] = {
    "Time Limits", "Heavy Objects", "Poor Judgment", "Digestive Limits", "Dog Shortage",
    "Own Vomit", "Colorblindness", "Pollution", "Garlic", "Closed Doors"
};

// Multidimensional array: [2][SIZE] – 0 = Year, 1 = Universe
string extraData[2][SIZE] = {
    {"1992", "1989", "1986", "1962", "1996", "2001", "1966", "1990", "1975", "1989"}, // Year
    {"Marvel", "DC", "Other", "DC", "DC", "Marvel", "DC", "Other", "Marvel", "Marvel"} // Universe
};

void displayAll(bool toUppercase) {
    cout << "\n--- Superhero List ---\n";
    for (int i = 0; i < SIZE; ++i) {
        string name = names[i];
        string power = powers[i];
        string weakness = weaknesses[i];

        if (toUppercase) {
            transform(name.begin(), name.end(), name.begin(), ::toupper);
            transform(power.begin(), power.end(), power.begin(), ::toupper);
            transform(weakness.begin(), weakness.end(), weakness.begin(), ::toupper);
        } else {
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            transform(power.begin(), power.end(), power.begin(), ::tolower);
            transform(weakness.begin(), weakness.end(), weakness.begin(), ::tolower);
        }

        cout << name << " | " << power << " | " << weakness
             << " | " << extraData[0][i] << " | " << extraData[1][i] << endl;
    }
}

void searchByName(string query) {
    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        string loweredName = names[i];
        transform(loweredName.begin(), loweredName.end(), loweredName.begin(), ::tolower);
        transform(query.begin(), query.end(), query.begin(), ::tolower);

        if (loweredName.find(query) != string::npos) {
            cout << "\nFound: " << names[i] << " | " << powers[i] << " | " << weaknesses[i]
                 << " | " << extraData[0][i] << " | " << extraData[1][i] << endl;
            found = true;
        }
    }
    if (!found) cout << "\nNo match found.\n";
}

void findByPower(string query) {
    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        string loweredPower = powers[i];
        transform(loweredPower.begin(), loweredPower.end(), loweredPower.begin(), ::tolower);
        transform(query.begin(), query.end(), query.begin(), ::tolower);

        if (loweredPower.find(query) != string::npos) {
            cout << "\nFound: " << names[i] << " | " << powers[i] << " | " << weaknesses[i]
                 << " | " << extraData[0][i] << " | " << extraData[1][i] << endl;
            found = true;
        }
    }
    if (!found) cout << "\nNo match found.\n";
}

void sortAlphabetically() {
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            if (names[i] > names[j]) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(extraData[0][i], extraData[0][j]);
                swap(extraData[1][i], extraData[1][j]);
            }
        }
    }
    cout << "\nSuperheroes sorted alphabetically!\n";
}

int main() {
    int choice;
    string input;
    bool running = true;

    cout << "Welcome to the Obscure Superhero Database!" << endl;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1. Search by name\n";
        cout << "2. Find by superpower\n";
        cout << "3. Sort alphabetically\n";
        cout << "4. Display ALL (UPPERCASE)\n";
        cout << "5. Display all (lowercase)\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Clear newline buffer

        switch (choice) {
            case 1:
                cout << "Enter name to search: ";
                getline(cin, input);
                searchByName(input);
                break;
            case 2:
                cout << "Enter power to find: ";
                getline(cin, input);
                findByPower(input);
                break;
            case 3:
                sortAlphabetically();
                break;
            case 4:
                displayAll(true);
                break;
            case 5:
                displayAll(false);
                break;
            case 6:
                running = false;
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}