#include <iostream>

#include "state/stack.h"
#include "game/main_state.h"

int main( int args, char *argv[])
{
	game::cmain_state main_state;
	state::cstack stack;
	stack.run( main_state );
	return 0;
}