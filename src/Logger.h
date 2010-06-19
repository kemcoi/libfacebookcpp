/*
 * Copyright (C) 2010 
 * Written by:
 * Aly Hirani <alyhirani@gmail.com>
 * James Chou <uohcsemaj@gmail.com>
 *
 * All Rights Reserved
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 *
 */

#ifndef FACEBOOK_LOGGER_H_
#define FACEBOOK_LOGGER_H_

#include "Common.h"


namespace Facebook
{
	class Logger
	{
	public:
		//----------------------------------------------
		Logger();
		~Logger();
		//----------------------------------------------
		//TODO: hardcore overload this
		template<typename T>
		static void FacebookLog(T type, int lineNumber, const char* file, const char* logString)
		{}
		
		template<>
		static void FacebookLog<LogType>(LogType type, int lineNumber, const char* file, const char* logString)
		{
			std::string f = file;
			std::string l = logString;
			switch(type)
			{
			case FB_Error:
				std::cout<< "Error: " << " @ " << f  << "Line: " << lineNumber;
				break;
			case FB_Debug:
				std::cout<< "Debug: "<< " @ " << f  << "Line: " << lineNumber;
				break;
			case FB_Info:
				std::cout<< "Info: ";
				break;
			case FB_Warn:
				std::cout<< "Warn: ";
				break;
			case FB_Message:
				std::cout<< "Message: ";
				break;
			}

			std::cout << "--" << l << std::endl;
		}
	private:
		int instance_;
	};
}

#endif