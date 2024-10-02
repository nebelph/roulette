#include <iostream>
#include <Windows.h>
#include <vector>
#include <math.h>
#include <string>
void print(std::vector<std::string>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i);
		if (i != v.size() - 1) std::cout << ", ";
	}
	std::cout << ".\n\n";
}
void printTeam(std::vector < std::string>& v) {
	std::cout << "Team '" << v.at(0) << "': ";
	for (int i = 1; i < v.size(); i++) {
		std::cout << v.at(i);
		if (i == v.size() - 1) std::cout << ".\n\n";
		else std::cout << ", ";
	}
}
std::string roll(std::vector<std::string>& v) {
	std::cout << std::endl;
	for (int i = 0; i < 20; i = i++) {
		int index = rand() % v.size();
		std::cout << v.at(index) << std::endl;
		Sleep(3 * pow(i, 1.8));
	}
	std::string random = v.at(rand() % v.size());
	std::cout << std::endl << random << " <-\n\n";
	return random;
}
std::string rollDelete(std::vector<std::string>& v) {
	std::cout << std::endl;
	for (int i = 0; i < 20; i = i++) {
		int index = rand() % v.size();
		std::cout << v.at(index) << std::endl;
		Sleep(3 * pow(i, 1.8));
	}
	std::string random = v.at(rand() % v.size());
	int index_random;
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) == random) {
			index_random = i;
			break;
		}
	}
	v.erase(v.begin() + index_random);
	std::cout << std::endl << random << " <-\n\n";
	return random;
}
std::vector<std::string> getSlots() {
	std::vector<std::string> slots;
	std::string name;
	int index = 1;
	for (;;) {
		std::cout << "Slot #" << index << " name: ";
		std::getline(std::cin, name);
		if (name == "") break;
		slots.push_back(name);
		index++;
	}
	return slots;
}
std::vector<std::string> getSlots(int number) {
	std::vector<std::string> slots;
	std::string name;
	for (int i = 0; i < number; i++) {
		std::cout << "Slot #" << i + 1 << " name: ";
		std::getline(std::cin, name);
		if (name == "") break;
		slots.push_back(name);
	}
	return slots;
}
void roulette() {
	std::string change;
	do {
		std::vector<std::string> slots = getSlots();
		std::vector<std::string> history;
		std::string repeat;
		do {
			std::string random = roll(slots);
			if (random != "") history.push_back(random);
			std::cout << "History: ";
			print(history);
			std::cout << "Repeat? ";
			std::getline(std::cin, repeat);
		} while (repeat == "yes");
		std::cout << "Change slots? ";
		std::getline(std::cin, change);
	} while (change == "yes");
}
void chooseTeams() {
	std::vector<std::vector<std::string>> v;
	v.resize(2);
	for (int i = 0; i < v.size(); i++) {
		std::cout << "Name of the " << i + 1 << " team: ";
		std::string team_name;
		std::getline(std::cin, team_name);
		v.at(i).push_back(team_name);
	}

	int players_count;
	std::string players_count_str;
	std::cout << "Amount of players: ";
	std::getline(std::cin, players_count_str);
	try {
		players_count = stoi(players_count_str);
	}
	catch (...) {
		std::cout << "Wrong input!\n\n";
		return;
	}
	std::vector<std::string> slots = getSlots(players_count);
	std::string name;
	if (players_count % 2 == 0) {
		for (int i = 0; i < players_count / 2; i++) {
			std::cout << "The " << i + 1 << " player of " << v.at(0).at(0) << " team is...\n";
			Sleep(300);
			name = rollDelete(slots);
			v.at(0).push_back(name);
			Sleep(1000);
			std::cout << "The " << i + 1 << " player of " << v.at(1).at(0) << " team is...\n";
			Sleep(500);
			name = rollDelete(slots);
			v.at(1).push_back(name);
			Sleep(1500);
		}
	}
	else {
		for (int i = 0; i < players_count / 2; i++) {
			std::cout << "The " << i + 1 << " player of '" << v.at(0).at(0) << "' team is...\n";
			Sleep(300);
			name = rollDelete(slots);
			v.at(0).push_back(name);
			Sleep(1000);
			std::cout << "The " << i + 1 << " player of '" << v.at(1).at(0) << "' team is...\n";
			Sleep(500);
			name = rollDelete(slots);
			v.at(1).push_back(name);
			Sleep(1500);
		}
		std::cout << "The last player of '" << v.at(0).at(0) << "' team is...\n";
		Sleep(300);
		name = rollDelete(slots);
		v.at(0).push_back(name);
		Sleep(1500);
	}
	printTeam(v.at(0));
	printTeam(v.at(1));
}
int main() {
	srand(time(0));
	chooseTeams();
	return 0;
}