#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>


int main()
{
		std::vector<std::string> vecchar;
		std::map<std::string,std::string>processtable;
		std::stringstream iss;
		std::string key,value;
		FILE *fd = popen("ps axco pid,command", "r");
		char *line = NULL;
		size_t len = 0;
		ssize_t nread;

    if (NULL == fd)
    {
        printf("Error in popen");
        return 0;
    }
		while((nread = getline(&line,&len,fd)) != -1)
		{
			vecchar.push_back(std::string(line,strlen(line)));
		}
		free(line);
    pclose(fd);
		std::vector<std::string>::iterator itr;
		for(itr = vecchar.begin();itr != vecchar.end();itr++)
		{
			iss << (*itr);
			iss >>	key >>std::ws >> value;
			processtable.insert(std::pair<std::string, std::string>(key,value));
		}	
		std::map<std::string,std::string>::iterator tableitr;
		for(tableitr = processtable.begin();tableitr != processtable.end();tableitr++)
		{
			std::cout << (*tableitr).first << ": " << (*tableitr).second << std::endl;
		}
		return 0;
}
