#include <iostream>

#include "../To-Do/todo.h"

namespace todo {
	int typeMode;
	std::vector<std::string> list;
	
	void displayText()
	{

		if (list.empty()) {
			mode();
		}
	}

	void addTask()
	{
		std::cout << "task name: ";
		
		std::string name;
		std::cin >> name;

		list.push_back(name);
		
		displayToDoList();
	}

	void removeTodo()
	{
		if (list.empty()) {
			std::cout << "\nyou have not added any task in order to be deleted!" << "\n\n";
			mode();
			return;
		}

		std::cout << "type the number of task you want to delete: " << "\n\n";
		int index;
		std::cin >> index;

		list.erase(list.begin() + index);
		displayToDoList();
	}

	void displayToDoList()
	{
		if (list.empty()) {
			std::cout << "\nyou have not added any task yet!!" << "\n\n";
			mode();
			return;
		}

		std::cout << "\n#### To-do-list" << "\n";

		for (int index = 0; index < list.size(); index++) {
			std::cout << index << " [ ] -> " << list[index] << "\n";
		}

		std::cout << "\n";
	}

	void switchMode()
	{
		std::cout << "Switch mode (y): ";
		std::string A;
		std::cin >> A;

		if (A == "y") {
			typeMode = 0;
			mode();
			return;
		}
	}

	void mode()
	{
		std::cout << "1_[ ]: add new task\n2_[ ]: remove task\n3_[ ]: display todo\n4_[ ]: exit program\ny_[ ]: switch mode" << "\n";
		std::cout << "Select a mode: ";
		std::cin >> typeMode;

		while (typeMode == 1) {
			std::cout << "1_[X]: add new task\n2_[ ]: remove task\n3_[ ]: display todo\n4_[ ]: exit program\ny_[ ]: switch mode" << "\n";
			
			addTask();
			switchMode();
		}

		while (typeMode == 2) {
			std::cout << "1_[ ]: add new task\n2_[X]: remove task\n3_[ ]: display todo\n4_[ ]: exit program\ny_[ ]: " << "\n";

			displayToDoList();
			removeTodo();
			switchMode();
		}

		while (typeMode == 3) {
			std::cout << "1_[ ]: add new task\n2_[ ]: remove task\n3_[X]: display todo\n4_[ ]: exit program\ny_[ ]: switch mode" << "\n";

			displayToDoList();
			switchMode(); 
		}
	}
}