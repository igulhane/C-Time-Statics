/**
 * Time.cpp
 */
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "Time.h"

using namespace std;

Time::Time( void )
{
   seconds = 0;
}

Time::Time( int _seconds )
{
   seconds = _seconds;
}

Time::Time( string t )
{
   setTime( t );
}

std::string Time::str() const
{
   // Use ostringstream to convert from int to string.

   ostringstream oss;
   oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60
   << ":" << setfill('0') << setw(2) << (seconds%60);
   return oss.str();

}

void Time::setTime( std::string t )
{
        int sec=0;
        int i=0;
        int temp=0;
       /*
        * Checking for location of ':' in string.
        */
        while(t[i]!=':' && i!= t.length())
        {
              i++;
        }
       /*
        * If i>0 then convert the hours in seconds and store in temporary variable sec.
        * istringstream converts string to int.
        */
        if(i!=0){
                 istringstream (t.substr(0,i)) >> temp;
                 //if value less than 0 throw Invalid Time entry exception.
                 if(temp <0){
                    throw runtime_error("Invalid time entry");
                 }
                 sec=temp*3600;
        }
       /*
        * Convert the min in seconds and add it to temporary variable sec.
        */
        int n=i;
        if(t[i]==':')
        {
	    n++;
            //Check the presence of next ':' 
            while(t[n]!=':' && n!= t.length())
            {
              n++;
            }
            istringstream (t.substr(i+1,n)) >> temp;
            //if value greater than 60 throw Invalid Time entry exception.
            if(temp>60){
               throw runtime_error("Invalid time entry");
            }
            sec=sec+temp*60;
        }
        i=n;
       /*
        * Add seconds to temporary variable seconds.
        */
        if(t[i]==':' && t.substr(i,t.length()).length()>1)
        {
            istringstream (t.substr(i+1,t.length()))>> temp;
            //if value greater than 60 throw Invalid Time entry exception.
            if(temp>60){
               throw runtime_error("Invalid time entry");
            }
            sec =sec+temp;
        }
        seconds=sec;
}

ostream& operator<< (ostream &out, Time const &time)
{
    out << time.str();
    return out;
}

istream& operator>> (istream &in, Time &time)
{
    string t;
    in >> t;
    time.setTime(t);
    return in;
}
