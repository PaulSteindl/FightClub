#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "pokemon.h"
#include "team.h"
#include "characters.h"
#include "winStruct.h"

class Game{
    public:
        void mainMenu();
        char GetMenuInput();
        void startGameMode(char input);
        char getYorN();
        void printStats();

    private:
        def_win winArray;
        int rounds = 0;
        int printRounds = 0;

        def_characters inputPokemon();
        Pokemon createCharacter(def_characters userInput);
        void startEvE();
        int randomAttack();
        bool characterAttack1(Pokemon &character1, Pokemon &character2);
        bool isDead(Pokemon &character1, Pokemon &character2);
        void FightRandomVsRandom(Pokemon character1, Pokemon character2);
        void FightRandomVsAttack(Pokemon character1, Pokemon character2);
        void FightAttackVsAttack(Pokemon character1, Pokemon character2);
        void FightAttackVsRandom(Pokemon character1, Pokemon character2);
        bool characterAttack(Pokemon &charater1, Pokemon &character2);
        void doStatusEffect(Pokemon &character);
        bool playerAttack(Pokemon &character1, Pokemon &character2);
        void FightAgainstPc(Pokemon character1, Pokemon character2);
        void startPvE();
        void FightAgainstPlayer(Pokemon character1, Pokemon character2);
        void startPvP();
        void start2v2();
        bool wantToSwitch();
        void TeamAgainstTeam(Team team1, Team team2);
        bool playerAttackTeam(Team  &team1, Team &team);
};

#endif // GAME_H_INCLUDED
