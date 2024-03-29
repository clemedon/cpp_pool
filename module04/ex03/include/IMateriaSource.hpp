// @author    Clément Vidon
// @created   230419 11:08:02  by  clem@spectre
// @modified  230419 11:19:09  by  clem@spectre
// @filename  IMateriaSource.hpp

#ifndef IMATERIASOURCE_HPP_
#define IMATERIASOURCE_HPP_

#include <string>

class AMateria;

/**
 * MateriaSource Interface
 */

class IMateriaSource {
 public:
  virtual ~IMateriaSource() {}
  virtual IMateriaSource& operator=( IMateriaSource const& rhs ) = 0;
  virtual void            print( std::ostream& o ) const = 0;

  virtual void      learnMateria( AMateria* m ) = 0;
  virtual AMateria* createMateria( std::string const& type ) = 0;

  virtual void      displayKnowledge( void ) const = 0;
  virtual AMateria* getKnowledge( int idx ) const = 0;
  virtual void      displayMaterias( void ) const = 0;
};

#endif  // IMATERIASOURCE_HPP_
