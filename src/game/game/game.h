#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Game
{
	class CGame
	{
		public:
			CGame(GLFWwindow* window);
			~CGame();
			void Run();
			
		private:
			GLFWwindow* m_window;
	};
}

#endif // GAME_GAME_H
