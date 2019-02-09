#include "mainwin.h"
#include <sstream>
#include <regex>
//Creates a window for GUI.
//A lot of this code is just copy and paste to make the boxes for the GUI.
Mainwin::Mainwin(Store & store): _store{store}{
    Gtk::ScrolledWindow *scrolled_window;
    set_default_size(400, 500);
    std::string cash2 = "";
    std::string blank = "";
    cash2 = std::to_string(_store.cash());

    // Put a vertical box container as the Window contents
     Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    Gtk::VBox *view = Gtk::manage(new Gtk::VBox());
     Gtk::VBox *create = Gtk::manage(new Gtk::VBox());
     Gtk::VBox *order = Gtk::manage(new Gtk::VBox());
     Gtk::VBox *etc = Gtk::manage(new Gtk::VBox());
      Gtk::HBox *statusbox = Gtk::manage(new Gtk::HBox());
     Gtk::HBox *moneybox = Gtk::manage(new Gtk::HBox());
     cash = Gtk::manage(new Gtk::Label(cash2));
     status = Gtk::manage(new Gtk::Label(blank));

    add(*vbox);
    /*    MENU BAR*/
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    vbox->pack_start(*create);
    vbox->pack_start(*view);
    vbox->pack_start(*order);
    vbox->pack_start(*etc);
    vbox->pack_start(*statusbox);
    vbox->pack_start(*moneybox);
    statusbox->pack_start(*cash);
    moneybox->pack_start(*status);
    Mainwin::update_cash(0);

    /*-Sets tools to the submenu-*/
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    /*View Submenu*/
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *view_menu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*view_menu);

    /*Create Submenu*/
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *create_menu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*create_menu);

    /*Order menu*/
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menubar->append(*menuitem_order);
    Gtk::Menu *order_menu = Gtk::manage(new Gtk::Menu());
    menuitem_order->set_submenu(*order_menu);

    /*Etc Menu*/
    Gtk::MenuItem *menuitem_etc = Gtk::manage(new Gtk::MenuItem("_ETC", true));
    menubar->append(*menuitem_etc);
    Gtk::Menu *etc_menu = Gtk::manage(new Gtk::Menu());
    menuitem_etc->set_submenu(*etc_menu);


    /*------Adding things to file menu*/
    Gtk::MenuItem *menuitem_table1 = Gtk::manage(new Gtk::MenuItem("_Quit",true));
    menuitem_table1->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_quit_click));
    filemenu->append(*menuitem_table1);
    /*******View menu********/
    Gtk::MenuItem *menuitem_table7 = Gtk::manage(new Gtk::MenuItem("_View Products",true));
    menuitem_table7->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_list_products_click));
    view_menu->append(*menuitem_table7);

    Gtk::MenuItem *menuitem_table6 = Gtk::manage(new Gtk::MenuItem("_View Customers",true));
    menuitem_table6->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_list_customers_click));
    view_menu->append(*menuitem_table6);

    Gtk::MenuItem *menuitem_table2 = Gtk::manage(new Gtk::MenuItem("_View All",true));
    menuitem_table2->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_view_all_click));
    view_menu->append(*menuitem_table2);

    Gtk::MenuItem *menuitem_table12 = Gtk::manage(new Gtk::MenuItem("_View Order",true));
    menuitem_table12->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_view_orders_click));
    view_menu->append(*menuitem_table12);
    /********CREATE MENU******/
    Gtk::MenuItem *menuitem_table3 = Gtk::manage(new Gtk::MenuItem("_Coffee",true));
    menuitem_table3->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_create_coffee_click));
    create_menu->append(*menuitem_table3);

    Gtk::MenuItem *menuitem_table4 = Gtk::manage(new Gtk::MenuItem("_Donut",true));
    menuitem_table4->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_create_donut_click));
    create_menu->append(*menuitem_table4);

    Gtk::MenuItem *menuitem_table5 = Gtk::manage(new Gtk::MenuItem("_Customer",true));
    menuitem_table5->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_new_customer_click));
    create_menu->append(*menuitem_table5);

    Gtk::MenuItem *menuitem_table11 = Gtk::manage(new Gtk::MenuItem("_Create Order",true));
    menuitem_table11->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_create_order_click));
    create_menu->append(*menuitem_table11);
    /* Order menu*/
    Gtk::MenuItem *menuitem_table40 = Gtk::manage(new Gtk::MenuItem("_Fill Order",true));
    menuitem_table40->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_fill_clicked));
    order_menu->append(*menuitem_table40);

    Gtk::MenuItem *menuitem_table41 = Gtk::manage(new Gtk::MenuItem("_Pay Order",true));
    menuitem_table41->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_pay_clicked));
    order_menu->append(*menuitem_table41);

    Gtk::MenuItem *menuitem_table42 = Gtk::manage(new Gtk::MenuItem("_Discard Order",true));
    menuitem_table42->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_discard_clicked));
    order_menu->append(*menuitem_table42);

    /*------ETC*/
    Gtk::MenuItem *menuitem_table8 = Gtk::manage(new Gtk::MenuItem("_Easter Egg",true));
    menuitem_table8->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_easter_click));
    etc_menu->append(*menuitem_table8);

    Gtk::MenuItem *menuitem_table9 = Gtk::manage(new Gtk::MenuItem("_About",true));
    menuitem_table9->signal_activate().connect(sigc::mem_fun(*this,&Mainwin::on_about_click));
    etc_menu->append(*menuitem_table9);

    /* Tool Bar*/
    /*Create ----------*/
    Gtk::Label *Create = Gtk::manage(new Gtk::Label("Create"));
    create->add(*Create);
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    create->add(*toolbar);
    /*View------*/
    Gtk::Label *View = Gtk::manage(new Gtk::Label("View"));
    view->add(*View);
    Gtk::Toolbar *toolbar2 = Gtk::manage(new Gtk::Toolbar);
    view->add(*toolbar2);
    /*Order*/
    Gtk::Label *Order = Gtk::manage(new Gtk::Label("Order"));
    order->pack_start(*Order);
    Gtk::Toolbar *toolbar4 = Gtk::manage(new Gtk::Toolbar);
    order->add(*toolbar4);
    /*Etc-------*/
    Gtk::Label *Etc = Gtk::manage(new Gtk::Label("ETC"));
    etc->pack_start(*Etc);
    Gtk::Toolbar *toolbar3 = Gtk::manage(new Gtk::Toolbar);
    etc->add(*toolbar3);

    /*------------Buttons */
    /*Create ------*/
    Gtk::Image *button11_on_image = Gtk::manage(new Gtk::Image{"create_java.png"});
    Gtk::ToolButton *button11 = Gtk::manage(new Gtk::ToolButton(*button11_on_image));
    button11->set_tooltip_markup("Create Java");
    button11->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
    toolbar->append(*button11);

    Gtk::Image *button12_on_image = Gtk::manage(new Gtk::Image{"create_donut.png"});
    Gtk::ToolButton *button12 = Gtk::manage(new Gtk::ToolButton(*button12_on_image));
    button12->set_tooltip_markup("Create Donut");
    button12->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
    toolbar->append(*button12);

    Gtk::Image *button10_on_image = Gtk::manage(new Gtk::Image{"add.png"});
    Gtk::ToolButton *button10 = Gtk::manage(new Gtk::ToolButton(*button10_on_image));
    button10->set_tooltip_markup("Create Customer");
    button10->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_new_customer_click));
    toolbar->append(*button10);

    Gtk::Image *button13_on_image = Gtk::manage(new Gtk::Image{"create_order.png"});
    Gtk::ToolButton *button13 = Gtk::manage(new Gtk::ToolButton(*button13_on_image));
    button13->set_tooltip_markup("Create Order");
    button13->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    toolbar->append(*button13);

    /*View -------*/
    Gtk::Image *button21_on_image = Gtk::manage(new Gtk::Image{"view_products.png"});
    Gtk::ToolButton *button21 = Gtk::manage(new Gtk::ToolButton(*button21_on_image));
    button21->set_tooltip_markup("View Products");
    button21->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_products_click));
    toolbar2->append(*button21);

    Gtk::Image *button22_on_image = Gtk::manage(new Gtk::Image{"list_of_person.png"});
    Gtk::ToolButton *button22 = Gtk::manage(new Gtk::ToolButton(*button22_on_image));
    button22->set_tooltip_markup("View Customers");
    button22->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers_click));
    toolbar2->append(*button22);

    Gtk::Image *button23_on_image = Gtk::manage(new Gtk::Image{"list.png"});
    Gtk::ToolButton *button23 = Gtk::manage(new Gtk::ToolButton(*button23_on_image));
    button23->set_tooltip_markup("View All");
    button23->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
    toolbar2->append(*button23);

    Gtk::Image *button24_on_image = Gtk::manage(new Gtk::Image{"view_order.png"});
    Gtk::ToolButton *button24 = Gtk::manage(new Gtk::ToolButton(*button24_on_image));
    button24->set_tooltip_markup("View Order");
    button24->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_view_orders_click));
    toolbar2->append(*button24);
    /*order************/
    Gtk::Image *button40_on_image = Gtk::manage(new Gtk::Image{"fill.png"});
    Gtk::ToolButton *button40 = Gtk::manage(new Gtk::ToolButton(*button40_on_image));
    button40->set_tooltip_markup("Fill Order");
    button40->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_fill_clicked));
    toolbar4->append(*button40);

    Gtk::Image *button41_on_image = Gtk::manage(new Gtk::Image{"pay.png"});
    Gtk::ToolButton *button41 = Gtk::manage(new Gtk::ToolButton(*button41_on_image));
    button41->set_tooltip_markup("Pay Order");
    button41->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_pay_clicked));
    toolbar4->append(*button41);

    Gtk::Image *button42_on_image = Gtk::manage(new Gtk::Image{"discard.png"});
    Gtk::ToolButton *button42 = Gtk::manage(new Gtk::ToolButton(*button42_on_image));
    button42->set_tooltip_markup("Discard Order");
    button42->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_discard_clicked));
    toolbar4->append(*button42);

    /******ETC----*/
    Gtk::Image *button30_on_image = Gtk::manage(new Gtk::Image{"egg.png"});
    Gtk::ToolButton *button30 = Gtk::manage(new Gtk::ToolButton(*button30_on_image));
    button30->set_tooltip_markup("Easter Egg");
    button30->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_easter_click));
    toolbar3->append(*button30);

    Gtk::Image *button31_on_image = Gtk::manage(new Gtk::Image{"que.png"});
    Gtk::ToolButton *button31 = Gtk::manage(new Gtk::ToolButton(*button31_on_image));
    button31->set_tooltip_markup("About");
    button31->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    toolbar3->append(*button31);

    Gtk::ToolButton *button32 = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    button32->set_tooltip_markup("Exit");
    button32->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    toolbar3->append(*button32);




    vbox->show_all();
}

