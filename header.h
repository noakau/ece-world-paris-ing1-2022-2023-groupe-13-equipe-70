#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H
typedef struct
{
    int ticket, victoire_roulette;
    char* nom;
}joueur;

void initialisation();
int roulette(int* symbole);
int main_jackpot(joueur* joueur);
#endif //PROJET_HEADER_H
