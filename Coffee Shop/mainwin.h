#ifndef MAINWIN_H
#define MAINWIN_H
#include <gtkmm.h>
#include "store.h"
enum Action{Show, Fill, Pay,Discard};
class Mainwin : public Gtk::Window
{
    public:
        Mainwin(Store & store);
        virtual ~Mainwin();

    protected:
      /*------Exiting------*/
      void on_quit_click();
      /*-----View Function----*/
      void on_view_all_click();
      void on_list_customers_click();
      void on_list_products_click();

      void on_view_orders_click();
      /*------Creating Function -----*/
      void on_create_coffee_click();
      void on_create_donut_click();
      void on_new_customer_click();
      void on_create_order_click();
      void update_cash(double money);
      void on_fill_clicked();
      void on_pay_clicked();
      void on_discard_clicked();

      /*------ETC------*/
      void on_about_click();
      void on_easter_click();
    private:
        Store _store;
          Gtk::Label *cash;
          Gtk::Label *status;
          double sum;
};

#endif // MAINWIN_H
