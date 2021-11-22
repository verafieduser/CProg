//  Trad.cpp
//  labb4_tree

#include <iostream>
#include "Trad.h"

template <class T>
void Trad<T>::satt_in( T newValue ) {
  if(tomt()){
    //skapa ny rot-nod,
    rot = new Nod(newValue);
    return; 
  }

  //typecast data?
  T rotdata = T(rot->data);

  if(newValue < rotdata){
    v_barn().satt_in(newValue);
    return;
  }

  if(newValue == rotdata){
    return;
  }

  if(newValue > rotdata){
    h_barn().satt_in(newValue);
    return;
  }
  
}

template <class T>
T Trad<T>::sok ( T value ) const {
  if(tomt()){
    return 0;
  }
  //typecast rot.data?
  if(value == rot->data){
    return value; //returnera värdet istället? 
  }
  T found = v_barn().sok(value);
  if(found != 0){
    return found;
  }

  found = h_barn().sok(value);
  return found;
}


template <class T>
void Trad<T>::kopiera( const Trad<T>& t)
{
  //std::cout << "*** Trad::kopiera\n";
  if (t.tomt())
    rot = 0;
  else
  {
    rot = new Nod( t.varde());
    v_barn().kopiera( t.v_barn());
    h_barn().kopiera( t.h_barn());
  }
}
template <class T>
Trad<T>& Trad<T>::operator= (const Trad<T>& t)
{
  //std::cout << "*** Trad::operator=\n";
  if (rot != t.rot)
  {
    delete rot;
    kopiera(t);
  }
  return *this;
}

template <class T>
bool Trad<T>::operator== (const Trad<T>& t) const
{
  //std::cout << "*** Trad::operator==\n";
  return (tomt() && t.tomt()) ||
          (!tomt() && !t.tomt() && varde() == t.varde() &&
           v_barn() == t.v_barn() && h_barn() == t.h_barn());
}

template <class T>
void Trad<T>::skriv_ut() const
{
  // traversera igenom trädet rekursivt enligt principen "in-order"
  if (!tomt())
  {
    v_barn().skriv_ut();
    std::cout << varde() << ' ';
    h_barn().skriv_ut();
  }
}

template class Trad<double>;
template class Trad<int>;
template class Trad<short>;