#pragma once

#include "./Impl/LoggerImpl.h"
#include <string>

namespace m2d
{
namespace ESP32
{
	namespace Logger
	{
		static Stream<Error> E;
		static Stream<Warning> W;
		static Stream<Info> I;
		static Stream<Debug> D;
		static Stream<Verbose> V;

		class Group
		{
		public:
			Stream<Error> error;
			Stream<Warning> warning;
			Stream<Info> info;
			Stream<Debug> debug;
			Stream<Verbose> verbose;

			std::string tag;

			Group(std::string tag)
			{
				this->error.set_tag(tag);
				this->warning.set_tag(tag);
				this->info.set_tag(tag);
				this->debug.set_tag(tag);
				this->verbose.set_tag(tag);
			}

			void set_log_level(esp_log_level_t level)
			{
				esp_log_level_set(this->tag.c_str(), level);
			}
		};
	}
}
}
