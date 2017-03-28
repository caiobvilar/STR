#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>

#define MAXBUFF 1000


std::string convert(char const(&data)[MAXBUFF])
{
	return std::string(data, std::find(data,data+MAXBUFF,'\0'));
}

int preenchetable(std::map<int,std::string>table)
{
	int key = 0;
	std::string procname = "";
	std::string filestr;
	FILE* fp;
	char buffer[MAXBUFF];
	fp = popen("ps -a","r");
	if(NULL == fp)
	{
		std::cout << "[ERROR]: could not open file." << std::endl;
		return 1;
	}
	fread(buffer, MAXBUFF,1,fp);
	filestr = convert(buffer);
	



	table.insert(std::pair<int,std::string>(key,procname));
	return 0;
}

int main()
{
	std::map<int ,std::string> processtable;

	return 0;
}
