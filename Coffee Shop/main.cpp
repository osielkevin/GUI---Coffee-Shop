#include "mainwin.h"
#include <gtkmm.h>
#include "store.h"
int main (int argc, char *argv[])
{
  //edu.uta.cse1325.nim
  auto app = Gtk::Application::create(argc, argv, "Coffee");
  // Instance a Window
  Store a{"The Store"};
  Mainwin win{a};

  // Set the window title
  win.set_title(a.name());

  //Show the window and returns when it is closed or hidden
  return app->run(win);
}
