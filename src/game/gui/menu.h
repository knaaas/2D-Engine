#ifndef GUI_MENU_H
#define GUI_MENU_H

#include <cstdio>
#include <iostream>

namespace GUI 
{
	class CMenu
	{
		public:
			CMenu( const char *options[], const size_t count );
			size_t Result();
		private:
			const char **p_options;
			const size_t m_count;
	};
}

#endif // GUI_MENU_H
