#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

unordered_map<string, string> userDB = {
    {"admin", "admin123"},
    {"user1", "pass1234"}
};

bool login(const string& username, const string& password) {
    return userDB.count(username) && userDB[username] == password;
}

int generateOTP() {
    srand(time(0));
    return 100000 + rand() % 900000; // 6-digit OTP
}

string secureInput(int maxLength) {
    string input;
    getline(cin, input);  // safer than cin >>
    if (input.length() > maxLength) {
        cout << "Input too long. Trimming it to " << maxLength << " characters.\n";
        input = input.substr(0, maxLength);
    }
    return input;
}


int main() {
    string username, password;

    cout << "=== Secure Login System with MFA ===\n";
    cin.ignore(); // clears input buffer before getline
cout << "Username: ";
username = secureInput(20);  // max 20 characters

cout << "Password: ";
password = secureInput(20);

if (username.empty() || password.empty()) {
    cout << "❌ Username or Password cannot be empty.\n";
    return 0; // exit the program early
}



    if (login(username, password)) {
        cout << "\n✅ Password Verified.\n";

        int otp = generateOTP();
        cout << "🔐 Your One-Time Password (OTP) is: " << otp << "\n";

        int userOTP;
        cout << "Enter OTP: ";
        cin >> userOTP;

        if (userOTP == otp) {
            cout << "\n🎉 Login Successful. Welcome, " << username << "!\n";
        } else {
            cout << "\n❌ Incorrect OTP. Access Denied.\n";
        }

    } else {
        cout << "\n❌ Login Failed. Invalid credentials.\n";
    }

    return 0;
}
