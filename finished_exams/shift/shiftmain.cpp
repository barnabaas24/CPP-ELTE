#include "arshift.h"
#include <string>
#include <iostream>
#include "arshift.h"

int main()
{
  int your_mark = 1;
   //2-es
  int v[] = { 7, 3, 1, 6 };
            //6,7,3,1 --> 3,1,6,7
  array_shifter vs( v, sizeof( v ) / sizeof( v[ 0 ] ) );

  int t[] = { 8, 1, 2, 9, 3, 5 };
  const array_shifter ts( t, sizeof( t ) / sizeof( t[ 0 ] ) );

  int x[] = { 3, 1, 4, 1, 5 };
  array_shifter xs( x, sizeof( x ) / sizeof( x[ 0 ] ) );

  if ( 5 == xs.size() )
  {
    your_mark = ts.size() - vs.size();
  }
  
  
  // 3-as

  vs >> 1;
  vs >> 2;

  xs << 3;
  

  if ( 5 == x[ 1 ] && x[ 0 ] == x[ 3 ] )
  {
    your_mark = v[ 0 ];
  }
  
  // 4-es
   int y[] = { 1, 2, 5, 4 };
  bool c = true;
  if ( c )
  {
    array_shifter ys( y, sizeof( y ) / sizeof( y[ 0 ] ) );
    ys >> 2;

    if ( 1 == y[ 2 ] )
    {
      c = false;
    }
  }
  if ( !c )
  {
    your_mark = y[ 3 ];
  }
  
  // 5-os
  std::string langs[] = { "C", "Python", "C++", "Haskell", "Ada" };
  array_shifter_util<std::string> ls( langs, sizeof( langs ) / sizeof( langs[ 0 ] ) );
  ls << 2;

  array_shifter_util<int> ys( y, sizeof( y ) / sizeof( y[ 0 ] ) );
  ys >> 2;
  ys << 1;

  if ( "C++" == langs[ 0 ] && "Ada" == langs[ 2 ] && 1 == y[ 1 ] )
  {
    your_mark = ls.size();
  }
  
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}