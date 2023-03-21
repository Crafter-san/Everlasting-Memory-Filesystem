#include <iostream>
#include "ememfs.hpp"
void main() {
	Device device = Device();
	Drive drive = Drive("D");
	Folder folder = Folder("Fun Folder");
	User user = User("Fun User");
	File file = File("Fun file", "HOI!");
	Drive& driveInstance = device.drives.Set(drive);
	User& userInstance = driveInstance.users.Set(user);
	Folder& folderInstance = userInstance.folders.Set(folder);
	File& fileInstance = folderInstance.files.Set(file);
	fileInstance.Append("Test", true);
	fileInstance.Append("Reeee");
	fileInstance.metadata.Set("meta", "this be getting 'meta'-data!");
	File newfile("File two", "reeeee");
	folderInstance.files.Create(newfile);
	File newFile("File three", "raaa");
	folderInstance.files.Create(newFile);
	File& newFileInstance = folderInstance.files.Get(fileInstance);
	newFileInstance.Append("reaafadasaf");
	std::cout << fileInstance.data;
	std::cout << fileInstance.metadata.Get("meta");
	for (int i = 0; i < folderInstance.files.dir.size(); i++) {
		std::cout << std::endl << folderInstance.files.dir[i] << std::endl;
	}
}
