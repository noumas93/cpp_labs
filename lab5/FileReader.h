#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <iterator>

class FileReader
{
private:
    struct fWordlist {
        std::string word;
        int copies;
    };

    struct sortbyCopies
    {
        inline bool operator() (fWordlist const struct1, fWordlist const struct2) const
        {
            return (struct1.copies > struct2.copies);
        }
    };
    
    std::vector<fWordlist> wordkopies{};
    std::vector<std::string> wordlist{};
    std::string secondArg{};
    std::string lastWord = "";
    std::string words = "";
    int thirdArg{};
    int copies = 1;
    void printWords(fWordlist const word) const;
    void prepareWords(std::string const word);
    void findValidWord(std::string const myFile);
    void isAlphaptic(char const c);

    public:
    FileReader(std::string arg1, std::string arg2, int arg3) :secondArg{ arg2 }, thirdArg{ arg3 } {}
    void eraser(std::string myFile);
    void sorting();
    void print() const;


};

#endif
