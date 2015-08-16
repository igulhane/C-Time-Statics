/**
 * Time.h
 */
#ifndef __TIME_H__
#define __TIME_H__

#include <string>

/**
 * This class manages time values.
 */
class Time
{
   public:
      /**
       * Default constructor. Time is set to 0
       */
      Time();

      /**
       * Time constructor that takes a string that represents time in the
       * format hh:mm
       * @param time Time in the format hh:mm
       */
      Time( std::string time );

      /**
       * Time constructor that takes elapsed number of seconds since the epoch
       * @param seconds the number of seconds since the epoch
       */
      Time( int seconds );

      /**
       * Set the time to a string specified by hh:mm since the epoch
       * @param time new time value in the format hh:mm since the epoch
       */
      void setTime( std::string time );

      /**
       * Return a string version of the time in the format hh:mm
       * @return string representation of the time in hh:mm since the epoch
       */
      std::string str() const;

      /**
       * Operator overloading for << to print the Time object.
       * @return string representation of the time in hh:mm:ss on ostream
       */
      friend std::ostream& operator<< (std::ostream &out, Time const &time);

      /**
       * Operator overloading for >> to get the time object.
       * @return returns the control to istream
       */
      friend std::istream& operator>> (std::istream &in, Time &time);

      /**
       * Operator overloading for < to compare the time object.
       * @return returns bool
       */
      bool operator< (const Time &t1) const
      {
         return (seconds < t1.seconds);
      }

      /**
       * Operator overloading for > to compare the time object.
       * @return returns bool
       */
      bool operator> (const Time &t2) const
      {
         return (seconds> t2.seconds);
      }

      /**
       * Operator overloading for == to compare the time object.
       * @return returns bool
       */
      bool operator== (const Time &t1) const
      {
         return (t1.seconds == seconds);
      }

      /**
       * Operator overloading for += to add the time object.
       * @return void
       */
      void operator+= (Time time)
      {
         seconds+= time.seconds;
      }

      /**
       * Operator overloading for /= .
       * @return void
       */
      void operator/=(int nValue)
      {
        seconds /= nValue;
      }

      /**
       * Returns the seconds.
       * @return returns seconds
       */
      int getTime(){
        return seconds;
      }

      private:
      /**
       * Number of seconds since the epoch
       */
      int seconds;

};

#endif // __TIME_H_HH
