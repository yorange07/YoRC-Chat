//Этот класс описывает пользователя
#pragma once

#include <string>
class User
{
    //Параметры пользователя
    const std::string _login;//Логин
    std::string _password;//Пароль
    std::string _username;//Имя пользователя

public:

    //Конструктор 
    User(const std::string& login, const std::string& password, const std::string& username) :_login(login), _password(password), _username(username) {};
    
    //Геттеры параметров пользователя
    const std::string& getUserLogin() const {return _login;};
    const std::string& getUserPassword() const {return _password;};
    const std::string& getUserName() const {return _username;};
    
    //Сеттеры параметров пользователя
    void setUserPassword(const std::string& password) {_password = password;};
    void setUserName(const std::string& name) {_username = name;};
};