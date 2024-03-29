// @author    Clément Vidon
// @created   230324 14:55:24  by  clem@spectre
// @modified  230324 14:58:08  by  clem@spectre
// @filename  DiamondTrap.hpp

#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include <iosfwd>
#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/**
 * DiamondTrap
 *
 * - attack() causes the target to lost <attackDamage> healthPoints
 * - beRepaired() gives <amount> healthPoints back
 * - attack() and beRepaired() cost 1 energyPoints point each
 * - DiamondTrap stops if it runs out of healthPoints or energyPoints
 */

class DiamondTrap : public FragTrap, public ScavTrap {
 public:
  explicit DiamondTrap( std::string const& name = "D" );
  DiamondTrap( DiamondTrap const& src );
  ~DiamondTrap( void );
  DiamondTrap& operator=( DiamondTrap const& rhs );
  void         print( std::ostream& o ) const;

  void attack( std::string const& target );
  void whoAmI( void );

 private:
  std::string _name;
};

std::ostream& operator<<( std::ostream& o, DiamondTrap const& i );

#endif  // DIAMONDTRAP_HPP_
