#ifndef MENU_H_
#define MENU_H_

#include "BaseObject.h"
#include "Button.h"

void HandlePlayButton(SDL_Event* e,
    SDL_Renderer* des,
    Button& PlayButton,
    bool& QuitMenu,
    bool& Play,
    Mix_Chunk* gClick,
    SDL_Rect(&gMap1Button)[BUTTON_TOTAL],
    SDL_Rect(&gMap2Button)[BUTTON_TOTAL],
    SDL_Rect(&gMap3Button)[BUTTON_TOTAL],
    Button& Map1Button,
    Button& Map2Button,
    Button& Map3Button,
    std::string& map_file_index,
    std::string& map_tile_index,
    std::string& map_background
    );

void HandleHelpButton(SDL_Event* e,
    SDL_Rect(&gBackButton)[BUTTON_TOTAL],
    Button& HelpButton,
    Button& BackButton,
    SDL_Renderer* gRenderer,
    bool& Quit_game,
    Mix_Chunk* gClick);

void HandleExitButton(SDL_Event* e,
    Button& ExitButton,
    bool& Quit,
    Mix_Chunk* gClick);

void HandleContinueButton(Button ContinueButton,
    SDL_Event* e,
    SDL_Renderer* gRenderer,
    SDL_Rect(&gContinueButton)[BUTTON_TOTAL],
    bool& Game_State, Mix_Chunk* gClick);

void HandlePauseButton(SDL_Event* e,
    SDL_Renderer* gRenderer,
    SDL_Rect(&gContinueButton)[BUTTON_TOTAL],
    Button& PauseButton,
    Button ContinueButton,
    bool& game_state,
    Mix_Chunk* gClick);
void DrawEndGameSelection(/*LTexture gLoseTexture,*/
    SDL_Event* e,
    SDL_Renderer* gRenderer,
    bool& Play_Again);

void HandleMapButton(SDL_Event* e,
    SDL_Renderer* des,
    SDL_Rect(&gMap1Button)[BUTTON_TOTAL],
    SDL_Rect(&gMap2Button)[BUTTON_TOTAL],
    SDL_Rect(&gMap3Button)[BUTTON_TOTAL],
    Button& Map1Button,
    Button& Map2Button,
    Button& Map3Button,
    bool& quit,
    Mix_Chunk* gClick,
    std::string& map_file_index,
    std::string& map_tile_index,
    std::string& map_background
    );

void HandleMap1Button(SDL_Event* e,
    SDL_Renderer* des,
    SDL_Rect(&gMap1Button)[BUTTON_TOTAL],
    Button& Map1Button,
    bool& quit_menu,
    Mix_Chunk* gClick,
    std::string& map_file_index,
    std::string& map_tile_index);

void HandleMap2Button(SDL_Event* e,
    SDL_Renderer* des,
    SDL_Rect(&gMap2Button)[BUTTON_TOTAL],
    Button& Map2Button,
    bool& quit_menu,
    Mix_Chunk* gClick,
    std::string& map_file_index,
    std::string& map_tile_index);

void HandleMap2Button(SDL_Event* e,
    SDL_Renderer* des,
    SDL_Rect(&gMap1Button)[BUTTON_TOTAL],
    Button& Map2Button,
    bool& quit_menu,
    Mix_Chunk* gClick,
    std::string& map_file_index,
    std::string& map_tile_index);

#endif // !MENU_H_
