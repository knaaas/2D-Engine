template <typename T>
CGPUStorage<T>::CGPUStorage()
{
	m_gpu_buffer_byte_size = 0;
	glGenBuffers( 1, &m_gpu_buffer_id );
}

template <typename T>
CGPUStorage<T>::~CGPUStorage()
{
	glDeleteBuffers( 1, &m_gpu_buffer_id );
}


template <typename T>		
size_t CGPUStorage<T>::Size()
{
	return m_gpu_buffer_byte_size/sizeof( T );
}


template <typename T>
void CGPUStorage<T>::Upload( T* src , size_t size)
{
	const size_t memory_byte_size = sizeof( T ) * size;
	
	//Bind GL buffer
	glBindBuffer( GL_ARRAY_BUFFER, m_gpu_buffer_id );
	
	//If size differ
	if( memory_byte_size != m_gpu_buffer_byte_size )
	{
		//Update old size 
		m_gpu_buffer_byte_size = memory_byte_size;
		
		//Allocate and update memory
		glBufferData( GL_ARRAY_BUFFER, memory_byte_size, src, GL_STREAM_DRAW );
	}
	else
	{
		//Map memory from GPU 
		T *dest = static_cast<T*>( glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY ) );
		
		//Write to it
		memcpy( dest, src, memory_byte_size );
		
		glUnmapBuffer( GL_ARRAY_BUFFER );
	}
	//Unbind buffer
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}


template <typename T>
void CGPUStorage<T>::Attribute( bool instanced , GLuint devisor )
{
	glBindBuffer( GL_ARRAY_BUFFER, m_gpu_buffer_id );
	T::Attribute( instanced, devisor );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}
			