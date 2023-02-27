#include <iostream>
#include <string>

#include "AMateria.hpp"

#include "MateriaSource.hpp"

extern const int g_knowledgeSize;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

MateriaSource::MateriaSource( void ) {
  int i;

  for( i = 0; i < g_knowledgeSize; i++ ) {
    this->_learned[i] = NULL;
  }
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

MateriaSource::MateriaSource( MateriaSource const& src ) {
  int i;

  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( src._learned[i] ) {
      this->_learned[i] = src._learned[i]->clone();
    } else {
      this->_learned[i] = NULL;
    }
  }
  std::cout << __FILE__;
  std::cout << " COPY CONSTRUCTED ";
  std::cout << *this;
  std::cout << " FROM ";
  std::cout << src;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

MateriaSource::~MateriaSource( void ) {
  int i;

  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;

  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( this->_learned[i] ) {
      delete this->_learned[i];
    }
  }
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

MateriaSource& MateriaSource::operator=( MateriaSource const& rhs ) {
  int i;

  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( this->_learned[i] ) {
      delete this->_learned[i];
    }
    this->_learned[i] = rhs._learned[i]->clone();
  }
  return *this;
}

/**
 * @brief       Print State
 */

void MateriaSource::print( std::ostream& o ) const {
  o << "MateriaSource";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, MateriaSource const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       Learn a new type of Materia
 *
 * @param[in]   m a new type of Materia
 */

void MateriaSource::learnMateria( AMateria* m ) {
  int i;

  if( m == NULL ) {
    return;
  }
  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( this->_learned[i] == NULL ) {
      this->_learned[i] = m;
      std::cout << *this;
      std::cout << " has placed ";
      std::cout << *m;
      std::cout << " in space ";
      std::cout << i;
      std::cout << " of its knowledge";
      std::cout << std::endl;
      return;
    }
  }
  return;
}

/**
 * @brief       Create a Materia of one of the learned type
 *
 * @param[in]   type a type of Materia
 * @return      a new Materia of the given type if the type if known or nothing
 */

AMateria* MateriaSource::createMateria( std::string const& type ) {
  int i;

  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( this->_learned[i]->compareType( type ) ) {
      return this->_learned[i]->clone();
    }
  }
  return NULL;
}

/**
 * @brief       Display the learned materia
 */

void MateriaSource::displayLearned( void ) const {
  int i;

  std::cout << *this << "'s knowledge:" << std::endl;
  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( this->_learned[i] ) {
      std::cout << " - space " << i + 1 << " contains " << *this->_learned[i]
                << std::endl;
    } else {
      std::cout << " - space " << i + 1 << " is free" << std::endl;
    }
  }
  return;
}
