#include "Authentication.h"
#include <iostream>

using namespace std;

// Default Constructor
Authentication::Authentication() {
    username = "";
    encryptedPassword = "";
    isLoggedIn = false;
}

// Parameterized Constructor
Authentication::Authentication(string user, string password) {
    username = user;
    encryptedPassword = encryptPassword(password);
    isLoggedIn = false;
}

// Destructor
Authentication::~Authentication() {
    username.clear();
    encryptedPassword.clear();
    isLoggedIn = false;
}

// Encrypt password using Caesar cipher
string Authentication::encryptPassword(const string& password) {
    string encrypted = "";
    
    for (char ch : password) {
        encrypted += char(ch + SHIFT_KEY);
    }
    
    return encrypted;
}

// Decrypt password
string Authentication::decryptPassword(const string& encryptedPass) {
    string decrypted = "";
    
    for (char ch : encryptedPass) {
        decrypted += char(ch - SHIFT_KEY);
    }
    
    return decrypted;
}

// Login user
bool Authentication::login(string user, string password) {
    if (user != username) {
        cout << "ERROR: Username not found!" << endl;
        return false;
    }
    
    string encryptedInput = encryptPassword(password);
    
    if (encryptedInput == encryptedPassword) {
        isLoggedIn = true;
        cout << "SUCCESS: User '" << username << "' logged in!" << endl;
        return true;
    } else {
        cout << "ERROR: Incorrect password!" << endl;
        return false;
    }
}

// Logout user
bool Authentication::logout() {
    if (!isLoggedIn) {
        cout << "ERROR: No user is logged in!" << endl;
        return false;
    }
    
    isLoggedIn = false;
    cout << "SUCCESS: User '" << username << "' logged out!" << endl;
    return true;
}

// Register new user
bool Authentication::registerUser(string user, string password) {
    if (user.empty() || password.empty()) {
        cout << "ERROR: Username and password cannot be empty!" << endl;
        return false;
    }
    
    username = user;
    encryptedPassword = encryptPassword(password);
    isLoggedIn = false;
    
    cout << "SUCCESS: User '" << user << "' registered!" << endl;
    return true;
}

// Get username
string Authentication::getUsername() const {
    return username;
}

// Get login status
bool Authentication::getLoginStatus() const {
    return isLoggedIn;
}

// Set username
void Authentication::setUsername(string user) {
    username = user;
    cout << "Username updated to: " << username << endl;
}

// Set password
void Authentication::setPassword(string password) {
    encryptedPassword = encryptPassword(password);
    cout << "Password updated!" << endl;
}

// Display auth status
void Authentication::displayAuthStatus() const {
    cout << "\n===== AUTHENTICATION STATUS =====" << endl;
    cout << "Username: " << (username.empty() ? "No user registered" : username) << endl;
    cout << "Status: " << (isLoggedIn ? "LOGGED IN" : "LOGGED OUT") << endl;
    cout << "==================================\n" << endl;
}
