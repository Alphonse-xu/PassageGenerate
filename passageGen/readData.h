#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"


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
		fileStr = {};

		readFile(fileStr);
		parserJson(fileStr, document);
		dealJson(document);
	}
	~readData() 
	{
		delete wordData;
		wordData = nullptr;
	}



	WordData* getWord()
	{
		return wordData;
	}


protected:
	rapidjson::Document document;

	std::string fileStr;

	WordData* wordData; //����

	//��ȡJSON�ļ�,װ��һ���ַ�����
	bool readFile(std::string& str)
	{
		//ȷ���ļ���ȡ״̬
		//std::ifstream in("data\\data.json", std::ios::binary);

		std::ifstream in;
		in.open("data\\data.json", std::ifstream::in);
		if (!in.is_open())
		{
			std::cout << "Error opening file\n";
			return false;
		}

		std::string line;
		while (std::getline(in, line))
		{
			str.append(line + "\n");
			std::cout << line;
		}
		in.close();

		return true;
	}

	bool parserJson(std::string& str, rapidjson::Document& doc)
	{
		doc.Parse<0>(str.c_str());
		if (doc.HasParseError())
		{
			std::cout << "error parser string\n";
			return false;
		}
			
		return true;
	}

	bool dealJson(rapidjson::Document& doc)
	{
		if (doc.IsObject())
		{
			
			if (doc.HasMember("example"))
			{
				const rapidjson::Value& bFamous = doc["famous"];
				if (bFamous.IsArray()) 
				{
					for (rapidjson::SizeType i = 0; i < bFamous.Size(); i++)
					{
						wordData->famousWord->push_back(bFamous[i].GetString()); //a ����ǰ��滰��b�������滰

					}
				}

				const rapidjson::Value& bBefore = doc["before"];
				if (bFamous.IsArray())
				{
					for (rapidjson::SizeType i = 0; i < bBefore.Size(); i++)
					{
						wordData->famousWord->push_back(bBefore[i].GetString()); //����������ǰ��Ū��ϻ�

					}
				}

				const rapidjson::Value& bAfter = doc["after"];
				if (bFamous.IsArray())
				{
					for (rapidjson::SizeType i = 0; i < bAfter.Size(); i++)
					{
						wordData->famousWord->push_back(bAfter[i].GetString()); //���������Ժ���Ū��ϻ�

					}
				}

				const rapidjson::Value& bBosh= doc["bosh"];
				if (bFamous.IsArray())
				{
					for (rapidjson::SizeType i = 0; i < bBosh.Size(); i++)
					{
						wordData->famousWord->push_back(bBosh[i].GetString());//����������Ҫ�ϻ���Դ

					}
				}

			}

		}

		return true;
	}


};


