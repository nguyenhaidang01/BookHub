#ifndef REPORTER_H
#define REPORTER_H

#include <fstream>
#include <stdexcept>
#include "Novel.h"
#include "SkillBook.h"
#include "TextBook.h"

class Reporter
{
public:
    static void saveLogToTxt(const std::string newLog);
    static std::string readLogFromTxt();
    static void resetLog();
};

void Reporter::saveLogToTxt(const std::string newLog)
{
    try
    {
        const std::string filename = "log.txt";
        std::ofstream file(filename, std::ios::app);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open the file");
        }
        file << newLog << std::endl;
        file << "_______________________________________________________________________________" << std::endl;

        file.close();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

std::string Reporter::readLogFromTxt()
{
    std::ifstream file("log.txt");
    std::string logs;

    if (!file)
    {
        throw std::runtime_error("Unable to open the file.");
    }
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Log Empty!!!" << std::endl;
        return "";
    }

    std::string line;
    while (std::getline(file, line))
    {
        logs += line + "\n";
    }
    file.close();

    return logs;
}
void Reporter::resetLog()
{
    try
    {
        const std::string filename = "log.txt";
        std::ofstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open the file");
        }
        file << "";
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

#endif // REPORTER_H