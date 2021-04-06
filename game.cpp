#include <iostream>
#include <time.h>
#include "game.h"
#include "pokemon.h"
#include "schiggy.h"
#include "glumanda.h"
//Nur schrift fürs MainMenu
void Game::mainMenu(){
    std::cout << "Willkommen bei Pokemon Ultra Delux Smash and Crash!" << std::endl << "Sollten Sie von Nintendo sein bitte verklagen Sie mich nicht, danke!" << std::endl << std::endl << "   PvP(r)  PvE(o)  EvE(f) 2v2(l)" << std::endl << "Deine Eingabe: ";
}

char Game::GetMenuInput(){
    char eingabe = 't';
    while(eingabe != 'r' && eingabe != 'o' && eingabe != 'f' && eingabe != 'l'){
        std::cin >> eingabe;
        if(eingabe != 'r' && eingabe != 'o' && eingabe != 'f' && eingabe != 'l'){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            return eingabe;
        }
    }
    return eingabe;
}

//Möchte y oder n
char Game::getYorN(){
    char eingabe = 't';

    while(eingabe != 'y' && eingabe != 'n'){
        std::cin >> eingabe;
        if(eingabe != 'y' && eingabe != 'n'){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            return eingabe;
        }
    }
    return eingabe;
}

//wählt modus aus
void Game::startGameMode(char input){
    switch(input){
        case 'r':
            Game::startPvP();
        break;

        case 'o':
            Game::startPvE();
        break;

        case 'f':
            Game::startEvE();
        break;

        case 'l':
            Game::start2v2();
        break;
    }
}


def_characters Game::inputPokemon(){
    char eingabe = 'f';
    std::cout << "W" << (char)132 << "hlen Sie das Pokemon aus: " << std::endl <<"  Glumanda(1)" << std::endl << "  Schiggy(2)" << std::endl << "  Custom(3)" << std::endl << "Deine Eingabe: ";
    while(eingabe != '1' && eingabe != '2' && eingabe != '3'){
        std::cin >> eingabe;
        if(eingabe != '1' && eingabe != '2' && eingabe != '3'){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            switch(eingabe){
                case'1':
                    return ch_glumanda;
                break;

                case'2':
                    return ch_schiggy;
                break;

                case'3':
                    return ch_custom;
                break;

                default:
                    return ch_custom;
            }
        }
    }
    return ch_custom;
}

//erstellt character und liefert ihn zurück
Pokemon Game::createCharacter(def_characters userInput){
    switch(userInput){
        case ch_glumanda:{
            Glumanda character;
            return character;
            break;
        }

        case ch_schiggy:{
            Schiggy character;
            return character;
            break;
        }

        case ch_custom:{
            Pokemon character(true);
            return character;
            break;
        }

        default:{
            Pokemon character(true);
            return character;
            break;
        }
    }
}

//wird zufällig ausgewält
int Game::randomAttack(){
    int randomNum;

    randomNum = rand() % 2;

    switch(randomNum){
        case 0:
            return sl_attackSlot1;
        break;

        case 1:
            return sl_attackSlot2;
        break;

        default:
            return sl_attackSlot1;
    }
}

//führt status effekt aus
void Game::doStatusEffect(Pokemon &character){
    int dmg;

    switch(character.getStatus()){
        case ef_burn:
            dmg = character.getMaxHp() * 0.0625;
            character.setHpWithDmg(dmg);
        break;

        case ef_none:
        break;

        default:
        break;
    }
}

//checkt ob character tot ist
bool Game::isDead(Pokemon &character1, Pokemon &character2){
    if(character2.getHp() <= 0){
        std::cout << character1.getName() << " hat " << character2.getName() << " besiegt!" << std::endl;
        Game::winArray.winner[Game::rounds] = character1.getName();
        Game::winArray.loser[Game::rounds] = character2.getName();
        Game::rounds++;
        if(Game::rounds > 9){
            Game::rounds = 0;
        }
        if(Game::printRounds < MAXWINARRAY){
            Game::printRounds++;
        }
        return true;
    }else{
        std::cout << character2.getName() << " hat noch " << character2.getHp() << " hp" << std::endl;
    }
    return false;
}

