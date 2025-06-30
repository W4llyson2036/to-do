// std headers
#include <iostream>
#include <vector>
#include <string>

namespace todo {
	extern std::vector<std::string> list;
	extern int typeMode;

	void displayText();
	void addTask();
	void removeTodo();
	void displayToDoList();
	void mode();
	void switchMode();
}