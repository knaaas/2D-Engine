
template <typename T>
CGPUInstance<T>::CGPUInstance()
{
	glGenVertexArrays( 1, &m_gpu_vertexarray );
}

template <typename T>
CGPUInstance<T>::~CGPUInstance()
{
	glDeleteVertexArrays( 1, &m_gpu_vertexarray );
}

template <typename T>		
void CGPUInstance<T>::Enable( CGPUStorage<T>* storage,  bool instanced, GLuint devisor )
{
	glBindVertexArray( m_gpu_vertexarray);
	storage->Attribute( instanced, devisor );
	glBindVertexArray( 0 );
}

template <typename T>
void CGPUInstance<T>::Render(  EDrawMode mode, GLint count )
{
	glBindVertexArray( m_gpu_vertexarray );
	glDrawArrays( mode, 0, count );
	glBindVertexArray( 0 );
}