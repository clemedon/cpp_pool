#include <Zombie.hpp>

#include <iostream>

Zombie::Zombie( void ) {
}

Zombie::~Zombie( void ) {
  std::cout << this->_name << " has been destroyed" << std::endl;
}

void Zombie::setName( std::string name ) {
  this->_name = name;
}

void Zombie::announce( void ) {
  std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
