#include <iostream>
#include "domino.h"
#include <string>
#include <utility>
#include "domino.h"

template <int N>
struct congruent
{

  bool operator()( int a, int b ) const
  {
    return a % N == b % N;
  }

};


struct equal_length
{

  bool operator()( const std::string& lhs,
                   const std::string& rhs ) const
  {
    return lhs.length() == rhs.length();
  }

};

const int max = 1000;

int main()
{
  int your_mark = 1;
  // 2-es
  domino<int> dim( std::make_pair( 0, 0 ) );
  for( int i = 0; i < max; ++i )
  {
    dim.push_back( std::make_pair( i + 1, i ) );
  }

  domino<int> di( std::make_pair( 3, 5 ) );
  di.push_back( std::make_pair( 4, 5 ) );
  di.push_front( std::make_pair( 3, 2 ) );
  di.push_front( std::make_pair( 1, 2 ) );
  di.push_front( std::make_pair( 6, 6 ) );

  //a cdi uj es egybol kap erteket, tehat copy constructor; ÉS NEM ÉRTÉKADÓ
  const domino<int> cdi = di;

  domino<std::string> ds( std::make_pair( "C++", "C" ) );
  ds.push_back( std::make_pair( "Java", "Javascript" ) );
  ds.push_back( std::make_pair( "C", "Python" ) );

  if ( 4 == cdi.size() && !di.push_back( std::make_pair( 5, 5 ) ) &&
       !di.push_front( std::make_pair( 0, 0 ) ) && max + 1 == dim.size() &&
       di.push_back( std::make_pair ( 4, 4 ) ) && 5 == di.size() )
  {
    your_mark = ds.size();
  }

  // 3-as
  ds >> std::make_pair( "Python", "Rust" );
  ds >> std::make_pair( "Haskell", "Scala" );
  ds << std::make_pair( "Ada", "Pascal" );
  std::make_pair( 2, 0 ) >> dim;
  std::make_pair( 4, 4 ) >> dim;

  if ( 2 + max == dim.size() && !( std::make_pair( 8, 8 ) << di ) )
  {
    your_mark = ds.size();
  }

  /* 4-es
  domino<int, congruent<5> > dcf( std::make_pair( 3, 7 ) );
  dcf.push_back( std::make_pair( 2, 2 ) );
  dcf >> std::make_pair( 3, 12 );
  dcf >> std::make_pair( 1, 1 );
  std::make_pair( 8, 2 ) << dcf;
  std::make_pair( 18, 18 ) >> dcf;

  domino<int, congruent<2> > dct( std::make_pair( 1, 1 ) );
  dct >> std::make_pair( 4, 3 );

  domino<int, congruent<2> > edct( std::make_pair( 3, 3 ) );
  edct >> std::make_pair( 8, 9 );

  domino<std::string, equal_length> dse( std::make_pair( "C++", "C" ) );
  std::make_pair<std::string, std::string>( "Ada", "Python" ) >> dse;

  domino<std::string, equal_length> ndse( std::make_pair( "C++", "C" ) );

  domino<std::string> eds( std::make_pair( "C", "C++" ) );
  eds << ( std::make_pair( "C", "Python" ) );
  eds << ( std::make_pair( "Rust", "Python" ) );

  if ( !( dse.push_back( std::make_pair( "Brainfuck", "Haskell" ) ) ) &&
       edct.equals( dct ) && !ndse.equals( dse ) && dct.size() == dse.size() &&
       !( cdi.equals( dim ) ) && eds.equals( ds ) && 5 == dcf.size() )
  {
    your_mark = cdi.size();
  }
  */
  /* 5-os
  domino<int, congruent<3> > a( std::make_pair( 2, 4 ) );
  a >> std::make_pair( 7, 7 );
  domino<int, congruent<3> > b( std::make_pair( 2, 2 ) );
  a += b;

  domino<std::string> p( std::make_pair( "Rust", "ArnoldC" ) );
  eds += p;

  domino<int, congruent<3> > c( std::make_pair( 5, 8 ) );
  c >> std::make_pair( 1, 1 );
  c >> std::make_pair( 8, 7 );

  if( c == a  && !( cdi == dim ) && !( eds == ds ) )
  {
    your_mark = dcf.size();
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}