// console.h

#pragma once

#include "console.h"
#include <cstdio>
#include <iostream>
#include <windows.h>

#include <fstream>
// http://www.williamwilling.com/blog/?p=74
class console
{
private:
  std::ofstream m_out;
  std::ofstream m_err;
  std::ifstream m_in;

  std::streambuf* m_old_cout;
  std::streambuf* m_old_cerr;
  std::streambuf* m_old_cin;

public:
  console();
  ~console();

  void hide();
  void show();
};



inline  console::console()
{
  // create a console window
  AllocConsole();

  // redirect std::cout to our console window
  m_old_cout = std::cout.rdbuf();
  m_out.open("CONOUT$");
  std::cout.rdbuf(m_out.rdbuf());

  // redirect std::cerr to our console window
  m_old_cerr = std::cerr.rdbuf();
  m_err.open("CONOUT$");
  std::cerr.rdbuf(m_err.rdbuf());

  // redirect std::cin to our console window
  m_old_cin = std::cin.rdbuf();
  m_in.open("CONIN$");
  std::cin.rdbuf(m_in.rdbuf());
}

inline console::~console()
{
  // reset the standard streams
  std::cin.rdbuf(m_old_cin);
  std::cerr.rdbuf(m_old_cerr);
  std::cout.rdbuf(m_old_cout);

  // remove the console window
  FreeConsole();
}