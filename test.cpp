#include "test.h"
#include "effect.h"
#include "pokemon.h"
#include "schiggy.h"
#include "glumanda.h"
#include "game.h"
#include "team.h"
#include <iostream>
#include <assert.h>

void runTests(){
    std::cout << "Tests sind aktiv" << std::endl;

    testIsSchiggyCorrectInitalized();
    testIsGlumandaCorrectInitalized();
    testAttackTackleOnSchiggy();
    testAttackBlubberOnSchiggy();
    testAttackKratzerOnSchiggy();
    testAttackGlutOnSchiggy();
    testTeamActivePokemonIsSetCorrectAndPrimaryPokemonCorrectRefrenz();
    testTeamPokemon1And2IsCorrect();
    testSwitchPrimaryForTeam();
    testTeamNameSetCorrect();

    system("cls");
    std::cout << "Tests waren erfolgreich!";
}

void testIsSchiggyCorrectInitalized(){
    Schiggy schiggy;

    assert(schiggy.getAttack1Name() == "Tackle");
    assert(schiggy.getAttack2Name() == "Blubber");
    assert(schiggy.getHp() == schiggy.getMaxHp());
    assert(schiggy.getInitiative() == 25);
    assert(schiggy.getName() == "Schiggy");
    assert(schiggy.getStatus() == ef_none);

    std::cout << "Schiggy wird richig initialisiert." << std::endl;
}

void testIsGlumandaCorrectInitalized(){
    Glumanda glumanda;

    assert(glumanda.getAttack1Name() == "Kratzer");
    assert(glumanda.getAttack2Name() == "Glut");
    assert(glumanda.getHp() == glumanda.getMaxHp());
    assert(glumanda.getInitiative() == 29);
    assert(glumanda.getName() == "Glumanda");
    assert(glumanda.getStatus() == ef_none);

    std::cout << "Glumanda wird richig initialisiert." << std::endl;
}

void testAttackTackleOnSchiggy(){
    Schiggy schiggyArray[200];
    Schiggy schiggy;
    int  missed=0, hit=0;

    for(int i=0; i < 200; i++){
        (schiggy.*(schiggy.attack1))(schiggyArray[i]);
        if(schiggyArray[i].getHp() == 38){
            missed++;
        }else if(schiggyArray[i].getHp() == 32){
            hit++;
        }
        assert(schiggyArray[i].getHp() == 38 || schiggyArray[i].getHp() == 32);
    }

    if(missed <= 0 || hit <= 0){
        std::cout << "Es gab nur " << hit << " treffen und es wurden nur " << missed << " verfehlt.";
        assert(false);
    }
}

void testAttackBlubberOnSchiggy(){
    Schiggy schiggyArray[200];
    Schiggy schiggy;
    int  decreased=0;

    for(int i=0; i < 200; i++){
        (schiggy.*(schiggy.attack2))(schiggyArray[i]);
        assert(schiggyArray[i].getHp() == 38 );
        if(schiggyArray[i].getInitiative() == 20){
            decreased++;
        }
    }

    if(decreased < 5){
        std::cout << "Es wurde nur " << decreased << " die Initative gesenkt!";
        assert(false);
    }
}

void testAttackKratzerOnSchiggy(){
    Schiggy schiggy;
    Glumanda glumanda;

    (glumanda.*(glumanda.attack1))(schiggy);
    assert(schiggy.getHp() == 27 );
}

void testAttackGlutOnSchiggy(){
    Schiggy schiggyArray[200];
    Glumanda glumanda;
    int  burning=0;

    for(int i=0; i < 200; i++){
        (glumanda.*(glumanda.attack2))(schiggyArray[i]);
        assert(schiggyArray[i].getHp() == 27);
        if(schiggyArray[i].getStatus() == ef_burn){
            burning++;
        }
    }

    if(burning < 5){
        std::cout << "Es wurde nur " << burning << " jmd in Brand gestekt!";
        assert(false);
    }
}

void testTeamActivePokemonIsSetCorrectAndPrimaryPokemonCorrectRefrenz(){
    Glumanda glumanda;
    Schiggy schiggy;
    Team team(glumanda, schiggy);

    assert(team.getActivePokemon() == pa_pokemon1Active);
    assert(team.getPrimary().getName() == "Glumanda");
}

void testTeamPokemon1And2IsCorrect(){
    Glumanda glumanda;
    Schiggy schiggy;
    Team team(glumanda, schiggy);

    assert(team.getPokemon1().getName() == "Glumanda");
    assert(team.getPokemon2().getName() == "Schiggy");
}

void testSwitchPrimaryForTeam(){
    Glumanda glumanda;
    Schiggy schiggy;
    Team team(glumanda, schiggy);

    team.switchPrimary(true);

    assert(team.getActivePokemon() == pa_pokemon2Active);
    assert(team.getPrimary().getName() == "Schiggy");
}

void testTeamNameSetCorrect(){
    Glumanda glumanda;
    Schiggy schiggy;
    Team team(glumanda, schiggy);

    team.setTeamName("KekW");
    assert(team.getTeamName() == "KekW");
}
