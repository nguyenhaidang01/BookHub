#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <vector>
#include <string>
#include <limits>

#include "Novel.h"
#include "SkillBook.h"
#include "TextBook.h"
#include "BookSearcher.h"
#include "Reporter.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

class MenuView
{
public:
    MenuView();
    ~MenuView();

    static void pauseScreen();
    static void clearScreen();

    int menu0View();

    int menu1View();
    void menu1_1View(std::vector<Book *> *books);
    Book *menu1_2View(std::vector<Book *> *books);
    void menu1_3View(std::vector<Book *> *books);

    int menu2View();
    void menu2_1View(std::vector<Book *> *books);

    void menu3View(std::vector<Book *> *books);

    std::vector<Book *> *menu4View(std::vector<Book *> *books);

    int menu5View();

private:
    std::string regex1_2;
    std::string regex1_3;
    std::string regex1_4;
    std::string regex1_5;
    std::string regex1_6;
    std::string y_nRegex;
    std::string allCharNoSpecial;
    std::string alphabetsAndSpacesRegex;
    std::string equalOrGreater0Regex;
    std::string ratingRegex;
};

MenuView::MenuView()
{
    regex1_2 = "^[1-2]$";
    regex1_3 = "^[1-3]$";
    regex1_4 = "^[1-4]$";
    regex1_5 = "^[1-5]$";
    regex1_6 = "^[1-6]$";
    y_nRegex = "^[yn]$";
    allCharNoSpecial = "^[A-Za-z0-9\\s]+$";
    alphabetsAndSpacesRegex = "^[A-Za-z\\s]+$";
    equalOrGreater0Regex = "^(?:[1-9]\\d*|0)$";
    ratingRegex = "^(?:[0-4](?:\\.\\d)?|5(?:\\.0)?)$";
}

MenuView::~MenuView()
{
}

