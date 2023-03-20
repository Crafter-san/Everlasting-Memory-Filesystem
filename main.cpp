#include <iostream>
#include "ememfs.hpp"
void main() {
	Device device = Device();
	Drive drive = Drive("D");
	Folder folder = Folder("Fun Folder");
	User user = User("Fun User");
	File file = File("Fun file", "HOI!");
	File& fileinstance = device.drives.Set(drive).users.Set(user).folders.Set(folder).files.Set(file);
	fileinstance.Append("Test", true);
	fileinstance.Append("Reeee");
	fileinstance.metadata.Set("meta", "this be getting 'meta'-data!");

	std::cout << std::endl << device.drives.Get(drive).users.Get(user).folders.Get(folder).files.Get(file).data;
	std::cout << std::endl << device.drives.Get(drive).users.Get(user).folders.Get(folder).files.Get(file).metadata.Get("meta");
}