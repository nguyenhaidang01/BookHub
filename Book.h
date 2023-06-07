#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <regex>

class Book
{
public:
    Book() : quantity(1) {}
    ~Book() {}

    static std::string validateInput(const std::string &regexPattern);
    bool bookExists(std::string inputTitle, std::string inputAuthor);

    virtual void printAllInformationVertical(int index);
    virtual void printAllInformationHorizontal(int index);

    virtual void setFirstCustomAttribute(std::string firstAttribute) = 0;
    virtual std::string getFirstCustomAttribute() = 0;
    virtual std::string getNameOfFirstCustomAttribute() = 0;
    virtual std::string getRegexOfFirstCustomAttribute() = 0;

    virtual void setSecondCustomAttribute(std::string secondAttribute) = 0;
    virtual std::string getSecondCustomAttribute() = 0;
    virtual std::string getNameOfSecondCustomAttribute() = 0;
    virtual std::string getRegexOfSecondCustomAttribute() = 0;

    void printQuantity(int index);

    std::string getTitle() const;
    void setTitle(std::string title);

    std::string getAuthor() const;
    void setAuthor(std::string author);

    std::string getCategory() const;
    void setCategory(std::string category);

    int getPrice() const;
    void setPrice(int price);

    std::string getStatus() const;
    void setStatus(std::string status);

    int getQuantity() const;
    void setQuantity(int quantity);

private:
    std::string title;
    std::string author;
    std::string category;
    int price;
    std::string status;
    int quantity;
};

std::string Book::validateInput(const std::string &regexPattern)
{
    std::string input;
    std::regex pattern(regexPattern);

    while (true)
    {
        try
        {
            std::getline(std::cin, input);

            if (std::regex_match(input, pattern))
            {
                return input;
            }
            else
            {
                throw std::invalid_argument("Invalid input.");
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << " Please try again." << std::endl;
        }
    }
}

bool Book::bookExists(std::string inputTitle, std::string inputAuthor)
{
    return (title == inputTitle) && (author == inputAuthor);
}

void Book::printAllInformationVertical(int index)
{
    std::cout << "Index: " << index << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << this->getNameOfFirstCustomAttribute() << ": " << this->getFirstCustomAttribute() << std::endl;
    std::cout << this->getNameOfSecondCustomAttribute() << ": " << this->getSecondCustomAttribute() << std::endl;
    std::cout << "____________________________________________________" << std::endl;
}

void Book::printAllInformationHorizontal(int index)
{
    std::cout << "Index: " << index << ", Title: " << title << ", Author: " << author;
    std::cout << ", Category: " << category << ", Price: " << price << "," << std::endl;
    std::cout << "Quantity: " << quantity << ", Status: " << status << ", ";

    std::cout << this->getNameOfFirstCustomAttribute() << ": " << this->getFirstCustomAttribute() << ", ";
    std::cout << this->getNameOfSecondCustomAttribute() << ": " << this->getSecondCustomAttribute() << ";" << std::endl;

    std::cout << "____________________________________________________" << std::endl;
}

void Book::printQuantity(int index)
{
    std::cout << "Index: " << index << ", Title: " << title << ", Author: " << author;
    std::cout << " | Quantity: " << quantity << ";" << std::endl;
}

std::string Book::getTitle() const
{
    return title;
}

void Book::setTitle(std::string title)
{
    this->title = title;
}

std::string Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(std::string author)
{
    this->author = author;
}

std::string Book::getCategory() const
{
    return category;
}

void Book::setCategory(std::string category)
{
    this->category = category;
}

int Book::getPrice() const
{
    return price;
}

void Book::setPrice(int price)
{
    this->price = price;
}

std::string Book::getStatus() const
{
    return status;
}

void Book::setStatus(std::string status)
{
    this->status = status;
}

int Book::getQuantity() const
{
    return quantity;
}

void Book::setQuantity(int quantity)
{
    this->quantity = quantity;
}

#endif // BOOK_H