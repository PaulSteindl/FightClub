#include <iostream>
#include "pokemon.h"
#include "schiggy.h"
#include "glumanda.h"
#include "game.h"
#include "team.h"
#include "test.h"

#define RUN_TESTS 1

using namespace std;

int main()
{
#if RUN_TESTS
    runTests();
#else
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
#endif // RUN_TESTS
    return 0;
}
