//���� ����� ��������� ������������
#pragma once

#include <string>
class User
{
    //��������� ������������
    const std::string _login;//�����
    std::string _password;//������
    std::string _username;//��� ������������

public:

    //����������� 
    User(const std::string& login, const std::string& password, const std::string& username) :_login(login), _password(password), _username(username) {};
    
    //������� ���������� ������������
    const std::string& getUserLogin() const {return _login;};
    const std::string& getUserPassword() const {return _password;};
    const std::string& getUserName() const {return _username;};
    
    //������� ���������� ������������
    void setUserPassword(const std::string& password) {_password = password;};
    void setUserName(const std::string& name) {_username = name;};
};