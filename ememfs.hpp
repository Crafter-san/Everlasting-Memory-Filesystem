#include <ctime>
#include <unordered_map>
#include <string>

template <typename T>

struct Manage {
	std::unordered_map<std::string, T> list;
	std::vector<std::string> dir;

	T& Create(T obj = T()) {
		if (!list.count(obj.name)) {
			list[obj.name] = obj;
			dir.push_back(obj.name);
		}
		return list[obj.name];
	}

	T Destroy(T& obj = T()) {
		T result = obj;
		if (list.count(obj.name)) {
			list.erase(obj.name);
			std::vector<std::string> new_dir;
			for (int i = 0; i < dir.size(); i++) {
				if (obj.name != dir[i]) new_dir.push_back(dir[i]);
				else result = dir[i];
			}
			dir = new_dir;
			//return obj;
		}
		return result;
	}
	T& Get(T& obj_ = T()) {
		return list[obj_.name];
	}
	T& Set(T& obj = T()) {
		if (!list.count(obj.name)) {
			dir.push_back(obj.name);
		}
		list[obj.name] = obj;
		return list[obj.name];
	}
	Manage(std::unordered_map<std::string, T> l = std::unordered_map<std::string, T>()) {
		list = l;
	}
};

struct Metadata {
	std::unordered_map<std::string, std::string> metadata;
	void Set(std::string key, std::string value) {
		metadata[key] = value;
	}
	std::string& Get(std::string key) {
		return metadata[key];
	}
};

struct Line {
	std::string name;
	std::string data;
	Line(std::string n = "default line name", std::string d = "default line value") {
		name = n;
		data = d;
	}
};
struct File {
	std::string name;
	std::string data;
	std::time_t timestamp;
	Metadata metadata;
	Manage<Line> lines;
	void Append(std::string line, bool newline = false) {
		if (newline) {
			Line new_line = Line(std::to_string(lines.dir.size()), line);
			lines.Set(new_line);
			line = "\n" + line;
		}
		else {
			lines.list[std::to_string(lines.dir.size() - 1)].data += line;
		}
		data += line;
	}
	Line Reduce() {
		Line wanted_line = Line(std::to_string(lines.dir.size() - 1));
		Line line = lines.Destroy(wanted_line);
		return line;
	}
	Line DeleteLine(int i) {
		Line wanted_line = Line(std::to_string(i - 1));
		Line line = lines.Destroy(wanted_line);
		return line;
	}
	void ModifyLine(int i, std::string value) {
		Line new_line = Line(std::to_string(i), value);
		lines.Set(new_line);
	}
	File(std::string fn = "Default File Name", std::string d = "Default File Data", std::time_t ts = std::time(NULL)) {
		name = fn;
		data = d;
		timestamp = ts;
	}
};

struct Folder {
	std::string name;
	std::string data;
	Metadata metadata;
	std::time_t timestamp;
	Manage<Folder> folders;
	Manage<File> files;
	Folder(std::string fn = "Default Folder Name", Manage<File> f = Manage<File>(), std::time_t ts = std::time(NULL)) {
		name = fn;
		files = f;
		timestamp = ts;
	}
};
struct User {
	std::string name;
	std::string data;
	Metadata metadata;
	std::time_t timestamp;
	Manage<User> users;
	Manage<Folder> folders;
	Manage<File> files;
	User(std::string un = "Default User Name", Manage<Folder> f = Manage<Folder>(), std::time_t ts = std::time(NULL)) {
		name = un;
		folders = f;
		timestamp = ts;
	}
};
struct Drive {
	std::string name;
	std::string data;
	Metadata metadata;
	std::time_t timestamp;
	Manage<Drive> drives;
	Manage<User> users;
	Manage<Folder> folders;
	Manage<File> files;
	Drive(std::string dn = "Default Drive Name", Manage<User> u = Manage<User>(), std::time_t ts = std::time(NULL)) {
		name = dn;
		users = u;
		timestamp = ts;
	}
};
struct Device {
	std::string name;
	std::string data;
	Metadata metadata;
	std::time_t timestamp;
	Manage<Device> devices;
	Manage<Drive> drives;
	Manage<User> users;
	Manage<Folder> folders;
	Manage<File> files;
	Device(std::string dn = "Default Device Name", Manage<Drive> d = Manage<Drive>(), std::time_t ts = std::time(NULL)) {
		name = dn;
		drives = d;
		timestamp = ts;
	}
};
