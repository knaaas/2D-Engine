template <typename T>
CGPURenderer<T>::CGPURenderer()
{
	
}
			
template <typename T>			
void CGPURenderer<T>::Enable()
{
	m_program.Bind();
}

template <typename T>
void CGPURenderer<T>::Disable()
{
	m_program.UnBind();
}


			
template <typename T>
CProgram& CGPURenderer<T>::Program()
{
	return m_program;
}

template <typename T>
const CProgram& CGPURenderer<T>::Program() const
{
	return m_program;
}

template <typename T>
void CGPURenderer<T>::Render( CGPUInstance<T> * instance, EDrawMode mode, GLuint count )
{
	instance->Render( mode, count );
}