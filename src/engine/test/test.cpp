#include <iostream>

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "../gpu/state.h"
#include "../gpu/shader.h"
#include "../gpu/storage.h"
#include "../gpu/instance.h"
#include "../gpu/renderer.h"

#include "../scene/camera.h"
#include "../scene/instance.h"



struct SSprite
{
	glm::vec2 position;
	glm::vec2 size;
	
	static void Attribute( bool instanced, GLuint devisor );
};

void SSprite::Attribute( bool instanced, GLuint devisor )
{
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( SSprite ), 0 );
	if( instanced )
		glVertexAttribDivisor( 0, devisor );
	
	glEnableVertexAttribArray( 1 );
	glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, sizeof( SSprite ), (const GLvoid*)sizeof( glm::vec2 ) );
	if( instanced )
		glVertexAttribDivisor( 1, devisor );
}


typedef Engine::CGPUStorage< SSprite >  GPUSpriteStorage;
typedef Engine::CGPUInstance< SSprite > GPUSpriteInstance;
typedef	Engine::CGPURenderer< SSprite > GPUSpriteRenderer;


int main( int args, char *argv[])
{
	
	//Platform init code
	GLFWwindow* window;
    if (!glfwInit())
        return 0;
    
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	
	
	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    
	if (!window)
    {
        glfwTerminate();
        return 0;
    }
    
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK)
	{
		glfwTerminate();
        return 0;
	}
	
	//End of platform init code

	const GLchar FragmentSource[] = {
		"#version 330 core							  \n"
		"out vec4 fcolor;							  \n"
		"void main(){  							      \n"
		"	fcolor = vec4( 1,0,0,0);				  \n"
		"}											  \n" 
	};
	
	const GLchar VertexSource[] = {
		"#version 330 core							  \n"
		"layout(location = 0) in vec2 in_position;    \n"
		"layout(location = 1) in vec2 in_size; 	      \n"
		"											  \n"
		"uniform sce_camera{						  \n"
		"	vec2 camera;							  \n"
		"   float zoom;								  \n"
		"};		  									  \n"
		"											  \n"
		"void main(){							      \n"
		"	gl_Position = vec4( in_position + camera, 0, 1 );  \n"
		"}											  \n" 
	};
	
	
	
	Engine::CShader VertexShader( Engine::VertexShader );
	if( !VertexShader.Compile( VertexSource ) ){
		std::cout << VertexShader.Log() << std::endl;
	}
	
	Engine::CShader FragmentShader( Engine::FragmentShader );
	if( !FragmentShader.Compile( FragmentSource ) ){
		std::cout << FragmentShader.Log() << std::endl;
	}
	
	Engine::CProgram SpriteProgram;
	SpriteProgram.Attach( &VertexShader );
	SpriteProgram.Attach( &FragmentShader );
	if( !SpriteProgram.Link())
	{
		std::cout << SpriteProgram.Log() << std::endl;
	}
	
	Engine::CSCECamera Camera;
	Engine::CSCEInstance Instance( &Camera );
	
	
	const size_t sprite_count = 128;
	SSprite *SpritesOfGods = new SSprite[sprite_count];
	for( size_t i = 0; i < sprite_count; i++ )
		SpritesOfGods[i].position = glm::vec2( 0,0 );
	
	GPUSpriteStorage*  SpriteStorage  = new GPUSpriteStorage();
	GPUSpriteInstance* SpriteInstance = new GPUSpriteInstance();
	GPUSpriteRenderer* SpriteRenderer = new GPUSpriteRenderer();
	
	SpriteRenderer->Program().Attach( &VertexShader   );
	SpriteRenderer->Program().Attach( &FragmentShader );
	if( !SpriteRenderer->Program().Link())
	{
		std::cout << SpriteRenderer->Program().Log() << std::endl;
	}
	
	Instance.Initialize( SpriteRenderer );
	Instance.Camera()->Position() = glm::vec2( 0.25, 0.25 );
	Instance.Camera()->UpdateGpuBuffer();
	
	
	//Upload sprites.... 
	SpriteStorage->Upload( SpritesOfGods, sprite_count );
	
	//Enable the sprites in an instance
	SpriteInstance->Enable( SpriteStorage );

	
	
	
	glPointSize( 10.0f );
	while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		
		SpriteRenderer->Enable( );
			SpriteRenderer->Render( SpriteInstance, Engine::Points, SpriteStorage->Size() );
		SpriteRenderer->Disable( );
		
		
		glfwSwapBuffers(window);
        glfwPollEvents();
		
	}
	
	
	//PLATFORM
	glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
	
}