Mainwin::~Mainwin()
{
    //dtor
}




/*========================FUNCTIONS START HERE=================================*/
void Mainwin::on_view_orders_click(){
  std::string temp= "";
  int i;
  int check;
  std::string temp1;
  int check1;
  std::stringstream so;
  do{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Select Customer");
    Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
    dialog->get_vbox()->pack_start(*box1);
    Gtk::HBox *box2 = Gtk::manage(new Gtk::HBox());
    dialog->get_vbox()->pack_start(*box2);
    Gtk::Label *label1 = Gtk::manage(new Gtk::Label(temp));
    box1->pack_start(*label1);
    Gtk::ComboBoxText *entry1 = Gtk::manage(new Gtk::ComboBoxText{});
    box2->pack_start(*entry1);
    for(i = 0; i < _store.number_of_orders();i++){
      entry1->append(std::to_string(i));
    }
    entry1->set_active(0);
    dialog->add_button("Close", 0);
    dialog->add_button("Show", 1);
    dialog->show_all();
    check = dialog->run();
    dialog->close();
      while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if(check == 1 && _store.number_of_orders() >= 1){
      check1 = entry1->get_active_row_number();
      temp+= _store.order_to_string(check1);
      temp+= "\n\n";
      delete dialog;
    }else{
      delete dialog;
      return;
    }
  }while(true);
}
/*Updates the cash label*/
void Mainwin::update_cash(double money){
  sum+= money;
  std::string word_cash = "$";
  std::string temp;
  std::stringstream ss;
  ss.precision(2);
  ss<<std::fixed<<_store.cash() + sum;
  ss>>temp;
  word_cash+=temp;
  cash->set_text(word_cash);
}
void Mainwin::on_pay_clicked(){
  std::string temp= "";
  int i;
  int check;
  std::string temp1;
  int check1;
  std::stringstream so;
  do{
    int counter = 0;
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Select an Order to Pay");
    Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
    dialog->get_vbox()->pack_start(*box1);
    Gtk::HBox *box2 = Gtk::manage(new Gtk::HBox());
    dialog->get_vbox()->pack_start(*box2);
    Gtk::Label *label1 = Gtk::manage(new Gtk::Label(temp));
    box1->pack_start(*label1);
    Gtk::ComboBoxText *entry1 = Gtk::manage(new Gtk::ComboBoxText{});
    box2->pack_start(*entry1);
    for(i = 0; i < _store.number_of_orders();i++){
        entry1->append(std::to_string(i));
    }
    entry1->set_active(0);
    dialog->add_button("Close", 0);
    dialog->add_button("Show", 1);
    dialog->add_button("Pay",2);
    dialog->show_all();
    check = dialog->run();
      while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if(check == 1 && _store.number_of_orders() >= 1 ){
      check1 = std::stoi(entry1->get_active_text());
      temp+= _store.order_to_string(check1);
      temp+= "\n\n";
      delete dialog;
    }else if(check == 2 &&_store.number_of_orders() >= 1){
      check1 = entry1->get_active_row_number();
      if(_store.order_is_paid(check1) == false){
      _store.pay_order(check1);
      if(_store.order_is_completed(check1) == true){
        Order r = _store.find_order_pair(check1);
        Mainwin::update_cash(r.profit());
      }
      delete dialog;
    }else{
      Gtk::MessageDialog *message = new Gtk::MessageDialog("Error in Filling out order");
    message->set_secondary_text("Order is already filled out!", true);
    message->run();
    delete message;
    delete dialog;
    }
    }else{
      delete dialog;
      return;
    }
  }while(true);
}
void Mainwin::on_fill_clicked(){
  std::string temp= "";
  int i;
  int check;
  std::string temp1;
  int check1;
  std::stringstream so;
  do{
    int counter = 0;
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Select an Order to Fill");
    Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
    dialog->get_vbox()->pack_start(*box1);
    Gtk::HBox *box2 = Gtk::manage(new Gtk::HBox());
    dialog->get_vbox()->pack_start(*box2);
    Gtk::Label *label1 = Gtk::manage(new Gtk::Label(temp));
    box1->pack_start(*label1);
    Gtk::ComboBoxText *entry1 = Gtk::manage(new Gtk::ComboBoxText{});
    box2->pack_start(*entry1);
    for(i = 0; i < _store.number_of_orders();i++){
        entry1->append(std::to_string(i));
        counter++;
    }
    entry1->set_active(0);
    dialog->add_button("Close", 0);
    dialog->add_button("Show", 1);
    dialog->add_button("Fill",2);
    dialog->show_all();
    check = dialog->run();
      while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if(check == 1 && _store.number_of_orders() >= 1){
      check1 = entry1->get_active_row_number();
      temp+= _store.order_to_string(check1);
      temp+= "\n\n";
      delete dialog;
    }else if(check == 2 &&_store.number_of_orders() >= 1){
      check1 = entry1->get_active_row_number();
      if(_store.order_is_filled(check1) == false){
      _store.fill_order(check1);
      if(_store.order_is_completed(check1) == true){
        Order r = _store.find_order_pair(check1);
        Mainwin::update_cash(r.profit());
      }
      delete dialog;
    }else{
      Gtk::MessageDialog *message = new Gtk::MessageDialog("Error in Filling out order");
    message->set_secondary_text("Order is already filled out!", true);
    message->run();
    delete message;
    delete dialog;
    }
    }else{
      delete dialog;
      return;
    }
  }while(true);

}
 void Mainwin:: on_create_order_click(){
int i;
int number;
std::string b;
Order z;
std::string a = "Order Number: ";
std::stringstream ss;
ss<<_store.number_of_orders();
ss>>b;
a+=b;
a+="\n";
ss.clear();
do{
Gtk::Dialog *dialog = new Gtk::Dialog();
dialog->set_title("Create An Order");
Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
dialog->get_vbox()->pack_start(*box1);
Gtk::HBox *box2 = Gtk::manage(new Gtk::HBox());
dialog->get_vbox()->pack_start(*box2);
Gtk::Label *label1 = Gtk::manage(new Gtk::Label(a));
box1->pack_start(*label1);
Gtk::Label *label2 = Gtk::manage(new Gtk::Label("Product"));
box2->pack_start(*label2);
Gtk::ComboBoxText *entry1 = Gtk::manage(new Gtk::ComboBoxText{});
box2->pack_start(*entry1);
for(i = 0; i < _store.number_of_products();i++){
  entry1->append(_store.product_to_string(i));
}
entry1->set_active(0);
dialog->add_button("Cancel", 0);
dialog->add_button("Add", 1);
dialog->add_button("Next", 2);
dialog->show_all();
int result = dialog->run();
dialog->close();
while (Gtk::Main::events_pending())  Gtk::Main::iteration();
if(result == 0){
  delete dialog;
  return;
}
if(result == 1){
  a+="\n";
  number = entry1->get_active_row_number();
  a+= _store.product_to_string(number);
  z.add_product(_store.get_product(number));
  a+="\n";
  delete dialog;

}
else{
  delete dialog;
  break;
}
}while(true);
Gtk::Dialog *dialog = new Gtk::Dialog();
dialog->set_title("Select Customer");
Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
dialog->get_vbox()->pack_start(*box1);
Gtk::ComboBoxText *entry1 = Gtk::manage(new Gtk::ComboBoxText{});
box1->pack_start(*entry1);
for(i = 0; i < _store.number_of_customers();i++){
  entry1->append(_store.customer_to_string(i));
}
entry1->set_active(0);
dialog->add_button("Cancel", 0);
a = "Place Order # ";
a+=b;
dialog->add_button(a, 1);
dialog->show_all();
int number1;
int result2 = dialog->run();
number1 = entry1->get_active_row_number();
if(result2 == 0){
  delete dialog;
}else{

  _store.place_order(z,number1);
  std::string stat = "Number of Products: ";
  stat+= std::to_string(_store.number_of_products());
  stat+=" ";
  stat += "Number of Customers: ";
  stat+= std::to_string(_store.number_of_customers());
  stat+=" ";
  stat += "Number of Orders: ";
  stat+= std::to_string(_store.number_of_orders());
  stat+=" ";
  status->set_text(stat);
  delete dialog;
}
}

