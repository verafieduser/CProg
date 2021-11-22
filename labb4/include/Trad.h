//  Trad.h
//  labb4_tree


#ifndef TRAD_H
#define TRAD_H

#include <iostream>

template <class T> class Trad {
  
public:
  Trad<T>() : rot(0) {};                    // default konstruktor
  Trad<T>( T d ) { rot= new Nod(d); };
  Trad<T>( const Trad<T>& t ) { kopiera(t); };   // kopieringskonstruktor
  ~Trad<T>() { delete rot; };

  void satt_in( T newValue);

  T sok( T value) const;

  bool tomt() const { return !rot; };


  T& varde() const
  {
    koll();
    return rot->data;
  };
  Trad& v_barn() const
  {
    koll();
    return *rot->vanster;
  };
  Trad& h_barn() const
  {
    koll();
    return *rot->hoger;
  };
  Trad& operator= ( const Trad& );
  bool operator== ( const Trad& ) const;
  void skriv_ut() const;
  
private:
  class Nod {
    friend class Trad;

    T data;
    Trad *vanster, *hoger;
    Nod( T d ) : data( d ), vanster( new Trad ), hoger( new Trad ) {};
    ~Nod()
    {
      delete vanster;
      delete hoger;
    };
  }; // end class Nod

  Nod *rot;
  void koll() const
  {
    if ( tomt() )
      throw std::range_error( "Trad" );
  }
  void kopiera( const Trad& t );
};



#endif /* Trad_h */
