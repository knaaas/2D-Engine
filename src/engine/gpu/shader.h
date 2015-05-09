#pragma once
#ifndef GPU_SHADER_H
#define GPU_SHADER_H

#include <cassert>
#include <string>

#include <GL/glew.h>

namespace Engine
{
	enum EShaderType
	{
		VertexShader   = GL_VERTEX_SHADER,
		FragmentShader = GL_FRAGMENT_SHADER
	};
	
	class CShader
	{
		public:
			CShader(const CShader& ) = delete;
			CShader operator =( const CShader& ) = delete;
				
			CShader( const EShaderType& type );
			~CShader();
			
			bool Compile( const std::string& string ); 
			
			bool IsCompiled();
			
			std::string Log();
			
			const GLuint& Shader( ) const;
			
		private:
			GLuint m_shaderid;
	};
	
	class CProgram
	{
		public:
			CProgram(const CProgram& ) = delete;
			CProgram operator =( const CProgram& ) = delete;
		
			CProgram();
			~CProgram();
			
			void Bind();
			void UnBind();
			
			void Attach( const CShader *shader );
			void Detach( const CShader *shader );
			
			bool Link();
			
			bool IsLinked();
			
			
			std::string Log();
			
			GLint Uniform( const std::string& name );
			GLint UniformBlock( const std::string& name );
			void  UniformBlock( GLuint location, GLuint index );
			
			static void Uniform( GLint location, const float& value );
		
		private:
			GLuint m_programid;
	};
	
}

#endif //GPU_SHADER_H