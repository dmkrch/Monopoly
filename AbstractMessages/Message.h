#include <string>

// 1 type - authorizationl block
// 2 type - registration block

// 11login-password
// 21login-password
// 22success/false


// so, how the authorization works? client click button 'authorize'.
// server takes login and password and searches for match with this credentials.
// if he found such - server sends client response: sucess
// if he didnt found such - server sends client response: fail : either login wrong or password
// after this, client is allowed to authorize

// and registration: same as authorizatoin in general, but there are several differences:

// client clicks 'registrate'. then login and password sends to server
// server searches for such login - if he didn't found - he can registrate client. response 'success' after successfull registration of client
// if he found - he can't. response - error


// so client can pass string in format: 123aksjdg&/asdgj/345366g3
// where 1 - type of message, 2 - subtype, 3-subsubtype and etc. and then needed info
// what is more, first 2 bytes will be size of string
// so: 141234hello12345 // means : 14 symbols in string. of type 1-2-3-4, login hello password 12345

// and the schema is:
// when client wants to send message, he knowns, which format it is: authorization, registration or other
// he creates object AuthorizationMessage, sets login and password, and then 'Unparse' to QByteArray
// this QByteArray would contain: size of str, type of str, all the needed info
// when server gets the QByteArray, it reads all the smymbols before the end (according to size of QByteArray)
// then this string is passed to switch, which checks the type of str and creates same object as client created before sending message
// then just takes the info from sended message from client and do some actions

enum class MessageEnum
{

};

class AbstractMessage
{
public:
    AbstractMessage() = default;
    AbstractMessage(std::string message)
        : m_message(message)
    {

    }

    virtual int Unparse() = 0;
    virtual void Parse(const std::string & msg) = 0;

private:
    std::string m_message;
};

class AuthorizationMessage : public AbstractMessage
{
public:
    virtual int Unparse() override
    {

    }

    virtual void Parse(const std::string & msg) override
    {
        
    }
};

void sendToServer()
{
    
}