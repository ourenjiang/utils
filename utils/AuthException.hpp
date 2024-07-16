#pragma once
#include <stdexcept>
#include <string>

namespace utils
{
using namespace std;

class AuthException: public std::runtime_error
{
public:
    AuthException(const std::string& msg, const std::string& username) 
        : std::runtime_error(msg), username_(username) {}
    
    string username() const { return username_; }
private:
     string username_;
};

}//namespace utils
