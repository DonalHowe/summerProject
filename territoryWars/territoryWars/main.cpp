#ifdef _DEBUG 
#pragma comment(lib,"thor-d.lib")
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"thor.lib")
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 



#include "Game.h"


/// <summary>
/// @brief starting point for all C++ programs.
/// 
/// Create a game object and run it.
/// </summary>
/// <param name=""></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int, char* argv[])
{
	Game game;


	game.run();
}