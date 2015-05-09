#ifndef ENGINE_PLATFORM_H
#define ENGINE_PLATFORM_H

#include <iostream>

#include <gl/glew.h> 
#include <GLFW/glfw3.h>

namespace Engine
{
	class CPlatform
	{
		public:
			struct SScreen
			{
				int width, height;
			};
		
			CPlatform();
			~CPlatform();

			/**
				Create window with OpenGL context.
				Note: The OpenGL context will be destroyed
				with the window. Calling gl* functions without
				context is undefined behaviour. 
			**/
			bool CreateWindow(int width, int height, const char *title, bool fullscreen);
			void DestroyWindow();
			
			//Get screen res
			SScreen ScreenResolution();
			
			//Update each frame
			void Update();
			
			//True if the application should exit 
			bool Exit();
			
		private:
			GLFWwindow* p_window;
	};
}

#endif //ENGINE_PLATFORM_H