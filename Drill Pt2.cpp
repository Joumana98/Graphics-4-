#include "../std_lib_facilites.h"

struct Person
{
    Person(string fn="",string ln="",int a=0);

    //Accessors
    string get_fname()const{return fname;};
    string get_lname()const{return lname;};
    int get_age() const{return age;}

    //Mutators
    void set_name(string fn,string ln);
    void set_fname(string fn);
    void set_lname(string ln);
    void set_age(int a);

    private:
    string fname;
    string lname;
    int age;

};

  //operators
    istream& operator>>(istream& is,Person& p);
    ostream& operator<< (ostream& os, const Person& p);

int main()
{
    Person p1{"Goofy","Luffy",63};
    cout << "Person: "<<p1.get_fname()<< " "<< p1.get_lname()<<" , " << p1.get_age() << endl;

    Person p2;
    cout << "Enter the name and the age of a new person: " ;
    cin>>p2;
    cout << endl;
    cout << p2;

    vector<Person> people;

    for (Person p;cin>>p;)
        people.push_back(p);
    for (Person p:people)
        cout << p<< endl;

    return 0;
}
void Person::set_fname(string fn)
{
    for (int i=0;i<fn.size();i++)
     {
        if (fn[i]==';'||fn[i]==':'||fn[i]=='"'||fn[i]=='\''||fn[i]=='['||fn[i]==']'||fn[i]=='*'||fn[i]=='&'||fn[i]=='^'||fn[i]=='%' )
            error("Wrong Person name");
        if(isdigit(fn[i]))
             error("First name not supplied");
     }
    fname=fn;
}
void Person::set_lname(string ln)
{
    for (int i=0;i<ln.size();i++)
    {
        if (ln[i]==';'||ln[i]==':'||ln[i]=='"'||ln[i]=='\''||ln[i]=='['||ln[i]==']'||ln[i]=='*'||ln[i]=='&'||ln[i]=='^' ||ln[i]=='%' )
            error("Wrong Person name");
        if(isdigit(ln[i]))
             error("Last name not supplied");
    }
    lname=ln;
}
void Person::set_name(string fn,string ln)
{
   set_fname(fn);
   set_lname(ln);
}

void Person::set_age(int a)
{
    if (a>=0 && a<150)
       age=a;
    else
        error("Wrong age");
}

Person::Person(string fn,string ln,int a)
{
    set_name(fn,ln);
    set_age(a);
}

 istream& operator>>(istream& is,Person& p)
 {
     string fn,ln;
     int a;
     if (is>>fn)
     {
         p.set_fname(fn);
         if (is>>ln)
         {
             p.set_lname(ln);
             if(is>>a)
                 p.set_age(a);
            else
            {
            is.clear(ios_base::failbit);
            return is;
            }
         }
         else
         {
            is.clear(ios_base::failbit);
            return is;
         }
     }
     else
     {
        is.clear(ios_base::failbit);
        return is;
     }
     return is;

 }
 ostream& operator<< (ostream& os, const Person& p)
 {
     os<< p.get_fname()<< " " << p.get_lname()<<"," << p.get_age();
     return os;

 }
