#include <raylib.h>
#include <iostream>
#include <sstream>


// Direction Enum
enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};



int main() {
    
    // Initialize the Window
    int screenWidth = 400;
    int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Snake");

    SetTargetFPS(10);

    // Initialize snake
    Vector2 headPos = { 0, 0 };
    Direction headDirection = Direction::DOWN;

    // Intialize apple
    Vector2 applePos = {GetRandomValue(0, (screenWidth-20)/20)*20, GetRandomValue(0, (screenHeight-20)/20)*20};

    // Initialize score
    long double score = 0;

    while (!WindowShouldClose()) {

        // Update Direction
        if (IsKeyPressed(KEY_RIGHT)) headDirection = Direction::RIGHT;
        if (IsKeyPressed(KEY_LEFT)) headDirection = Direction::LEFT;
        if (IsKeyPressed(KEY_DOWN)) headDirection = Direction::DOWN;
        if (IsKeyPressed(KEY_UP)) headDirection = Direction::UP;

        // Update Position
        switch (headDirection) {
            case Direction::UP:
                headPos.y -= 20;
                break;
            case Direction::DOWN:
                headPos.y += 20;
                break;
            case Direction::LEFT:
                headPos.x -= 20;
                break;
            case Direction::RIGHT:
                headPos.x += 20;
                break;
        }

        // Check if the snake is off the screen
        if (headPos.x < 0) headPos.x = screenWidth - 20;
        if (headPos.x > screenWidth - 20) headPos.x = 0;
        if (headPos.y < 0) headPos.y = screenHeight - 20;
        if (headPos.y > screenHeight - 20) headPos.y = 0;

        // If the head hits the apple
		if (headPos.x == applePos.x && headPos.y == applePos.y) {
            // Move the apple to a new position and increase the score
			applePos = { GetRandomValue(0, (screenWidth-20)/20)*20, GetRandomValue(0, (screenHeight-20)/20)*20 };
			score++;
		}

        // Converting the score to a string
		std::stringstream ss;
		ss << score;
		const char* score_c = ss.str().c_str();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Print Score
            DrawText(score_c, screenWidth / 2 - MeasureText(score_c, 40)/2, screenHeight / 2 - 20, 40, GRAY);

            // Draw Snake
            DrawRectangle(headPos.x, headPos.y, 20, 20, DARKGREEN);

            // Draw Apple
            DrawRectangle(applePos.x, applePos.y, 20, 20, MAROON);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
