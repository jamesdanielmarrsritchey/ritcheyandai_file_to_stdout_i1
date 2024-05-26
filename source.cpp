#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::string source_filename;
    int bytes = 0;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--bytes" && i + 1 < argc) {
            bytes = std::stoi(argv[++i]);
        } else if (arg == "--source_file" && i + 1 < argc) {
            source_filename = argv[++i];
        }
    }

    // Open the source file
    std::ifstream source_file(source_filename, std::ios::binary);
    if (!source_file) {
        std::cerr << "Could not open source file: " << source_filename << std::endl;
        return 1;
    }

    // Create a buffer
    std::vector<char> buffer(bytes);

    // Read the source file and output to stdout
    while (source_file.read(buffer.data(), bytes)) {
        std::cout.write(buffer.data(), source_file.gcount());
    }

    // Close the source file
    source_file.close();

    return 0;
}

/*
To compile this program, you can use the g++ compiler. Here is the command:

g++ source.cpp -o program

This will compile the source.cpp file and create an executable named 'program'.

To run the program, use the following command:

./program --source_file source_filename --bytes value

Replace 'source_filename' with the name of the source file to read, and 'value' with the number of bytes to read at a time.

To install g++ on Debian, you can use the following command:

sudo apt-get install build-essential

This will install not only g++, but also other tools necessary for building software.
*/