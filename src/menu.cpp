#include <format>
#include <iostream>
#include <limits>

#include "menu.hpp"

void displayAsciiBanner() {
    std::cout << "           ___                                  \n"
                 "    ____  /   |  ______________ ___  ____ _____ \n"
                 "   / __ \\/ /| | / ___/ ___/ __ `__ \\/ __ `/ __ \\\n"
                 "  / /_/ / ___ |(__  |__  ) / / / / / /_/ / / / /\n"
                 " / .___/_/  |_/____/____/_/ /_/ /_/\\__,_/_/ /_/ \n"
                 "/_/                                              \n\n\n";
}

void displayEntryMenu() {
    std::cout << " - Please Choose an Option: - \n"
                 "1. - Sign in. \n"
                 "2. - Sign up: \n"
                 "0. - Quit.\n";
}

void displaySignupMenu() {
    std::cout
        << "Thank you for choosing pAssman for your account storage needs.\n"
           "Please choose a username for your account. Your username must contain the following:\n"
           " - Must contain at least 3 alpha-numeric characters.\n"
           " - Can not be longer than 20 characters, or contain special characters other than: '-' or '_'.\n"
           " - Can not contain spaces.\n";
}

void displaySigninMenu() {
    std::cout << " - Main Menu: -\n"
                 "1. - View saved Credentials. \n"
                 "2. - Add to saved Credentials. \n"
                 "3. - Delete a Credential entry. \n"
                 "4. - Go back to the main menu. \n"
                 "0. - Quit pAssman. \n";
}

void displayQuitMessage() {
    std::cout << "Thank you for using pAssman: Quitting...\n";
}

void clearTerminal() {
    std::cout << "\033[1;1H\033[2J";  // Move cursor to (1,1) and clear from there
}

int getUserChoice(const std::string& menuName, int minChoice, int maxChoice) {
    int choice{};
    std::cout << "[DEBUG] - getUserChoice(): Please enter your choice for " << menuName << ": ";

    while (!(std::cin >> choice) || choice < minChoice || choice > maxChoice) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Please enter a number between " << minChoice << " and "
                  << maxChoice << ": ";
    }
    return choice;
}

void handleMenuLoop() {
    Menu currentMenu = Menu::ENTRY_MENU;

    clearTerminal();
    displayAsciiBanner();
    displayEntryMenu();

    bool isRunningFlag = true;

    while (isRunningFlag) {
        switch (currentMenu) {
            case Menu::ENTRY_MENU:
                currentMenu = handleEntryMenu();
                break;
            case Menu::SIGNIN_MENU:
                currentMenu = handleSigninMenu();
                break;
            case Menu::SIGNUP_MENU:
                currentMenu = handleSignupMenu();
                break;
        }
    }
}

Menu handleEntryMenu() {
    int choice = getUserChoice("Entry Menu", 0, 2);
    switch (choice) {
        case 0:
            clearTerminal();
            displayQuitMessage();
            std::exit(EXIT_SUCCESS);  // Exit the program
        case 1:
            clearTerminal();
            displaySigninMenu();
            return Menu::SIGNIN_MENU;
        case 2:
            clearTerminal();
            displaySignupMenu();
            return Menu::SIGNUP_MENU;
        default:
            clearTerminal();
            std::cout << "Error: Invalid choice. Please enter a number between 0 and 2.\n";
            return Menu::ENTRY_MENU;  // Stay in the same menu
    }
}

Menu handleSigninMenu() {
    int choice = getUserChoice("Signin Menu", 0, 4);
    switch (choice) {
        case 0:
            clearTerminal();
            displayQuitMessage();
            std::exit(EXIT_SUCCESS);  // Exit the program
        case 1:
            clearTerminal();
            std::cout << "Feature under development: View saved Credentials.\n";
            break;
        case 2:
            clearTerminal();
            std::cout << "Feature under development: Add to saved Credentials.\n";
            break;
        case 3:
            clearTerminal();
            std::cout << "Feature under development: Delete a Credential entry.\n";
            break;
        case 4:
            clearTerminal();
            displayEntryMenu();
            return Menu::ENTRY_MENU;
        default:
            clearTerminal();
            std::cout << "Error: Invalid choice. Please enter a number between 0 and 4.\n";
            return Menu::SIGNIN_MENU;  // Stay in the same menu
    }
    return Menu::SIGNIN_MENU;
}

Menu handleSignupMenu() {
    // TODO: Finish menuing for signing up a user account.
    return Menu::SIGNUP_MENU;
}
