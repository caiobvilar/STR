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

struct proc
{
	std::string PID;
	std::string filename;
	std::string status;
	std::string PID_Parent;
	std::string ID_process_group;
	std::string session_ID;
	std::string control_terminal;
	std::string ID_process_group_foregr;
	std::string task_flags;
	std::string minor_pg_faults;
	std::string minor_pg_faults_child;
	std::string major_pg_faults;
	std::string major_pg_faults_child;
	std::string CPU_time_usr_code;
	std::string CPU_time_krn_code;
	std::string CPU_time_usr_code_child;
	std::string CPU_time_krn_code_child;
};

int main()
{
		std::vector<std::string> vecchar;
		std::map<std::string,proc>processtable;
		std::stringstream iss;
		std::string key,value;
		proc aux;
		FILE *fd1 = popen("ps axco pid,command", "r");
		char *line1 = NULL;
		size_t len1 = 0;
		ssize_t nread1;
    if (NULL == fd1)
    {
        printf("Error in popen");
        return 0;
    }
		while((nread1 = getline(&line1,&len1,fd1)) != -1)
		{
			vecchar.push_back(std::string(line1,strlen(line1)));
		}
		free(line1);
    pclose(fd1);
		std::string process_pid;
		std::string command = "cat /proc/";
		command.append(process_pid);
		command.append("/stat");

		FILE *fd2 = popen(command.c_str(),"r");
		char *line2 = NULL;
		size_t len2 = 0;
		ssize_t nread2;
		nread2 = getline(&line2,&len2,fd2);
		iss << nread2;
		iss >> aux.PID >> std::ws >> aux.filename >> std::ws
				>> aux.status >> std::ws >> aux.PID_Parent >> std::ws
				>> aux.ID_process_group >> std::ws >> aux.session_ID >> std::ws
				>> aux.control_terminal >> std::ws >> aux.ID_process_group_foregr >> std::ws
				>> aux.task_flags >> std::ws >> aux.minor_pg_faults >> std::ws
				>> aux.minor_pg_faults_child >> std::ws >> aux.major_pg_faults >> std::ws
				>> aux.major_pg_faults_child >> std::ws >> aux.CPU_time_usr_code >> std::ws
				>> aux.CPU_time_krn_code >> std::ws >> aux.CPU_time_usr_code_child >> std::ws
				>> aux.CPU_time_krn_code_child;
		free(line2);
		pclose(fd2);
		std::vector<std::string>::iterator itr;
		for(itr = vecchar.begin();itr != vecchar.end();itr++)
		{
			iss << (*itr);
			iss >>	key >>std::ws >> aux.filename;
			processtable.insert(std::pair<std::string, proc>(key,aux));
		}	
		std::map<std::string,proc>::iterator tableitr;
		for(tableitr = processtable.begin();tableitr != processtable.end();tableitr++)
		{
			std::cout << (*tableitr).first << ": " << (*tableitr).second.CPU_time_usr_code << (*tableitr).second.filename << std::endl;
		}
		return 0;
}
