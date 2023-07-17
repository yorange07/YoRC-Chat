//���� ����� ��������� ���� ����
#pragma once

#include <string>
#include <vector>
#include <exception>
#include <memory>
#include"Message.h"

//����������, ���� ����� ��� �����
struct UserLoginExp :public std::exception
{
    const char* what() const noexcept override {return "User login is busy";};
};

//����������, ���� ��� ��� ������
struct UserNameExp :public std::exception
{
    const char* what() const noexcept override {return "Username is busy";};
};

class Chat
{

private:

    bool _chatActivation = false;//��������� ����
    std::shared_ptr<User> _currentUser = nullptr;//��������� �� �������� ������������
    std::vector<User> _userList;//������ �������������
    std::vector<Message> _messageBank;//��� ��������� ������ ����
    
    std::shared_ptr<User> getUserByLogin(const std::string& login) const;//������� ������������ �� ������
    std::shared_ptr<User> getUserByName(const std::string& name) const;//������� ������������ �� �����
    std::vector<User>& getAllUsers() {return _userList;};//������� ������ �������������
    std::vector<Message>& getAllMessages() {return _messageBank;};//������� ���� ��������� ������
   
    void login();//���� ������������
    void signUp();//����������� ������������
    void sendMessage();//�������� ���������
    void showChat() const;//�������� ���
    void showUsersList() const;//�������� ������ �������������
    
public:
    
    std::shared_ptr<User> getCurrentUser() const {return _currentUser;};//������� ��������� �� �������� ������������
    
    void start();//����� ����
    void showLoginMenu();//���� � ����
    void showUserMenu();//���� ������������
    bool getChatActivation() const {return _chatActivation;};//������� ��������� ���� 
};
