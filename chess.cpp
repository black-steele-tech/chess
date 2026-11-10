#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

int main() {
    int rows_and_cols_count = 8; // Changed from 7 to 8 to fit the 800x800 window
    float squareSize = 100.0f;

    std::vector<std::vector<int>> grid(rows_and_cols_count, std::vector<int>(rows_and_cols_count, 0));

    // Fixed '<=' to '<' to prevent an out-of-bounds crash
    for (int i = 0; i < rows_and_cols_count; i++) {
        for (int j = 0; j < rows_and_cols_count; j++) {
            grid[i][j] = (i + j) % 2;
        }
    }

    sf::RectangleShape mapSquare(sf::Vector2f(squareSize, squareSize));
    sf::RenderWindow window(sf::VideoMode({800, 800}), "C++: Draw Chess Board!");

    while (window.isOpen()) {
        // Removed unused 'sf::Event event;' and fixed 'cosnt' typo
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();

        for (int i = 0; i < rows_and_cols_count; i++) {
            for (int j = 0; j < rows_and_cols_count; j++) {
                if (grid[i][j] == 0) {
                    mapSquare.setFillColor(sf::Color::White);
                } else {
                    mapSquare.setFillColor(sf::Color::Black);
                }

                // Wrapped coordinates in braces {} for SFML 3's sf::Vector2f
                mapSquare.setPosition({j * squareSize, i * squareSize});
                window.draw(mapSquare);
            }
        }

        window.display();
    }

    return 0;
}