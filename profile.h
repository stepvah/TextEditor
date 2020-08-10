#pragma once

#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;


class LogDuration {
public:
	explicit LogDuration(const string& msg)
		: message(msg)
		, start(steady_clock::now())
	{
	}

	~LogDuration() {
		auto finish = steady_clock::now();
		auto dur = finish - start;
		cerr << message
			<< duration_cast<milliseconds>(dur).count()
			<< "ms" << endl;
	}
private:
	string message = "";
	steady_clock::time_point start;
};

#define UNIQUE_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQUE_ID(lineno) UNIQUE_ID_IMPL(lineno)

#define LOG_DURATION(message) \
	LogDuration UNIQUE_ID(__LINE__){message};