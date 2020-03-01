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
        //��������� c++11
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

            std::cout << sectionTmp; //����̨��ʾ

        }
        
        return true;
    }

    std::string newSection(std::string section)
    {
        return section + "��" +  "\r\n" +"����";
        
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

        startpos = word.find('a');   //�ҵ�'.'��λ��
        if (startpos != std::string::npos) //std::string::npos��ʾû���ҵ����ַ�
        {
            word.replace(startpos, 1, ranList(datajson->readFileJson()->beforeWord)); //ʵʩ�滻��ע�����һ��Ҫ��""����������ʾ�ַ���
        }

        startpos = word.find('b');   //�ҵ�'.'��λ��
        if (startpos != std::string::npos) //std::string::npos��ʾû���ҵ����ַ�
        {
            word.replace(startpos, 1, ranList(datajson->readFileJson()->afterWord)); //ʵʩ�滻��ע�����һ��Ҫ��""����������ʾ�ַ���
        }
    }


    readData* datajson;
    std::string theme;
    std::string passage;

    int repeatTime;
    int branch;
    float maxWord;

};
