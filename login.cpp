#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Simulated user database
unordered_map<string, string> userDB = {
    {"admin", "admin123"},
    {"user1", "pass1234"}
};

// Login function
bool login(const string& username, const string& password) {
    if (userDB.find(username) != userDB.end()) {
        if (userDB[username] == password) {
            return true;
        }
    }
    return false;
}

int main() {
    string username, password;

    cout << "=== Secure Login System ===\n";
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (login(username, password)) {
        cout << "\n✅ Login Successful. Welcome, " << username << "!\n";
    } else {
        cout << "\n❌ Login Failed. Invalid credentials.\n";
    }

    return 0;
}
