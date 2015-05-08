template <typename T>
CGPURenderer<T>::CGPURenderer()
{
	
}

template <typename T>			
void CGPURenderer<T>::Initialize( Material::CMaterial *material )
{
	material->InitializeProgram( m_program );
}
			
template <typename T>			
void CGPURenderer<T>::Enable()
{
	m_program.Bind();
}

template <typename T>
void CGPURenderer<T>::Disable()
{
	m_program.Disable();
}

template <typename T>
void CGPURenderer<T>::Render( CGPUInstance<T> * instance, GLuint count )
{
	instance->render( count );
}