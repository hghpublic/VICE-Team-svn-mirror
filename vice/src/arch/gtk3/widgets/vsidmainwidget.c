/** \file   vsidmainwidget.c
 * \brief   GTK3 main widget for VSD
 *
 * \author  Bas Wassink <b.wassink@ziggo.nl>
 */

/*
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */


#include "vice.h"

#include <stdlib.h>
#include <gtk/gtk.h>

#include "vice_gtk3.h"
#include "debug.h"
#include "machine.h"
#include "lib.h"
#include "log.h"
#include "vsidtuneinfowidget.h"

#include "vsidmainwidget.h"


static GtkWidget *tune_info_widget;


/** \brief  Create VSID main widget
 *
 * \return  GtkGrid
 */
GtkWidget *vsid_main_widget_create(void)
{
    GtkWidget *grid;
#if 0
    GtkWidget *label;
#endif
    grid = vice_gtk3_grid_new_spaced(VICE_GTK3_DEFAULT, VICE_GTK3_DEFAULT);
#if 0
    label = gtk_label_new("This needs a lot of work.");
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(label, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand(label, TRUE);
    gtk_widget_set_vexpand(label, TRUE);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
#endif

    tune_info_widget = vsid_tune_info_widget_create();
    gtk_grid_attach(GTK_GRID(grid), tune_info_widget, 0, 0, 1, 1);
    gtk_widget_show_all(grid);
    return grid;
}
