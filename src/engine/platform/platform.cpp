#include "platform.h"

namespace Engine
{
	CPlatform::CPlatform()
	: p_window( nullptr )
	{
		// GLFW Init
		if(!glfwInit()){
			std::cerr << "ERROR: glfwInit() failed. See " << __FILE__ << " " << __LINE__ << std::endl;
		}
	}
	
	CPlatform::~CPlatform()
	{
		DestroyWindow();
		glfwTerminate();
	}
	
	bool CPlatform::CreateWindow(int width, int height, const char *title, bool fullscreen)
	{
		DestroyWindow();
		
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		//Monitor required for fullscreen. 
		GLFWmonitor* monitor = nullptr;
		if( fullscreen )
			monitor = glfwGetPrimaryMonitor();
			
		
		if ((p_window = glfwCreateWindow(width, height, title, monitor, NULL)) == false){
			std::cerr << "ERROR: glfwCreateWindow() failed. See " << __FILE__ << " " << __LINE__ <<  std::endl;
			return false;
		}
		
	
		glfwMakeContextCurrent(p_window);

		// OpenGL 3.3+ Init
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK) {
			std::cerr << "ERROR: glewInit() failed. See " << __FILE__ << " " << __LINE__  << std::endl;
			return false;
		}
		return true;
	}
	
	void CPlatform::DestroyWindow()
	{
		if( p_window ){
			glfwDestroyWindow(p_window);
			p_window = nullptr;
		}
	}
	
	void CPlatform::Update()
	{
		
		glfwSwapBuffers(p_window);
		glfwPollEvents();
	}
	
	bool CPlatform::Exit()
	{
		return (glfwWindowShouldClose(p_window));
	}
	
	CPlatform::SScreen CPlatform::ScreenResolution()
	{
		SScreen screen;
		glfwGetFramebufferSize(p_window, &screen.width, &screen.height);
		return ( screen );
	}
	
}