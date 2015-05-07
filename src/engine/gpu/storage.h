#ifndef ENGINE_GPU_STORAGE_H
#define ENGINE_GPU_STORAGE_H

#include <GL/glew.h>

namespace Engine
{
	template <typename T>
	class CGPUStorage
	{
		public:
			CGPUStorage();
			~CGPUStorage();
			
			//Upload memory to GPU
			void upload( T* src , size_t size, size_t offset = 0 );
			
		private:
			
			GLuint m_gpu_buffer_id;
			GLuint m_gpu_buffer_byte_size;
	};
}

#endif //ENGINE_GPU_STORAGE_H