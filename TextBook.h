#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "Book.h"

class TextBook : public Book
{
public:
    TextBook();
    ~TextBook();

    virtual void setFirstCustomAttribute(std::string firstAttribute) override;
    virtual std::string getFirstCustomAttribute() override;
    virtual std::string getNameOfFirstCustomAttribute() override;
    virtual std::string getRegexOfFirstCustomAttribute() override;
    virtual std::string getRegexOfSecondCustomAttribute() override;

    virtual void setSecondCustomAttribute(std::string secondAttribute) override;
    virtual std::string getSecondCustomAttribute() override;
    virtual std::string getNameOfSecondCustomAttribute() override;

    virtual void printAllInformationHorizontal(int index) override;
    virtual void printAllInformationVertical(int index) override;

    std::string getMajor() const;
    void setMajor(std::string major);

    std::string getSubject() const;
    void setSubject(std::string subject);

private:
    std::string major;
    std::string subject;
};

TextBook::TextBook() : major(""), subject("")
{
    this->setCategory("TextBook");
}

TextBook::~TextBook()
{
}

void TextBook::setFirstCustomAttribute(std::string firstAttribute)
{
    major = firstAttribute;
}

std::string TextBook::getFirstCustomAttribute()
{
    return major;
}

std::string TextBook::getNameOfFirstCustomAttribute()
{
    return "Major";
}

std::string TextBook::getRegexOfFirstCustomAttribute()
{
    std::string alphabetsAndSpacesRegex = "^[A-Za-z\\s]+$";
    return alphabetsAndSpacesRegex;
}

std::string TextBook::getRegexOfSecondCustomAttribute()
{
    std::string alphabetsAndSpacesRegex = "^[A-Za-z\\s]+$";
    return alphabetsAndSpacesRegex;
}

void TextBook::setSecondCustomAttribute(std::string secondAttribute)
{
    subject = secondAttribute;
}

std::string TextBook::getSecondCustomAttribute()
{
    return subject;
}

std::string TextBook::getNameOfSecondCustomAttribute()
{
    return "Subject";
}

void TextBook::printAllInformationHorizontal(int index)
{
    Book::printAllInformationHorizontal(index);
}

void TextBook::printAllInformationVertical(int index)
{
    Book::printAllInformationVertical(index);
}

std::string TextBook::getMajor() const
{
    return major;
}

void TextBook::setMajor(std::string major)
{
    this->major = major;
}

std::string TextBook::getSubject() const
{
    return subject;
}

void TextBook::setSubject(std::string subject)
{
    this->subject = subject;
}

#endif // TEXTBOOK_H