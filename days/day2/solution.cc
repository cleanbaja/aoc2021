#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdint>

enum class Mode : uint8_t {
	FORWARD = 5,
	DOWN,
	UP
};

struct Command {
	Mode md;
	int count;
	Command(Mode m = Mode::FORWARD, int s = 0) : md(m), count(s) {}
	static Command from_string(std::string str) {
		std::istringstream sream(str);
		std::string check_buf;
		Command cm;

		sream >> check_buf;

		if (check_buf == "forward") {
			cm.md = Mode::FORWARD;
		} else if (check_buf == "down") {
			cm.md = Mode::DOWN;
		} else if (check_buf == "up") {
			cm.md = Mode::UP;
		}

		sream >> cm.count;
		return cm;
	}
};

std::vector<Command> dataset;

static void load_dataset(std::string filepath) {
	std::ifstream data_stream(filepath);
	std::string buffer;

	while (std::getline(data_stream, buffer) && buffer != "") {
		dataset.push_back(Command::from_string(buffer));
		buffer.clear();
	}
	
	data_stream.close();
}

static int solve_dataset() {
	int horiz, depth = 0;

	for (auto cmd : dataset) {
		switch (cmd.md) {
		case Mode::FORWARD:
			horiz += cmd.count;
			break;
		case Mode::DOWN:
			depth += cmd.count;
			break;
		case Mode::UP:
			depth -= cmd.count;
			break;
		}
	}

	return horiz * depth;
}

static int solve_dataset2() {
	int horiz, depth, aim = 0;

	for (auto cmd : dataset) {
		switch (cmd.md) {
		case Mode::FORWARD:
			horiz += cmd.count;
			depth += aim * cmd.count;
			break;
		case Mode::DOWN:
			aim += cmd.count;
			break;
		case Mode::UP:
			aim -= cmd.count;
			break;
		}
	}

	return horiz * depth;
}

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "error: no input passed!" << argv[0] << "!\n";
		std::exit(1);
	}

	std::string ja = argv[1];
	load_dataset(ja);
	
	std::cout << "Hello from Advent of Code (Day 2, 2021)!\n";
	std::cout << "Solution: "   << solve_dataset()  << "\n";
	std::cout << "Solution 2: " << solve_dataset2() << "\n";
}