void MenuView::pauseScreen()
{
    std::cout << "Press Double Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void MenuView::clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

int MenuView::menu0View()
{
    while (true)
    {

        clearScreen();
        std::cout << "~~~ Menu ~~~" << std::endl;
        std::cout << "1. Manage Book Information" << std::endl;
        std::cout << "2. Manage Warehouse" << std::endl;
        std::cout << "3. Sell Books" << std::endl;
        std::cout << "4. Search Books" << std::endl;
        std::cout << "5. Generate Reports" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "-> Your selection: ";
        int selection = std::stoi(Book::validateInput(regex1_6));
        return selection;
    }
}

int MenuView::menu1View()
{
    while (true)
    {
        clearScreen();
        std::cout << "~~~ Manage Book Information ~~~" << std::endl;
        std::cout << "1. View Book List" << std::endl;
        std::cout << "2. Add New Book" << std::endl;
        std::cout << "3. Update Book Information" << std::endl;
        std::cout << "4. Go Back" << std::endl;
        std::cout << "-> Your selection: ";
        int selection = std::stoi(Book::validateInput(regex1_4));
        return selection;
    }
}

void MenuView::menu1_1View(std::vector<Book *> *books)
{

    if (books->empty())
    {
        std::cout << "Inventory empty!" << std::endl;
        MenuView::pauseScreen();
        return;
    }
    for (int i = 0; i < books->size(); i++)
    {
        books->at(i)->printAllInformationVertical(i);
    }
    MenuView::pauseScreen();
}

Book *MenuView::menu1_2View(std::vector<Book *> *books)
{
    while (true)
    {
        Book *book = nullptr;
        int myInt;
        std::string myStr, newLog, inputTitle, inputAuthor;
        clearScreen();
        std::cout << "~~~ Add New Book ~~~" << std::endl;
        std::cout << "- Enter title: ";
        inputTitle = Book::validateInput(allCharNoSpecial);
        std::cout << "- Enter author: ";
        inputAuthor = Book::validateInput(alphabetsAndSpacesRegex);
        book = BookSearcher::checkDuplicateBooks(books, inputTitle, inputAuthor);
        if (book != nullptr)
        {
            book->setQuantity(book->getQuantity() + 1);
            std::cout << "Books similar to this book already exist in the warehouse. Increasing the quantity by 1!" << std::endl;
            newLog = "+1 Book \"" + inputTitle + "\" by author \"" + inputAuthor + "\" have just been added to the Warehouse.";
            Reporter::saveLogToTxt(newLog);
            return nullptr;
        }
        std::cout << "  1. Novel\t2. Text Book\t3. Skill Book" << std::endl;
        std::cout << "- Select the book category: ";
        myInt = std::stoi(Book::validateInput(regex1_3));
        switch (myInt)
        {
        case 1:
            book = new Novel();
            break;
        case 2:
            book = new TextBook();
            break;
        case 3:
            book = new SkillBook();
            break;
        }
        book->setTitle(inputTitle);
        book->setAuthor(inputAuthor);
        std::cout << "- Enter price: ";
        myInt = std::stoi(Book::validateInput(equalOrGreater0Regex));
        book->setPrice(myInt);
        book->setStatus("Available");
        std::cout << "- Enter " << book->getNameOfFirstCustomAttribute() << ": ";
        myStr = Book::validateInput(book->getRegexOfFirstCustomAttribute());
        book->setFirstCustomAttribute(myStr);
        std::cout << "- Enter " << book->getNameOfSecondCustomAttribute() << ": ";
        myStr = Book::validateInput(book->getRegexOfSecondCustomAttribute());
        book->setSecondCustomAttribute(myStr);

        std::cout << "Book has been added to the Warehouse." << std::endl;
        newLog = "+1 Book \"" + inputTitle + "\" by author \"" + inputAuthor + "\" have just been added to the Warehouse.";
        Reporter::saveLogToTxt(newLog);
        return book;
    }
}

void MenuView::menu1_3View(std::vector<Book *> *books)
{
    int i = 0, inputIndex;
    clearScreen();
    std::cout << "~~~ Update Book Information ~~~" << std::endl;
    for (const auto &book : *books)
    {
        std::cout << "Index: " << i << ", Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ";" << std::endl;
        i++;
    }
    std::cout << "Choose index of book you want to update information: ";
    while (true)
    {
        inputIndex = std::stoi(Book::validateInput(equalOrGreater0Regex));
        if (inputIndex <= (books->size() - 1))
            break;
        std::cout << "Invalid Input. Please try again." << std::endl;
    }

    Book *targetBook = books->at(inputIndex);
    std::string cusAtt1, cusAtt2;
    cusAtt1 = targetBook->getNameOfFirstCustomAttribute();
    cusAtt2 = targetBook->getNameOfSecondCustomAttribute();
    clearScreen();
    std::cout << "~~~ Update Book Information ~~~" << std::endl;
    targetBook->printAllInformationHorizontal(inputIndex);

    std::cout << "1. Title" << std::endl;
    std::cout << "2. Author" << std::endl;
    std::cout << "3. Price" << std::endl;
    std::cout << "4. Status" << std::endl;
    std::cout << "5. " << cusAtt1 << std::endl;
    std::cout << "6. " << cusAtt2 << std::endl;

    std::cout << "->Choose information want to update: ";
    int choose = std::stoi(Book::validateInput(regex1_6));
    std::string regexPattern;
    std::string newInput;
    std::cout << "->Enter new information: ";

    switch (choose)
    {
    case 1:
        newInput = Book::validateInput(allCharNoSpecial);
        targetBook->setTitle(newInput);
        break;
    case 2:
        newInput = Book::validateInput(alphabetsAndSpacesRegex);
        targetBook->setAuthor(newInput);
        break;

    case 3:
        newInput = Book::validateInput(equalOrGreater0Regex);
        targetBook->setPrice(std::stoi(newInput));
        break;
    case 4:
        newInput = Book::validateInput(alphabetsAndSpacesRegex);
        targetBook->setStatus(newInput);
        break;
    case 5:
        regexPattern = targetBook->getRegexOfFirstCustomAttribute();
        newInput = Book::validateInput(regexPattern);
        targetBook->setFirstCustomAttribute(newInput);
        break;
    case 6:
        regexPattern = targetBook->getRegexOfSecondCustomAttribute();
        newInput = Book::validateInput(regexPattern);
        targetBook->setSecondCustomAttribute(newInput);
        break;
    }
}

int MenuView::menu2View()
{
    while (true)
    {
        clearScreen();
        std::cout << "~~~ Manage Warehouse~~~" << std::endl;
        std::cout << "1. View Book Quantity in Warehouse" << std::endl;
        std::cout << "2. Go Back" << std::endl;
        std::cout << "-> Your selection: ";
        int selection = std::stoi(Book::validateInput(regex1_2));
        return selection;
    }
}

void MenuView::menu2_1View(std::vector<Book *> *books)
{
    int i = 0;
    clearScreen();
    std::cout << "~~~ Manage Warehouse ~~~" << std::endl;
    for (const auto &book : *books)
    {
        book->printQuantity(i);
        i++;
    }
    pauseScreen();
}

void MenuView::menu3View(std::vector<Book *> *books)
{
    int i = 0;
    clearScreen();
    std::cout << "~~~ Sell Books ~~~" << std::endl;
    for (const auto &book : *books)
    {
        book->printQuantity(i);
        i++;
    }
    std::cout << "Choose index of book you want to sell: ";
    int inputIndex;
    while (true)
    {
        inputIndex = std::stoi(Book::validateInput(equalOrGreater0Regex));
        if (inputIndex <= (books->size() - 1))
            break;
        std::cout << "Invalid Input. Please try again." << std::endl;
    }
    int quantitySell;
    int quantityCurrent = books->at(inputIndex)->getQuantity();
    std::cout << "-> Enter the quantity of books to sell: ";
    while (true)
    {
        quantitySell = std::stoi(Book::validateInput(equalOrGreater0Regex));
        if (quantitySell <= quantityCurrent)
            break;
        std::cout << "Invalid Input. Please try again." << std::endl;
    }
    books->at(inputIndex)->setQuantity(quantityCurrent - quantitySell);
    std::string bookTitle = books->at(inputIndex)->getTitle();
    std::string bookAuthor = books->at(inputIndex)->getAuthor();
    std::string newLog = "-" + std::to_string(quantitySell) + " copies of \"" + bookTitle + "\" by author \"" + bookAuthor + "\" have been sold";
    Reporter::saveLogToTxt(newLog);
}

std::vector<Book *> *MenuView::menu4View(std::vector<Book *> *books)
{
    while (true)
    {
        int selection;
        clearScreen();
        std::cout << "~~~ Search Books~~~" << std::endl;
        std::cout << "1. Search by Book Title" << std::endl;
        std::cout << "2. Search by Author" << std::endl;
        std::cout << "3. Go Back" << std::endl;
        std::cout << "-> Your selection: ";
        selection = std::stoi(Book::validateInput(regex1_3));
        clearScreen();
        std::vector<Book *> *searchResult = nullptr;
        BookSearcher searcher;
        std::string searchTerm;
        std::cout << "~~~ Search Books~~~" << std::endl;
        switch (selection)
        {
        case 1:
            std::cout << "Enter title: ";
            searchTerm = Book::validateInput(allCharNoSpecial);
            searcher.setSearchStrategy(new TitleSearch());
            break;
        case 2:
            std::cout << "Enter autor: ";
            searchTerm = Book::validateInput(alphabetsAndSpacesRegex);
            searcher.setSearchStrategy(new AuthorSearch());
            break;
        case 3:
            return searchResult;
        }
        searchResult = searcher.searchBooks(books, searchTerm);

        if (searchResult != nullptr)
            return searchResult;

        std::cout << "No search result" << std::endl;
        std::cout << "Do you want to search another books (y/n): ";
        char y_n = Book::validateInput(y_nRegex)[0];
        if (y_n == 'n')
            return searchResult;
    }
}

int MenuView::menu5View()
{
    while (true)
    {
        int selection;
        clearScreen();
        std::cout << "~~~ Generate Reports~~~" << std::endl;
        std::cout << "1. Show Report" << std::endl;
        std::cout << "2. Reset Report" << std::endl;
        std::cout << "3. Go Back" << std::endl;
        std::cout << "-> Your selection: ";
        selection = std::stoi(Book::validateInput(regex1_3));
        return selection;
    }
}

#endif // MENUVIEW_H