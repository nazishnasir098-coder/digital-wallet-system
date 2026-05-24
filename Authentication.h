#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <iostream>

using namespace std;

// Authentication class handles user login, registration, and password security
class Authentication {
private:
    string username;              // Stores the username
    string encryptedPassword;     // Stores encrypted password
    bool isLoggedIn;              // Tracks if user is logged in
    static const int SHIFT_KEY = 5;  // Encryption key for Caesar cipher
    
public:
    // Constructor - creates empty authentication object
    Authentication();
    
    // Constructor - creates authentication with username and password
    Authentication(string user, string password);
    
    // Destructor - cleans up resources
    ~Authentication();
    
    // Encrypts password using Caesar cipher
    string encryptPassword(const string& password);
    
    // Decrypts password back to original text
    string decryptPassword(const string& encryptedPass);
    
    // Login user with username and password
    bool login(string user, string password);
    
    // Logout current user
    bool logout();
    
    // Register new user
    bool registerUser(string user, string password);
    
    // Get username
    string getUsername() const;
    
    // Check if user is logged in
    bool getLoginStatus() const;
    
    // Set new username
    void setUsername(string user);
    
    // Set new password
    void setPassword(string password);
    
    // Display authentication status
    void displayAuthStatus() const;
};

#endif
