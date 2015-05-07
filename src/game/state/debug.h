#pragma once
#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#ifndef NLOG
#define LOG( OSTREAM ) std::cout << "Log: " << OSTREAM << std::endl; 
#else
#define LOG( OSTREAM )	
#endif 


#ifndef NWARNING
#define LOGW( OSTREAM ) std::cerr << "Warning: " << OSTREAM << std::endl;;
#else
#define LOGW( OSTREAM )	
#endif 


#ifndef NERROR
#define LOGE( OSTREAM ) std::cerr << "Error: " << OSTREAM << std::endl;;
#else
#define LOGE( OSTREAM )	
#endif 

#endif //DEBUG_H