// @author    Clément Vidon
// @created   230324 15:21:59  by  clem@spectre
// @modified  230324 15:21:59  by  clem@spectre
// @filename  WrongAnimal.cpp

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

WrongAnimal::WrongAnimal( std::string const& type ) : _type( type ) {
  std::cout << *this;
  std::cout << " CONSTRUCTED ";
  std::cout << _type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

WrongAnimal::WrongAnimal( WrongAnimal const& src ) : _type( src._type ) {
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

WrongAnimal::~WrongAnimal( void ) {
  std::cout << *this;
  std::cout << " DESTROYED ";
  std::cout << _type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

WrongAnimal& WrongAnimal::operator=( WrongAnimal const& rhs ) {
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  _type = rhs._type;
  return *this;
}

/**
 * @brief       Print State
 */

void WrongAnimal::print( std::ostream& o ) const {
  o << _type;
  std::cout << " (via " << __FILE__ << ")";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, WrongAnimal const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void WrongAnimal::makeSound( void ) const {
  std::cout << "*" << _type << " sound‥ silence*";
  std::cout << std::endl;
  return;
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string WrongAnimal::getType( void ) const {
  return _type;
}
