#include "system.h"

int main()
{
	// "Database/accounts.txt"
	std::unique_ptr<System> system = std::make_unique<System>("Database/accounts.txt");

	system->importDB();

	system->printDB();

	system->exportDB();

	return 0;
}