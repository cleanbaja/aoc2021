#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

std::vector<int> dataset;
std::list<int> hot_queue;

static void load_dataset(std::string filepath) {
	std::ifstream data_stream(filepath);
	std::string buffer;

	while (std::getline(data_stream, buffer) && buffer != "") {
		dataset.push_back(std::stoi(buffer));
		buffer.clear();
	}
	
	data_stream.close();
}

static int solve_dataset() {
	int old_num, total_hits = 0;

	for (auto num : dataset) {
		if (num > old_num) {
			total_hits++;
		}

		old_num = num;
	}

	return total_hits - 1;
}

static int solve_dataset2() {	
	int old_sum, total_hits, queue_sum = 0;

	for (auto num : dataset) {
		hot_queue.pop_back();
		hot_queue.push_front(num);

		// Calculate the sum of the queue
		for (int j : hot_queue) {
			queue_sum += j;
		}

		if (queue_sum > old_sum) {
			total_hits++;
		}

		old_sum = queue_sum;
		queue_sum = 0;
	}

	return total_hits - 3;
}

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "error: Input list not passed to " << argv[0] << "!\n";
		std::exit(1);
	}

	// Setup the queue
	for(int i = 0; i < 3; i++)
		hot_queue.push_front(0);

	std::string fname = argv[1];
	load_dataset(fname);
	std::cout << "Hello from Advent of Code (Day 1, 2021)!\n";
	std::cout << "Solution: "   << solve_dataset()  << "\n";
	std::cout << "Solution 2: " << solve_dataset2() << "\n";
}

