#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "pokemonActive.h"
#include "pokemon.h"

class Team{
    public:
        Team(Pokemon pokemon1, Pokemon pokemon2);

        ~Team();

        void setTeamName(std::string name){teamName = name;}
        void setActivePokemon(def_pokemonActive active){activePokemon = active;}

        std::string getTeamName()  const {return teamName;}
        Pokemon & getPokemon1(){return pokemon1;}
        Pokemon & getPokemon2(){return pokemon2;}
        def_pokemonActive getActivePokemon() const {return activePokemon;}
        Pokemon getPrimary();

        bool switchPrimary(bool pokemonDied);

    private:
        std::string teamName;
        Pokemon &primaryPokemon;
        def_pokemonActive activePokemon = pa_pokemon1Active;
        Pokemon pokemon1;
        Pokemon pokemon2;
};

#endif // TEAM_H_INCLUDED
