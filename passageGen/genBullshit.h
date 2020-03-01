#include<string>
#include<iostream>
#include<random>
#include<time.h>

#include "readData.h"

class generateShit
{
public:
    generateShit(std::string shitTheme)
    {
        theme = shitTheme;
        datajson = new readData();

        repeatTime = 2;
        maxWord = 6000;

        newArticle();
    }

    ~generateShit() 
    {
        delete datajson;
        datajson = nullptr;
    }

    void printShit()
    {
        std::cout << passage;
    }

protected:
    bool newArticle()
    {
        //生辰随机数 c++11
        std::default_random_engine random(time(NULL));
        std::uniform_int_distribution<int> randomNum(0, 100);
        branch = randomNum(random);

        for (auto x : theme)
        {
            std::string sectionTmp{};

            while (sectionTmp.length() < maxWord)
            {

                if (branch < 5)
                {
                    sectionTmp += newSection(sectionTmp);

                }
                else if (branch < 20)
                {
                    sectionTmp += newFamous();
                }
                else
                {
                    sectionTmp += newBosh();
                    

                }
            }

            std::cout << sectionTmp; //控制台显示

        }
        
        return true;
    }

    std::string newSection(std::string section)
    {
        return section + "。" +  "\r\n" +"　　";
        
    }

    std::string newFamous()
    {
        std::string nextFamous;
        nextFamous = ranList(datajson->readFileJson()->famousWord);

        repWord(nextFamous);

        return nextFamous;
    }

    std::string newBosh()
    {
        std::string nextBosh;
        nextBosh = ranList(datajson->readFileJson()->famousWord);

        repWord(nextBosh);

        return nextBosh;
    }

    std::string ranList(std::vector<std::string>* nextWord)
    {
        std::default_random_engine random(time(NULL));
        std::uniform_int_distribution<int> randomNum(0, nextWord->size());
        int pos =  randomNum(random);

        std::string tmp;
        for (auto i : nextWord[pos])
        {
            tmp = tmp + i;
        }

        return tmp;
    }

    void repWord(std::string& word)
    {
        std::string::size_type startpos;

        startpos = word.find('a');   //找到'.'的位置
        if (startpos != std::string::npos) //std::string::npos表示没有找到该字符
        {
            word.replace(startpos, 1, ranList(datajson->readFileJson()->beforeWord)); //实施替换，注意后面一定要用""引起来，表示字符串
        }

        startpos = word.find('b');   //找到'.'的位置
        if (startpos != std::string::npos) //std::string::npos表示没有找到该字符
        {
            word.replace(startpos, 1, ranList(datajson->readFileJson()->afterWord)); //实施替换，注意后面一定要用""引起来，表示字符串
        }
    }


    readData* datajson;
    std::string theme;
    std::string passage;

    int repeatTime;
    int branch;
    float maxWord;

};
