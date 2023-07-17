#include<iostream>
using namespace std;
#include "YoRC.h"

int main()
{
    setlocale(LC_ALL, "rus");
    
    Chat chat;
    chat.start();
    while (chat.getChatActivation())
    {
        chat.showLoginMenu();
        while (chat.getCurrentUser())
        {
            chat.showUserMenu();
        }
    }
    return 0;
}