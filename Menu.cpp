#include "Menu.h"
#include "CommonFunc.h"
#include "Button.h"

void HandleMapButton(SDL_Event* e,
	SDL_Renderer* des,
	SDL_Rect(&gMap1Button)[BUTTON_TOTAL],
	SDL_Rect(&gMap2Button)[BUTTON_TOTAL],
	SDL_Rect(&gMap3Button)[BUTTON_TOTAL],
	Button& Map1Button,
	Button& Map2Button,
	Button& Map3Button,
	bool& quit_menu,
	Mix_Chunk* gClick,
	std::string& map_file_index,
	std::string& map_tile_index,
	std::string& map_background
	)
{
	if (Map1Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Map1Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Map1Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			Mix_PauseMusic();
			map_file_index = "map//Map1//map.dat";
			map_tile_index = "map//Map1//.png";
			map_background = "map//Map1//background.png";
			break;
		}
	}
	else
	{
		Map1Button.currentSprite = BUTTON_MOUSE_OUT;
	}
	//
	if (Map2Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Map2Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Map2Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			Mix_PauseMusic();
			map_file_index = "map//Map2//map.dat";
			map_tile_index = "map//Map2//.png";
			map_background = "map//Map2//background.png";
			break;
		}
	}
	else
	{
		Map2Button.currentSprite = BUTTON_MOUSE_OUT;
	}
	//
	if (Map3Button.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			Map3Button.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Map3Button.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			Mix_PauseMusic();
			map_file_index = "map//Map3//map.dat";
			map_tile_index = "map//Map3//.png";
			map_background = "map//Map3//background.png";
			break;
		}
	}
	else
	{
		Map3Button.currentSprite = BUTTON_MOUSE_OUT;
	}
	BaseObject menu_background;
	menu_background.LoadImg("img//Choosemap.png", des);
	menu_background.Render(des, NULL);
	SDL_Rect* currentClip_Map1 = &gMap1Button[Map1Button.currentSprite];
	Map1Button.Show(des, currentClip_Map1);

	SDL_Rect* currentClip_Map2 = &gMap2Button[Map2Button.currentSprite];
	Map2Button.Show(des, currentClip_Map2);

	SDL_Rect* currentClip_Map3 = &gMap3Button[Map3Button.currentSprite];
	Map3Button.Show(des, currentClip_Map3);
}


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
	std::string& map_file_index_,
	std::string& map_tile_index_,
	std::string& map_background
	)
{
	if (e->type == SDL_QUIT)
	{
		QuitMenu = true;
	}

	if (PlayButton.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			PlayButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Play = true;
			Mix_PlayChannel(MIX_CHANNEL, gClick, 0);
			PlayButton.currentSprite = BUTTON_MOUSE_OVER;
			QuitMenu = true;
			bool quit_choose_map = false;
			while (!quit_choose_map)
			{
				do
				{
					HandleMapButton(e, des, gMap1Button, gMap2Button, gMap3Button, Map1Button, Map2Button, Map3Button, QuitMenu, gClick, map_file_index_, map_tile_index_, map_background);
					SDL_RenderPresent(des);
					if (map_file_index_ != "" && map_tile_index_ != "")
					{
						quit_choose_map = true;
					}
				}
				while (SDL_PollEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
			}
		}
	}
	else
	{
		PlayButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

void HandleHelpButton(SDL_Event* e,
	SDL_Rect(&gBackButton)[BUTTON_TOTAL],
	Button& HelpButton,
	Button& BackButton,
	SDL_Renderer* des,
	bool& Quit_game,
	Mix_Chunk* gClick)
{
	if (HelpButton.IsInside(e, COMMON_BUTTON))
	{
		BaseObject g_introduction;
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			HelpButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			HelpButton.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);

			bool ReadDone = false;
			while (!ReadDone)
			{
				do
				{
					if (e->type == SDL_QUIT)
					{
						ReadDone = true;
						Quit_game = true;
					}
					else if (BackButton.IsInside(e, COMMON_BUTTON))
					{
						switch (e->type)
						{
						case SDL_MOUSEMOTION:
							BackButton.currentSprite = BUTTON_MOUSE_OVER;
							break;
						case SDL_MOUSEBUTTONDOWN:
							BackButton.currentSprite = BUTTON_MOUSE_OVER;
							Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
							ReadDone = true;
							break;
						}
					}
					else
					{
						BackButton.currentSprite = BUTTON_MOUSE_OUT;
					}

					g_introduction.LoadImg("img//instruction.png", des);
					g_introduction.Render(des, NULL);

					SDL_Rect* currentClip_Back = &gBackButton[BackButton.currentSprite];
					BackButton.Show(des, currentClip_Back);

					SDL_RenderPresent(des);
				} while (SDL_PollEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
			}
			break;
		}
	}
	else
	{
		HelpButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

void HandleExitButton(SDL_Event* e,
	Button& ExitButton,
	bool& Quit,
	Mix_Chunk* gClick)
{
	if (ExitButton.IsInside(e, COMMON_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			ExitButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			Quit = true;
			ExitButton.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			break;
		}
	}
	else
	{
		ExitButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

void HandleContinueButton(Button ContinueButton,
	/*LTexture gContinueButtonTexture,*/
	SDL_Event* e,
	SDL_Renderer* des,
	SDL_Rect(&gContinueButton)[BUTTON_TOTAL],
	bool& Game_State,
	Mix_Chunk* gClick)
{
	bool Back_To_Game = false;
	while (!Back_To_Game)
	{
		do
		{
			if (ContinueButton.IsInside(e, SMALL_BUTTON))
			{
				switch (e->type)
				{
				case SDL_MOUSEMOTION:
					ContinueButton.currentSprite = BUTTON_MOUSE_OVER;
					break;
				case SDL_MOUSEBUTTONDOWN:
				{
					ContinueButton.currentSprite = BUTTON_MOUSE_OVER;
					Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
					Mix_ResumeMusic();
					Game_State = true;
					Back_To_Game = true;
				}
				break;
				}
			}
			else
			{
				ContinueButton.currentSprite = BUTTON_MOUSE_OUT;
			}
			SDL_Rect* currentClip_Continue = &gContinueButton[ContinueButton.currentSprite];
			ContinueButton.Show(des, currentClip_Continue);
		} while (SDL_WaitEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
	}
}

void HandlePauseButton(SDL_Event* e,
	SDL_Renderer* des,
	SDL_Rect(&gContinueButton)[BUTTON_TOTAL],
	Button& PauseButton,
	Button ContinueButton,
	/*LTexture gContinueButtonTexture,*/
	bool& Game_State,
	Mix_Chunk* gClick)
{
	if (PauseButton.IsInside(e, SMALL_BUTTON))
	{
		switch (e->type)
		{
		case SDL_MOUSEMOTION:
			PauseButton.currentSprite = BUTTON_MOUSE_OVER;
			break;
		case SDL_MOUSEBUTTONDOWN:
			PauseButton.currentSprite = BUTTON_MOUSE_OVER;
			Mix_PlayChannel(MIX_CHANNEL, gClick, NOT_REPEATITIVE);
			Mix_PauseMusic();
			break;
		case SDL_MOUSEBUTTONUP:
			Game_State = false;
			HandleContinueButton(ContinueButton, e, des, gContinueButton, Game_State, gClick);
			break;
		}
	}
	else
	{
		PauseButton.currentSprite = BUTTON_MOUSE_OUT;
	}
}

void DrawEndGameSelection(/*LTexture gLoseTexture,*/
	SDL_Event* e,
	SDL_Renderer* gRenderer,
	bool& Play_Again)
{
	if (Play_Again)
	{
		bool End_Game = false;
		while (!End_Game)
		{
			while (SDL_PollEvent(e) != 0)
			{
				if (e->type == SDL_QUIT)
				{
					Play_Again = false;
				}

				if (e->type == SDL_KEYDOWN)
				{
					switch (e->key.keysym.sym)
					{
					case SDLK_SPACE:
						End_Game = true;
						break;
					case SDLK_ESCAPE:
						End_Game = true;
						Play_Again = false;
						break;
					}
				}
			}
			BaseObject g_lose_menu;
			g_lose_menu.LoadImg("img//lose.png", gRenderer);
			SDL_Rect renderquad = { 320, 160, 640, 320 };
			SDL_RenderCopy(gRenderer, g_lose_menu.GetObject() , NULL, &renderquad);
			SDL_RenderPresent(gRenderer);
		}
	}
}

