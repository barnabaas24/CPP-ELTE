#include <iostream>
#include "arsorter.h"
#include <string>
#include "arsorter.h"

int main()
{
  int your_mark = 1;
  // 2-es
  int v[] = { 8, 3, 2, 5, 9, 1 };
  array_sorter vs( v, sizeof( v ) / sizeof( v[ 0 ] ) );

  int x[] = { 2, 9, 3, 1, 4 };
  array_sorter xs( x, sizeof( x ) / sizeof( x[ 0 ] ) );

  if ( 5 == xs.size() && 6 == vs.size() && 1 == v[ 0 ] && 9 == x[ 4 ] )
  {
    your_mark = x[ your_mark ];
  }

  //3-as
  -xs;
  -xs;

  -vs;
  +vs;

  if ( 9 == x[ 0 ] && 9 == v[ 5 ] && 8 == v[ 4 ] )
  {
    your_mark = x[ your_mark ];
  }
  
  // 4-es
  int a[] = { 6, 1, 8, 5 };
  bool b = false;
  if ( !b )
  {
    array_sorter as( a, sizeof( a ) / sizeof( a[ 0 ] ) );
    if ( 1 == a[ 0 ] )
    {
      b = true;
    }
  }
  if ( b && 5 == a[ your_mark ] )
  {
    your_mark = a[ 3 ] - a[ 1 ];
  }
  
  // 5-os
  std::string langs[] = { "Python", "C", "Cobol", "Fortran" };
  array_sorter_util<std::string> ls( langs, sizeof( langs ) / sizeof( langs[ 0 ] ) );
  +ls;
  -ls;

  if ( "C" == langs[ 3 ] )
  {
    your_mark = langs[ 2 ].size();
  }
  
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}