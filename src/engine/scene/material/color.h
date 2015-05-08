#ifdef ENGINE_SCENE_MATERIAL_H
#define ENGINE_SCENE_MATERIAL_COLOR_H

#include <glm/glm.hpp>
#include "../../gpu/shader.h"

namespace Engine
{
	namespace Material
	{
		class CColor
		{
			public:
				CColor( const glm::vec3& color );
				
				virtual bool InitializeProgram( CProgram* program );
				
				virtual void Enable();
				virtual void Disable();	
				
			private:
				glm::vec3 m_color; 
				CShader m_fragment_shader;
		};
	}
}

#endif //ENGINE_SCENE_MATERIAL_H