//führt zufällige attacke aus
bool Game::characterAttack(Pokemon &character1, Pokemon &character2){
    switch(randomAttack()){
        case sl_attackSlot1:
            (character1.*(character1.attack1))(character2);
        break;

        case sl_attackSlot2:
            (character1.*(character1.attack2))(character2);
        break;
    }

    if(character2.getStatus() != ef_none){
        doStatusEffect(character2);
    }

    return isDead(character1, character2);
}

//führt immer ersten Angriff aus
bool Game::characterAttack1(Pokemon &character1, Pokemon &character2){

    (character1.*(character1.attack1))(character2);

    if(character2.getStatus() != ef_none){
        doStatusEffect(character2);
    }

    return isDead(character1, character2);
}

//EvE random attacke beide
void Game::FightRandomVsRandom(Pokemon character1, Pokemon character2){
    bool isBreak = false;
    //setzt srand außerhalb schleife
    time_t t;
    srand((unsigned) time(&t));


//cleart console
    system("cls");
    std::cout << "Der Kampf zwischen " << character1.getName() << " und " << character2.getName() << " beginnt!" << std::endl;

    while(character1.getHp() > 0 && character2.getHp() > 0){
        if(character1.getInitiative() > character2.getInitiative()){
            isBreak = characterAttack(character1, character2);
            if(isBreak){
                break;
            }
            isBreak = characterAttack(character2, character1);
            if(isBreak){
                break;
            }
        }else{
            isBreak = characterAttack(character2, character1);
            if(isBreak){
                break;
            }
            isBreak = characterAttack(character1, character2);
            if(isBreak){
                break;
            }
        }
    }
}

//EvE random attacke gegen nur erste attacke
void Game::FightRandomVsAttack(Pokemon character1, Pokemon character2){
    bool isBreak = false;
    //setzt srand außerhalb schleife
    time_t t;
    srand((unsigned) time(&t));


//cleart console
    system("cls");
    std::cout << "Der Kampf zwischen " << character1.getName() << " und " << character2.getName() << " beginnt!" << std::endl;

    while(character1.getHp() > 0 && character2.getHp() > 0){
        if(character1.getInitiative() > character2.getInitiative()){
            isBreak = characterAttack(character1, character2);
            if(isBreak){
                break;
            }
            isBreak = characterAttack1(character2, character1);
            if(isBreak){
                break;
            }
        }else{
            isBreak = characterAttack1(character2, character1);
            if(isBreak){
                break;
            }
            isBreak = characterAttack(character1, character2);
            if(isBreak){
                break;
            }
        }
    }
}

//EvE nur erste attacke gegen nur erste attacke
void Game::FightAttackVsAttack(Pokemon character1, Pokemon character2){
    bool isBreak = false;

//cleart console
    system("cls");
    std::cout << "Der Kampf zwischen " << character1.getName() << " und " << character2.getName() << " beginnt!" << std::endl;

    while(character1.getHp() > 0 && character2.getHp() > 0){
        if(character1.getInitiative() > character2.getInitiative()){
            isBreak = characterAttack1(character1, character2);
            if(isBreak){
                break;
            }
            isBreak = characterAttack1(character2, character1);
            if(isBreak){
                break;
            }
        }else{
            isBreak = characterAttack1(character2, character1);
            if(isBreak){
                break;
            }
            isBreak = characterAttack1(character1, character2);
            if(isBreak){
                break;
            }
        }
    }
}

//EvE nur erste attacke gegen random attacke
void Game::FightAttackVsRandom(Pokemon character1, Pokemon character2){
    bool isBreak = false;
    //setzt srand außerhalb schleife
    time_t t;
    srand((unsigned) time(&t));

//cleart console
    system("cls");
    std::cout << "Der Kampf zwischen " << character1.getName() << " und " << character2.getName() << " beginnt!" << std::endl;

    while(character1.getHp() > 0 && character2.getHp() > 0){
        if(character1.getInitiative() > character2.getInitiative()){
            isBreak = characterAttack1(character1, character2);
            if(isBreak){
                break;
            }
            isBreak = characterAttack(character2, character1);
            if(isBreak){
                break;
            }
        }else{
            isBreak = characterAttack(character2, character1);
            if(isBreak){
                break;
            }
            isBreak = characterAttack1(character1, character2);
            if(isBreak){
                break;
            }
        }
    }
}

