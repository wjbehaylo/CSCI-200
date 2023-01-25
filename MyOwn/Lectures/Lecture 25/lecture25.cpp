

void Zombie:: greet( const Zombie &OTHER) const {
    cout<< "Hello "<<OTHER.getName() << endl;
    cout<< "I am " << getName() << endl;
}

Zombie bill( "Bill");
Zombie ted( "Ted");
bill.greet( ted )