#include <gtk/gtk.h>





void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkWidget     *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonelctionaffichage_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_button7_election_chercher_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
