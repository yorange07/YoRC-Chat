#include<iostream>
#include "YoRC.h"

std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) const
{
    for (auto& user : _userList)
    {
        if (login == user.getUserLogin())
            return std::make_shared <User>(user);
    }
    return nullptr;
};

std::shared_ptr<User> Chat::getUserByName(const std::string& name) const
{
    for (auto& user : _userList)
    {
        if (name == user.getUserName())
            return std::make_shared<User>(user);
    }
    return nullptr;
};

void Chat::login()
{
    std::string login, password;
    char action;
    std::cout << std::endl;
    do
    {
        std::cout << "Enter your login >> ";
        std::cin >> login;
        std::cout << "Enter your password >> ";
        std::cin >> password;

        _currentUser = getUserByLogin(login);
        
        if (_currentUser == nullptr || (password != _currentUser->getUserPassword()))
        {
            _currentUser == nullptr;
            std::cout << "User with this login was not found." << std::endl;
            std::cout << "Press 0 to exit or any key to repeat" << std::endl;
            std::cout << ">> ";
            std::cin >> action;
            if (action == '0')
                break;
        }
    } while (!_currentUser);
};

void Chat::signUp()
{
    std::string login, password, name;
    std::cout << std::endl;
    std::cout << "Enter your login >> ";
    std::cin >> login;
    std::cout << "Enter your password >> ";
    std::cin >> password;
    std::cout << "Enter your name >> ";
    std::cin >> name;
    
    if (getUserByLogin(login) || login == "all")
    {
        throw UserLoginExp();
    }
    
    if (getUserByName(name) || name == "all")
    {
        throw UserNameExp();
    }
    
    User user = User(login, password, name);
    _userList.push_back(user);
    _currentUser = std::make_shared<User>(user);
};

void Chat::sendMessage()
{
    std::string addressee, massageText;
    std::cout << std::endl;
    std::cout << "Enter username or all >> ";
    std::cin >> addressee;
    std::cout << "Enter a massage >> ";
    std::cin.ignore();
    std::getline(std::cin, massageText);
    
    if (!(addressee == "all" || getUserByName(addressee)))
    {
        std::cout << "Username not found!" << addressee << std::endl;
        return;
    }
    
    if (addressee == "all")
    {
        _messageBank.push_back(Message(_currentUser->getUserLogin(), "all", massageText));
    }
    
    else
    {
        _messageBank.push_back(Message(_currentUser->getUserLogin(), getUserByName(addressee)->getUserLogin(), massageText));
    }
};

void Chat::showChat() const
{
    std::string from, to;
    std::cout << std::endl;
    std::cout << "///////////////////////////////////////////////////////////////////////" << std::endl;
    
    for (auto& mess : _messageBank)
    {
        if (_currentUser->getUserLogin() == mess.getFrom() || _currentUser->getUserLogin() == mess.getTo() || mess.getTo() == "all")
        {
            from = (_currentUser->getUserLogin() == mess.getFrom()) ? "me" : getUserByLogin(mess.getFrom())->getUserName();
        }
        
        if (mess.getTo() == "all")
        {
            to = "all";
        }
        
        else
        {
            to = (_currentUser->getUserLogin() == mess.getTo()) ? "me" : getUserByLogin(mess.getTo())->getUserName();
        }
        std::cout << "Message from user" << from << " " << "to " << to << std::endl;
        std::cout << "text: " << mess.getText() << std::endl << "-----------------------------------------------------" << std::endl;
    }
    std::cout << "///////////////////////////////////////////////////////////////////////" << std::endl;
};

void Chat::showUsersList() const
{
    std::cout << std::endl;
    std::cout << "Users in Chat:" << std::endl;
    
    for (auto& user : _userList)
    {
        std::cout << user.getUserName() << std::endl;
       
        if (_currentUser->getUserLogin() == user.getUserLogin())
        {
            std::cout << "Me";
            std::cout << std::endl;
        }
        
        std::cout << std::endl;
    }
};

void Chat::start()
{
    _chatActivation = true;
};

void Chat::showLoginMenu()
{
    _currentUser = nullptr;
    char action;
    std::cout << "////// Welcome to YoRC-chat! //////" << std::endl << std::endl;
    
    do
    {
        std::cout << "MAIN MENU" << std::endl;
        std::cout << "- press 1 to login" << std::endl;
        std::cout << "- press 2 to sign up" << std::endl;
        std::cout << "- press 0 to exit" << std::endl << std::endl;
        std::cout << ">> ";
        std::cin >> action;
        switch (action)
        {
        case '1':
            login();
            break;
        case '2':
            try
            {
                signUp();
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case '0':
            std::cout << "We will miss you..." << std::endl;
            _chatActivation = false;
            break;
        default:
            std::cout << "Such a command does not exist. Try again!" << std::endl;
            break;
        }
    } while (!_currentUser && _chatActivation);
};

void Chat::showUserMenu()
{
    char action;
    std::cout << std::endl;
    std::cout << "Hi, " << _currentUser->getUserName() << "! " << "We are glad to see you!" << std::endl;
    
    while (_currentUser)
    {
        std::cout << std::endl;
        std::cout << "Choose an action:" << std::endl 
            << "- press 1 to show chat" << std::endl 
            << "- press 2 to send a message" << std::endl 
            << "- press 3 to show users" << std::endl 
            << "- press 0 to logout";
        
        std::cout << std::endl << std::endl;
        std::cout << ">> ";
        std::cin >> action;
        switch (action)
        {
        case '1':
            showChat();
            break;
        case '2':
            sendMessage();
            break;
        case '3':
            showUsersList();
            break;
        case '0':
            _currentUser = nullptr;
            break;
        default:
            std::cout << "Such a command does not exist. Try again!" << std::endl;
            break;
        }
    }
};



