//Этот класс описывает ядро чата
#pragma once

#include <string>
#include <vector>
#include <exception>
#include <memory>
#include"Message.h"

//Исключение, если логин уже занят
struct UserLoginExp :public std::exception
{
    const char* what() const noexcept override {return "User login is busy";};
};

//Исключение, если имя уже занято
struct UserNameExp :public std::exception
{
    const char* what() const noexcept override {return "Username is busy";};
};

class Chat
{

private:

    bool _chatActivation = false;//Состояние чата
    std::shared_ptr<User> _currentUser = nullptr;//Указатель на текущего пользователя
    std::vector<User> _userList;//Список пользователей
    std::vector<Message> _messageBank;//Все сообшения сессии чата
    
    std::shared_ptr<User> getUserByLogin(const std::string& login) const;//Возврат пользователя по логину
    std::shared_ptr<User> getUserByName(const std::string& name) const;//Возврат пользователя по имени
    std::vector<User>& getAllUsers() {return _userList;};//Возврат списка пользователей
    std::vector<Message>& getAllMessages() {return _messageBank;};//Возврат всех сообщений сессии
   
    void login();//Вход пользователя
    void signUp();//Регистрация пользователя
    void sendMessage();//Написать сообщение
    void showChat() const;//Показать чат
    void showUsersList() const;//Показать список пользователей
    
public:
    
    std::shared_ptr<User> getCurrentUser() const {return _currentUser;};//Возврат указателя на текущего пользователя
    
    void start();//Старт чата
    void showLoginMenu();//Вход и меню
    void showUserMenu();//Меню пользователя
    bool getChatActivation() const {return _chatActivation;};//Возврат состояния чата 
};
