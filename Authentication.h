#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <iostream>

class Authentication {
private:
    std::string username;
    std::string encryptedPassword;
    bool isLoggedIn;
    
    // Encryption key (Caesar cipher shift value)
    static const int SHIFT_KEY = 5;
    
public:
    // Constructor
    Authentication();
    Authentication(std::string user, std::string password);
    
    // Destructor
    ~Authentication();
    
    // Encryption and Decryption Methods
    std::string encryptPassword(const std::string& password);
    std::string decryptPassword(const std::string& encryptedPass);
    
    // Authentication Methods
    bool login(std::string user, std::string password);
    bool logout();
    bool registerUser(std::string user, std::string password);
    
    // Getter Methods
    std::string getUsername() const;
    bool getLoginStatus() const;
    
    // Setter Methods
    void setUsername(std::string user);
    void setPassword(std::string password);
    
    // Display Methods
    void displayAuthStatus() const;
};

#endif