//startet EvE
void Game::startEvE(){
    char yOrN = 'f';

    def_characters userInput;
    Pokemon character1, character2;

    userInput = Game::inputPokemon();
    character1 = Game::createCharacter(userInput);

    userInput = Game::inputPokemon();
    character2 = Game::createCharacter(userInput);


    std::cout << "Soll das erste Pokemon nur einen Angriff benutzen k" << (char)148 << "nnen [y/n]? ";
    yOrN = getYorN();
    if(yOrN == 'y'){
        std::cout << "Soll das zweite Pokemon nur einen Angriff benutzen k" << (char)148 << "nnen [y/n]? ";
        yOrN = getYorN();
        if(yOrN == 'y'){
            FightAttackVsAttack(character1, character2);
        }else{
            FightRandomVsAttack(character1, character2);
        }
    }else{
        std::cout << "Soll das zweite Pokemon nur einen Angriff benutzen k" << (char)148 << "nnen [y/n]? ";
        yOrN = getYorN();
        if(yOrN == 'y'){
            FightAttackVsRandom(character1, character2);
        }else{
            FightRandomVsRandom(character1, character2);
        }
    }
}

//gibt WinArray aus
void Game::printStats(){
    std::cout << std::endl << "Letze 10 K" << (char)132 << "mpfer werden angezeigt:" << std::endl;

    for(int i=0; i<Game::printRounds; i++){
        std::cout << Game::winArray.winner[i] << " hat " << Game::winArray.loser[i] << " besiegt." << std::endl;
    }
}

//führt einen vom Spiler ausgewählten angriff aus
bool Game::playerAttack(Pokemon &character1, Pokemon &character2){
    std::string AttackInput;
    int eingabe = -1;

    std::cout << character1.getName() << " w" << (char)132 << "hle eine Attacke:" << std::endl << "  " << character1.getAttack1Name() << "(1)" << std::endl << "  " << character1.getAttack2Name() << "(2)" << std::endl << "Deine Eingabe: ";
    while(eingabe < 1 || eingabe > 2){
        std::cin >> AttackInput;
        eingabe = std::stoi(AttackInput);
        if(eingabe < 1 || eingabe > 2){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            switch(eingabe){
                case 1:
                    (character1.*(character1.attack1))(character2);
                break;

                case 2:
                    (character1.*(character1.attack2))(character2);
                break;
            }
            if(character2.getStatus() != ef_none){
                doStatusEffect(character2);
            }

            if(character2.getHp() <= 0){
                std::cout << character1.getName() << " hat " << character2.getName() << " besiegt!" << std::endl;
                Game::winArray.winner[Game::rounds] = character1.getName();
                Game::winArray.loser[Game::rounds] = character2.getName();
                Game::rounds++;
                if(Game::rounds > 9){
                    Game::rounds = 0;
                }
                if(Game::printRounds < MAXWINARRAY){
                    Game::printRounds++;
                }
                return true;
            }else{
                std::cout << character2.getName() << " hat noch " << character2.getHp() << " hp" << std::endl;
            }
        }
    }
    return false;
}

//PvE
void Game::FightAgainstPc(Pokemon character1, Pokemon character2){
    bool isBreak = false;
    //setzt srand außerhalb schleife
    time_t t;
    srand((unsigned) time(&t));


//cleart console
    system("cls");
    std::cout << "Der Kampf zwischen " << character1.getName() << " und " << character2.getName() << " beginnt!" << std::endl;

    while(character1.getHp() > 0 && character2.getHp() > 0){
        if(character1.getInitiative() > character2.getInitiative()){
            isBreak = playerAttack(character1, character2);
            if(isBreak){
                break;
            }
            isBreak = characterAttack(character2, character1);
            if(isBreak){
                break;
            }
        }else{
            isBreak = characterAttack(character2, character1);
            if(isBreak){
                break;
            }
            isBreak = playerAttack(character1, character2);
            if(isBreak){
                break;
            }
        }
    }
}

