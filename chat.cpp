/*
 * Copyright 2019 TangYida
 *
 * chat
 *
 */

#include "./include/nlohmann/json.hpp"

#include<sys/stat.h>
#include<fcntl.h>
#include<bits/stdc++.h>

const std::string configPath{"./hack.chat-terminal-client/config.json"};
const std::string runPath{"node ./hack.chat-terminal-client/index.js"};

inline int lauch()
{
	return system(runPath.c_str());
}

inline void help()
{
	std::cout << "chat: use hack.chat and hack.chat-terminal-client\n"
		"options:\n"
		"-r [roomname]:must be provided.\n"
		"-u [username]:must be provided.\n";
	std::cout << std::flush;
}
#define DEBUG(x) std::cerr << #x << " = " << x << "\n"

inline bool writeRoom(std::string name)
{
	nlohmann::json prs;
	std::fstream fio(configPath);
	fio >> prs;
	fio.close();
	prs["channel"] = name;

	remove(configPath.c_str());
	creat(configPath.c_str(),S_IRWXU);
	fio.open(configPath);

	fio << std::setw(4) << prs;
	fio.close();
	return true;
}

inline bool writeUser(std::string name)
{
	nlohmann::json prs;
	std::fstream fio(configPath);
	fio >> prs;
	fio.close();
	prs["username"] = name;

	remove(configPath.c_str());
	creat(configPath.c_str(),S_IRWXU);
	fio.open(configPath);

	fio << std::setw(4) << prs;
	fio.close();
	return true;
}

int main(int argc,char** argv)
{
	if(argc < 2) {
		std::cerr << "Please provide your room name and username\n";
		help();
		exit(1);
	}
	for(int i = 1;i <= argc - 1;) {
		std::string param(argv[i]);
		if(param == "-r") {
			if(i == argc - 1) {
				std::cerr << "-r:incorrect usage\n";
				exit(1);
			} else writeRoom(argv[++i]);
		} else if(param == "-u") {
			if(i == argc - 1) {
				std::cerr << "-u:incorrect usage\n";
				exit(1);
			} else writeUser(argv[++i]);
		} else if(param == "-h") {
			help();
		} else {
			std::cerr << param << ": unknown command\n";
			exit(1);
		}
		i++;
	}
	lauch();
	exit(0);
}
