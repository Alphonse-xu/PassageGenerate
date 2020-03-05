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

	WordData* wordData; //数据

	//读取JSON文件,装入一个字符串中
	bool readFile(std::string& str)
	{
		//确认文件读取状态
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
						wordData->famousWord->push_back(bFamous[i].GetString()); //a 代表前面垫话，b代表后面垫话

					}
				}

				const rapidjson::Value& bBefore = doc["before"];
				if (bFamous.IsArray())
				{
					for (rapidjson::SizeType i = 0; i < bBefore.Size(); i++)
					{
						wordData->famousWord->push_back(bBefore[i].GetString()); //在名人名言前面弄点废话

					}
				}

				const rapidjson::Value& bAfter = doc["after"];
				if (bFamous.IsArray())
				{
					for (rapidjson::SizeType i = 0; i < bAfter.Size(); i++)
					{
						wordData->famousWord->push_back(bAfter[i].GetString()); //在名人名言后面弄点废话

					}
				}

				const rapidjson::Value& bBosh= doc["bosh"];
				if (bFamous.IsArray())
				{
					for (rapidjson::SizeType i = 0; i < bBosh.Size(); i++)
					{
						wordData->famousWord->push_back(bBosh[i].GetString());//代表文章主要废话来源

					}
				}

			}

		}

		return true;
	}


};


