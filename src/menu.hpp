#ifndef MENU_HPP
#define MENU_HPP

#include <string>

enum class Menu {
    ENTRY_MENU,
    SIGNIN_MENU,
    SIGNUP_MENU,
};

void handleMenuLoop();
Menu handleEntryMenu();
Menu handleSigninMenu();
Menu handleSignupMenu();

#endif