//startet PvE
void Game::startPvE(){
    def_characters userInput;
    Pokemon character1, character2;

    userInput = Game::inputPokemon();
    character1 = Game::createCharacter(userInput);

    userInput = Game::inputPokemon();
    character2 = Game::createCharacter(userInput);

    FightAgainstPc(character1, character2);
}

//PvP
void Game::FightAgainstPlayer(Pokemon character1, Pokemon character2){
    bool isBreak = false;
    //setzt srand außerhalb schleife
    time_t t;
    srand((unsigned) time(&t));


//cleart console
    system("cls");
    std::cout << "Der Kampf zwischen " << character1.getName() << " und " << character2.getName() << " beginnt!" << std::endl;

    while(character1.getHp() > 0 && character2.getHp() > 0){
        if(character1.getInitiative() > character2.getInitiative()){
            isBreak = playerAttack(character1, character2);
            if(isBreak){
                break;
            }
            isBreak = playerAttack(character2, character1);
            if(isBreak){
                break;
            }
        }else{
            isBreak = playerAttack(character2, character1);
            if(isBreak){
                break;
            }
            isBreak = playerAttack(character1, character2);
            if(isBreak){
                break;
            }
        }
    }
}

//start PvP
void Game::startPvP(){
    def_characters userInput;
    Pokemon character1, character2;

    userInput = Game::inputPokemon();
    character1 = Game::createCharacter(userInput);

    userInput = Game::inputPokemon();
    character2 = Game::createCharacter(userInput);

    FightAgainstPlayer(character1, character2);
}

//fürs wechseln
bool Game::wantToSwitch(){
    char swichInput = 't';

    std::cout << "M" << (char)148 << "chtest du Pokemon wechseln [y/n]? ";
    while(swichInput != 'n' && swichInput != 'y'){
        std::cin >> swichInput;
        if(swichInput != 'n' && swichInput != 'y'){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            if(swichInput == 'n'){
                return false;
            }else if(swichInput == 'y'){
                return true;
            }
        }
    }
    return false;
}

//Teamkampf angriff auswählen
bool Game::playerAttackTeam(Team  &team1, Team &team2){
    std::string AttackInput;
    int eingabe = -1;

    std::cout << team1.getPrimary().getName() << " w" << (char)132 << "hle eine Attacke:" << std::endl << "  " << team1.getPrimary().getAttack1Name() << "(1)" << std::endl << "  " << team1.getPrimary().getAttack2Name() << "(2)" << std::endl << "Deine Eingabe: ";
    while(eingabe < 1 || eingabe > 2){
        std::cin >> AttackInput;
        eingabe = std::stoi(AttackInput);
        if(eingabe < 1 || eingabe > 2){
            std::cout << "Ung" << (char)129 << "ltige Eingabe, versuch es erneut: ";
        }else{
            switch(eingabe){
                case 1:
                    if(team2.getActivePokemon() == pa_pokemon1Active){
                        (team1.getPrimary().*(team1.getPrimary().attack1))(team2.getPokemon1());
                    }else{
                        (team1.getPrimary().*(team1.getPrimary().attack1))(team2.getPokemon2());
                    }
                break;

                case 2:
                    if(team2.getActivePokemon() == pa_pokemon1Active){
                        (team1.getPrimary().*(team1.getPrimary().attack2))(team2.getPokemon1());
                    }else{
                        (team1.getPrimary().*(team1.getPrimary().attack2))(team2.getPokemon2());
                    }
                break;
            }

            if(team2.getPrimary().getStatus() != ef_none){
                if(team2.getActivePokemon() == pa_pokemon1Active){
                    doStatusEffect(team2.getPokemon1());
                }else{
                    doStatusEffect(team2.getPokemon2());
                }
            }

            if(team2.getPrimary().getHp() <= 0){
                std::cout << team2.getPrimary().getName() << " hat " << team2.getPrimary().getName() << " besiegt!" << std::endl;
                Game::winArray.winner[Game::rounds] = team1.getPrimary().getName();
                Game::winArray.loser[Game::rounds] = team2.getPrimary().getName();
                Game::rounds++;
                if(Game::rounds > 9){
                    Game::rounds = 0;
                }
                if(Game::printRounds < MAXWINARRAY){
                    Game::printRounds++;
                }
                return true;
            }else{
                std::cout << team2.getPrimary().getName() << " hat noch " << team2.getPrimary().getHp() << " hp" << std::endl;
            }
        }
    }
    return false;
}

