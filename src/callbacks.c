#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "election.h"
#include <string.h>



void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)

{
	int v ;
	char f[50];
	election e ;
	GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8;
	GtkWidget *window1;
	window1 = lookup_widget(objet,"window1");
	
	
	
	input1 = lookup_widget(objet,"jour");
	input2 = lookup_widget(objet,"mois");
	input3 = lookup_widget(objet,"ann__e");
	input4 = lookup_widget(objet,"entry1");
	input5 = lookup_widget(objet,"entry2");
	input6 = lookup_widget(objet,"entry3");
        input7 = lookup_widget(objet,"entry4");
	input8 = lookup_widget(objet,"entry5");

	
	e.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
	e.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
	e.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
        strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(input4)));
        strcpy(e.nbre_habitant,gtk_entry_get_text(GTK_ENTRY(input5)));
        strcpy(e.municipalite,gtk_entry_get_text(GTK_ENTRY(input6)));
        strcpy(e.conseillers,gtk_entry_get_text(GTK_ENTRY(input7)));
        strcpy(e.code_postal,gtk_entry_get_text(GTK_ENTRY(input8)));
	
	
	ajouter_election(e);
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)

{
	GtkWidget *input1 ,*input2 ,*input3 ,*input4 ,*input5 ,*input6 ,*input7 ,*input0 ,*output7;
	int tr,a;
	election e , b ;
	GtkWidget *window1;
	window1 = lookup_widget(objet,"window1");
	input0 = lookup_widget(objet,"entry6elec");
	input1 = lookup_widget(objet,"entry7election");
	input2 = lookup_widget(objet,"entry8elec");
        input3 = lookup_widget(objet,"entry9election");
	input4 = lookup_widget(objet,"entry10election");

	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(input0)));
	strcpy(e.nbre_habitant,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(e.conseillers,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(e.code_postal,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(e.municipalite,gtk_entry_get_text(GTK_ENTRY(input4)));
	
	modifier_election("nouv.txt", e.id,e);

}
void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)


{
	election e;
	int n;
	char str[50];
	GtkWidget *input1 ;
GtkWidget *window1;
	window1 = lookup_widget(objet_graphique,"window1");
	
	//GtkWidget *election;
	//election = lookup_widget(objet_graphique,"election");
	input1=lookup_widget(objet_graphique,"entryelection_id7");
	strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(input1)));
 	supprimer_elc("nouv.txt", e.id);
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)


{
	GtkTreeIter iter;

	gchar* id;
	gchar* nbre_habitant;
	gchar* municipalite;
	gchar* conseillers;
	gchar* code_postal;
	election e;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);


	if (gtk_tree_model_get_iter(model, &iter, path)) 
 {
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nbre_habitant, 2, &municipalite, 3, &conseillers, 4, &code_postal, -1);
	strcpy(e.id,id);
	strcpy(e.nbre_habitant,nbre_habitant);
	strcpy(e.municipalite,municipalite);
	strcpy(e.conseillers,conseillers);
	strcpy(e.code_postal,code_postal);

	
	afficher_election(treeview,"nouv.txt");
 }

}	





void
on_buttonelctionaffichage_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1 ;
GtkWidget *window1 ;
window1=lookup_widget(objet_graphique,"window1");
treeview1=lookup_widget(window1,"treeview1");
afficher_election(GTK_TREE_VIEW(treeview1),"nouv.txt");
afficher_election(treeview1,"nouv.txt");

}

void
on_button7_election_chercher_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1 ;
GtkWidget *output7;
election e;
int tr=0;
char str[20];

input1=lookup_widget(objet_graphique,"entryelection_id7");
output7= lookup_widget(objet_graphique,"labelelectiontrouver");
strcpy(str,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE * f=fopen("nouv.txt", "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s  %s %s\n",e.id,e.nbre_habitant,e.municipalite,e.conseillers,e.code_postal)!=EOF)
        {
            if(strcmp(str,e.id)==0)
                tr=1;
        }
    fclose (f);
    }
if (tr==1)
{
//bv p=rechercher_bv(str);
gtk_label_set_text(GTK_LABEL(output7),"election trouver");
        
}
else
{
gtk_label_set_text(GTK_LABEL(output7),"election non trouver");
}
	
}

