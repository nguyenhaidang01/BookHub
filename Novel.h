#ifndef NOVEL_H
#define NOVEL_H

#include "Book.h"

class Novel : public Book
{
public:
    Novel();
    ~Novel();

    virtual void setFirstCustomAttribute(std::string firstAttribute) override;
    virtual std::string getFirstCustomAttribute() override;
    virtual std::string getNameOfFirstCustomAttribute() override;
    virtual std::string getRegexOfFirstCustomAttribute() override;

    virtual void setSecondCustomAttribute(std::string secondAttribute) override;
    virtual std::string getSecondCustomAttribute() override;
    virtual std::string getNameOfSecondCustomAttribute() override;
    virtual std::string getRegexOfSecondCustomAttribute() override;

    virtual void printAllInformationHorizontal(int index) override;
    virtual void printAllInformationVertical(int index) override;

    std::string getGenre() const;
    void setGenre(std::string genre);

    float getRating() const;
    void setRating(float rating);

private:
    std::string genre;
    float rating;
};

Novel::Novel() : genre(""), rating(0)
{
    this->setCategory("Novel");
}

Novel::~Novel()
{
}

void Novel::setFirstCustomAttribute(std::string firstAttribute)
{
    genre = firstAttribute;
}

std::string Novel::getFirstCustomAttribute()
{
    return genre;
}

std::string Novel::getNameOfFirstCustomAttribute()
{
    return "Genre";
}

std::string Novel::getRegexOfFirstCustomAttribute()
{
    std::string alphabetsAndSpacesRegex = "^[A-Za-z\\s]+$";
    return alphabetsAndSpacesRegex;
}

void Novel::setSecondCustomAttribute(std::string secondAttribute)
{
    rating = std::stof(secondAttribute);
}

std::string Novel::getSecondCustomAttribute()
{
    return std::to_string(rating);
}

std::string Novel::getNameOfSecondCustomAttribute()
{
    return "Rating";
}

std::string Novel::getRegexOfSecondCustomAttribute()
{
    std::string ratingRegex = "^(?:[0-4](?:\\.\\d)?|5(?:\\.0)?)$";
    return ratingRegex;
}

void Novel::printAllInformationHorizontal(int index)
{
    Book::printAllInformationHorizontal(index);
}

void Novel::printAllInformationVertical(int index)
{
    Book::printAllInformationVertical(index);
}

std::string Novel::getGenre() const
{
    return genre;
}

void Novel::setGenre(std::string genre)
{
    this->genre = genre;
}

float Novel::getRating() const
{
    return rating;
}

void Novel::setRating(float rating)
{
    this->rating = rating;
}

#endif // NOVEL_H