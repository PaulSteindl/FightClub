#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include <string>
#include "attack.h"
#include "attackSlot.h"
#include "effect.h"

class Pokemon{
    public:
        Pokemon();
//wird gebraucht da defaultkonstrukor am start eines spiels aufgerufen wird um charaktere zu deklarieren
        Pokemon(bool custom);
        Pokemon(def_attack attack1, def_attack attack2);

        virtual ~Pokemon();

        int getHp() const {return hp;}
        int getMaxHp() const {return maxhp;}
        int getInitiative() const {return initiative;}
        std::string getName() const {return name;}
        def_effect getStatus() const {return status;}
        std::string getAttack1Name() const {return attack1Name;}
        std::string getAttack2Name() const {return attack2Name;}

        void setHpWithDmg(int dmg){hp -= dmg;}
        void setCustomAttacks();

        void (Pokemon:: *attack1)(Pokemon&);
        void (Pokemon:: *attack2)(Pokemon&);

    protected:
        std::string attack1Name;
        std::string attack2Name;
        std::string name;
        int hp;
        int maxhp;
        int def;
        int ap;
        int initiative;
        def_effect status;

    private:
        int skillPoints = 37;

        int getSkillpointInput();
        void CheckDefense(int thisAp, int &otherDef, int &otherHp, int dmg);
        void selectAttack(def_attack attack, def_attackSlot attackSlot);
        void tackle(Pokemon& other);
        void blubber(Pokemon& other);
        void kratzer(Pokemon& other);
        void glut(Pokemon& other);
};

#endif // POKEMON_H_INCLUDED
