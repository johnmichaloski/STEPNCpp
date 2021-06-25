//
//http://209.85.165.104/search?q=cache:PcxdVldM-VEJ:69.10.233.10/KB/debug/debugout.aspx+cout+debugging+mfc+outputdebugstring&hl=en&ct=clnk&cd=8&gl=us
//
#pragma once

#include <Windows.h>
#include <ostream>
#include <sstream>
#include <string>

#include <streambuf>
#include <fstream>

class Fstream
{
public:

	tfstream fp;

	Fstream(const TCHAR * filename)
	{
		fp.open (filename, std::fstream::out );
	}

	~Fstream() {  fp.close();}
};

class basic_debugbuf : public tstreambuf
{
public:
	basic_debugbuf(int bufferSize=100) 
	{
		if (bufferSize)
		{
			TCHAR *ptr = new TCHAR[bufferSize];
			setp(ptr, ptr + bufferSize);
		}
		else
			setp(0, 0);
	}
	virtual ~basic_debugbuf() 
	{
		sync();
		delete[] pbase();
	}

    virtual void writeString(const tstring &str)
    {
       // OutputDebugString(str.c_str());
    }

private:
    int	overflow(int c)
    {
        sync();

        if (c != EOF)
        {
            if (pbase() == epptr())
            {
                tstring temp;
                temp += TCHAR(c);
                writeString(temp);
            }
            else
                sputc(c);
        }

        return 0;
    }

    int	sync()
    {
        if (pbase() != pptr())
        {
            int len = int(pptr() - pbase());
            tstring temp(pbase(), len);
            writeString(temp);
			//OutputDebugString(temp.c_str());
            setp(pbase(), epptr());
        }
        return 0;
    }
   
};
class DebugFileOut
	: public basic_debugbuf
{
public:
	Fstream _stream;
	DebugFileOut(const TCHAR * filename) : _stream (filename)
	{

	}
	virtual void writeString(const tstring &str)
	{
		 _stream.fp << str;
	}

};