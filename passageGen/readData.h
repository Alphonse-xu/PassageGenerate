#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "json/json.h"
#include "jsoncpp.cpp"

struct WordData {
	std::vector<std::string>* famousWord;
	std::vector<std::string>* beforeWord;
	std::vector<std::string>* afterWord;
	std::vector<std::string>* boshWord;

};

class readData {
public:
	readData() 
	{
		wordData = new WordData;
	}
	~readData() 
	{
		delete wordData;
		wordData = nullptr;
	}

	WordData* readFileJson()
	{
		//ȷ���ļ���ȡ״̬
		std::ifstream in("data\\data.json", std::ios::binary);

		if (!in.is_open())
		{
			std::cout << "Error opening file\n";
			return false;
		}

		if (reader.parse(in, root))
		{
			std::string name = root["title"].asString();

			if (name == "example")
			{
				//wordData->testWord.push_back(root["famous"].asString());
				for (size_t i = 0; i < root["famous"].size(); i++)
				{
					wordData->famousWord->push_back(root["famous"][i].asString()); //a ����ǰ��滰��b�������滰

				}

				for (size_t i = 0; i < root["before"].size(); i++)
				{
					wordData->beforeWord->push_back(root["before"][i].asString()); //����������ǰ��Ū��ϻ�

				}

				for (size_t i = 0; i < root["after"].size(); i++)
				{
					wordData->afterWord->push_back(root["after"][i].asString()); 

				}//���������Ժ���Ū��ϻ�

				for (size_t i = 0; i < root["bosh"].size(); i++)
				{
					wordData->boshWord->push_back(root["bosh"][i].asString()); 

				}//����������Ҫ�ϻ���Դ
			}

		}
		return wordData;
	}

protected:
	Json::Reader reader;
	Json::Value root;

	WordData* wordData;
};

