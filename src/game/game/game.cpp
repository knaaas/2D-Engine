#include "game.h"

namespace Game
{
	CGame::CGame()
	{
		
	}
	
	CGame::~CGame()
	{
		
	}

	void SSprite::Attribute( bool instanced, GLuint devisor )
	{
		//index size type normalized stride starting_offset
		//cause I am stupid
		
		//position
		glEnableVertexAttribArray( 0 );
		glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( SSprite ), 0 );
		if( instanced )
			glVertexAttribDivisor( 0, devisor );
		
		//size 
		glEnableVertexAttribArray( 1 );
		glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, sizeof( SSprite ), (const GLvoid*)sizeof( glm::vec2 ) );
		if( instanced )
			glVertexAttribDivisor( 1, devisor );
		
		//color
		glEnableVertexAttribArray( 2 );
		glVertexAttribPointer( 2, 3, GL_FLOAT, GL_FALSE, sizeof( SSprite ), (const GLvoid*)(2*sizeof( glm::vec2 )) );
		if( instanced )
			glVertexAttribDivisor( 2, devisor );
	}

	void CGame::Run(Engine::CPlatform* platform)
	{
		const GLchar VertexSource[] = {
			"#version 330 core							  \n"
			"layout(location = 0) in vec2 in_position;    \n"
			"layout(location = 1) in vec2 in_size; 	      \n"
			"layout(location = 2) in vec3 in_color; 	  \n"
			"     						  				  \n"
			"out vec3 out_color; 	     				  \n"
			"     						  				  \n"
			"void main(){							      \n"
			"	out_color = in_color;                     \n"
			"	gl_Position = vec4( in_position, 0.0f, 1.0f );  \n"
			"}											  \n" 
		};
		
		const GLchar FragmentSource[] = {
			"#version 330 core 							  \n"
			"in vec3 out_color;							  \n"
			"											  \n"
			"out vec4 fcolor;							  \n"
			"void main(){  							      \n"
			"	fcolor = vec4( out_color,0.0f );		  \n"
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
		
		
		
		// Create and initialize sprites
		const size_t sprite_count = 128;
		SSprite *SpritesOfGods = new SSprite[sprite_count];
		for( size_t i = 0; i < sprite_count; i++ ) {
			SpritesOfGods[i].position = glm::vec2( 
				(float)( rand()%2000)/1000.0f - 1.0f, 
				(float)( rand()%2000)/1000.0f - 1.0f );
			SpritesOfGods[i].color = glm::vec3( 1.0f, 1.0f, 1.0f);
			
		}
		
		GPUSpriteStorage*  SpriteStorage  = new GPUSpriteStorage();
		GPUSpriteInstance* SpriteInstance = new GPUSpriteInstance();
		GPUSpriteRenderer* SpriteRenderer = new GPUSpriteRenderer();
		
		SpriteRenderer->Program().Attach( &VertexShader );
		SpriteRenderer->Program().Attach( &FragmentShader );
		if( !SpriteRenderer->Program().Link())
		{
			std::cout << SpriteRenderer->Program().Log() << std::endl;
		}
		
		//Upload sprites.... 
		SpriteStorage->Upload( SpritesOfGods, sprite_count );
		
		//Enable the sprites in an instance
		SpriteInstance->Enable( SpriteStorage );

		
		glPointSize( 10.0f );
		while (!platform->Exit())
		{
			Engine::CPlatform::SScreen Screen( platform->ScreenResolution() );
			
			glViewport(0, 0, Screen.width, Screen.height);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

			SpriteRenderer->Enable();
				SpriteRenderer->Render( SpriteInstance, Engine::Points, SpriteStorage->Size() );
			SpriteRenderer->Disable();
			
			platform->Update();
			
		}
	}
}