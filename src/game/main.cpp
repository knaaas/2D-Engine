#include <iostream>

#include "state/stack.h"
#include "game/main_state.h"

int main( int args, char *argv[])
{
	Game::CMainState main_state;
	State::CStack stack;
	stack.Run( main_state );
	return 0;
}
