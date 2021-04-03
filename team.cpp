#include <iostream>
#include "team.h"

Team::Team(Pokemon pokemon1, Pokemon pokemon2) : primaryPokemon(pokemon1){
    this->pokemon1 = pokemon1;
    this->pokemon2 = pokemon2;
}

Team::~Team(){}

bool Team::switchPrimary(bool pokemonDied){
    if((pokemon1.getHp() > 0 && pokemon2.getHp() > 0) || pokemonDied){
        if(activePokemon == pa_pokemon1Active){
            primaryPokemon = pokemon2;
            activePokemon = pa_pokemon2Active;
        }else{
            primaryPokemon = pokemon1;
            activePokemon = pa_pokemon1Active;
        }
        std::cout << teamName << " hat zu " << primaryPokemon.getName() << " gewechselt." << std::endl;
        return true;
    }
    std::cout << "Du kannst nicht wechseln!" << std::endl;
        return false;
}

Pokemon Team::getPrimary(){
    if(activePokemon == pa_pokemon1Active){
        return pokemon1;
    }

    return pokemon2;
};
