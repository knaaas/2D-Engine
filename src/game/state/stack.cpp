#include "stack.h"

namespace State
{
	void CStack::Run( CState& state ){
						
		CState* active_state = &state;
		LOG("State::CStack::Run - begin" );
		
		//If there are any sub states
		while( active_state ){
		
			LOG("Running active state: " << active_state );	
			//Run state and grab next sub state
			/*THIS IS BAD! What if a stupid developer write a state that does no return 
			a nullptr or a state */
			CState* sub_state = active_state->Run();
			
			//If any sub state. Push the current state
			if( sub_state ){
				LOG( "Pushing active state" );
				m_state.push( active_state );
			}
			//Otherwise pop previous state
			else if( !m_state.empty() ){
				LOG( "Popping previous state" );
				sub_state = m_state.top();
				m_state.pop();
			}
			
			//Make the new state active
			active_state = sub_state;
		}
		LOG("State::CStack::Run - end");
	}
}