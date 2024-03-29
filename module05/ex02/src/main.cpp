// @author    Clément Vidon
// @created   230417 14:39:14  by  clem@spectre
// @modified  230417 14:39:14  by  clem@spectre
// @filename  main.cpp

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/**
 * ex00
 *
 * Bureaucrat throws EGradeTooHigh and EGradeTooLow as "temporary", they are
 * created and thrown at once like: throw EGradeTooLow ( _grade );
 *
 * ex01
 *
 * Bureaucrat::giveGrade is exactly the same as Bureaucrat::getGrade but unlike
 * the latter it does respect encapsulation principle.
 *
 * Attempting to sign a contract at too high a level will not interrupt the
 * program as catch() is in a member function in the middle of the program,
 * conversely if the grade of a Bureaucrat is not legal then the program will
 * end as the catch() is at the end of the program in the main.
 *
 * ex02
 *
 * In my quest for my non-use of getters I was confronted with a problem when
 * implementing the copy constructor of AForm derived classes, indeed, how to
 * access AForm source attributes to build AForm copy if they are private? The
 * solution was to set AForm copy constructor to protected, therefor I can
 * directly call AForm's copy constructor from its derived classes and build a
 * copy without accessing its attributes.
 *
 * In addition to that it is recommended to set any abstract class' constructors
 * to protected to prevent any attempt of illegal instantiation on the user side
 *
 * I decided to (void)executor; in execute() because I dont need him since I
 * have a beExecuted() in AForm that already print "<bureaucrat> executed
 * <form>" message, to stay consistent with previously implemented beSigned()
 * behavior.
 */

int main( void ) {
  Bureaucrat olaf = Bureaucrat( "Olaf", 6 );
  AForm*     f1 = new PresidentialPardonForm( "Vadim" );
  AForm*     f2 = new ShrubberyCreationForm( "Kitchen" );
  AForm*     f3 = new RobotomyRequestForm( "Vadim" );
  std::cout << std::endl;
  try {
    olaf.signForm( *f1 );
    olaf.executeForm( *f1 );
    olaf.upGrade();
    olaf.executeForm( *f1 );
    std::cout << std::endl;

    olaf.signForm( *f2 );
    olaf.executeForm( *f2 );
    std::cout << std::endl;

    olaf.signForm( *f3 );
    olaf.executeForm( *f3 );
    std::cout << std::endl;

    olaf.upGrade();
    olaf.upGrade();
    olaf.upGrade();
    olaf.upGrade();
    olaf.upGrade();
    std::cout << std::endl;

  } catch( EBureaucratGradeTooHigh const& e ) {
    std::cout << e.what() << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  } catch( EBureaucratGradeTooLow const& e ) {
    std::cout << e.what() << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  } catch( EAFormGradeTooHigh const& e ) {
    std::cout << e.what() << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  } catch( EAFormGradeTooLow const& e ) {
    std::cout << e.what() << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  } catch( ... ) {
    std::cout << "Error occurred during what() message formatting";
    std::cout << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  }
  delete f1;
  delete f2;
  delete f3;
  return 0;
}
