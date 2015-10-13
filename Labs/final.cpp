
    #include <iostream>
  using namespace std;
    class Base{
    //Convert the following function to be generic and list the operators that would be required to be overloaded to support the operators in the function.
    public:
        int name;
    Base() {
        name = 0;
    }
    ~Base() {

    }
    template<typename T> bool Afunction(T f, T l, const T v)

    {
        T m = f;

        //f = Bfunction( f, l, v); // assume Bfunction also is generic

        if ( m > f)
            f = m;
        return (f && !(v < f));

        }


                             //=, >, <,

    };
    int main() {
         Base Bp;
         Base a;
         Base b;


        //delete Bp;

        return 0;
}
