#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

#include "Form.hpp"

size_t const Form::_topGrade = 1;
size_t const Form::_botGrade = 150;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Form::Form( std::string const& name,
            bool const&        s,
            size_t const&      signGrade,
            size_t const&      execGrade )
  : _name( name ),
    _signed( s ),
    _signGrade( signGrade ),
    _execGrade( execGrade ) {
  checkGradeLimits( _signGrade );
  checkGradeLimits( _execGrade );
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " CONSTRUCTED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

Form::Form( Form const& src )
  : _name( src._name ),
    _signed( src._signed ),
    _signGrade( src._signGrade ),
    _execGrade( src._execGrade ) {
  *this = src;
  checkGradeLimits( _signGrade );
  checkGradeLimits( _execGrade );
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " COPY CONSTRUCTED ";
  std::cerr << *this;
  std::cerr << " FROM ";
  std::cerr << src;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

Form::~Form( void ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " DESTRUCTED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Form& Form::operator=( Form const& rhs ) {
#if defined( DEBUG )
  std::cerr << rhs;
  std::cerr << " ASSIGNED TO " << *this;
  std::cerr << std::endl;
#endif
  if( this == &rhs ) {
    return *this;
  }
  *this = rhs;
  return *this;
}

/**
 * @brief       Print State
 */

void Form::print( std::ostream& o ) const {
  o << "[ Form: ";
  o << _name;
  o << " SIG_";
  o << _signGrade;
  o << " EXE_";
  o << _execGrade;
  if( _signed ) {
    o << " SIGNED ]";
  } else {
    o << " UNSIGNED ]";
  }
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Form const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void Form::checkGradeLimits( size_t const& grade ) const {
  if( grade < Form::_topGrade ) {
    throw EFormGradeTooHigh( grade );
  } else if( grade > Form::_botGrade ) {
    throw EFormGradeTooLow( grade );
  }
  return;
}

void Form::beSigned( Bureaucrat const& b ) {
  if( _signed ) {
    std::cout << *this << " form already signed." << std::endl;
  } else {
    b.isAccredited( _signGrade );
    _signed = true;
  }
  return;
}

bool Form::isSigned( void ) const {
  return _signed == true;
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string Form::getName( void ) const {
  return _name;
}

bool Form::getSigned( void ) const {
  return _signed;
}

size_t Form::getSignGrade( void ) const {
  return _signGrade;
}

size_t Form::getExecGrade( void ) const {
  return _execGrade;
}

/*  EXCEPTIONS
------------------------------------------------- */

EFormGradeTooHigh::GradeTooHighException( size_t grade )
  : _message( "Error: Grade " + std::to_string( grade )
              + " grade abnormaly high" ) {
  return;
}

EFormGradeTooHigh::~GradeTooHighException( void ) throw() {
  return;
}

char const* EFormGradeTooHigh::what( void ) const throw() {
  return _message.c_str();
}

EFormGradeTooLow::GradeTooLowException( size_t grade )
  : _message( "Error: Grade " + std::to_string( grade )
              + " is abnormaly low" ) {
  return;
}

EFormGradeTooLow::~GradeTooLowException( void ) throw() {
  return;
}

char const* EFormGradeTooLow::what( void ) const throw() {
  return _message.c_str();
}
