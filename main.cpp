#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser();
bool loginUser();
bool checkUserExists(const string& username);

int main() {
    int choice;

    while (true) {
        cout << "\n=== Login and Registration System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "Login successful! Welcome!\n";
                } else {
                    cout << "Login failed! Please check your credentials.\n";
                }
                break;
            case 3:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3.\n";
                break;
        }
    }
}

void registerUser() {
    string username, password;

    cout << "\n=== User Registration ===\n";
    cout << "Enter a username: ";
    cin >> username;

    if (checkUserExists(username)) {
        cout << "Username already exists. Please try a different username.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream file("database.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful! You can now login.\n";
}

bool loginUser() {
    string username, password, fileUsername, filePassword;

    cout << "\n=== User Login ===\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("database.txt");
    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            return true;
        }
    }
    return false;
}

bool checkUserExists(const string& username) {
    string fileUsername, filePassword;

    ifstream file("database.txt");
    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username) {
            return true;
        }
    }
    return false;
}