void Mainwin::on_quit_click() {
    hide();
}
void Mainwin::on_about_click(){
  std::string about = R"(Follow the instructions in the GUI......
  it's self explanatory)";
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("About");
  dialog->set_secondary_text(about, true);
  dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  delete dialog;
}
void Mainwin::on_new_customer_click(){
Gtk::Dialog *dialog = new Gtk::Dialog();
dialog->set_title("Adding Customer");
Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
Gtk::HBox *box2 = Gtk::manage(new Gtk::HBox());
dialog->get_vbox()->pack_start(*box1);
dialog->get_vbox()->pack_start(*box2);
Gtk::Label *label1 = Gtk::manage(new Gtk::Label("Name:"));
Gtk::Label *label2 = Gtk::manage(new Gtk::Label("Phone Number:"));
box1->pack_start(*label1,Gtk::PACK_EXPAND_WIDGET,10);
box2->pack_start(*label2,Gtk::PACK_EXPAND_WIDGET,10);
Gtk::Entry *entry1 = Gtk::manage(new Gtk::Entry{});
Gtk::Entry *entry2 = Gtk::manage(new Gtk::Entry{});
box1->pack_start(*entry1);
box2->pack_start(*entry2);
entry1->set_text("Enter the Name");
entry1->set_max_length(50);
entry2->set_text("Enter the Phone Number");
entry2->set_max_length(50);
dialog->add_button("Cancel", 0);
dialog->add_button("OK", 1);
std::regex integer{"(\\d{3,3}-)?\\d{3,3}-\\d{4,4}"};
std::regex integer1{"[(]\\d{3,3}[)]?\\d{3,3}-\\d{4,4}"};
std::regex input{"Enter the Name"};
std::string name1;
std::string name2;
int result;
dialog->show_all();
bool phone_number = true;
while (Gtk::Main::events_pending())  Gtk::Main::iteration();
do{
  entry1->set_text("Enter the Name");
  result = dialog->run();
  if(result == 0)
    break;
  if(result == 1){
  name1 = entry1->get_text();
  name2 = entry2->get_text();
  if (!std::regex_match(name2, integer) && !std::regex_match(name2,integer1)){
          entry2->set_text("Enter 972-579-0145");
        }
  else if(std::regex_match(name1,input)){
          entry1->set_text("Enter an actual name:");
        }
  else{
          phone_number = false;
      }
 }
}while(phone_number);
delete entry1;
delete entry2;
delete label1;
delete label2;
delete box1;
delete box2;
delete dialog;
if (result == 1){
    _store.add_customer(new Customer{name1,name2});
    std::string stat = "Number of Products: ";
    stat+= std::to_string(_store.number_of_products());
    stat+=" ";
    stat += "Number of Customers: ";
    stat+= std::to_string(_store.number_of_customers());
    stat+=" ";
    stat += "Number of Orders: ";
    stat+= std::to_string(_store.number_of_orders());
    stat+=" ";
    status->set_text(stat);
}
}
void Mainwin::on_discard_clicked(){
  std::string temp= "";
  int i;
  int check;
  std::string temp1;
  int check1;
  std::stringstream so;
  do{
    int counter = 0;
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Select an Order to Discard");
    Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
    dialog->get_vbox()->pack_start(*box1);
    Gtk::HBox *box2 = Gtk::manage(new Gtk::HBox());
    dialog->get_vbox()->pack_start(*box2);
    Gtk::Label *label1 = Gtk::manage(new Gtk::Label(temp));
    box1->pack_start(*label1);
    Gtk::ComboBoxText *entry1 = Gtk::manage(new Gtk::ComboBoxText{});
    box2->pack_start(*entry1);
    for(i = 0; i < _store.number_of_orders();i++){
        entry1->append(std::to_string(i));
        counter++;
    }
    entry1->set_active(0);
    dialog->add_button("Close", 0);
    dialog->add_button("Show", 1);
    dialog->add_button("Discard",2);
    dialog->show_all();
    check = dialog->run();
      while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if(check == 1 && _store.number_of_orders() >= 1){
      check1 = entry1->get_active_row_number();
      temp+= _store.order_to_string(check1);
      temp+= "\n\n";
      delete dialog;
    }else if(check == 2 &&_store.number_of_orders() >= 1){
      check1 = entry1->get_active_row_number();
      if(_store.order_is_discarded(check1) == true){
      _store.fill_order(check1);
      delete dialog;
    }else{
      Gtk::MessageDialog *message = new Gtk::MessageDialog("Error");
    message->set_secondary_text("Order is already discarded", true);
    message->run();
    delete message;
    delete dialog;
    }
    }else{
      delete dialog;
      return;
    }
  }while(true);

}
void Mainwin::on_easter_click(){
  _store.add_product(new Donut{"Mochiato",9.00,7.00,(Frosting)1,true,(Filling)2});
  _store.add_product(new Donut{"Pig",10.00,7.99,(Frosting)0,true,(Filling)1});
  _store.add_product(new Donut{"Yellow",7.00,5.36,(Frosting)0,true,(Filling)0});
  Java *r = new Java{"ICE",2.95,2.00,(Darkness)0};
  r->add_shot((Shot)2);
  _store.add_product(r);
  Java *a = new Java{"HOT ICE",9.95,8.00,(Darkness)2};
  a->add_shot((Shot)0);
  a->add_shot((Shot)3);
  _store.add_product(a);
  _store.add_customer(new Customer{"Kevin Lopez", "469-955-5945"});
  _store.add_customer(new Customer{"Steve Bill", "972-572-0151"});
  std::string stat = "Number of Products: ";
  stat+= std::to_string(_store.number_of_products());
  stat+=" ";
  stat += "Number of Customers: ";
  stat+= std::to_string(_store.number_of_customers());
  stat+=" ";
  stat += "Number of Orders: ";
  stat+= std::to_string(_store.number_of_orders());
  stat+=" ";
  status->set_text(stat);
}

