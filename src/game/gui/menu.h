#pragma once
#ifndef GUI_MENU_H
#define GUI_MENU_H

#include <cstdio>
#include <iostream>

namespace gui
{
	class cmenu
	{
		public:
			cmenu( const char *options[], const size_t count );
			size_t result();
		private:
			const char **p_options;
			const size_t m_count;
	};
}

#endif //GUI_MENU_H