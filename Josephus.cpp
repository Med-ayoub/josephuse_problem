////////////////////////////////////////////////////////////////////////////////
// Name:        unknown error
// Date:        10/30/2022
// Assignment:  CSCI 362: THE JOSEPHUS PROBLEM
// Description: The loop body of execute function first finds the element to be
//              removed,removes it, and then backtracks to the element before it
//              Once the loop exited,inserts the remaining element into the list
////////////////////////////////////////////////////////////////////////////////

//includes
#include <iostream>
#include <list>
#include <iterator>
#include <math.h>
#include <numeric>
#include "Josephus.h"



/* Simulate the Josephus problem modeled as a std::list.
 * This function will modify the passed list with only a
 * single survivor remaining.
 *
 * @param circle -- the linked list of people
 * @param k -- skip amount. NOTE: k > 0
 *
 */
template <typename T>
std::list<T>
execute (std::list<T>& circle, int k)
{
  std::cout<<"Killed ";
  int nbIteration=0; //to count complexity
  std::list<T> killed;
  std::iota(std::begin(circle), std::end(circle), 1);
  auto it = std::next(std::begin(circle), circle.size());

  //Loop until one element is left
  while (circle.size() > 1)
  {
    // Find the element before the one to be removed.
    for(auto i = 1; i < k; ++i)
    {
      ++it;
      if (it == std::end(circle)) it = std::begin(circle);
      // Increment nbIteration to count complexity for each interation
      nbIteration++;
    }
    // Update the next element.
    const auto itNext = std::next(it) == std::end(circle) ? std::begin(circle)
                                                             : std::next(it);
    std::cout<<" "<<*itNext;
    // Remove the next element.
    circle.erase(itNext);
  }
  std::cout<<"\n";
  //Insert the remaining element
  killed.push_back(*it);

  return killed;
}

/* entry point to the Josephus problem from the autograder / main
 *
 * @param n -- number of people in the circle
 * @param k -- skip amount. NOTE: k > 0
 *
 * @return the last element in the list wich is the survior
 */
int
josephus (int n, int k)
{

  //make a list
  std::list<int> circle;

  //populate list with values [1, 2, 3, ... , N]
  for(auto i=0; i<n; i++) {
    circle.push_back(i);
  }

  std::list<int> killed;

  //Complexity is O(n)
  //Explanations : first finds the element to be removed,removes it,
  //and then backtracks to the element before it
  killed=execute(circle,k);

  //return remaining element
  return killed.front();
}
