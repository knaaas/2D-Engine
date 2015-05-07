#include "menu.h"
#include <algorithm>
namespace GUI 
{
	CMenu::CMenu( const char *options[], const size_t count )
	: p_options( options )
	, m_count( count )
	{
		
	}
	
	size_t CMenu::Result( )
	{
		size_t option = m_count+1; 
	
		while( m_count < option  ){
			option = m_count+1;
			for( size_t i = 0; i < m_count; i++ )
				std::cout << i << ": " << p_options[i] << std::endl;
			printf("Select(0 - %u):", m_count-1 );
			// std::cin fail = infinite loop
			std::cin >> option;
		}
	
		return option;
	}
}
