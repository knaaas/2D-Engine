#ifndef ENGINE_GPU_STATE_H
#define ENGINE_GPU_STATE_H

#include <gl/glew.h>

namespace Engine
{
	template <typename T>
	class CGPUState
	{
		public:
			CGPUState(const T& state);
			~CGPUState();
			
			void State(const T& state);
			
			void Bind( GLuint index );
			
		private:
			GLuint m_gpu_buffer_id;
	};
	#include "state.hpp"
}

#endif //ENGINE_GPU_STATE_H