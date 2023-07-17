//Этот класс описывает сообщение
#pragma once

#include <string>
#include "User.h"
class Message
{
    //Параметры сообщения
    const std::string _to;//Кому
    const std::string _from;//От кого
    const std::string _text;//Текст
public:

    //Констрктор 
    Message(const std::string& from, const std::string& to, const std::string& text) :_from(from), _to(to), _text(text) {};
    
    //Геттеры параметров сообщения
    const std::string& getFrom() const {return _from;};
    const std::string& getTo() const {return _to;};
    const std::string& getText() const {return _text;};

};