#pragma once
#include <iostream>
// Described in a paper in 1995 called CRTP - Curiously Recurring Template Pattern
// This pattern avoids using virual on functions in order to improve performance. 

// Limitations: 
// Every derived type technically has a different base class. ( No array of Animals.)

template <typename Derived>
class CRTPAnimal
{
private:
	//Must default the constructer and destructor!
	CRTPAnimal() = default;  //Protects against
	~CRTPAnimal() = default; //"wrong" Derived class
	friend Derived;

public:
	void make_sound() const
	{
		// This ensures the derived type will be the one used to define what the base fuction does.
		Derived& derivedClass = static_cast<Derived const&>(*this);
		derivedClass.make_sound();
	}
};

// This works because as soon as we call class dog we kind of forward declared it
// also we are allowed to intantiate class templates with incomplete types. 
class CRTPDog : public CRTPAnimal <CRTPDog>
{
public:
	// ~CRTPDog(); no need for this, remember Rule-of-5
	// ...

	// This is not a virtual function so the way we get it to work is by
	// static casting "this" to Derived in the base class function. 
	void make_sound() const { std::cout << "woof"; }
};

// This function has to be a template in order to interact with the CRTP classes. 
// Might be inline
template<typename Derived>
void print(CRTPAnimal<Derived> const& animal)
{
	// ...
}
