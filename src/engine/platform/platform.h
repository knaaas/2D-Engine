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
		
			typedef SScreen SMouse;
		
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
			
			enum EKeyState : int
			{
				Released = GLFW_RELEASE,
				Pressed = GLFW_PRESS
			};
			
			enum EMouseKey : int 
			{
				MouseKeyLeft   = GLFW_MOUSE_BUTTON_LEFT,
				MouseKeyRight  = GLFW_MOUSE_BUTTON_RIGHT,
				MouseKeyCenter = GLFW_MOUSE_BUTTON_MIDDLE
			};
			
			EKeyState Keyboard( const char key );
			
			EKeyState MouseKey( const EMouseKey& key );
			
			//Get mouse position
			SMouse MousePosition();
				
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