void Mainwin::on_list_customers_click(){
  int i;
  std::string word = "Customers:\n***********************************************\n";
  if(_store.number_of_customers() == 0){
    word = "No Customers!!!\n";
  }
  for(i = 0; i < _store.number_of_customers();i++){
    word+= _store.customer_to_string(i);
    word+="\n----------------------------------------------\n";
  }
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("View Customers");
  dialog->set_secondary_text(word, true);
  dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  delete dialog;
}

void Mainwin::on_list_products_click(){
  int i;
  std::string word = "Products:\n***********************************************\n";
  if(_store.number_of_products() == 0){
    word = "Products!!!\n";
  }
  for(i = 0; i < _store.number_of_products();i++){
    word+= _store.product_to_string(i);
    word+="\n----------------------------------------------\n";
  }
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("View Products");
  dialog->set_secondary_text(word, true);
  dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  delete dialog;
}



void Mainwin::on_view_all_click(){
  int i;
  std::string word = "Products:\n***********************************************\n";
  std::string word1 = "Customers:\n***********************************************\n";
  for(i = 0; i < _store.number_of_products();i++){
    word+= _store.product_to_string(i);
    word+="\n----------------------------------------------\n";
  }
  if(_store.number_of_products() == 0){
    word = "No Products!!!\n";
  }
  if(_store.number_of_customers() == 0){
    word1 = "No Customers!!!\n";
  }
  for(i = 0; i < _store.number_of_customers();i++){
    word1+= _store.customer_to_string(i);
    word1+="\n----------------------------------------------\n";
  }
  word+=word1;
  Gtk::MessageDialog *dialog = new Gtk::MessageDialog("View All");
  dialog->set_secondary_text(word, true);
  dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  delete dialog;
}

