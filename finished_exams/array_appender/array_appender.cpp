#include <iostream>
#include "arrapp.h"
#include "arrapp.h"

int main()
{
  int your_mark = 1;
  // 2-es
  int a[] = { 3, 8, 1, 2 };
  int b[] = { 1, 7, 2, 5, 4 };
  int c[] = { 5, 1, 2 };
  array_appender s;
  s.append( a, sizeof( a ) / sizeof( a[ 0 ] ) );
  s.append( b, sizeof( b ) / sizeof( b[ 0 ] ) );
  s.append( c, sizeof( c ) / sizeof( c[ 0 ] ) );

  int d[] = { 1, 8, 5 };
  int e[] = { 8, 2, 1 };
  int f[] = { 7, 1 };
  int g[] = { 2, 5 };
  array_appender t;

  t.append( g, sizeof( g ) / sizeof( g[ 0 ] ) );
  t.append( f, sizeof( f ) / sizeof( f[ 0 ] ) );
  t.append( e, sizeof( e ) / sizeof( e[ 0 ] ) );
  t.append( d, sizeof( d ) / sizeof( d[ 0 ] ) );

  if ( 10 == t.size() )
  {
    your_mark = s.size() - t.size();
  }
  
  // 3-as
  t.at( 5 ) = 3;

  s.array_printer();
  s.at( 5 ) = 8;
  s.array_printer();
  ++s.at( 4 );
  s.array_printer();

  if ( 8 == b[ 1 ] && your_mark == t.at( 0 ) && 2 == b[ 0 ] )
  {
    your_mark = e[ 1 ];
  }
  
  // 4-es
  t[ 9 ]--;
  s[ 2 ] = 3;

  if ( your_mark == a[ 2 ] )
  {
    your_mark = d[ 2 ];
  }
  
  // 5-os
  int x[] = { 3, 8, 1 };
  s.append( x );

  int y[] = { 7, 2, 4, 8, 1 };
  t.append( y );

  if ( t.size() == s.size() && your_mark == t[ 12 ] )
  {
    your_mark = t[ 10 ] - t[ 11 ];
  }
  
  std::endl( std::cout << "Your mark is " << your_mark );
}