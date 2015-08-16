#include "Statistics.h"
#include "Time.h"
#include <iostream>
#include <iterator>

using namespace std;

template< typename T >
void showStats( T data )
{
   try
   {
      cout << "min: " << data.min() << endl;
      cout << "max: " << data.max() << endl;
      cout << "mean: " << data.mean() << endl;
      cout << "median: " << data.median() << endl;
      cout << "mode: ";

      set<typename T::value_type> mode = data.mode();
      ostream_iterator<typename T::value_type> out_it (cout," ");
      copy( mode.begin(), mode.end(), out_it );
      cout << endl;
   } 
   catch ( runtime_error &e )
   {
      cerr << "Runtime exception: " << e.what() << endl;
   }

}


int main()
{
   Statistics<Time> stats;
   Time t;

   while ( true )
   {
      try 
      {
         cin >> t;
      }
      catch ( runtime_error &e )
      {
         cerr << "Runtime exception: " << e.what() << endl;
         continue;
      }
      if ( cin.eof() )
      {
         break;
      }
      stats.push( t );
   }
   showStats(stats);




}
