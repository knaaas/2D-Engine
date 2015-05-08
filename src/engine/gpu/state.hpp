template <typename T>
CGPUState<T>::CGPUState(const T& state)
{
	glGenBuffers( 1, &m_gpu_buffer_id );
	glBindBuffer( GL_UNIFORM_BUFFER, m_gpu_buffer_id );
	glBufferData( GL_UNIFORM_BUFFER, sizeof(T), &state, GL_STREAM_DRAW );
	glBindBuffer( GL_UNIFORM_BUFFER, 0 );
}

template <typename T>
CGPUState<T>::~CGPUState()
{
	glDeleteBuffers( 1, &m_gpu_buffer_id );
}

template <typename T>
void CGPUState<T>::State(const T& state)
{
	glBindBuffer( GL_UNIFORM_BUFFER, m_gpu_buffer_id );
	glBufferData( GL_UNIFORM_BUFFER, sizeof(T), &state, GL_STREAM_DRAW );
	glBindBuffer( GL_UNIFORM_BUFFER, 0 );	
}


template <typename T>
void CGPUState<T>::Bind(GLuint index)
{
	glBindBufferBase( GL_UNIFORM_BUFFER, index, m_gpu_buffer_id );	
}
