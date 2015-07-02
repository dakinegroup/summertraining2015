### Object Oriented Design

#### Objects and Classes
**Objects** - These are the things with independent runtime existance. These are entities in object oriented systems.  
At run time objects interact with each other by sending messages.  
**Class** - Class is a collection of objects of same type.  
For example - there are fruits in a basket like banana, orange and apple. In this example fruit is a class and banana , orange and apple are its objects.
#### Inheritance 
It is the property in oop in which sub classes  inherit or acquire the properties of its main class.
####Class Access Modifiers
Data hiding in object oriented programming allows preventing the functions of a program to access directly the internal representation of a class type. It can be specified by labelling public, private or protected in the class. The default members in the class are private.  
**Public** - A public member is accessible from anywhere outside the class but within a program. You can set and get the value of public variables without any member function.
```C
#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      double length;
      void setLength( double len );
      double getLength( void );
};
 
// Member functions definitions
double Line::getLength(void)
{
    return length ;
}
 
void Line::setLength( double len )
{
    length = len;
}
 
// Main function for the program
int main( )
{
   Line line;
 
   // set line length
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   // set line length without member function
   line.length = 10.0; // OK: because length is public
   cout << "Length of line : " << line.length <<endl;
   return 0;
}
```
**Private**-  The private member of the class cannot be accessed or viewed from outside the class. Only the other members of that class can access that member. 
```C
#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      double length;
      void setWidth( double wid );
      double getWidth( void );
 
   private:
      double width;
};
 

double Box::getWidth(void)
{
    return width ;
}
 
void Box::setWidth( double wid )
{
    width = wid;
}
 

int main( )
{
   Box box;
   box.length = 10.0; 
   cout << "Length of box : " << box.length <<endl;
   box.setWidth(10.0); 
   cout << "Width of box : " << box.getWidth() <<endl;
 
   return 0;
}
```
**Protected**- It is similar to private but with an additional feature of being accessed in derived classes or child classes.


#### Polymorphism
Means the ability to take more than on form.  
Consider a situation. There is a class names Area. It has three objects circle, square & triangle with functions area(circle), area(square) & area(triangle) respectively. But the operation area is different for all three figures. So polymorphism will be helpful in objects with different internal functions to show same external functions. 

#### Operator Overloading
It is the process in which a operator is asked to do different tast at different instances.  
For example - operation of addition adds two integers. But wern this operator is used in strings it forms a new string by concatenation.
