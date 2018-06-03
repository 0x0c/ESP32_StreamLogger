#pragma once

#include <esp_log.h>
#include <sstream>
#include <string>

namespace m2d
{
namespace ESP32
{
	static std::string endl = "\n";
	namespace Logger
	{
		class Impl
		{
		public:
			const char *tag = "StreamLogger";
			Impl(){};
			virtual void print(const char *str) = 0;
		};

		class Error : Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGE(this->tag, "%s", str);
			}
		};

		class Warning : Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGW(this->tag, "%s", str);
			}
		};

		class Info : Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGI(this->tag, "%s", str);
			}
		};

		class Debug : Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGD(this->tag, "%s", str);
			}
		};

		class Verbose : Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGV(this->tag, "%s", str);
			}
		};

		template <typename T>
		class Stream
		{
		private:
			T impl;
			std::stringstream ss;

			void operator=(const Stream &);

			void print(std::string str)
			{
				this->impl.print(const_cast<char *>(str.c_str()));
			}

			void print()
			{
				this->print(this->ss.str());
				this->ss.str("");
				this->ss.clear(std::stringstream::goodbit);
			}

		public:
			bool print_function = false;
			Stream &operator<<(const std::string &str)
			{
				if (str == GROOVE::endl) {
					this->print();
				}
				else {
					this->ss << str;
				}
				return *this;
			}

			Stream &operator<<(const char &str)
			{
				this->ss << &str;
				return *this;
			}

			Stream &operator<<(const char *str)
			{
				this->ss << str;
				return *this;
			}

			Stream &operator<<(const int &i)
			{
				this->ss << i;
				return *this;
			}

			Stream &operator<<(const unsigned int &i)
			{
				this->ss << i;
				return *this;
			}

			Stream &operator<<(const float &i)
			{
				this->ss << i;
				return *this;
			}

			Stream &operator<<(const double &i)
			{
				this->ss << i;
				return *this;
			}
		};
	}
}
}
