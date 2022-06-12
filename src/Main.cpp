#include <raylib.h>
#include <iostream>
#include <sstream>



enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};



int main() {
    
    int screenWidth = 400;
    int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Snake");

    SetTargetFPS(10);

    Vector2 headPos = { 0, 0 };
    Direction headDirection = Direction::DOWN;

    Vector2 applePos = {GetRandomValue(0, (screenWidth-20)/20)*20, GetRandomValue(0, (screenHeight-20)/20)*20};


    long double score = 0;

    


    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_RIGHT)) headDirection = Direction::RIGHT;
        if (IsKeyPressed(KEY_LEFT)) headDirection = Direction::LEFT;
        if (IsKeyPressed(KEY_DOWN)) headDirection = Direction::DOWN;
        if (IsKeyPressed(KEY_UP)) headDirection = Direction::UP;


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

        if (headPos.x < 0) headPos.x = screenWidth - 20;
        if (headPos.x > screenWidth - 20) headPos.x = 0;
        if (headPos.y < 0) headPos.y = screenHeight - 20;
        if (headPos.y > screenHeight - 20) headPos.y = 0;


		if (headPos.x == applePos.x && headPos.y == applePos.y) {
			applePos = { GetRandomValue(0, (screenWidth-20)/20)*20, GetRandomValue(0, (screenHeight-20)/20)*20 };
			score++;
		}

		std::stringstream ss;
		ss << score;
		const char* score_c = ss.str().c_str();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText(score_c, screenWidth / 2 - MeasureText(score_c, 40)/2, screenHeight / 2 - 20, 40, GRAY);

            DrawRectangle(headPos.x, headPos.y, 20, 20, DARKGREEN);

            DrawRectangle(applePos.x, applePos.y, 20, 20, MAROON);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