void Mainwin::on_create_coffee_click(){
  Gtk::Dialog *dialog = new Gtk::Dialog();
  dialog->set_title("Creating Coffee");
  Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
  Gtk::HBox *box2 = Gtk::manage(new Gtk::HBox());
  Gtk::HBox *box3 = Gtk::manage(new Gtk::HBox());
  Gtk::HBox *box4 = Gtk::manage(new Gtk::HBox());
  dialog->get_vbox()->pack_start(*box1);
  dialog->get_vbox()->pack_start(*box2);
  dialog->get_vbox()->pack_start(*box3);
  dialog->get_vbox()->pack_start(*box4);
  Gtk::Label *label1 = Gtk::manage(new Gtk::Label("Name"));
  Gtk::Label *label2 = Gtk::manage(new Gtk::Label("Price"));
  Gtk::Label *label3 = Gtk::manage(new Gtk::Label("Cost"));
  Gtk::Label *label4 = Gtk::manage(new Gtk::Label("Darkness"));
  box1->pack_start(*label1,Gtk::PACK_EXPAND_WIDGET,10);
  box2->pack_start(*label2,Gtk::PACK_EXPAND_WIDGET,10);
  box3->pack_start(*label3,Gtk::PACK_EXPAND_WIDGET,10);
  box4->pack_start(*label4,Gtk::PACK_EXPAND_WIDGET,10);
  Gtk::Entry *entry1 = Gtk::manage(new Gtk::Entry{});
  Gtk::Entry *entry2 = Gtk::manage(new Gtk::Entry{});
  Gtk::Entry *entry3 = Gtk::manage(new Gtk::Entry{});
  Gtk::ComboBoxText *entry4 = Gtk::manage(new Gtk::ComboBoxText{});
  entry4->append("Blonde");
  entry4->append("Light");
  entry4->append("Medium");
  entry4->append("Dark");
  entry4->append("Extra Dark");
  entry4->set_active(0);
  box1->pack_start(*entry1);
  box2->pack_start(*entry2);
  box3->pack_start(*entry3);
  box4->pack_start(*entry4);
  entry1->set_text("Enter the Name");
  entry1->set_max_length(50);
  entry2->set_text("Enter the Price");
  entry2->set_max_length(50);
  entry3->set_text("Enter the Cost");
  entry3->set_max_length(50);
  dialog->add_button("Cancel", 0);
  dialog->add_button("Next", 1);
  dialog->set_default_response(1);
  dialog->show_all();
  int result = dialog->run();
  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  std::string name1 = entry1->get_text();
  std::string name2 = entry2->get_text();
  std::string name3 = entry3->get_text();
  int ok = entry4->get_active_row_number();
  std::stringstream ss;
  std::stringstream si;
  double price;
  double cost;
  bool flag;
  ss<<name2;
  ss>>price;
  si<<name3;
  si>>cost;
  delete entry1;
  delete entry2;
  delete entry3;
  delete entry4;
  delete label1;
  delete label2;
  delete label3;
  delete label4;
  delete box1;
  delete box2;
  delete box3;
  delete box4;
  delete dialog;
  bool s = true;
  if (result == 1){
      Java *r = new Java{name1,price,cost,(Darkness)ok};
      do{
      Gtk::Dialog *dialog = new Gtk::Dialog();
      dialog->set_title("Adding Shots");
      Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
      dialog->get_vbox()->pack_start(*box1);
      Gtk::ComboBoxText *entry4 = Gtk::manage(new Gtk::ComboBoxText{});
      box1->pack_start(*entry4);
      entry4->append("None");
      entry4->append("Chocolate");
      entry4->append("Vanilla");
      entry4->append("Peppermint");
      entry4->append("Hazelnut");
      entry4->set_active(0);
      Gtk::Label *label1 = Gtk::manage(new Gtk::Label(r->to_string()));
      dialog->get_vbox()->pack_start(*label1);
      dialog->add_button("Cancel", 0);
      dialog->add_button("Create", 1);
      dialog->add_button("Next", 2);
      dialog->show_all();
      int duh = dialog->run();
      dialog->close();
      while (Gtk::Main::events_pending())  Gtk::Main::iteration();
      int ans = entry4->get_active_row_number();
      if(duh == 1){
        r->add_shot((Shot)ans);
        delete label1;
        delete entry4;
        delete box1;
        delete dialog;
        break;
      }else if(duh == 2){
        r->add_shot((Shot)ans);
        delete label1;
        delete entry4;
        delete box1;
        delete dialog;
      }else{
        delete label1;
        delete entry4;
        delete box1;
        delete dialog;
        break;
      }
    }while(s);
    _store.add_product(r);
    std::string stat = "Number of Products: ";
    stat+= std::to_string(_store.number_of_products());
    stat+=" ";
    stat += "Number of Customers: ";
    stat+= std::to_string(_store.number_of_customers());
    stat+=" ";
    stat += "Number of Orders: ";
    stat+= std::to_string(_store.number_of_orders());
    stat+=" ";
    status->set_text(stat);
    }
}
void Mainwin::on_create_donut_click(){
  Gtk::Dialog *dialog = new Gtk::Dialog();
  dialog->set_title("Creating Donut");
  Gtk::HBox *box1 = Gtk::manage(new Gtk::HBox());
  Gtk::HBox *box2 = Gtk::manage(new Gtk::HBox());
  Gtk::HBox *box3 = Gtk::manage(new Gtk::HBox());
  Gtk::HBox *box4 = Gtk::manage(new Gtk::HBox());
  Gtk::HBox *box5 = Gtk::manage(new Gtk::HBox());
  dialog->get_vbox()->pack_start(*box1);
  dialog->get_vbox()->pack_start(*box2);
  dialog->get_vbox()->pack_start(*box3);
  dialog->get_vbox()->pack_start(*box4);
  dialog->get_vbox()->pack_start(*box5);
  Gtk::Label *label1 = Gtk::manage(new Gtk::Label("Name"));
  Gtk::Label *label2 = Gtk::manage(new Gtk::Label("Price"));
  Gtk::Label *label3 = Gtk::manage(new Gtk::Label("Cost"));
  Gtk::Label *label4 = Gtk::manage(new Gtk::Label("Frosting"));
  Gtk::Label *label5 = Gtk::manage(new Gtk::Label("Filling"));
  box1->pack_start(*label1,Gtk::PACK_EXPAND_WIDGET,10);
  box2->pack_start(*label2,Gtk::PACK_EXPAND_WIDGET,10);
  box3->pack_start(*label3,Gtk::PACK_EXPAND_WIDGET,10);
  box4->pack_start(*label4,Gtk::PACK_EXPAND_WIDGET,10);
  box5->pack_start(*label5,Gtk::PACK_EXPAND_WIDGET,10);
  Gtk::Entry *entry1 = Gtk::manage(new Gtk::Entry{});
  Gtk::Entry *entry2 = Gtk::manage(new Gtk::Entry{});
  Gtk::Entry *entry3 = Gtk::manage(new Gtk::Entry{});
  Gtk::ComboBoxText *entry4 = Gtk::manage(new Gtk::ComboBoxText{});
  Gtk::ComboBoxText *entry5 = Gtk::manage(new Gtk::ComboBoxText{});
  entry4->append("Unfrosted");
  entry4->append("Chocolate_top");
  entry4->append("Vanilla_top");
  entry4->append("Pink_top");

  entry5->append("Unfilled");
  entry5->append("Creme");
  entry5->append("Bavarian");
  entry5->append("Strawberry");
  entry4->set_active(0);
  entry5->set_active(0);
  box1->pack_start(*entry1);
  box2->pack_start(*entry2);
  box3->pack_start(*entry3);
  box4->pack_start(*entry4);
  box5->pack_start(*entry5);
  bool flag12;
  Gtk::CheckButton *c = Gtk::manage(new Gtk::CheckButton("Add Sprinkles"));
  dialog->get_vbox()->pack_start(*c);
  entry1->set_text("Enter the Name");
  entry1->set_max_length(50);
  entry2->set_text("Enter the Price");
  entry2->set_max_length(50);
  entry3->set_text("Enter the Cost");
  entry3->set_max_length(50);
  dialog->add_button("Cancel", 0);
  dialog->add_button("OK", 1);
  dialog->set_default_response(1);
  dialog->show_all();
  int result = dialog->run();
  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  std::string name1 = entry1->get_text();
  std::string name2 = entry2->get_text();
  std::string name3 = entry3->get_text();
  int ok = entry4->get_active_row_number();
  int ko = entry5->get_active_row_number();
  if(c->get_active())
    flag12 = true;
  std::stringstream ss;
  std::stringstream si;
  double price;
  double cost;
  bool flag;
  ss<<name2;
  ss>>price;
  si<<name3;
  si>>cost;
  delete entry1;
  delete entry2;
  delete entry3;
  delete entry4;
  delete label1;
  delete label2;
  delete label3;
  delete label4;
  delete label5;
  delete box1;
  delete box2;
  delete box5;
  delete box3;
  delete box4;
  delete dialog;
  if (result == 1){
      _store.add_product(new Donut{name1,price,cost,(Frosting)ok,flag12,(Filling)ko});
      std::string stat = "Number of Products: ";
      stat+= std::to_string(_store.number_of_products());
      stat+=" ";
      stat += "Number of Customers: ";
      stat+= std::to_string(_store.number_of_customers());
      stat+=" ";
      stat += "Number of Orders: ";
      stat+= std::to_string(_store.number_of_orders());
      stat+=" ";
      status->set_text(stat);
    }
}
