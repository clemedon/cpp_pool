#include <iostream>
#include <sstream>
#include <string>
#include "ScavTrap.hpp"

/*  STANDARD MEMBER FUNCTIONS
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

ScavTrap::ScavTrap( std::string const& name,
                    int const&         healthPoints,
                    int const&         energyPoints,
                    int const&         attackDamage )
  : ClapTrap( name, healthPoints, energyPoints, attackDamage ) {
  std::cout << *this;
  std::cout << "IS BORN !" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

ScavTrap::ScavTrap( ScavTrap const& src )
  : ClapTrap( src._name,
              src._healthPoints,
              src._energyPoints,
              src._attackDamage ) {
  std::cout << *this;
  std::cout << "IS BORN as a clone of " << src << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

ScavTrap::~ScavTrap( void ) {
  std::cout << *this;
  std::cout << "IS DEAD !" << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

ScavTrap& ScavTrap::operator=( ScavTrap const& rhs ) {
  std::cout << rhs;
  std::cout << "is assigned to " << *this << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  this->_name = rhs._name;
  this->_healthPoints = rhs._healthPoints;
  this->_energyPoints = rhs._energyPoints;
  this->_attackDamage = rhs._attackDamage;
  return *this;
}

/**
 * @brief       Print Instance State
 */

void ScavTrap::print( std::ostream& o ) const {
  o << "[";
  o << " health = " << this->_healthPoints;
  o << " energy = " << this->_energyPoints;
  o << " attack = " << this->_attackDamage;
  o << "\t] ";
  o << "ScavTrap " << this->_name << " ";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, ScavTrap const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       ScavTrap attacks
 *
 * Causes its target to lose health points.
 * Costs 1 points of energy.
 *
 * @param[in]   target the target to attack
 */

void ScavTrap::attack( std::string const& target ) {
  if( this->isAble() ) {
    this->_energyPoints -= 1;
    std::cout << *this << "ATTACKED " << target << " with a fork, causing "
              << this->_attackDamage << " points of damage !" << std::endl;
  }
  return;
}

/**
 * @brief       ScavTrap guard gate
 *
 * Causes its target to lose health points.
 * Costs 1 points of energy.
 *
 * @param[in]   target the target to attack
 */

void ScavTrap::guardGate( void ) {
  if( this->isAble() ) {
    std::cout << *this << "is now in gate keeper mode" << std::endl;
  }
  return;
}
