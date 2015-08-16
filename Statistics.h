/**
 * Statistics.h
 * STL container : list
 * Lists are sequence containers that allow constant time insert and erase
 * operations anywhere within the sequence, and iteration in both directions.
 * Compared to other base standard sequence containers (array, vector and deque),
 * lists perform generally better in inserting, extracting and moving elements in
 * any position within the container
 */

#ifndef _STATISTICS_H_
#define _STATISTICS_H_
#include <stdexcept>
#include <list>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
/**
 * This class manages the functions to get the time values.
 */
template< class T >
class Statistics
{
public:

   /**
    * Calculate the mean (average) of the data entered.
    *
    * @return the mean of the data pushed into our data set
    */
    T mean(){
    T temp;

    //If list of items empty throw underflow_error.
    if(listItems.empty())
    {
        throw std::underflow_error("Not enough data");
    }

    //Calculate the average of Time objects
    typename std::list<T>::iterator it;
    for(it =listItems.begin(); it!=listItems.end(); ++it)
    {
        temp+=(*it);
    }
    temp/=listItems.size();
    return temp;
    }

   /**
    * Calculate the median (middle element when the data is sorted)
    *
    * @return the mode of the data pushed into our data set
    */
    T median(){
    T temp;

    //Sort the elements in List.
    listItems.sort();
    //Calculate the location of middle element.
    int i=listItems.size()/2;
    
    //Move the iterator to middle element
    typename std::list<T>::iterator it = listItems.begin();
    std::advance(it,i);
    temp=(*it);
    return temp;
    }

   /**
    * Calculate the mode (most common element).
    *
    * @return a set of the most common elements.  This can be the empty set if
    * there is a uniform distribution
    */
    std::set<T> mode(){
    std::set<T> result;
    std::set<T> temp;

    //for loop inserts the unique time objects in temp set
    typename std::list<T>::iterator itr;
       for(itr = listItems.begin();itr!=listItems.end();++itr){
           temp.insert(*itr);
       }

    // Condition to check if all the objects are unique
    if(temp.size()== listItems.size()){
       return result;
    }

    int countValue=0;
    typename std::map<T, int> map1;
    typename std::set<T>::iterator it= temp.begin();

    //Calculate the count of each unique object and save it in map
    while(it!=temp.end()){
        countValue= std::count(listItems.begin(),listItems.end(),*it);
        map1.insert(typename std::map<T, int>::value_type(*it,countValue));
        ++it;
    }

    //Find  the max-count of most common object.
    int maxValue=0;
    typename std::map<T, int>::iterator itr1;
    for (itr1 = map1.begin(); itr1 != map1.end(); ++itr1){
        if ((itr1)->second > maxValue){
            maxValue=(itr1)->second;
        }
    }

    //Insert the objects with max-count in result set.
    for (itr1 = map1.begin(); itr1 != map1.end(); ++itr1)
    {
        if (itr1->second == maxValue)
        {
          result.insert(itr1->first);
        }
    }
    return result;
    }

   /**
    * Get the value of the smallest element
    *
    * @return the minimum value of the data pushed in
    */
    T min(){
    T temp;
    typename std::list<T>::iterator it = listItems.begin();
    if(!listItems.empty())
      {
         temp =(*it);
         ++it;
      }

    //While loop gets the smallest element and stores it in temp object
    while(it!=listItems.end())
    {
     if(temp>(*it))
     {
     temp=(*it);
     }
     ++it;
    }
    return temp;
   }
   /**
    * Get the value of the largest element
    *
    * @return the maximum value of the data pushed in
    */
    T max(){
    T temp;
    typename std::list<T>::iterator it = listItems.begin();
        if(!listItems.empty())
        {
         temp =(*it);
         ++it;
        }

    //While loop gets the largest element and stores it in temp object
    while(it!=listItems.end())
    {
        if(temp<(*it))
        {
            temp=(*it);
        }
     ++it;
    }
    return temp;
    }

   /**
    * Add an element to our data set
    *
    * @param t Element to add to our data
    */
    void push( T t ){
    listItems.push_back(t);
    }

   /**
    * Removes all elements from the data
    */
    void clear(){
    listItems.clear();
    }

    typedef T value_type;
    std::list<T> listItems;
};
#endif // _STATISTICS_H_
