#include "shader.h"

namespace Engine
{
	CShader::CShader( const EShaderType& type ){
		m_shaderid = glCreateShader( type );
	}
	CShader::~CShader(){
		glDeleteShader( m_shaderid );
	}
			
	bool CShader::Compile( const std::string& string )
	{
		const GLchar* source = (const GLchar*)string.c_str();
		assert( source );
		
		glShaderSource( m_shaderid, 1, (const GLchar**)&source, NULL );
		glCompileShader( m_shaderid );
		
		return IsCompiled();
	}
	
	bool CShader::IsCompiled()
	{
		GLint state = GL_FALSE;
		glGetShaderiv( m_shaderid , GL_COMPILE_STATUS, &state );
		if( state == GL_FALSE ) return false;
		return true;
	}
			
			
	std::string CShader::Log()
	{
		std::string result;
		GLint length(0);
		glGetShaderiv( m_shaderid,  GL_INFO_LOG_LENGTH , &length );
		
		if( length != 0){
			result.resize( length );
			glGetShaderInfoLog( m_shaderid, length, NULL, (GLchar*)result.c_str());
		}
		return (result);
	}
	
	const GLuint& CShader::Shader( ) const
	{
		return m_shaderid;
	}
	
	CProgram::CProgram()
	{
		m_programid = glCreateProgram();
	}
	CProgram::~CProgram()
	{
		glDeleteProgram( m_programid );
	}
	
	
	void CProgram::Bind()
	{
		glUseProgram( m_programid );
	}
	
	void CProgram::UnBind()
	{
		glUseProgram( 0 );
	}
	
			
	void CProgram::Attach( const CShader *shader )
	{
		glAttachShader( m_programid, shader->Shader() );
	}
	
	void CProgram::Detach( const CShader *shader )
	{
		glDetachShader( m_programid, shader->Shader() );
	}
			
	bool CProgram::Link()
	{
		glLinkProgram( m_programid );
		return IsLinked();
	}
	
	bool CProgram::IsLinked()
	{
		GLint state = GL_FALSE;
		glGetProgramiv( m_programid, GL_LINK_STATUS, &state );
		if( state == GL_FALSE ) return false;
		return true;
	}
	
	std::string CProgram::Log()
	{
		std::string result;
		GLint length = 0;
		glGetProgramiv( m_programid, GL_INFO_LOG_LENGTH, &length );
		if( length != 0 ){
			result.resize( length );
			glGetProgramInfoLog( m_programid, length, NULL, (GLchar*)result.c_str());
		}
		return result;
	}
	
	GLint CProgram::Uniform( const std::string& name )
	{
		return glGetUniformLocation( m_programid, name.c_str() );
	}
	
	void CProgram::Uniform( GLint location, const float& value )
	{
		glUniform1f( location, value );
	}
	
}