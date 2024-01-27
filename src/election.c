
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<callbacks.h>
#include<interface.h>
#include "election.h"
#include <gtk/gtk.h>
enum
{EID,
EMUNICIPALITE,
ENBRE_HABITANT,
ECONSEILLERS,
ECODE_POSTAL,
COLUMNS
};
void ajouter_election(election e )
{
    FILE * f=fopen("nouv.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s  %s %s\n",e.id,e.nbre_habitant,e.municipalite,e.conseillers,e.code_postal);
        fclose(f);
    }
    
}
/*
void supprimer_election(election e)
{
	char id[30];
	char nbre_habitant[30];
	char municipalite[30];
	char conseillers[30];
	char code_postal[30];
    FILE * f=fopen("nouv.txt", "r");
    FILE * f2=fopen("nouv2.txt", "w");
    if(f==NULL || f2==NULL)
   {
 	return;
   }
    else{

  	 while(fscanf(f,"%s %s %s %s %s\n",id,nbre_habitant,municipalite,conseillers,code_postal)!=EOF)
        {
            if(strcmp(e.id,id)!=0 || strcmp(e.nbre_habitant,nbre_habitant)!=0 || strcmp(e.municipalite,municipalite)!=0 || strcmp(e.conseillers,conseillers)!=0 || strcmp(e.code_postal,code_postal)!=0 )
                fprintf(f2,"%s %s %s %s %s \n",id,nbre_habitant,municipalite,conseillers,code_postal);
        }
    }
    fclose(f);
    fclose(f2);
    remove("nouv.txt");
    rename("nouv2.txt", "nouv.txt");
   // election_cherhcer(char*filenale,char id[]);
    
}

election_chercher(char*filename,char id[])
{
    election e;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %s %d %s %d %d\n",&e.id,&e.nbre_habitant,e.municipalite,&e.date.jour,e.date.mois,&e.date.annee,&e.conseillers)!=EOF)
        {
            if(e.id== id)
                tr=1;
        }
    }
    fclose(f);
   
    return ;

}*/
void modifier_election( char * filename, char id[], election nouv )
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv2.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s\n",e.id,e.nbre_habitant,e.municipalite,e.code_postal,e.conseillers)!=EOF)
        {
            if(strcmp(e.id,id)==0)
            {
                fprintf(f2,"%s %s %s %s %s\n",nouv.id,nouv.nbre_habitant,nouv.municipalite,nouv.code_postal,nouv.conseillers);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s\n",e.id,e.nbre_habitant,e.municipalite,e.code_postal,e.conseillers);

        }
    }
    fclose(f);
    fclose(f2);
    remove("nouv.txt");
    rename("nouv2.txt", "nouv.txt");
   

}
void afficher_election(GtkWidget *liste,char*filename)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	election e;
	/*char id[30];
	char nbre_habitant[30];
	char municipalite[30];
	char conseillers[30];
	char code_postal[30];*/
	store=gtk_tree_view_get_model(liste);
	store=NULL;
	FILE *f;
	store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id" , renderer, "text" ,EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nbre_habitant" , renderer, "text" ,ENBRE_HABITANT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("municipalite" , renderer, "text" ,EMUNICIPALITE,NULL);
	
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("conseillers" , renderer, "text" ,ECONSEILLERS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("code_postal" , renderer, "text" ,ECODE_POSTAL, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);	
	f=fopen(filename, "r");
	if(f==NULL)
	{
	         return;
	}
	else
	{
		f=fopen(filename, "a+");
		while(fscanf(f,"%s %s %s %s %s \n" ,e.id,e.nbre_habitant,e.conseillers,e.municipalite,e.code_postal)!=EOF)
	{
		gtk_list_store_append (store, &iter);
		gtk_list_store_set (store, &iter, EID, e.id, ENBRE_HABITANT, e.nbre_habitant,  ECONSEILLERS, e.conseillers, EMUNICIPALITE, e.municipalite, ECODE_POSTAL, e.code_postal, -1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
	}
}

void supprimer_elc(char * filename, char id [])
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv2.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s\n",e.id,e.nbre_habitant,e.municipalite,e.conseillers,e.code_postal)!=EOF)
        {
            if(strcmp(e.id,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s\n",e.id,e.nbre_habitant,e.municipalite,e.conseillers,e.code_postal);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv2.txt", filename);

}






	








