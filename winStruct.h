#ifndef WINSTRUCT_H_INCLUDED
#define WINSTRUCT_H_INCLUDED

#define MAXWINARRAY 10

typedef struct def_win{
    std::string winner[MAXWINARRAY];
    std::string loser[MAXWINARRAY];
}def_win;

#endif // WINSTRUCT_H_INCLUDED
