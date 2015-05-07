#include "main_state.h"

namespace Game
{
	const char *emenu_option[] = {
		"play",
		"help",
		"exit"
	};
	
	CMainState::CMainState() 
	{
		p_run_state = new CRunState();
		assert( p_run_state );
	}
	
	CMainState::~CMainState()
	{
		delete p_run_state;
	}
	
	State::CState* CMainState::Run()
	{
		
		//Read selected menu option
		const EMenuState state( _ReadMenuInput() );
		
		//Return the state of given menu option
		return _ReturnSubState( state );
	}
	
	const EMenuState CMainState::_ReadMenuInput()
	{
		GUI::CMenu menu( emenu_option, 3 );
		const EMenuState state = static_cast<const EMenuState>(  menu.Result() );
		return state;
	}
	
	State::CState* CMainState::_ReturnSubState( const EMenuState& state )
	{
		
		switch( state )
		{
			case menu_play:
				return _ReturnRunState( ); 
			case menu_help:{
				std::cout << "cmain_state - help not implemented." << std::endl;
				return nullptr;
			}
			case menu_exit:
				return nullptr;
		}
		
		return nullptr;
	}
	
	State::CState* CMainState::_ReturnRunState()
	{
		p_run_state->Initialize( );
		return p_run_state;
	}
	
}
