#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct date
{
    int jour;
    int mois;
    int annee;
} date;
typedef struct election
{
    char id[20] ;
    char nbre_habitant[30] ;
    char municipalite[50];
    date date ;
    char conseillers[30];
    char code_postal[30];
    char modification[30];
}election;

//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
void ajouter_election(election e );
void modifier_election( char*filename ,char id[], election e );
void supprimer_election(election e);
void afficher_election(GtkWidget *liste,char*filename);
election_chercher(char*filename,char id[]);
void supprimer_elc(char * filename, char id []);

#endif // POINT_H_INCLUDED
