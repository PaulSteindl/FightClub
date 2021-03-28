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
        input = game.wannaContinue();
        if(input  == 'n'){
            break;
        }
    }

    return 0;
}
