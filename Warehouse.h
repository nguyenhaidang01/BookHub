#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <fstream>
#include <stdexcept>
#include "Novel.h"
#include "SkillBook.h"
#include "TextBook.h"

class Warehouse
{
public:
    void saveBooksToTxt(const std::vector<Book *> *books);
    std::vector<Book *> *readBooksFromTxt();
};

void Warehouse::saveBooksToTxt(const std::vector<Book *> *books)
{
    try
    {
        const std::string filename = "warehouse.txt";
        std::ofstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open the file");
        }

        for (const auto &book : *books)
        {
            file << "Category: " << book->getCategory() << "\n";
            file << "Title: " << book->getTitle() << "\n";
            file << "Author: " << book->getAuthor() << "\n";
            file << "Price: " << book->getPrice() << "\n";
            file << "Quantity: " << book->getQuantity() << "\n";
            file << "CusAtt1: " << book->getFirstCustomAttribute() << "\n";
            file << "CusAtt2: " << book->getSecondCustomAttribute() << "\n";
            file << "Status: " << book->getStatus() << "\n\n";
        }

        file.close();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

std::vector<Book *> *Warehouse::readBooksFromTxt()
{
    const std::string filename = "warehouse.txt";
    std::vector<Book *> *books = new std::vector<Book *>();
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open the file");
    }

    std::string line;
    Book *currentBook = nullptr;

    while (std::getline(file, line))
    {
        if (line.find("Category: ") != std::string::npos)
        {
            std::string bookType = line.substr(10);
            if (bookType == "Novel")
                currentBook = new Novel();
            else if (bookType == "SkillBook")
                currentBook = new SkillBook();
            else if (bookType == "TextBook")
                currentBook = new TextBook();
            books->push_back(currentBook);
        }
        else if (line.find("Title: ") != std::string::npos)
        {
            currentBook->setTitle(line.substr(7));
        }
        else if (line.find("Author: ") != std::string::npos)
        {
            currentBook->setAuthor(line.substr(8));
        }
        else if (line.find("Price: ") != std::string::npos)
        {
            currentBook->setPrice(std::stof(line.substr(7)));
        }
        else if (line.find("Quantity: ") != std::string::npos)
        {
            currentBook->setQuantity(std::stoi(line.substr(10)));
        }
        else if (line.find("CusAtt1: ") != std::string::npos)
        {
            currentBook->setFirstCustomAttribute(line.substr(9));
        }
        else if (line.find("CusAtt2: ") != std::string::npos)
        {
            currentBook->setSecondCustomAttribute(line.substr(9));
        }
        else if (line.find("Status: ") != std::string::npos)
        {
            currentBook->setStatus(line.substr(8));
        }
    }
    file.close();
    return books;
}

#endif // WAREHOUSE_H