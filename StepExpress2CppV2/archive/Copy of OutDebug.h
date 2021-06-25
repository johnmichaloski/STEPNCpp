//
//http://209.85.165.104/search?q=cache:PcxdVldM-VEJ:69.10.233.10/KB/debug/debugout.aspx+cout+debugging+mfc+outputdebugstring&hl=en&ct=clnk&cd=8&gl=us
//
#pragma once

#include <Windows.h>
#include <ostream>
#include <sstream>
#include <string>

#include <streambuf>


class basic_debugbuf : public std::streambuf
{
public:
	typedef std::basic_stringbuf<CharT, TraitsT> _Myt;

	virtual ~basic_debugbuf()
	{
		if (pbase() != 0)
			sync();
	}

protected:
	virtual std::streamsize xsputn(const CharT *_S, std::streamsize _N)
	{
		std::streamsize _Ns = 0;
		while (0 < _N) // loop as long as we wrote the whole string
		{
			std::streamsize _M = pptr() - pbase();
			if (_M >= _MAXSIZE) // synchronize if there are already 1023 chars
				sync();
			_M = _MAXSIZE - _M; // maximal amount of chars we can write this time
			if (_N < _M)
				_M = _N;
			_M = _Myt::xsputn(_S, _M);
			_S += _M; _Ns += _M; _N -= _M; }
		return _Ns;
	}

	int sync()
	{
		sputc('\0'); // add string termination because we use pbase() to access string
		output_debug_string(pbase());
		str(std::basic_string<CharT>());
		return 0;
	}
	virtual void writeString(const std::string &str)
	{
		output_debug_string(str.c_str());
	}

	void output_debug_string(const CharT *text) {}

private:
	enum {_MAXSIZE = 1023};
};


template<>
void basic_debugbuf<char>::output_debug_string(const char *text)
{
    ::OutputDebugStringA(text);
}

template<>
void basic_debugbuf<wchar_t>::output_debug_string(const wchar_t *text)
{
    ::OutputDebugStringW(text);
}



template<class CharT, class TraitsT = std::char_traits<CharT> >
class basic_dostream : 
    public std::basic_ostream<CharT, TraitsT>
{
public:

    basic_dostream() : std::basic_ostream<CharT, TraitsT>
                (new basic_debugbuf<CharT, TraitsT>()) {}
    ~basic_dostream() 
    {
        delete rdbuf(); 
    }
};

typedef basic_dostream<char>    dostream;
typedef basic_dostream<wchar_t> wdostream;

