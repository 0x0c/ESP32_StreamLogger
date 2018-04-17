#pragma once

#include "./Impl/LoggerImpl.h"

namespace m2d
{
namespace ESP32
{
	namespace Logger
	{
		static Stream<Error> Error;
		static Stream<Warning> Warning;
		static Stream<Info> Info;
		static Stream<Debug> Debug;
		static Stream<Verbose> Verbose;
	}
}
}
