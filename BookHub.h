#ifndef BOOKHUB_H
#define BOOKHUB_H

#include "Book.h"
#include "Novel.h"
#include "TextBook.h"
#include "SkillBook.h"
#include "MenuView.h"
#include "BookSearcher.h"
#include "Warehouse.h"
#include "Reporter.h"

class BookHub
{
public:
    BookHub();
    ~BookHub();
    void Menu();

private:
    MenuView *menu;
    std::vector<Book *> *books;
    int numOfBook;
    BookSearcher *searcher;
    Warehouse *warehouse;
    std::string logs;

    void waitUpdate();
    void loadBooks();
    void addBook(Book *book);
    void Menu1();
    void Menu1_1();
    void Menu1_2();
    void Menu1_3();
    void Menu2();
    void Menu3();
    void Menu4();
    void Menu5();
};

BookHub::BookHub() : menu(new MenuView()), books(new std::vector<Book *>()), numOfBook(0), searcher(new BookSearcher()), warehouse(new Warehouse())
{
}

BookHub::~BookHub()
{
    delete menu;
    delete searcher;
    delete warehouse;
    for (Book *book : *books)
    {
        delete book;
    }
    delete books;
}

void BookHub::waitUpdate()
{
    MenuView::clearScreen();
    std::cout << "This feature will be updated later!" << std::endl;
    MenuView::pauseScreen();
}

void BookHub::loadBooks()
{
    delete books;
    books = warehouse->readBooksFromTxt();
}

void BookHub::addBook(Book *book)
{
    if (book != nullptr)
    {
        books->push_back(book);
        numOfBook++;
    }
    warehouse->saveBooksToTxt(books);
}

void BookHub::Menu()
{
    loadBooks();
    while (true)
    {
        int selection = menu->menu0View();
        switch (selection)
        {
        case 1:
            Menu1();
            break;
        case 2:
            Menu2();
            break;
        case 3:
            Menu3();
            break;
        case 4:
            Menu4();
            break;
        case 5:
            Menu5();
            break;
        case 6:
            std::cout << "BookHub has ended!" << std::endl;
            return;
        }
    }
}

void BookHub::Menu1()
{
    while (true)
    {
        int selection = menu->menu1View();
        switch (selection)
        {
        case 1:
            Menu1_1();
            break;
        case 2:
            Menu1_2();
            loadBooks();
            break;
        case 3:
            Menu1_3();
            break;
        case 4:
            return;
        }
    }
}

void BookHub::Menu1_1()
{
    MenuView::clearScreen();
    std::cout << "~~~View Book List~~~" << std::endl;
    menu->menu1_1View(books);
}

void BookHub::Menu1_2()
{
    while (true)
    {
        Book *book = menu->menu1_2View(books);
        addBook(book);
        std::string y_nRegex = "^[yn]$";
        std::cout << "Do you want to add more books? (y/n): ";
        char y_n = Book::validateInput(y_nRegex)[0];
        if (y_n == 'n')
            return;
    }
}

void BookHub::Menu1_3()
{
    menu->menu1_3View(books);
    warehouse->saveBooksToTxt(books);
}

void BookHub::Menu2()
{
    while (true)
    {
        int selection = menu->menu2View();
        switch (selection)
        {
        case 1:
            menu->menu2_1View(books);
            break;
        case 2:
            return;
        }
    }
}

void BookHub::Menu3()
{
    menu->menu3View(books);
    warehouse->saveBooksToTxt(books);
}

void BookHub::Menu4()
{
    while (true)
    {
        std::vector<Book *> *searchResult = menu->menu4View(books);
        if (!searchResult)
        {
            return;
        }
        MenuView::clearScreen();
        std::cout << "~~~ Search Books~~~" << std::endl;
        menu->menu1_1View(searchResult);
    }
}

void BookHub::Menu5()
{
    while (true)
    {
        int selection = menu->menu5View();

        switch (selection)
        {
        case 1:
            MenuView::clearScreen();
            std::cout << "~~~ Generate Reports~~~" << std::endl;
            logs = Reporter::readLogFromTxt();
            std::cout << logs << std::endl;
            MenuView::pauseScreen();
            break;
        case 2:
            logs = "";
            Reporter::resetLog();
            MenuView::clearScreen();
            std::cout << "~~~ Generate Reports~~~" << std::endl;
            std::cout << "Logs have been reset" << std::endl;
            MenuView::pauseScreen();
            break;
        case 3:
            return;
        }
    }
}

#endif // BOOKHUB_H