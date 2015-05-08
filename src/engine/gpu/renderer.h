#ifndef ENGINE_GPU_RENDERER_H
#define ENGINE_GPU_RENDERER_H

#include "shader.h"
#include "instance.h"

namespace Engine
{
	template <typename T>
	class CGPURenderer
	{
		public:
			CGPURenderer();
			
			void Enable();
			void Disable();
			
			void Render( CGPUInstance<T> * instance, EDrawMode mode, GLuint count );
			
			CProgram& Program();
			const CProgram& Program() const;
			
		private:
			friend class CSCEInstance;
			CProgram m_program;
	};
	#include "renderer.hpp"
}

#endif //ENGINE_GPU_RENDERER_H