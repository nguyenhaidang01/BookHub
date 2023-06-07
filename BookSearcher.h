#ifndef BOOKSEARCHER_H
#define BOOKSEARCHER_H

#include "Book.h"
class ISearch
{
public:
    virtual std::vector<Book *> *search(const std::vector<Book *> *books, const std::string &searchTerm) = 0;
};

class AuthorSearch : public ISearch
{
public:
    std::vector<Book *> *search(const std::vector<Book *> *books, const std::string &searchTerm) override;
};

class TitleSearch : public ISearch
{
public:
    std::vector<Book *> *search(const std::vector<Book *> *books, const std::string &searchTerm) override;
};

class BookSearcher
{
private:
    ISearch *searchStrategy;

public:
    void setSearchStrategy(ISearch *strategy);
    std::vector<Book *> *searchBooks(const std::vector<Book *> *books, const std::string &searchTerm);
    static Book *checkDuplicateBooks(const std::vector<Book *> *books, const std::string &inputTitle, const std::string &inputAuthor);
};

std::vector<Book *> *AuthorSearch::search(const std::vector<Book *> *books, const std::string &searchTerm)
{
    std::vector<Book *> *result = new std::vector<Book *>();

    for (const auto &book : *books)
    {
        if (book->getAuthor() == searchTerm)
            result->push_back(book);
    }
    if (result->empty())
    {
        delete result;
        result = nullptr;
    }
    return result;
}

std::vector<Book *> *TitleSearch::search(const std::vector<Book *> *books, const std::string &searchTerm)
{
    std::vector<Book *> *result = new std::vector<Book *>();

    for (const auto &book : *books)
    {
        if (book->getTitle() == searchTerm)
            result->push_back(book);
    }
    if (result->empty())
    {
        delete result;
        result = nullptr;
    }
    return result;
}

void BookSearcher::setSearchStrategy(ISearch *strategy)
{
    searchStrategy = strategy;
}

std::vector<Book *> *BookSearcher::searchBooks(const std::vector<Book *> *books, const std::string &searchTerm)
{
    if (!searchStrategy)
    {
        throw std::runtime_error("Search strategy has not been set.");
    }
    return searchStrategy->search(books, searchTerm);
}

Book *BookSearcher::checkDuplicateBooks(const std::vector<Book *> *books, const std::string &inputTitle, const std::string &inputAuthor)
{
    for (const auto &book : *books)
    {
        if (book->bookExists(inputTitle, inputAuthor))
            return book;
    }
    return nullptr;
}

#endif // BOOKSEARCHER_H