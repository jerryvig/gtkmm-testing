/* -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
#include <config.h>

#include <locale.h>
#include <glib/gi18n.h>
#include "application.hpp"

int main (int argc, char *argv[]) {
    bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
    bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
    textdomain (GETTEXT_PACKAGE);
    setlocale (LC_ALL, "");

    Glib::RefPtr<GsmApplication> application = GsmApplication::get();
    return application->run(argc, argv);
}
