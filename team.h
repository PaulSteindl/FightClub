#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "pokemonActive.h"
#include "pokemon.h"

class Team{
    public:
        Team(Pokemon pokemon1, Pokemon pokemon2);

        ~Team();

        void setPokemon1(Pokemon pokemon){pokemon1 = pokemon;}
        void setPokemon2(Pokemon pokemon){pokemon2 = pokemon;}
        void setTeamName(std::string name){teamName = name;}
        void setActivePokemon(def_pokemonActive active){activePokemon = active;}

        std::string getTeamName()  const {return teamName;}
        Pokemon getPokemon1() const {return pokemon1;}
        Pokemon getPokemon2() const {return pokemon2;}
        Pokemon getPrimary() const {return primaryPokemon;};
        def_pokemonActive getActivePokemon() const {return activePokemon;}
        bool switchPrimary(bool pokemonDied);

    private:
        std::string teamName;
        Pokemon pokemon1;
        Pokemon pokemon2;
        Pokemon &primaryPokemon;
        def_pokemonActive activePokemon = pa_pokemon1Active;
};

#endif // TEAM_H_INCLUDED
