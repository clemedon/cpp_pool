/* src/main */
/* Created: 230718 20:00:55 by clem@spectre */
/* Updated: 230718 20:00:55 by clem@spectre */
/* Maintainer: Clément Vidon */

#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

double calculateExecutionTime( struct timeval start, struct timeval finish ) {
  double startTime, finishTime;

  startTime = static_cast<double>( start.tv_sec )
              + static_cast<double>( start.tv_usec ) * 1e-6;
  finishTime = static_cast<double>( finish.tv_sec )
               + static_cast<double>( finish.tv_usec ) * 1e-6;
  return ( finishTime - startTime ) * 1e6;
}

/**
 * @brief       Ford-Johnson merge-insertion sort
 *
 * Wikipedia:
 *
 * Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving
 * one element unpaired if there is an odd number of elements.
 *
 * Perform [n/2] comparisons, one per pair, to determine the larger of the two
 * elements in each pair.
 *
 * Recursively sort the [n/2] larger elements from each pair, creating a sorted
 * sequence S of [n/2] of the input elements, in ascending order.
 *
 * Insert at the start of S the element that was paired with the first and
 * smallest element of S.
 *
 * Insert the remaining [n/2] − 1 elements of X ∖ S into S, one at a time, with
 * a specially chosen insertion ordering described below. Use binary search in
 * subsequences of S (as described below) to determine the position at which
 * each element should be inserted.
 */

int main( int argc, char** argv ) {
  try {
    if( argc < 2 ) {
      throw std::runtime_error( "Error" );
    }

    std::vector<std::string> numbers;
    long                     num;
    char*                    endptr;
    std::vector<long>        vec;
    std::deque<long>         deq;

    numbers.assign( argv + 1, argv + argc );
    std::vector<std::string>::const_iterator it;
    for( it = numbers.begin(); it != numbers.end(); ++it ) {
      num = std::strtol( ( *it ).c_str(), &endptr, 10 );
      if( *endptr != '\0' || num < 0 ) {
        throw std::runtime_error( "Error" );
      } else {
        vec.push_back( num );
        deq.push_back( num );
      }
    }
    if( vec.size() == 1 ) {
      throw std::runtime_error( "Error" );
    }

    struct timeval start, finish;
    double         vecExecutionTime;
    double         deqExecutionTime;

    std::cout << "Before:\t";
    printUnits( vec );

    std::cout << "After:\t";
    gettimeofday( &start, NULL );
    printUnits( sort( vec ) );
    gettimeofday( &finish, NULL );
    vecExecutionTime = calculateExecutionTime( start, finish );

    gettimeofday( &start, NULL );
    sort( deq );
    gettimeofday( &finish, NULL );
    deqExecutionTime = calculateExecutionTime( start, finish );

    /* std::cout << "      \t"; */
    /* printNumbers( deq ); */
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::vector : " << std::scientific
              << std::setprecision( 6 ) << vecExecutionTime << " μs\n";
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::deque  : " << std::scientific
              << std::setprecision( 6 ) << deqExecutionTime << " μs\n";
  } catch( const std::exception& e ) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
