#ifndef SKILLBOOK_H
#define SKILLBOOK_H

#include "Book.h"

class SkillBook : public Book
{
public:
    SkillBook();
    ~SkillBook();

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

    std::string getField() const;
    void setField(std::string field);

    std::string getDifficulty() const;
    void setDifficulty(std::string difficulty);

private:
    std::string field;
    std::string difficulty;
};

SkillBook::SkillBook() : field(""), difficulty("")
{
    this->setCategory("SkillBook");
}

SkillBook::~SkillBook()
{
}

void SkillBook::setFirstCustomAttribute(std::string firstAttribute)
{
    field = firstAttribute;
}

std::string SkillBook::getFirstCustomAttribute()
{
    return field;
}

std::string SkillBook::getNameOfFirstCustomAttribute()
{
    return "Field";
}

std::string SkillBook::getRegexOfFirstCustomAttribute()
{
    std::string alphabetsAndSpacesRegex = "^[A-Za-z\\s]+$";
    return alphabetsAndSpacesRegex;
}

void SkillBook::setSecondCustomAttribute(std::string secondAttribute)
{
    difficulty = secondAttribute;
}

std::string SkillBook::getSecondCustomAttribute()
{
    return difficulty;
}

std::string SkillBook::getNameOfSecondCustomAttribute()
{
    return "Difficulty";
}

std::string SkillBook::getRegexOfSecondCustomAttribute()
{
    std::string alphabetsAndSpacesRegex = "^[A-Za-z\\s]+$";
    return alphabetsAndSpacesRegex;
}

void SkillBook::printAllInformationHorizontal(int index)
{
    Book::printAllInformationHorizontal(index);
}

void SkillBook::printAllInformationVertical(int index)
{
    Book::printAllInformationVertical(index);
}

std::string SkillBook::getField() const
{
    return field;
}

void SkillBook::setField(std::string field)
{
    this->field = field;
}

std::string SkillBook::getDifficulty() const
{
    return difficulty;
}

void SkillBook::setDifficulty(std::string difficulty)
{
    this->difficulty = difficulty;
}

#endif // SKILLBOOK_H
