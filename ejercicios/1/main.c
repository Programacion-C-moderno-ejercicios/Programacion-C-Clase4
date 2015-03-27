#include "concesionario.h"
#include <gtk/gtk.h>

struct concesionario **concesionarios;
int id = 0;
int con_activo;

static void add_car(GtkButton *widget, gpointer data)
{
	GtkWidget **entry;
	struct coche *c;
	GtkWidget *entry_ptr_marca;
	GtkWidget *entry_ptr_matricula;
	const gchar *matricula, *marca;

	entry = (GtkWidget **)data;
	entry_ptr_marca = entry[0];
	entry_ptr_matricula = entry[1];

	printf("llega\n");

	marca = gtk_entry_get_text((GtkEntry *)entry_ptr_marca);
	matricula = gtk_entry_get_text((GtkEntry *)entry_ptr_matricula);

	c = curso_coche_alloc();
	if (c == NULL)
		return;

	curso_coche_attr_set_u32(c, CURSO_COCHE_ATTR_ID, id++);
	curso_coche_attr_set_str(c, CURSO_COCHE_ATTR_MATRICULA, matricula);
	curso_coche_attr_set_str(c, CURSO_COCHE_ATTR_MARCA, marca);

	curso_concesionario_attr_set_coche(concesionarios[con_activo], CURSO_CONCESIONARIO_ATTR_COCHE,
					   c);

	printf ("Result: %d , %s, %s\n", id - 1, marca, matricula);

	gtk_entry_set_text((GtkEntry *)entry_ptr_marca, "");
	gtk_entry_set_text((GtkEntry *)entry_ptr_matricula, "");
}

static void show_concesionario(GtkButton *widget, gpointer data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *entry1, *entry2;
	GtkWidget *box;
	GtkWidget **entry;

	entry = calloc(1, 2 * sizeof(GtkWidget));

	int i = 0;
	for(i = 0; i < 10; i++){
		if(concesionarios[i] == (struct concesionario*) data) con_activo = i;
	}
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_label("Add me");
	box = gtk_vbox_new(TRUE,2);
	entry1 = gtk_entry_new();
	entry2 = gtk_entry_new();

	entry[0] = entry1;
	entry[1] = entry2;

	gtk_box_pack_start ((GtkBox *)box, entry1, TRUE, TRUE, 2);
	gtk_box_pack_start ((GtkBox *)box, entry2, TRUE, TRUE, 2);

	gtk_box_pack_start ((GtkBox *)box, button, TRUE, TRUE, 2);

	gtk_container_add((GtkContainer *)window, box);

	g_signal_connect((GObject *)button, "clicked", (GCallback)add_car,
			 (gpointer)entry);
	gtk_widget_show_all(window);
}

static void funcion_quit(GtkButton *boton, gpointer data)
{
	int i;
	for(i = 0; i < 10; i++){
		curso_concesionario_free(concesionarios[i]);
	}
	gtk_main_quit();
}

int main (int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *button0;
	GtkWidget *button1;
	GtkWidget *button2;
	GtkWidget *button3;
	GtkWidget *button4;
	GtkWidget *button5;
	GtkWidget *button6;
	GtkWidget *button7;
	GtkWidget *button8;
	GtkWidget *button9;
	GtkWidget *vbox;

	concesionarios = calloc(10, sizeof(struct concesionario *));
	int i = 0;
	for(i = 0; i < 10; i++){
		concesionarios[i] = curso_concesionario_alloc();
		if (concesionarios[i] == NULL)
			return -1;

		curso_concesionario_attr_set_str(concesionarios[i], CURSO_CONCESIONARIO_ATTR_DUENO,
					 	"Pablo");
	}

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button0 = gtk_button_new_with_label("Concesionario 0");
	button1 = gtk_button_new_with_label("Concesionario 1");
	button2 = gtk_button_new_with_label("Concesionario 2");
	button3 = gtk_button_new_with_label("Concesionario 3");
	button4 = gtk_button_new_with_label("Concesionario 4");
	button5 = gtk_button_new_with_label("Concesionario 5");
	button6 = gtk_button_new_with_label("Concesionario 6");
	button7 = gtk_button_new_with_label("Concesionario 7");
	button8 = gtk_button_new_with_label("Concesionario 8");
	button9 = gtk_button_new_with_label("Concesionario 9");
	vbox = gtk_vbox_new(TRUE,5);

	gtk_window_set_title((GtkWindow *)window, "Concesionarios");

	gtk_box_pack_start((GtkBox *)vbox, button0, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button1, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button2, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button3, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button4, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button5, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button6, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button7, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button8, TRUE, TRUE, 2);
	gtk_box_pack_start((GtkBox *)vbox, button9, TRUE, TRUE, 2);

	gtk_container_add((GtkContainer *)window, vbox);

	g_signal_connect((GObject *)button0, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[0]);
	g_signal_connect((GObject *)button1, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[1]);
	g_signal_connect((GObject *)button2, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[2]);
	g_signal_connect((GObject *)button3, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[3]);
	g_signal_connect((GObject *)button4, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[4]);
	g_signal_connect((GObject *)button5, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[5]);
	g_signal_connect((GObject *)button6, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[6]);
	g_signal_connect((GObject *)button7, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[7]);
	g_signal_connect((GObject *)button8, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[8]);
	g_signal_connect((GObject *)button9, "clicked", (GCallback)show_concesionario, (gpointer) concesionarios[9]);

	g_signal_connect((GObject *)window, "delete-event",
			 (GCallback)funcion_quit, NULL);

	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}
