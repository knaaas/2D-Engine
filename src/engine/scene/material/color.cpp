#include "color.h"

namespace Engine
{
	namespace Material
	{
		CColor::CColor(const glm::vec3& color)
		: m_color( color )
		{
			const GLchar FragmentSource[] = {
				"out vec4 fcolor;							  \n"
				"void main(){  							      \n"
				"	fcolor = vec4( 1,0,0,0);				  \n"
				"}											  \n" 
			};
			
			if( !m_fragment_shader.Compile(FragmentSource) )
			{
				std::cerr << "Error: built in shader didn't compile. " << std::endl
				<< "See "<<__FILE__ << " for details." << std::endl;
			}
		}
		
		bool CColor::InitializeProgram( CProgram* program )
		{
			program->Attach( &m_fragment_shader );
		}
				
		void CColor::Enable()
		{
			
		}
		
		void CColor::Disable()
		{
			
		}
		
	}
}