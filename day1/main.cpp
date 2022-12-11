#include <iostream>
#include <string>
#include <fstream>

long calories_count(const std::string &filename) {
    std::ifstream input_file;
    long first_max = 0;
    long second_max = 0;
    long third_max = 0;
    long cur_calories_count = 0;
    std::string line;
    input_file.open(filename);
    while (!input_file.eof()) {
        std::getline(input_file, line, '\n');
        if (line.empty()) {
            if (cur_calories_count > first_max) {
                third_max = second_max;
                second_max = first_max;
                first_max = cur_calories_count;
            } else if (cur_calories_count > second_max) {
                third_max = second_max;
                second_max = cur_calories_count;
            } else if (cur_calories_count > third_max) {
                third_max = cur_calories_count;
            }
            cur_calories_count = 0;
        } else {
            cur_calories_count += std::stol(line);
        }
    }
    input_file.close();
    if (cur_calories_count > first_max) {
        third_max = second_max;
        second_max = first_max;
        first_max = cur_calories_count;
    } else if (cur_calories_count > second_max) {
        third_max = second_max;
        second_max = cur_calories_count;
    } else if (cur_calories_count > third_max) {
        third_max = cur_calories_count;
    }
    return first_max + second_max + third_max;
}

int main() {
    long max_calories = calories_count("day1/input.txt");
    std::cout << max_calories << std::endl;
}