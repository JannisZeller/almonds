// A Basic C++ Script to generate Mandelbrot Set Data
// -----------------------------------------------------------------------------
// Inspiration: https://www.gcardone.net/2021-03-04-blistering-fast-mandelbrot-in-rust/


// Includes
// -----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <thread>


// Defining the algorithms
// -----------------------------------------------------------------------------

// Single-Point core Algorithm
void almond(float x0, float y0, int &grid_elem, int max_iter) {
    float x_sq = 0;
    float y_sq = 0;
    float x = 0;
    float y = 0;
    int iter = 0;
    do {
        y = (x + x) * y + y0;
        x = x_sq - y_sq + x0;
        x_sq = x * x;
        y_sq = y * y;
        iter++;
    } while (x_sq + y_sq <= 4 and iter < max_iter);
    grid_elem = iter;
}

// Image grid looping
std::vector<std::vector<int>> create_pixels(
    int width,
    int height,
    float x_min,
    float x_max,
    float y_min,
    float y_max,
    int max_iter
    ) {

    // Initializing empty Grid
    std::vector<std::vector<int>> grid(height, std::vector<int> (width, 0));

    // Progress
    int progress = 1;
    std::cout << "Creating Mandelbrot Set with " << width << "x" << height << " pixels." << std::endl;
    std::cout << "Progress:" << std::endl;
    std::cout << "[";

    for (int i = 0; i < height; i++) {
        for (int k = 0; k < width; k++) {
            float y0 = (y_max - y_min) * i / (height-1) + y_min;
            float x0 = (x_max - x_min) * k / ( width-1) + x_min;

            almond(x0, y0, grid[i][k], max_iter);
        }
        if ((float)i / (float)height >= (float)progress * 0.1) {
            std::cout << "#";
            progress++;
        }
    }
    std::cout << "] 100%" << std::endl;
    return grid;
}

// Save grid to file
void save_grid(std::vector<std::vector<int>> grid) {
    std::ofstream file;
    file.open("./data/data.csv");
    for (int i = 0; i<grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++)
        {
            file << grid[i][j] << ",";
        }
        file << std::endl;
    }
    file.close();
}


// Main
// -----------------------------------------------------------------------------

int main() {
    // Declaring variables
    int max_iter;
    int width;
    int height;
    float x_min;
    float x_max;
    float y_min;
    float y_max;

    // Welcome Message
    std::cout << "almonds.cpp" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << "Creating Mandelbrot Set data. Please specify your data layout:" << std::endl;

    // Getting the input
    std::cout << "\nMaximum iterations per pixel (100 to 1000 recommended): ";
    std::cin >> max_iter;
    std::cout << "X-Min: ";
    std::cin >> x_min;
    std::cout << "X-Max: ";
    std::cin >> x_max;
    std::cout << "Y-Min: ";
    std::cin >> y_min;
    std::cout << "Y-Max: ";
    std::cin >> y_max;
    std::cout << "Width: ";
    std::cin >> width;
    std::cout << "Height: ";
    std::cin >> height;
    std::cout << std::endl;

    // Generating the pixels (recommended 3840x2160 or 1920x1080)
    std::vector<std::vector<int>> grid = create_pixels(
        width, height, x_min, x_max, y_min, y_max, max_iter);

    // Saving the pixels
    save_grid(grid);

    // Keeping the terminal up
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "\nCreated Mandelbrot Set data with C++ Version " << __cplusplus << "." << std::endl;
    std::cout << "\nPress any key to close." << std::endl;
    std::cin.get();

    // Final return.
    return 1;
}
