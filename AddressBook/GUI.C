#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Return_Button.H>
#include <cstdlib>
#include "AddressBook.h"
#include "Book.h"
#include "Contact.h"

using namespace std;

static void new_cb(Fl_Widget* , void* );
void open_cb(Fl_Widget* , void* );
void close_cb(Fl_Widget* , void* );
void save_cb(Fl_Widget* , void* );
void save2_cb(Fl_Widget* , void* );
void add_cb(Fl_Widget* , void* );
void add2_cb(Fl_Widget*, void* );
void del_cb(Fl_Widget* , void* );
void edit_cb(Fl_Widget* , void* );
void sort1_cb(Fl_Widget* , void* );
void sort2_cb(Fl_Widget* , void* );
void search_cb(Fl_Widget* , void* );
void quit_cb(Fl_Widget* , void* );
void quit2_cb(Fl_Widget* , void* );
Fl_Window* initializeGUI();


class BookWindow : public Fl_Window {
    public:
        BookWindow(int w, int h, const char* title);
        ~BookWindow();

        Fl_Window *insertWindow;
        Fl_Input *FirstName;
        Fl_Input *LastName;
        Fl_Input *Phone;
        Fl_Input *Address1;
        Fl_Input *Address2;
        Fl_Input *City;
        Fl_Input *State;
        Fl_Input *ZIP;
        Fl_Return_Button *AcceptInsert;
        Fl_Button *QuitInsert;

        Fl_Text_Display *AddressBookDisplay;
        Fl_Text_Buffer *BookDisplay;

        int changed;
        char filename[256];

        AddressBook *thisAddBook;
};

BookWindow::BookWindow(int w, int h, const char* title=0):Fl_Window(w, h, title)
{
    insertWindow = new Fl_Window(250, 350, "Add an Entry");
    insertWindow->begin();
        FirstName = new Fl_Input(50, 15, 150, 25, "First Name:");
        LastName = new Fl_Input(50, 55, 150, 25, "Last Name:");
        Phone = new Fl_Input(50, 95, 150, 25, "Phone Number:");
        Address1 = new Fl_Input(50, 135, 150, 25, "Address:");
        Address2 = new Fl_Input(50, 175, 150, 25, "Address pt 2:");
        City = new Fl_Input(50, 215, 150, 25, "City:");
        State = new Fl_Input(50, 255, 150, 25, "State:");
        ZIP = new Fl_Input(50, 295, 150, 25, "ZIP Code:");
  AcceptInsert = new Fl_Return_Button(50, 335, 50, 25, "Insert Entry");
        AcceptInsert->callback((Fl_Callback *)add2_cb, this);
        QuitInsert = new Fl_Button(150, 335, 75, 25, "Cancel");
        QuitInsert->callback((Fl_Callback *)quit2_cb, this);
    insertWindow->end();
    changed = SAVED;
    AddressBookDisplay = 0;
    thisAddBook = new AddressBook();
    printf("did it boi\n");
    //thisAddBook->CreateBook();
    thisWindow->begin();
	  Fl_Menu_Item AddressBookMenu[] =
        {
            {"&File", 0, 0, 0, FL_SUBMENU},
                {"&New", FL_CTRL + 'n', (Fl_Callback *)new_cb,thisWindow->thisAddBook},
                {"&Open", FL_CTRL + 'o', (Fl_Callback *)open_cb},
                {"&Close", 0, (Fl_Callback *)close_cb},
                {"&Save", FL_CTRL + 's', (Fl_Callback *)save_cb},
                {"Save &As", FL_CTRL + 'a', (Fl_Callback *)save2_cb, 0, FL_MENU_DIVIDER},
                {"&Quit", FL_CTRL + 'q', (Fl_Callback *)quit_cb},
                {0},
            {"&Edit", 0, 0, 0, FL_SUBMENU},
                {"&Insert", FL_CTRL + 'i', (Fl_Callback *)add_cb},
                {"&Remove", FL_CTRL + 'r', (Fl_Callback *)del_cb},
                {"Edit &Entry", FL_CTRL +'e', (Fl_Callback *)edit_cb},
                {"&Find", FL_CTRL +'f', (Fl_Callback *)search_cb},
                {0},
            {"&Sort", 0, 0, 0, FL_SUBMENU},
                {"Sort by &ZipCode", FL_ALT + 'z', (Fl_Callback *)sort1_cb},
                {"Sort by &Last Name", FL_ALT + 'l', (Fl_Callback *)sort2_cb},
                {0},
            {0}
        };
        Fl_Menu_Bar *BookMenu = new Fl_Menu_Bar(0, 0, 800, 30);
        BookMenu->copy(AddressBookMenu);
        thisWindow->AddressBookDisplay = new Fl_Text_Display(10, 40, 780, 750);
        thisWindow->BookDisplay = new Fl_Text_Buffer();
        thisWindow->AddressBookDisplay->buffer(thisWindow->BookDisplay);
    thisWindow->end();
    //thisWindow->thisAddBook->CreateBook();
    return thisWindow;
    //thisWindow->callback((Fl_Callback *)quit_cb, thisWindow);
}

BookWindow::~BookWindow()
{
    //delete insertWindow;
    printf("undid it boi\n");
}

int main()
{
    Fl_Window *MainWindow = initializeGUI();
    MainWindow->show();
    return Fl::run();
}

Fl_Window* initializeGUI()
{
    BookWindow *thisWindow = new BookWindow(800, 800, "Address Book");

}

static void new_cb(Fl_Widget* o, void* v)
{
    BookWindow* w = (BookWindow*)o;
    w->thisAddBook->CreateBook();
    w->BookDisplay->text("made a new book!\n");
}

void open_cb(Fl_Widget* o, void* v)
{

}

void save_cb(Fl_Widget* o, void* v)
{

}
void close_cb(Fl_Widget* o, void* v)
{

}

void save2_cb(Fl_Widget* o, void* v)
{

}

void quit_cb(Fl_Widget* o, void* v)
{

}

void quit2_cb(Fl_Widget* o, void* v)
{
    Fl_Window* w = (Fl_Window*)o;
    w->hide();
}

void add_cb(Fl_Widget* o, void* v)
{
    BookWindow* w = (BookWindow*)o;
    w->insertWindow->show();
}

void add2_cb(Fl_Widget* o, void* v)
{
    BookWindow* w = (BookWindow*)o;
    Contact *contact = new Contact(w->FirstName->value(), w->LastName->value(), w->Phone->value(), w->Address1->value(), w->Address2->value(), w->City->value(), w->State->value(), w->ZIP->value());
    w->thisAddBook->AddContact(contact);
}

void del_cb(Fl_Widget* o, void* v)
{

}

void edit_cb(Fl_Widget* o, void* v)
{

}

void search_cb(Fl_Widget* o, void* v)
{

}

void sort1_cb(Fl_Widget* o, void* v)
{

}

void sort2_cb(Fl_Widget* o, void* v)
{

}
