#include <iostream>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <vector>
#include <bitset>

/* A Quick note on bit widths...
 * The sample for day 3 uses a bit width of 5, where the real 
 * data uses a bit width of 12. To transition between the 2,
 * find and replace, (or ':%s/12/5/g' and vice versa in vim)\
 * to swap between the bit widths. */

#define TO_NUMBER(k) (std::bitset<12>(std::string(k.data())).to_ulong())

std::vector<std::string> dataset;

static void load_dataset(std::string filepath) {
	std::ifstream data_stream(filepath);
	std::string buffer;

	while (std::getline(data_stream, buffer) && buffer != "") {
		dataset.push_back(buffer);
		buffer.clear();
	}
	
	data_stream.close();
}

static int solve_dataset() {
	std::vector<char> gamma;
	std::vector<char> epsilon;

	for(int i = 0; i < 12; i++) {
		int one = 0; int zero = 0;
		for(auto ja : dataset) {
			if (ja[i] == '0') {
				zero++;
			} else {
				one++;
			}
		}

		if (one > zero) {
			gamma.push_back('1');
			epsilon.push_back('0');
		} else {
			gamma.push_back('0');
			epsilon.push_back('1');
		}
	}
	
	
	return TO_NUMBER(gamma) * TO_NUMBER(epsilon);
}

static int solve_dataset2() {
	std::string oxygen_rating;
	std::string carbon_rating;
	std::vector<std::string> selected(dataset);

	// Calculate the oxygen rating
	for(int i = 0; i < 12; i++) {
		int one = 0; int zero = 0;
		for(auto ja : selected) {
			if (ja[i] == '0') {
				zero++;
			} else {
				one++;
			}
		}

		if (one > zero || one == zero) {
			selected.erase(std::remove_if(
			selected.begin(),
			selected.end(),
			[i](std::string str) {
			    return (str[i] == '0');
			}), selected.end());
		} else {
			selected.erase(std::remove_if(
			selected.begin(),
			selected.end(),
			[i](std::string str) {
			    return (str[i] == '1');
			}), selected.end());
		}
	}

	// Rinse and repeat for the carbon rating...
	oxygen_rating = selected[0];
	selected.clear();
	for (auto item : dataset) {
		selected.push_back(item);
	}

	// Calculate the carbon rating
	for(int i = 0; i < 12; i++) {
		int one = 0; int zero = 0;
		for(auto ja : selected) {
			if (ja[i] == '0') {
				zero++;
			} else {
				one++;
			}
		}

		if (one > zero || one == zero) {
			selected.erase(std::remove_if(
			selected.begin(),
			selected.end(),
			[i](std::string str) {
			    return (str[i] == '1');
			}), selected.end());
		} else {
			selected.erase(std::remove_if(
			selected.begin(),
			selected.end(),
			[i](std::string str) {
			    return (str[i] == '0');
			}), selected.end());
		}
	}

	carbon_rating = selected[0];
	return TO_NUMBER(oxygen_rating) * TO_NUMBER(carbon_rating);
}

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "error: no input passed!" << "!\n";
		std::exit(1);
	}

	std::string ja = argv[1];
	load_dataset(ja);
	
	std::cout << "Hello from Advent of Code (Day 3, 2021)!\n";
	std::cout << "Solution: "   << solve_dataset()  << "\n";
	std::cout << "Solution 2: " << solve_dataset2() << "\n";
}

