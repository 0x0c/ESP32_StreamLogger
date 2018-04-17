#pragma once

#include <esp_log.h>
#include <sstream>
#include <string>

namespace m2d
{
namespace ESP32
{
	namespace Logger
	{
		static std::string endl = "\n";
		class Impl
		{
		public:
			std::string tag = "StreamLogger";
			Impl(){};
			virtual void print(const char *str) = 0;
		};

		class Error : public Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGE(this->tag.c_str(), "%s", str);
			}
		};

		class Warning : public Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGW(this->tag.c_str(), "%s", str);
			}
		};

		class Info : public Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGI(this->tag.c_str(), "%s", str);
			}
		};

		class Debug : public Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGD(this->tag.c_str(), "%s", str);
			}
		};

		class Verbose : public Impl
		{
		public:
			void print(const char *str)
			{
				ESP_LOGV(this->tag.c_str(), "%s", str);
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
			void set_tag(std::string tag)
			{
				this->impl.tag = tag;
			}

			Stream &operator<<(const std::string &str)
			{
				if (str == Logger::endl) {
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
