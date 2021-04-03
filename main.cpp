#include <iostream>
#include "pokemon.h"
#include "schiggy.h"
#include "glumanda.h"
#include "game.h"
#include "team.h"

using namespace std;

int main()
{
    Game game;
    char input = 't';

    while(input != 'n'){
        system("cls");
        game.mainMenu();
        input = game.GetMenuInput();
        game.startGameMode(input);
        game.printStats();
        std::cout << std::endl << "Willst du nochmal Spielen [y/n]? ";
        input = game.getYorN();
        if(input  == 'n'){
            break;
        }
    }

    return 0;
}