//Teamkampf runde
void Game::TeamAgainstTeam(Team team1, Team team2){
    bool isBreak = false;
    bool wantSwitch, switchSucces;
    //setzt srand außerhalb schleife
    time_t t;
    srand((unsigned) time(&t));

    system("cls");

//setzt primary Pokemon, geht nicht in klasse da es ne referenz ist. Wenn doch wie?
    std::cout << "Der Kampf zwischen " << team1.getTeamName() << " und " << team2.getTeamName() << " beginnt!" << std::endl;

    while((team1.getPokemon1().getHp() > 0 || team1.getPokemon2().getHp() > 0) && (team2.getPokemon1().getHp() > 0 || team2.getPokemon2().getHp() > 0)){
        if(team1.getPrimary().getInitiative() > team2.getPrimary().getInitiative()){
            std::cout << "Team " << team1.getTeamName() << ":" << std::endl;
            wantSwitch = wantToSwitch();
            if(wantSwitch){
                switchSucces = team1.switchPrimary(false);
            }else{
                switchSucces = false;
            }

            if(!switchSucces){
                isBreak = playerAttackTeam(team1, team2);
                if(isBreak){
                    if(team2.getPokemon1().getHp() <= 0 && team2.getPokemon2().getHp() <= 0){
                        break;
                    }else{
                        switchSucces = team2.switchPrimary(true);
                    }
                }
            }
            std::cout << "Team " << team2.getTeamName() << ":" << std::endl;
            wantSwitch = wantToSwitch();
            if(wantSwitch){
                switchSucces = team2.switchPrimary(false);
            }else{
                switchSucces = false;
            }

            if(!switchSucces){
                isBreak = playerAttackTeam(team2, team1);
                if(isBreak){
                    if(team1.getPokemon1().getHp() <= 0 && team1.getPokemon2().getHp() <= 0){
                        break;
                    }else{
                        switchSucces = team1.switchPrimary(true);
                    }
                }
            }

        }else{
            std::cout << "Team " << team2.getTeamName() << ":" << std::endl;
            wantSwitch = wantToSwitch();
            if(wantSwitch){
                switchSucces = team2.switchPrimary(false);
            }else{
                switchSucces = false;
            }

            if(!switchSucces){
                isBreak = playerAttackTeam(team2, team1);
                if(isBreak){
                    if(team1.getPokemon1().getHp() <= 0 && team1.getPokemon2().getHp() <= 0){
                        break;
                    }else{
                        switchSucces = team1.switchPrimary(true);
                    }
                }
            }
            std::cout << "Team " << team1.getTeamName() << ":" << std::endl;
            wantSwitch = wantToSwitch();
            if(wantSwitch){
                switchSucces = team1.switchPrimary(false);
            }else{
                switchSucces = false;
            }

            if(!switchSucces){
                isBreak = playerAttackTeam(team1, team2);
                if(isBreak){
                    if(team2.getPokemon1().getHp() <= 0 && team2.getPokemon2().getHp() <= 0){
                        break;
                    }else{
                        switchSucces = team2.switchPrimary(true);
                    }
                }
            }
        }
    }
}
//startet 2v2
void Game::start2v2(){
    std::string teamName;
    def_characters userInput;
    Pokemon pokemon1, pokemon2;

    userInput = Game::inputPokemon();
    pokemon1 = Game::createCharacter(userInput);
    userInput = Game::inputPokemon();
    pokemon2 = Game::createCharacter(userInput);
    Team team1(pokemon1, pokemon2);
    std::cout << "Wie soll Team 1 hei" << (char)225 << "en: ";
    std::cin >> teamName;
    team1.setTeamName(teamName);


    system("cls");
    userInput = Game::inputPokemon();
    pokemon1 = Game::createCharacter(userInput);
    userInput = Game::inputPokemon();
    pokemon2 = Game::createCharacter(userInput);
    Team team2(pokemon1, pokemon2);
    std::cout << "Wie soll Team 2 hei" << (char)225 << "en: ";
    std::cin >> teamName;
    team2.setTeamName(teamName);

    TeamAgainstTeam(team1, team2);
}
